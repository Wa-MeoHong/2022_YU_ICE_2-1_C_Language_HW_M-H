#include "Thread.h"

using namespace std;

void Thread_EventGenerator(T_P_Ev* pParam)
{
	Event* pEv;

	// 초기값 설정
	int event_no = 0;
	int event_pri = 0;
	int event_gen_count = 0;
	int myRole = pParam->myAddr;
	int myGenAddr = pParam->myAddr;
	int target_E_G = pParam->targetEventGen;
	DLL_EvQ* pEvQ;
	DLL_EvQ* priH_EvQ = pParam->EvQ_PriH;
	DLL_EvQ* priL_EvQ = pParam->EvQ_PriL;
	T_Stat* pThrdMon = pParam->pThrdMon;
	int maxround = pParam->maxRound;

	pParam->pCS_main->lock(); // 문 걸어잠금
	printf("Thread_EventGenerator(%d) : targetEventGen(%d)\n", myGenAddr, target_E_G);
	pParam->pCS_main->unlock(); // 문 해제

	for (int round = 0; round < maxround; round++)
	{
		if (event_gen_count < target_E_G)
		{
			// 이벤트 생성 후 enqueue를 해준다.
			pEv = (Event*)calloc(1, sizeof(Event));
			pEv->ev_gen_addr = myGenAddr;
			pEv->seq_no = event_no = event_gen_count + (NUM_EV_PER_GEN * myGenAddr);
			pEv->ev_pri = event_pri = rand() % NUM_PRIORITY;
			pEv->ev_han_addr = -1; // 이 이벤트는 아직 핸들링 되지 않음
			QueryPerformanceCounter(&pEv->t_gen); // 생성된 시간 측정
			pEvQ = (event_pri < PRIORITY_THRESHOLD) ? priH_EvQ : priL_EvQ;
			while (enEventQ(pEvQ, pEv) == NULL) // enqueue 작업
			{
				Sleep(100);
			}

			pParam->pCS_thrd_mon->lock(); // 쓰레드 락
			// 생성된 이벤트를 기록용 배열에 집어넣음
			pThrdMon->eventGen[myGenAddr]++;
			pThrdMon->ev_Generated[pThrdMon->total_G_E] = *pEv;
			pThrdMon->total_G_E++;
			pParam->pCS_thrd_mon->unlock(); // 쓰레드 언락
			event_gen_count++;
		}

		else
		{
			if (*(pThrdMon->pFlagThreadTerminated) == TERMINATE)
				break; //쓰레드가 종료상태이면 for문을 탈출한다.
		}
		Sleep(100 + rand() % 100); // 슬립을 준다.
	}
}

void Thread_EventHandler(T_P_Ev* pParam)
{
	// 초기값 설정
	int myRole = pParam->myAddr;
	int myProcAddr = pParam->myAddr;
	Event* pEv;
	DLL_EvQ* priH_EvQ = pParam->EvQ_PriH;
	DLL_EvQ* priL_EvQ = pParam->EvQ_PriL;
	T_Stat* pThrdMon = pParam->pThrdMon;
	int maxround = pParam->maxRound;
	Event* evProc = pParam->pThrdMon->ev_Processed;
	int target_E_G = pParam->targetEventGen;
	LARGE_INTEGER freq = pParam->freq; // 아까 잰 클럭을 가져옴

	pParam->pCS_main->lock(); // 문 걸어잠금
	printf("Thread_EventHandler(%d) : targetEventGen(%d)\n", myProcAddr, target_E_G);
	pParam->pCS_main->unlock(); // 문 해제

	for (int round = 0; round < maxround; round++)
	{
		if (*(pThrdMon->pFlagThreadTerminated) == TERMINATE)
			break; //쓰레드가 종료상태이면 for문을 탈출한다.

		while ((pEv = deEventQ(priH_EvQ)) != NULL) // 우선순위가 높은 큐부터 진행
		{
			pParam->pCS_thrd_mon->lock();
			pEv->ev_han_addr = myProcAddr;
			QueryPerformanceCounter(&pEv->t_proc);
			calc_elapsed_time(pEv, freq);
			pThrdMon->ev_Processed[pThrdMon->total_P_E] = *pEv;
			pThrdMon->eventProc[myProcAddr]++;
			pThrdMon->total_P_E++;
			pThrdMon->num_P_E_H++;
			free(pEv); // 처리된 이벤트는 삭제된다. (값은 배열에 복사되어있으므로 괜찮음)
			pParam->pCS_thrd_mon->unlock();
			Sleep(100 + rand() % 200); // 슬립 줌(쓰레드 시간 맞추기)
		}
		if ((pEv = deEventQ(priL_EvQ)) != NULL) // 우선순위가 낮은 큐부터 진행
		{
			pParam->pCS_thrd_mon->lock();
			pEv->ev_han_addr = myProcAddr;
			QueryPerformanceCounter(&pEv->t_proc);
			calc_elapsed_time(pEv, freq);
			pThrdMon->ev_Processed[pThrdMon->total_P_E] = *pEv;
			pThrdMon->eventProc[myProcAddr]++;
			pThrdMon->total_P_E++;
			pThrdMon->num_P_E_L++;
			free(pEv); // 처리된 이벤트는 삭제된다. (값은 배열에 복사되어있으므로 괜찮음)
			pParam->pCS_thrd_mon->unlock();
		}
		Sleep(100 + rand() % 200); // 슬립 줌(쓰레드 시간 맞추기)
	}
}