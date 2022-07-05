/*
  파일명 : "HW3-1_21912193_신대홍	"
  프로그램의 목적 및 기본 기능:
	- ASCII code를 입력받고, 그 ASCII code가 문자인지, 숫자인지, 자음, 모음, 기호인지 판별하는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 20일)
  최종 Update : Version 1.1.0, 2022년 3월 21일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/20		v1.0.0		  최초작성
   신대홍		 2022/03/21		v1.5.0		  Enter입력시 다시 입력하도록 추가

===========================================================================================================
*/

#include <stdio.h>
#include <conio.h>										// getch()를 입력하기 위한 라이브러리

#define CR 0x0D											// CR = \r(첫줄로 돌아가기)
#define LF 0x0A											// LF = \n(줄바꿈)
#define ESC 0x1B										// ESC

void judge(char cht);									// 영문자 자음, 모음 판단 함수

int main(void)
{
	char cht = 0;
	while (1)
	{
		printf("\nInput a character : ");
		cht = _getch();									// 문자 입력, 누른키 하나만 인식함, 버퍼가 없음

		if (cht == CR || cht == LF)						// CR = \r(첫줄로 돌아가기), LF = \n(줄바꿈)
			continue;									// 다시 입력
		else
		{
			if (cht == ESC)								// ESC 입력시 끝
			{
				printf("close...\n");
				break;
			}
			else
			{
				if (cht >= 'A' && cht <= 'Z')			//대문자 알파벳
				{
					printf("%c\n => alphabet upper-case, ", cht);
					judge(cht);
				}
				else if (cht >= 'a' && cht <= 'z')		//소문자 알파벳
				{
					printf("%c\n => alphabet lower-case, ", cht);
					judge(cht);
				}
				else if (cht >= 0x30 && cht <= 0x39)	// 숫자
					printf("%c\n => decimal number.\n", cht);
				else									//모두아니면 기호
					printf("%c\n => symbol (not decimal number, not alphabet)\n", cht); 
			}
		}
	}
	return 0;
}

void judge(char cht)									// 모음형인지 아닌지 판단함
{
	switch (cht)
	{													// 대문자, 소문자 a, e, i, o, u (모음)
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("vowel\n"); break;						// 모음 출력

	default:
		printf("consonanat\n"); break; 					// 자음 출력
	}
}