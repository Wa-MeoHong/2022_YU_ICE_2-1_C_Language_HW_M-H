#ifndef MTRX_GH_H
#define MTRX_GH_H
#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 
 
#include "Matrix.h"
#include <stdio.h>
#include <math.h>

#define Epsilon 0.000001									// Epsilon = 소수점 표기 자리수 밑으로 넘어가는지 확인하기 위함

void pivoting(double** augMtrx, int SIZE_N, int p, int* piv_FOUND);			// 행 바꿔주는 함수 pivoting
void Diagnolize(FILE* fout, double** augMtrx, int SIZE_N, int* solExist);	// 가우스-조던 소거법 계산 함수
double** InvMtrx(double** mA, int row_SIZE);								// 역행렬 계산 함수

#endif // !MTRX_GH_H
