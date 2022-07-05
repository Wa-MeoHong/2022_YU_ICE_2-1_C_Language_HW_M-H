/*
  파일명 : "HW3-3_21912193_신대홍	"

  프로그램의 목적 및 기본 기능:
	- 년도, 월을 입력받아 달력을 생성하는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 13일)
  최종 Update : Version 1.1.0, 2022년 3월 14일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/13		v1.0.0		  최초작성
   신대홍		 2022/03/14		v1.1.0		  윤년 계산 수정
===========================================================================================================
*/

#pragma warning(disable: 4996)								// scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MONTHS 12											// 월은 12달
#define WEEKDAYS 7											// 일주일은 7일

// enum 열거형 자료형을 사용해 숫자에 이름을 붙여 사용
enum weekday { SUN, MON, TUE, WEN, TUR, FRI, SAT };			// 일요일을 0부터 시작해서 토요일을 6으로
enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };	// 월을 사용자지정변수로 셜정 ( 1 ~ 12 )

int months[MONTHS + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 달마다 있는 날수(윤년제외), 전역변수로 설정

int LeapYears(int year);									//지나간 윤년갯수 구하기
int Days(int year, int month);								//서기 1년 1월 1일 (월)부터 며칠째인지 계산하기
void PrintCalender(int year, int month, int days);			//달력 출력

int main(void)
{
	int year = 0, month = 0, days = 0;								// 년도, 월, 며칠째인지 계산하는 days
	int leap_years = 0;												// 지나간 윤년갯수

	while (1)
	{
		printf("연도와 날짜를 입력하세요. (연도 = 0 입력시 나가기): "); // 연도에 0입력시 반복문 탈출
		scanf("%d %d", &year, &month);
		if (year == 0)
			break;

		days = Days(year, month);									// 지나간 날 구하기
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			months[FEB] = 29;										// 입력한 해가 윤년이면 2월을 29일로 변경

		PrintCalender(year, month, days);							// 달력 출력

		printf(" 출력 완료. 아무 키를 입력하여 처음으로 돌아가시오.");
		_getch();
		system("cls");
	}
	return 0;
}

int LeapYears(int year)											// 윤년계산
{
	int leap_years = 0;
	for (int k = 1; k <= year; k++)
		if (((k % 4 == 0) && (k % 100 != 0)) || (k % 400 == 0))
			leap_years += 1;									//윤년공식에 따라 계산
	return leap_years;
}

int Days(int year, int month)									// 지나간 날 계산
{
	int days = 1;												// 1일 부터 시작함
	days += (year - 1) * 365;									// 윤년은 아직 고려하지 않고, 지나간 년수만큼 추가
	for (int i = 1; i < month; i++)
		days += months[i];										// 지나간 월에 따라 날짜를 계산
	days += LeapYears(year);									// 지나간 윤년의 개수만큼 날을 더한다.
	if (month < 3 && year == 4)			//서기 4년, 아직 윤달이 지나지 않았으므로 하루를 제외한다.
		days -= 1;

	return days;												// 날수 반환
}

void PrintCalender(int year, int month, int days)				// 달력 출력
{
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>%4d년 %2d월<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n", year, month);
	printf("==================================================================\n");
	printf("	일	월	화	수	목	금	토\n");
	printf("==================================================================\n");

	for (int wd = 0; wd < (days % 7); wd++)						// 시작날까지 tap키로 건너뛰기
		printf("	");
	
	for (int d = 1; d <= months[month]; d++)					// 1일 부터 시작하여 그 달의 날수 까지 반복
	{
		if (days % 7 == 0) 
			printf("\n   ");									// 만약 일요일이면 한줄 내리기
		printf("	%2d", d);									// 아니면 정상 출력
		days++;													// days를 더해줘서 날수를 맞춘다.
	}
	printf("\n==================================================================\n");
	months[FEB] = 28;											//모든 계산이 끝난후, 2월을 28일로 다시 변경
}