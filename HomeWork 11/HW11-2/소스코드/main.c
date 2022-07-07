#include "Event.h"
#include "PriQ_E.h"

#define OUTPUT "output.txt"
#define RANDOMIZE() srand((unsigned int)time(NULL))
#define INIT_PriQ_SIZE 1

void test_PriQ_Event(FILE* fout, int max_events_P_round);	// 실행함수

int main(void)
{
	FILE* fout = NULL;
	int max_events_P_round;

	if ((fout = fopen(OUTPUT, "w")) == NULL)				//출력용 파일 열기, 에러면 메세지 출력
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}
	RANDOMIZE();											// 난수 생성을 위한 시드 생성
	printf("Input Num_events per round : ");				// 한 라운드당 최대 이벤트 개수
	scanf("%d", &max_events_P_round);

	test_PriQ_Event(fout, max_events_P_round);
	fclose(fout);
	return 0;
}

void test_PriQ_Event(FILE* fout, int max_events_P_round)
{
	PriQ* pPriQ_Ev = NULL;
	Event* pEv = NULL;
	Event Processed_event[N_O_EVENTS];
	int total_P_E = 0;										// processed 된 총 events
	int total_G_E = 0;										// generated 된 총 events
	int num_events = 0;										// 한 라운드 당 이벤트 수( = max_events_P_round)
	int num_G_R = 0;										// Generated 된 Round 수
	int num_P_R = 0;										// processed 된 Round 수 

	fprintf(fout, "Testing Event Handling with Priority Queue\n");
	pPriQ_Ev = (PriQ*)calloc(1, sizeof(PriQ));				// malloc보다 calloc이 안전하기 때문에 이렇게 정의했다.
	if (pPriQ_Ev == NULL)									// 동적할당이 되지 않으면 오류 메세지 출력후 종료
	{
		printf("Error!! Not allocing for PriorityQueue_Event!\n");
		fclose(fout);
		exit(-1);
	}
	printf("Initializing PriorityQueue_Event of capacity (%d)\n", INIT_PriQ_SIZE);
	initPriQ_Ev(pPriQ_Ev, "PriorityQueue_Event", INIT_PriQ_SIZE);	//초기값 설정

	// enqueue작업
	for (int round = 0; round < MAX_ROUND; round++)			
	{
		fprintf(fout, "\n*** Start of round(%2d)...\n", round);
		num_G_R = 0;
		if (total_G_E < N_O_EVENTS)							// Generated된 이벤트가 N_O_EVENTS( = 50)이 될때까지
		{
			num_events = max_events_P_round;
			if ((total_G_E + num_events) >= N_O_EVENTS)		// 만약 Generated된 이벤트가 이미 몇개 존재할 경우
				num_events = N_O_EVENTS - total_G_E;		// 그 수를 뺀 수만큼만 Generate한다.
			fprintf(fout, ">>> enque %2d events\n", num_events);
			for (int i = 0; i < num_events; i++)
			{
				pEv = genEvent(pEv, total_G_E, 0, N_O_EVENTS - total_G_E - 1); // 이벤트 생성
				if (pEv == NULL)							//안되면 종료
				{
					printf("Error in generation of event !! \n");
					fclose(fout);
					exit(-1);
				}
				fprintf(fout, "*** enque event : ");
				fprintEvent(fout, pEv);						// 파일에 출력
				enPriQ(pPriQ_Ev, pEv);						// 이진트리 큐에 추가 및 우선순위 재정렬
				total_G_E++;								// 생성된 이벤트 수 증가
				num_G_R++;									// 수 증가
				fprintPriQ(fout, pPriQ_Ev);					// 출력
			}
		}
		fprintf(fout, "\n===========================================================================\n");
		fprintf(fout, "\nRemoving min data from Priority Queue . . . \n");
		
		// Dequeue작업
		num_events = max_events_P_round;
		if ((total_P_E + num_events) > N_O_EVENTS)
			num_events = N_O_EVENTS - total_P_E;
		fprintf(fout, "<<< Dequeue %2d events\n", num_events);
		num_P_R = 0;
		for (int i = 0; i < num_events; i++)
		{
			pEv = dePriQ(pPriQ_Ev);					// dequeue한 후, 이벤트 반환받은 것
			if (pEv == NULL)						// 받은게 없다면 종료
			{
				fprintf(fout, "   PriQ is empty\n");
				break;
			}

			fprintf(fout, " *** Dequeued Event : ");
			fprintEvent(fout, pEv);					// 출력
			Processed_event[total_P_E] = *pEv;		// Processed된 이벤트를 따로 배열에 저장                                                               
			total_P_E++;							// dequeue한 이벤트 수 증가
			num_P_R++;								// 수 증가
		}

		//Monitoring Simulation Status (시뮬레이션 중인 상태를 출력 )
		fprintf(fout, "Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		fprintf(fout, "processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		fprintf(fout, "events_in_queue(%3d)\n\n", pPriQ_Ev->priQ_size);

		printf("Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		printf("processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		printf("events_in_queue(%3d)\n", pPriQ_Ev->priQ_size);

		if (total_P_E >= N_O_EVENTS)
			break;
		// 만약 Processe가 끝났다면( 모든 이벤트들을 Dequeue했다면) 반복문 중지
	}

	printf("Processed Events : \n");				// Dequeue까지 완료한 이벤트들을 이제 출력해본다.
	for (int i = 0; i < N_O_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_event[i].event_no, Processed_event[i].event_pri);
		if ((i + 1) % 5 == 0)						// 5번째마다 줄바꿈을 실행
			printf("\n");
	}
	printf("\n");
	delPriQ_Ev(pPriQ_Ev);							// 이제 우선순위 큐 사용이 끝났으므로 동적할당 해제
}