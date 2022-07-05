/*
  파일명 : "HW5-2_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 전처리기, 헤더파일을 만들어서 main함수에 끌어서 쓰고, 파일을 작성해서 파일에 입력하는 프로그램

  프로그램 작성자 : 신대홍(2022년 4월 1일)
  최종 Update : Version 1.1.0, 2022년 7월 6일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/04/01		v1.0.0		  최초작성
   신대홍		 2022/07/06		v1.1.0		  전반적으로 코드 최적화
===========================================================================================================
*/

#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H
#pragma warning(disable: 4996)								// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>											// 시간 난수 생성 시드를 위한 헤더파일
#include <windows.h>

#define RANDOMIZE() srand((unsigned int)time(NULL))			// 시간 난수 매크로
#define LINE_SIZE 10										// 한줄당 출력하는 숫자의 개수
#define NUM_OF_LINES 3										// 많은 수를 출력할 때, 처음 X줄, 마지막 X줄만 출력
#define OUT_DATA "output.txt"								// 출력용 파일 이름 output.txt

void genBigRandArray(int* array, int SIZE);						// 난수 생성 함수
void suffleBigArray(int* array, int SIZE);						// 생성된 난수 배열을 섞어주는 함수
void printBigarraySample(int* array, int SIZE, int line_size, int num_sample_lines);	// 생성된 난수 배열을 출력하는 함수
void fprintBigarraySample(FILE* fout, int* array, int SIZE, int line_size, int num_sample_lines);	// 파일 출력함수

#endif // !BIG_ARRAY_H
