/*
  파일명 : "HW4-1_21912193_신대홍"

  프로그램의 목적 및 기본 기능:
	- 기존 Rand()함수에서 낼 수 있는 난수값보다 더 많은 값들을 랜덤으로 발생시킨후
	그걸 동적메모리할당을 받은 배열에 받아 값을 출력시키는 프로그램

  프로그램 작성자 : 신대홍(2022년 3월 24일)
  최종 Update : Version 1.1.0, 2022년 3월 25일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/03/24		v1.0.0		  최초작성
   신대홍		 2022/03/25		v1.1.0		  동적배열 flag반환 명령 추가
===========================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>										// rand()함수를 사용하기 위한 헤더파일
#include <time.h>										// time()을 사용하기 위한 헤더파일

#define RANDOMIZE() srand((unsigned int)time(NULL))		// 시간에 따른 시드를 define으로 매크로를 생성
#define LINE_SIZE 10									// 기본 표시 줄 수.

void BigRandArray(int* array, int SIZE);				// 원래의 Rand() (0~32767)을 넘어서는 랜덤수 만드는 함수
void PrintArray(int* array, int SIZE, int line_size);	// 최종 출력함수

int main(void)
{
	int* array = NULL;								// 포인터(배열)을 변수 생성 후 초기화

	RANDOMIZE();									// 시드 생성
	for (int size = 200000; size <= 1000000; size += 200000) // 20만개의 부터 시작해서 +20만개씩 늘려감
	{
		array = (int*)calloc(size, sizeof(int));	// 동적 메모리 할당받음(이제 배열주소와 공간 받음), 실패시 바로 종료
		if (array == NULL)
		{
			printf("Error in Dynamic memory allocation for integer array of size (%d)\n\n ", size);
			exit(-1);								// 종료
		}

		BigRandArray(array, size);					// 난수발생후 array배열에 저장
		PrintArray(array, size, LINE_SIZE);			// 최종 출력함수
	}
	free(array);									//동적 메모리 반환 (array는 동적으로 할당받았으므로 꼭 해제를 해야됨)
	return 0;
}

void BigRandArray(int* array, int SIZE)
// 중복없는 수를 랜덤으로 생성하는 함수
{
	char* flag = NULL;							// 중복되는 난수 값을 확인하기 위해 만들어둠
	int count = 0;								// while 초기식 변수
	unsigned int bigRand = 0;					// 임시저장 공간 

	flag = (char*)calloc(SIZE, sizeof(char));	// 발생시킬 개수만큼 동적메모리 할당 (실패시 바로 종료)
	if (flag == NULL)
	{	
		printf("Error in Dynamic memory allocation for character array of size (%d)\n ", SIZE);
		exit(-1);
	} 

	while (count < SIZE)						//발생시킬 개수만큼
	{
		bigRand = (((long)rand() << 15) | (long)rand()) % SIZE;
		//SIZE보다 작아야하는 이유 : 그래야 중복값을 찾을 배열에 값을 맞춰 넣을 수 있음..

		if (flag[bigRand] == 1)				//만약 bigRand가 이미 나온 난수라면 
		{
			continue;						// 다시실행 ( 난수 다시 생성 )
		} 
		else
		{
			flag[bigRand] = 1;				// 아니면 체크해주고
			array[count++] = bigRand;		// array에 값을 대입해준후, count를 ++한다.
		}
	}
	free(flag);								//다끝나면 동적메모리 반환해줌 ( 중복 수를 체크하기 위한 임시 배열)
}

void PrintArray(int* array, int SIZE, int line_size)
// 출력
{
	printf("Testing Generation of dynamic array of random numbers (size : %d)\n", SIZE);
	for (int i = 0; i < 3; i++)							//처음 30개 난수
	{
		for (int j = 0; j < line_size; j++, array++)	// 10개 출력
		{
			printf("%8d", *(array));
		}
		printf("\n");
	}
	printf(" . . . . . .\n");

	for (int i = 0; i < 3; i++)							//마지막 30개 난수 출력
	{
		for (int j = 0; j < line_size; j++, array++)
		{
			printf("%8d", *(array + SIZE - 61));		//위에 30을 먼저 +했기때문에 SIZE를 더한후 마지막 30개를 출력하기 위해
			//61개를 빼준다.
		}
		printf("\n");
	}
	printf("\n");
}

// 사실 그냥 동적할당만 해놓고, 숫자를 1부터 SIZE까지 정수를 배열에 대입하고 섞어주는 함수 쓰면 됨.
// suffle하는 방법은 배열 swap하는 함수를 응용하는 것.