/*
*파일명 : "HW11-1_21912193_신대홍"
*프로그램의 목적 및 기본 기능:
*      - 환형 큐를 구성하고, 이벤트의 추가, 삭제를 하며 어떤식으로 메모리가 관리되는지 확인해보는 프로그램
*
*프로그램 작성자 : 신대홍(2022년 5월 20일)
*최종 Update : Version 1.0.0, 2022년 5월 20일(신대홍)
*============================================================================
*프로그램 수정/보완 이력
*============================================================================
*수정자			수정일			버전			수정/보완내용
*----------------------------------------------------------------------------
*신대홍		 2022/05/20			v1.0.0		최초작성
*============================================================================
*/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "Event.h"

// 환형 큐 구조체
typedef struct Circle_Queue {
	Event* pEv;					// 이벤트 주소
	int capacity;				// 용량
	int front;					// 환형은 front와 end가 서로 이어진다.
	int end;
	int num_elements;			// 현재 큐에 든 이벤트의 개수
} CirQ;									

CirQ* initCirQ(CirQ* pCirQ, int capacity);				// CirQ 구조체 자료형 초기값 설정
void fprintCirQ(FILE* fout, CirQ* pCirQ);				// 환형큐 현황 파일 출력 함수
bool isCirQFull(CirQ* pCirQ);							// 환형 큐의 이벤트 개수가 최대치(capacity)에 도달했는가?
bool isCirQEmpty(CirQ* pCirQ);							// 환형 큐의 이벤트 개수가 0개 인가?
Event* enCirQ(CirQ* pCirQ, Event ev);					// 환형큐에서 이벤트 추가(FIFO이기 때문에 줄서는것 처럼 마지막에 추가됨)
Event* deCirQ(CirQ* pCirQ);								// 환형큐에서 이벤트 줄이기(FIFO이기 때문에 front가 뒤로 밀림)
void delCirQ(CirQ* pCirQ);								// 환형 큐 동적할당 해제 함수 (모든 것이 끝난 후, 해제)

#endif 