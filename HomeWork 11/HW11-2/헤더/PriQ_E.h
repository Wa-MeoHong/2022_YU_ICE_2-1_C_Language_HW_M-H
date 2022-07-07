/*
*파일명 : "HW11-2_21912193_신대홍"
*프로그램의 목적 및 기본 기능:
*      - 우선순위 큐를 구성하고, 이벤트의 추가, 삭제를 하며 어떤식으로 메모리가 관리되는지 확인해보는 프로그램
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

#ifndef PRIQ_E_H
#define PRIQ_E_H

#include "Event.h"
#include <string.h>

#define POS_ROOT 1								// 최우선 노드
#define MAX_NAME_LEN 80

// 이벤트1개를 담는 구조체
typedef struct CBTN_Event {
	int priority;
	Event* pEv;
} CBTN_Event;

// 우선순위 큐 구조체
typedef struct PriorityQueue {
	char PriQ_Name[MAX_NAME_LEN];
	int priQ_capacity;
	int priQ_size;
	int pos_last;
	CBTN_Event* pCBT_Ev;
} PriQ; 

bool hasLeftChild(int pos, PriQ* pPriQ_Ev);				// 부모노드가 왼쪽 자식노드를 가지고 있는가?
bool hasRightChild(int pos, PriQ* pPriQ_Ev);			// 부모노드가 오른쪽 자식노드를 가지고 있는가?
PriQ* initPriQ_Ev(PriQ* pPriQ_Ev, char* name, int capacity); //PriQ 초기값 설정
void delPriQ_Ev(PriQ* pPriQ_Ev);						//동적할당 해제 함수 
void enPriQ(PriQ* pPriQ_Ev, Event* pEv);				// 노드 추가 함수
Event* dePriQ(PriQ* pPriQ_Ev);							// 최상위 노드 삭제 함수
void fprintPriQ(FILE* fout, PriQ* pPriQ_Ev);			// 파일 출력 함수

#endif // !PRIQ_E_H