/*
  파일명 : "HW8_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 회로내의 저항과 전압과의 선형방정식을 세운 후, 흐르는 전류의 값을 가우스-조던 소거법으로 찾아내는 프로그램
	  역행렬을 사용해서 찾는 프로그램

  프로그램 작성자 : 신대홍(2022년 4월 17일)
  최종 Update : Version 1.1.0, 2022년 7월 6일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/04/17		v1.0.0		  최초작성
   신대홍		 2022/07/06		v1.5.0		  전반적으로 코드 최적화, 역행렬 부분 추가
===========================================================================================================
*/
 
#ifndef MATRIX_H
#define MATRIX_H

#pragma warning(disable: 4996)						// scanf오류 안뜨게 하는 pragma정의 
#include <stdio.h>
#include <stdlib.h>

double** fGetMtrx(FILE* fin, int* row_SIZE, int* col_SIZE);		// 파일에서 행렬을 읽어와서 동적생성
void DeleteDynMtrx(double** dM, int row_SIZE);				// 동적생성된 행렬을 해제
void PrintMtrx(char* name, double** mA, int row_SIZE, int col_SIZE);		// 행렬 출력 함수
void fPrintMtrx(FILE* fout, char* name, double** mA, int row_SIZE, int col_SIZE);		// 행렬 출력 (파일) 함수
double** AddMtrx(double** mA, double** mB, int row_SIZE, int col_SIZE);		// 행렬 덧셈
double** SubMtrx(double** mA, double** mB, int row_SIZE, int col_SIZE);		// 행렬 뺄셈
double** MulMtrx(double** mA, double** mC, int row_SIZE, int col_SIZE, int SIZE_k); // 행렬 곱셈

#endif
