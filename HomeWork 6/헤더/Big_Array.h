/*
  파일명 : "HW6_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 난수 생성한 다음, 각각의 정렬을 비교하는 함수

  프로그램 작성자 : 신대홍(2022년 4월 8일)
  최종 Update : Version 2.0.0, 2022년 7월 6일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/04/08		v1.0.0		  최초작성
   신대홍		 2022/04/08		v1.1.0		  큰 배열 시간측정 함수 수정
   신대홍		 2022/07/06		v2.0.0		  난수 생성과 정렬 헤더파일을 분리, 자잘한 오류 수정
===========================================================================================================
*/

#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H
#pragma warning(disable: 4996)								// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>											// 시간 난수 생성을 위한 헤더파일
#include <windows.h>
#include <math.h>

#define RANDOMIZE() srand((unsigned int)time(NULL))			// 시간 난수 매크로

#define Small_SIZE 100
//==================================
#define Milli 1000											// 밀리초 = 1000
#define Micro 1000000										// 마이크로초 = 1000000
#define BIG_SIZE 10000										// 많은 수 (10000)일때는
#define SMALL_SIZE 10										// 적은 수일때는
#define SELECTION_SORT_THRESHOLD 500000						// 50만개 이상이면 선택정렬을 하지 않게한다.
#define StopSort 50000000									// 난수 생성범위가 5천만을 넘기면 멈춘다.							

void genBigRandArray(int* array, int SIZE, int offset);		// 난수 생성 함수
void printBigarraySample(int* array, int SIZE, int items_per_size, int num_sample_lines); // 생성된 난수 배열을 출력하는 함수
void SuffleBigArray(int* array, int SIZE);					// 생성된 난수 배열을 섞어주는 함수

#endif // !BIG_ARRAY_H
