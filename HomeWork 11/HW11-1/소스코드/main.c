#include "Event.h"
#include "CirQ_E.h"

#define OUTPUT "output.txt"
#define RANDOMIZE() srand((unsigned int)time(NULL))

void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round);			// 실행 함수 

int main(void)
{
	FILE* fout = NULL;
	int max_events_P_round;

	if ((fout = fopen(OUTPUT, "w")) == NULL)		//출력용 파일 열기, 에러면 메세지 출력
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}
	RANDOMIZE();									// 난수 생성을 위한 시드 생성
	printf("Input Num_events per round : ");		// 한 라운드당 최대 이벤트 개수
	scanf("%d", &max_events_P_round);

	test_FIFO_CirQ_Event(fout, max_events_P_round);
	fclose(fout);
	return 0;
}

void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round)
{
	CirQ* pCirQ_Event;
	Event* pEv = NULL;
	Event Processed_Events[N_O_EVENTS];

	int total_P_E = 0;									// processed 된 총 events
	int total_G_E = 0;									// generated 된 총 events
	int num_events = 0;									// 한 라운드 당 이벤트 수( = max_events_P_round)
	int num_G_R = 0;									// Generated 된 Round 수
	int num_P_R = 0;									// processed 된 Round 수 

	pCirQ_Event = (CirQ*)calloc(1, sizeof(CirQ));		// 환형 큐 생성
	fprintf(fout, "Testing Event Handling with FIFO Circular Queue\n");
	printf("Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	fprintf(fout, "Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	pCirQ_Event = initCirQ(pCirQ_Event, max_events_P_round);

	fprintf(fout, "\nEnqueuing Data into Event Circular queue: \n"); //먼저 이벤트 추가부터 한다.
	for (int round = 0; round < MAX_ROUND; round++)
	{
		fprintf(fout, "Start of (%2d) ****\n", round);	// 파일 출력
		if (total_G_E < N_O_EVENTS)
		{
			num_events = max_events_P_round;
			if (total_G_E + num_events > N_O_EVENTS)
				num_events = N_O_EVENTS - total_G_E;	// 만약 생성된 이벤트가 존재한다면, 그 이벤트들을 빼고 나머지만 만들면됨
			fprintf(fout, "Generated and enque %2d events\n", num_events);
			num_G_R = 0;								// Generated된 라운드 개수 초기화

			for (int i = 0; i < num_events; i++)
			{
				if (isCirQFull(pCirQ_Event))			// 만약 환형 큐가 꽉찼으면
				{
					fprintf(fout, "   !!! CirQ_Event is full --> SKIP Generation and Enqueueing of Event. \n");
					break;								// 그 즉시 종료한다.
				}

				// 이벤트를 생성함
				pEv = genEvent(pEv, total_G_E, EVENT_GENERATOR, N_O_EVENTS - total_G_E - 1);
				fprintf(fout, ">>> Enqueue event = ");
				fprintEvent(fout, pEv);

				// Handling 중 이벤트 추가(enqueue)
				enCirQ(pCirQ_Event, *pEv);				// 이제 이벤트를 enqueue(추가)함
				fprintCirQ(fout, pCirQ_Event);			// 이벤트1개 출력
				free(pEv);								// 아까 이벤트 생성하기 위해서 만든 주소를 해제해줌
				total_G_E++;							// 생성된 이벤트 수 갱신
				num_G_R++;
			}

			// Handling 중 이벤트 처리후 제거(dequeue)
			fprintf(fout, "\nDequeuing Data from Event Circular queue: \n"); 
			num_events = max_events_P_round;	// 위에서 50개를 생성했기 때문

			if ((total_P_E + num_events) > N_O_EVENTS)
				num_events = N_O_EVENTS - total_P_E;
			//만약 완료된 이벤트가 존재한다면, 그 이벤트들을 빼고 나머지만 만들면됨

			// dequeue 시작
			fprintf(fout, "Dequeue %2d events\n", num_events);
			num_P_R = 0;							// 작업 완료된 round 개수 초가화
			for (int i = 0; i < num_events; i++)	
			{
				if (isCirQEmpty(pCirQ_Event))		// 만약 Dequeue할 이벤트마저 없으면 바로 for문 탈출
					break;
				pEv = deCirQ(pCirQ_Event);
				if (pEv != NULL)
				{
					fprintf(fout, "<<< Dequeued event = ");		// dequeue한 이벤트 출력 
					fprintEvent(fout, pEv);						// 출력
					fprintf(fout, "\n");						//한칸 띄움
					Processed_Events[total_P_E] = *pEv;			// processed된 이벤트 주소를 담는 배열에 담음
					total_P_E++;								// Processed된 이벤트 개수 갱신
					num_P_R++;									// 라운드 UP
				}
				fprintCirQ(fout, pCirQ_Event);
			}
		}
		//Monitoring Simulation Status (시뮬레이션 중인 상태를 출력 )

		fprintf(fout, "Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		fprintf(fout, "processed_in_this_round(% 3d), total_processed_events(% 3d), ", num_P_R, total_P_E);
		fprintf(fout, "events_in_queue(%3d)\n\n", pCirQ_Event->num_elements);

		printf("Round(%2d): Generated_in_this_round(%3d), total_Generated_Events(%3d), ", round, num_G_R, total_G_E);
		printf("processed_in_this_round(%3d), total_processed_events(%3d), ", num_P_R, total_P_E);
		printf("events_in_queue(%3d)\n", pCirQ_Event->num_elements);

		if (total_P_E >= N_O_EVENTS)
			break;
		// 만약 Processe가 끝났다면( 모든 이벤트들을 Dequeue했다면) 반복문 중지
	}

	printf("Processed Events : \n");							// Dequeue까지 완료한 이벤트들을 이제 출력해본다.
	for (int i = 0; i < N_O_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_Events[i].event_no, Processed_Events[i].event_pri);
		if ((i + 1) % 5 == 0) 
			printf("\n");
	}
	printf("\n");
	delCirQ(pCirQ_Event);										// 이제 환형 큐 사용이 끝났으므로 동적할당 해제
}