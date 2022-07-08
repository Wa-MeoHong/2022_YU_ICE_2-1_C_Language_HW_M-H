#ifndef EVENT_H
#define EVENT_H
#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "SimParam.h"
#include "ConsoleDisplay.h"

typedef struct Event // 이벤트 구조체
{
	// 이벤트의 정보들
	int seq_no;
	int ev_gen_addr;
	int ev_han_addr;
	int ev_pri;
	LARGE_INTEGER t_gen; // 이벤트가 생성된 시간 측정용
	LARGE_INTEGER t_proc; // 이벤트가 처리된 시간 측정용
	double elapsed; // 생성 - 처리되기까지 시간 측정
} Event;

void printEvent(Event* pEv);	// 이벤트 출력
void printEvent_withTime(Event* pEvt);		// 이벤트 출력 (시간 포함)
void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq); // 이벤트 생성 - 처리까지 걸린 시간
void fprintEvent(FILE* fout, Event* pEv); // 이벤트 출력 함수

#endif // !EVENT_H