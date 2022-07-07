/* 
  파일명 : "HW9-1_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 복소수 구조체 자료형 선언 후, 복소수 2개를 입력받고 연산을 진행 후, 퀵정렬을 하여 출력하는 프로그램

  프로그램 작성자 : 신대홍(2022년 5월 7일)
  최종 Update : Version 1.1.0, 2022년 5월 8일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/05/07		v1.0.0		  최초작성
   신대홍		 2022/05/08		v1.1.0		  코드완성
===========================================================================================================
*/

#ifndef CMPLX_H
#define CMPLX_H
#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <math.h>
#define CmplxNUM 7															//복소수 개수

typedef struct Complex_Number
{
	double real;					// 실수부분
	double imagin;					// 허수 부분
	double magnitude;				// 복소수 크기(복소수 크기비교용)
} Cmplx;

typedef enum Oper { ADD, SUB, MUL, DIV } Oper; 
// 복소수 연산 결과 출력용 enum

Cmplx InputCmplx();											// 복소수 입력 함수

// 복소수 출력
void printCmplxNum(const Cmplx c);													// 복소수 출력 함수
void printCplxresult(const Cmplx c1, const Cmplx c2, const Cmplx res, Oper num);	// 복소수 연산 출력 함수
void printCmplxs(const Cmplx* cmplxs, int SIZE);									// 복소수 배열 출력 함수

// 복소수 연산, 비교
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2);										// 복소수 덧셈
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);										// 복소수 뺄셈
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);										// 복소수 곱셈
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);										// 복소수 나눗셈
double CmpCmplx(const Cmplx c1, const Cmplx c2);									// 복소수 비교 함수

// 정렬
void quickSortCmplx(Cmplx* cmplxs, int SIZE); // 퀵정렬 최초함수
void quickSort(Cmplx* cmplxs, int SIZE, int left, int right); // 퀵정렬 본함수
int _partition(Cmplx* cmplxs, int SIZE, int left, int right, int P_I); //파티션 위치값 반환

#endif // CMPLX_H
