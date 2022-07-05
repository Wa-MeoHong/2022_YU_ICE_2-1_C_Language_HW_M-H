/*
  파일명 : "HW2-4_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
    -1 ~ 32,765 범위의 정수 (integer) 값을 입력 받아, 
    만, 천, 백, 십, 일의 단위 값을 구분한 후, 차례로 출력하는 알고리즘

  프로그램 작성자 : 신대홍(2022년 3월 6일)
  최종 Update : Version 2.1.0, 2022년 3월 8일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전		수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/06		v1.0.0		  최초작성
   신대홍		 2022/03/07		v2.0.0		 소스코드 변경
   신대홍		 2022/03/08		v2.1.0		 자리수부분을 문자열로 출력으로 변경
===========================================================================================================
*/

#pragma warning(disable: 4996)							// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <math.h>										// pow(제곱)을 사용하기 위해 사용

#define N 10								// 나누기수 10
#define DIGITS 4							//만은 10의 4승이기에 4로 설정, 1의자리를 0으로 생각하자.

int main(void)
{
	int integer;
	int i = DIGITS;												// 자리수 계산에 필요
	const char digit[DIGITS + 1][3] = { " ", "십","백","천","만" };	//자리수출력을 위한 2차원배열(한글은 2바이트를 먹기때문)
	printf("1 ~ 32765 사이의 정수를 입력하시오. ");
	scanf_s("%d", &integer);									// 정수 입력

	while (integer != 0)										// 정수가 0이 될때까지
	{
		int k = (int)pow(N, i);									// k = 10의제곱수, 자리수를 의미
		if ((integer / k) == 0)									// 만약 첫째자리수가 0이다
		{
			i -= 1;
			continue;						// 점점 자리수를 내려가며 첫째자리수가 0이아닌 곳을 찾는다.
		}
		printf("%d%s ", integer / k, digit[i]);

		integer = integer - (integer / k) * k;					// 쓴 자리수를 없애줌
		i -= 1;													// 10의 제곱수를 줄여줌 
	}
	return 0;
}