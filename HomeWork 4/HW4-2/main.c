/*
  파일명 : "HW4-2_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 거듭제곱을 하는 함수를 2개(for반복문 사용, 재귀함수 사용)만든 후,
	각각의 함수들이 처리하는 시간을 출력하게 하여 비교해보는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 25일)
  최종 Update : Version 2.0.0, 2022년 7월 6일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/25		v1.0.0		  최초작성
   신대홍		 2022/03/27		v1.1.0		  재귀함수 수정(4000번대 됨)
   신대홍		 2022/07/06		v2.0.0		  재귀함수를 동적할당배열을 이용해서 재구성
===========================================================================================================
*/

#include <stdio.h>
#include <windows.h>								// 시간계산에 필요한 헤더파일 1 ( windows.h 이용 )
#include <time.h>									// 시간계산에 필요한 헤더파일 2 ( time.h 이용 )

#define Milli 1000									// 시간 환산용 상수

double PowerFor(double base, int exponent);									// 반복문 사용 거듭제곱
double PowerRecursive(double base, int exponent, double* array);			// 재귀함수 거듭제곱

int main(void)
{
	double resultF, resultR;						// 각각 for문의 결과, 재귀함수 결과 받을 변수들
	double base = 1.015;							// 1.015를 밑으로 설정
	double* Rarray;									// 오버플로로 인한 오류를 방지하기 위해 동적할당을 한다. (최적화를 위함)

	// 시간 계산에 필요한 변수 1 (windows.h 헤더파일을 이용)
	LARGE_INTEGER freq, t_1, t_2;							// CPU의 클럭을 담는 변수 freq, 시작 t_1, 끝 t_2
	LONGLONG t_diff_pc;										// t_2 - t_1 = t_diff_pc (시간차 계산) (LONGLONG = windows.h에 있는 64비트형 정수)
	double t_elapse_ms;										// t_diff_pc를 ms단위로 환산함 *( * 1000 )
	
	// 시간 계산에 필요한 변수 2 (time.h 헤더파일을 이용) 
	time_t t_before, t_after;
	double t_diff;											// t_after - t_before 
	
	Rarray = (double*)calloc(50000, sizeof(double));		// 먼저 Rarray를 동적할당 해준다 (이 배열은 반복문 도중에 사용하기 때문에 여기서 할당)
	QueryPerformanceFrequency(&freq);					// CPU 클럭에 따른 1초당 진행되는 틱수, (거의 고정값이라서 1번만 하면 끝)
	for (int exponent = 1000; exponent <= 5000; exponent += 1000)
	{
		time(&t_before);								//시간재기(함수시작전) 1 (time.h)
		QueryPerformanceCounter(&t_1);					//시간재기(함수시작전) 2 (windows.h)
		resultF = PowerFor(base, exponent);				//제곱최종결과 가져오기 (반복문)'
		time(&t_after);									//시간재기(함수끝) 1
		QueryPerformanceCounter(&t_2);					//시간재기(함수끝) 2

		// 시간차 계산
		t_diff = difftime(t_before, t_after);			// time.h
		t_diff_pc = t_2.QuadPart - t_1.QuadPart;		// windows.h (LARGE_INTEGER 자료형은 사용시 .QuadPart를 붙여야함)
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * Milli; //시간차 계산(주파수의 역수) 2

		// 출력
		printf("Pow(%.3lf, %d) by iterative = %40.5lf / took time : (%3d)sec, (%5.2lf)ms\n",
			base, exponent, resultF, (int)t_diff, t_elapse_ms); 


		//밑은 함수만 재귀함수인 차이빼고는 동일
		time(&t_before); QueryPerformanceCounter(&t_1);
		resultR = PowerRecursive(base, exponent, Rarray);
		time(&t_after);	QueryPerformanceCounter(&t_2);

		// 시간차 계산
		t_diff = difftime(t_before, t_after);
		t_diff_pc = t_2.QuadPart - t_1.QuadPart;
		t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * Milli;
		
		// 출력
		printf("Pow(%.3lf, %d) by Recursive = %40.5lf / took time : (%3d)sec, (%5.2lf)ms\n",
			base, exponent, resultR, (int)t_diff, t_elapse_ms);
	}
	free(Rarray);										// 사용한 동적할당된 배열은 마지막에 할당해제를 한다.
	return 0;
}

double PowerFor(double base, int exponent) // 반복문을 이용한 거듭제곱 함수
{
	double result = 1; //거듭제곱 결과 초기값으로 1을 설정.
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	} //계속 base를 곱해주면서 반복한다.
	return result;  //반환
}

double PowerRecursive(double base, int exponent, double* array) // 재귀함수를 이용한 거듭제곱 함수
{
	if (exponent == 0)								// 재귀함수 종료조건
		return 1;

	if (array[exponent] >= 1)						// 배열에 값이 입력되있으면
		return array[exponent];						// 따로 계산할 필요없이 값을 반환한다.

	else
	{
		array[exponent] = base * PowerRecursive(base, exponent - 1, array);
		return array[exponent];						// 재곱할 만큼 했으면 값을 반환
	}
}