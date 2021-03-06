/*
  파일명 : "HW3-4_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 12 * 12 곱셈표를 출력하는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 14일)
  최종 Update : Version 1.0.0, 2022년 3월 14일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/13		v1.0.0		  최초작성
===========================================================================================================
*/

#pragma warning(disable: 4996)								// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#define Multiplicand 12										//곱하는 수
#define Multiplication 12									//곱해지는 수 

int main(void)
{
	// 출력
	printf(">>>>>>>>>> 12*12 table <<<<<<<<<<< \n\n");		// 제목
	printf("     |");										// 나누기 칸

	for (int i = 1; i <= Multiplication; i++)				// 곱해지는 수 출력
	{
		printf("%5d", i);									
	}
	printf("\n");

	printf("-----+---------------------------------------------------------------\n");
	
	// 본 출력
	for (int k = 1; k <= Multiplicand; k++)
	{
		printf("%5d|", k);									// 곱하는 수 출력
		for (int j = 1; j <= Multiplication; j++)			// 곱해지는 수 만큼 반복
		{
			printf("%5d", k * j);							// 결과 값 출력
		}
		printf("\n");										// 1줄이 끝나면 띄우고 반복 (12번)
	}

	return 0;
}