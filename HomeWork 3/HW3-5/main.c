/*
*파일명 : "Print Matrix "
*프로그램의 목적 및 기본 기능:
*      - 행렬A, 행렬B를 입력받아 (5 * 5짜리 둘다) 행렬곱을해 결과인 행렬M을 출력
*
*프로그램 작성자 : 신대홍(2022년 3월 14일)
*최종 Update : Version 1.5.0, 2022년 3월 15일(신대홍)
*============================================================================
*프로그램 수정/보완 이력
*============================================================================
*수정자			수정일			버전			수정/보완내용
*----------------------------------------------------------------------------
*신대홍		 2022/03/14			v1.0.0		최초작성
*신대홍		 2022/03/15			v1.5.0		행렬곱셈함수 추가
*
*============================================================================
*/

#include <stdio.h>
#define MTX_SIZE 5							// 행렬 사이즈 = 5 (행, 열 전부)

double MtxA[][MTX_SIZE] = {
	{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
/*
	행렬 A : 
	┌  1  2  3  4  5  ┐
	│  6  7  8  9  10 │
	│  11 12 13 14 15 │
	│  16 17 18 19 20 │
	└  21 22 23 24 25 ┘
*/
double MtxB[][MTX_SIZE] = {
	{1,1,0,0,0}, {0,1,1,0,0},{0,0,1,1,0}, {0,0,0,1,1},{0,0,0,0,1} };
/*
	행렬 B :
	┌  1  1  0  0  0  ┐
	│  0  1  1  0  0  │
	│  0  0  1  1  0  │
	│  0  0  0  1  1  │
	└  0  0  0  0  1  ┘
*/

double MtxM[][MTX_SIZE] = { {0},{0},{0},{0},{0} };

void printMtx(double mA[][MTX_SIZE], int SIZE);					// 행렬 출력 함수
void multipleMtx(double mA[][MTX_SIZE], double mB[][MTX_SIZE], double mM[][MTX_SIZE], int SIZE); // 행렬 곱 함수

int main(void)
{
	printf("print MtxA:\n");							// 행렬 A 출력
	printMtx(MtxA, MTX_SIZE);
	printf("print MtxB:\n");							// 행렬 B 출력
	printMtx(MtxB, MTX_SIZE);
	multipleMtx(MtxA, MtxB, MtxM, MTX_SIZE);			// 행렬 M 계산 ( M = A * B )
	printf("print MtxM:\n");							// 행렬 M 출력
	printMtx(MtxM, MTX_SIZE);
	return 0;
}

void multipleMtx(double mA[][MTX_SIZE], double mB[][MTX_SIZE], double mM[][MTX_SIZE], int SIZE)
// 행렬 곱 함수
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
				mM[i][j] += mA[i][k] * mB[k][j];				// 행렬 곱 = 행렬 A, B의 대응되는 원소의 곱의 합
		}
	}
}

void printMtx(double mA[][MTX_SIZE], int SIZE)
{
	const unsigned char a6 = 0xa6, a5 = 0xa5, a4 = 0xa4, a3 = 0xa3, a2 = 0xa2, a1 = 0xa1; 
	//확장형 문자코드 : ( ─ : a6a1, │ : a6a2, ┌ : a6a3, ┐ : a6a4, ┘ : a6a5, └ : a6a6 )

	for (int i = 0; i < SIZE; i++)
	{
		for (int k = 0; k < SIZE; k++)
		{
			// 대괄호 출력부분 ( 앞줄 [ )
			if (i == 0 && k == 0)
				printf("%c%c", a6, a3);							// ┌
			else if (i > 0 && i < SIZE - 1 && k == 0)
				printf("%c%c", a6, a2);							// │
			else if (i == SIZE - 1 && k == 0)
				printf("%c%c", a6, a6);							// └

			printf(" %3.0lf ", mA[i][k]);						// 숫자 출력부분
			
			// 대괄호 출력부분 ( 뒷줄 ] )
			if (i == 0 && k == SIZE - 1)
				printf("%c%c", a6, a4);							// ┐
			else if (i > 0 && i < SIZE - 1 && k == SIZE - 1)	
				printf("%c%c", a6, a2);							// │
			else if (i == SIZE - 1 && k == SIZE - 1)
				printf("%c%c", a6, a5);							// ┘
		}
		printf("\n");
	}
	printf("\n");
}