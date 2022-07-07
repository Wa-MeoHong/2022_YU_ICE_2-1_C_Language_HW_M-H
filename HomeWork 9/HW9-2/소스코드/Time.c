#include "Time.h"

Time InputTime()								// 시간 입력 함수
{
	Time input;									// 입력값 담을 변수

	// 입력
	printf("Input hour, minute, second : ");
	scanf("%d %d %d", &input.hour, &input.min, &input.sec); 
	
	// 입력받은 시간을 초로 환산
	input.Allsecs = (input.hour) * 60 * 60 + (input.min) * 60 + input.sec;
	
	return input;								// 값 반환
}

void printTime(Time* t)							// 시간 출력 함수 (기본형), 출력 형식 : "(시:분:초)"
{
	printf("(%02d:%02d:%02d)", t->hour, t->min, t->sec);
}

void printTimes(Time* times, int SIZE)			// 시간 배열 출력 함수
{
	for (int i = 0; i < SIZE; i++)				// 사이즈 갯수만큼
	{
		//출력 형식 : "time[i] = (시:분:초)"
		printf("times[%d] = ", i); printTime(&times[i]); 
		printf("\n");
	}
	printf("\n"); 
}

void incrementTime(Time* t, int incr_sec)				//시간 증가했을 때 시간 계산
{
	t->Allsecs += incr_sec;								// 모든초에서 증가시킴

	t->sec = t->Allsecs % 60;							// 모든 초에서 60을 나누었을 때 나머지 = 초
	t->min = (t->Allsecs / 60) % 60;					// 모든 초에서 60을 나눈 후, 그 수에서 60을 나누었을 때 나머지 = 분
	t->hour = (t->Allsecs / 3600);						// 모든 초에서 60 * 60을 나누었을 때 나온 수 = 시

	// 만약 24시를 넘겼으면 시간을 24를 빼주어 0시부터 시작하게함
	if (t->hour >= 24) 
	{
		t->hour -= 24;
	}

	// 구조체 자료형의 데이터를 포인터로 가져와서 따로 반환할 것이 없다.
}

int compareTime(const Time* ptr1, const Time* ptr2)			// 시간차 비교 함수
{
	return (ptr1->Allsecs - ptr2->Allsecs);					// 차를 반환 (우리가 비교할 것은 양수, 0, 음수만 필요로 한다)
}

void SSTime(Time* times, int SIZE)							// 선택정렬 함수
{
	Time temp;												// 최대값(교체할 값)
	int min_index = 0;										// 최소값 인덱스 번호
	int sort_index = 0;										// 정렬할 때의 기준 인덱스 번호(이 인덱스 이전을 제외한 오른쪽것들에서 최대값 찾음) 

	for (int i = 0; i < SIZE; i++)
		times[i].Allsecs = (times[i].hour) * 60 * 60 + (times[i].min) * 60 + times[i].sec;
		// 배열의 요소들의 합계초를 구해줌 (초환산 자료는 배열안에 없기때문에 생성, 시간 크기비교를 위해서)

	// 선택정렬
	while (1)												
	{
		if (sort_index == SIZE)								// 만약 정렬 기준 인덱스 값이 배열의 범위를 벗어나면 종료
			break;
		temp = times[sort_index];							// 최소값(교체값) 초기값 설정
		min_index = sort_index;								// 최소값 인덱스 초기값 설정

		for (int j = sort_index; j < SIZE; j++)
		{
			if (compareTime(&temp, &times[j]) > 0)			// 만약 temp가 더 크다면
			{
				temp = times[j];							// 최소값(바꿀값)갱신
				min_index = j;								// 인덱스 번호 갱신
			}
		}

		// swap
		times[min_index] = times[sort_index];
		times[sort_index] = temp;
		sort_index++;
	}
}