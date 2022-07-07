/*
  파일명 : "HW10-1_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 영단어가 든 텍스트파일을 읽고, 단어의 길이를 알아내 형식에 맞게 출력후, 단어를 오름차순으로 정렬 후, 단어 출력
  
  프로그램 작성자 : 신대홍(2022년 5월 14일)
  최종 Update : Version 1.0.0, 2022년 5월 14일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/05/14		v1.0.0		  최초작성
===========================================================================================================
*/

#ifndef WORD_H
#define WORD_H
#pragma warning(disable: 4996)						// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM_WORDS 10								// 단어의 개수
#define WORD_LENS 15								// 최대 단어의 길이

void FprintWords(FILE* fout, char words[][WORD_LENS], int* word_len, int num_words); // 파일출력함수
void SelectionSortWords(char words[][WORD_LENS], int num_words); // 단어 선택 정렬 함수

#endif // !WORD_H 
