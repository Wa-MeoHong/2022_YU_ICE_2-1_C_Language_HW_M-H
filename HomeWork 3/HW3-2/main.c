/*
  파일명 : "HW3-2_21912193_신대홍	"

  프로그램의 목적 및 기본 기능:
	- N개의 정수를 한줄로 입력받고, 입력된 정수들을 배열에 넣고
	최대, 최소, 평균, 분산, 표준편차를 출력하는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 13일)
  최종 Update : Version 1.1.0, 2022년 3월 14일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/13		v1.0.0		  최초작성
   신대홍		 2022/03/14		v1.1.0		  분산, 표준편차 계산 추가
===========================================================================================================
*/

#pragma warning(disable: 4996)						// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <limits.h>									// INT_MIN, MAX를 이용하기 위한 헤더파일
#include <math.h>									// pow 함수 사용을 위한 math.h 헤더파일

#define N 10										// 입력할 정수의 개수 (10개)
#define POW_two 2									// 제곱수 2

int main(void)
{
	// 변수 선언
	int integer[N];									// 입력할 변수를 담는 배열
	int max = INT_MIN, min = INT_MAX, sum = 0;		// 최댓값, 최솟값, 합계
	double avg, var, powsum = 0;					// 평균, 분산, 제곱의 합

	// 숫자 입력 (10번 반복)
	for (int i = 0; i < N; i++)
		scanf("%d", &integer[i]);

	// 입력한 숫자를 바탕으로 최댓값, 최솟값을 찾고, 평균을 계산
	for (int j = 0; j < N; j++)
	{
		if (max < integer[j])
			max = integer[j];
		if (min > integer[j])
			min = integer[j];
		sum += integer[j];
	}
	avg = (double)sum / N;

	// 분산을 계산 ( 제곱의 평균 - 평균의 제곱 )
	for (int a = 0; a < N; a++)						// 제곱의 평균을 계산하기위해 제곱의 합을 계산
		powsum = powsum + pow(integer[a], POW_two);
	var = (powsum / N) - (pow(avg, POW_two));

	//출력
	for (int k = 0; k < N; k++)
		printf("%d ", integer[k]);
	printf("\nnumber of input date = %d, min = %d, max = %d, avg = %lf,\
 var = %lf, std = %lf", N, min, max, avg, var, sqrt(var));	// 표준편차 = 분산의 제곱근

	return 0;
}