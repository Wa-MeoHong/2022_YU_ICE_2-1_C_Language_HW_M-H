#include "Event.h"

void initEvent(Event* pEv, unsigned int sAddr, unsigned int sN)
{
	pEv->ev_gen_addr = sAddr;
	pEv->ev_han_addr = -1;
	pEv->seq_no = sN;


}

void calc_elapsed_time(Event* pEv, LARGE_INTEGER freq)			// 생성-> 처리까지 걸린 시간 측정
{
	LONGLONG t_diff;											// LONGLONG 자료형 = 64비트 실수형 자료형
	t_diff = pEv->t_proc.QuadPart - pEv->t_gen.QuadPart;
	pEv->elapsed = (double)t_diff / freq.QuadPart;
}

void printEvent(Event* pEv)										// 이벤트 출력 함수
{
	printf("Ev[%3d, pri(%2d), gen(%2d), proc(%2d)] ", pEv->seq_no, pEv->ev_pri, pEv->ev_gen_addr, pEv->ev_han_addr);
}

void fprintEvent(FILE* fout, Event* pEv)						// 이벤트 파일 출력 함수
{
	fprintf(fout, "Ev[%3d, pri(%2d), gen(%2d), proc(%2d)] ", pEv->seq_no, pEv->ev_pri, pEv->ev_gen_addr, pEv->ev_han_addr);
}

void printEvent_withTime(Event* pEvt)							// 이벤트를 걸린 시간과 함께 출력
{
	printf("Ev(no: %3d, pri: %2d, elap_t : %6.0lf[ms]) ", pEvt->seq_no, pEvt->ev_pri, pEvt->elapsed * 1000);
}