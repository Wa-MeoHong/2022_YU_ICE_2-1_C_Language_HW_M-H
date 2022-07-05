/*
	파일명 : "Big_Array_Sort.c"
	프로그램의 목적 및 기본 기능:
		- Big_Array_Sort.c 코드파일 
*/

#include "Big_Array_Sort.h"

//------------------------------선택 정렬----------------------------------

void selectionSort(int* array, int SIZE, int left, int right)		// 선택정렬 함수
{
	int min_NUM;													// 작은값 찾기
	int Index_min_NUM;												// 작은값의 인덱스 넘버

	for (int round = left; round < right - 1; round++)
	{
		Index_min_NUM = round;										// 최소값의 인덱스 초기값(round) 설정
		min_NUM = array[round];										// 최소값 초기값 설정
		for (int i = round + 1; i < right; i++)
		{
			if (array[i] < min_NUM)									// 자기보다 작은 값을 찾았으면 갱신
			{
				Index_min_NUM = i;
				min_NUM = array[i];
			}
		}
		if (Index_min_NUM != round)									//만약 가장 작은 값이 자기자신(기준값)이 아니라면
		{
			array[Index_min_NUM] = array[round];					//찾았던 인덱스 주소안의 값을 기준값과 변경
			array[round] = min_NUM;									//가장작은값은 아까 저장했던 그 작은값.
		}
		// 배열 끝까지 갈때 까지 반복
	}
}

//------------------------------병합 정렬----------------------------------

void mergeSort(int* array, int SIZE) // 병합정렬 초기함수
{
	int* temp_array = (int*)calloc(SIZE, sizeof(int));
	//단순히 이 temp_array(임시저장 배열) 생성만을 위해 이렇게 만든함수..
	if (temp_array == NULL)
	{
		printf("Error in creation of temp_array (size = %d)!\n", SIZE);
		exit(-1);
	}
	_mergeSort(array, temp_array, 0, SIZE - 1); // 시작
	free(temp_array);
}

void _mergeSort(int* array, int* temp_array, int left, int right)
// 병합정렬 메인함수
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_mergeSort(array, temp_array, left, mid);						// 계속 반을 쪼개서 왼쪽끝까지 간다.
	_mergeSort(array, temp_array, mid + 1, right);					// 반을 쪼개서 오른쪽을 간다.

	for (int i = left; i <= mid; i++)								// 왼쪽은 순서대로 임시 배열에 넣어줌
		temp_array[i] = array[i];
	for (int j = 1; j <= right - mid; j++)							// 오른쪽은 역순(중요)으로 임시배열에 넣어줌
		temp_array[right - j + 1] = array[j + mid];
	// [1, 5, 2, 9, ----- ] → [1, 5, 9, 2, -----]

	for (int i = left, j = right, k = left; k <= right; k++)		//중간 기준으로
	{
		if (temp_array[i] < temp_array[j])
			array[k] = temp_array[i++];
		else
			array[k] = temp_array[j--];
	}
}

//------------------------------퀵 정렬--------------------------------

void _QUICKSORT(int* array, int SIZE) //퀵 정렬 최초 함수
{
	quickSort(array, SIZE, 0, SIZE - 1);
	//처음 할때는 left = 위치값이 0, right = size-1
}

void quickSort(int* array, int SIZE, int left, int right) 
// 퀵정렬,본함수
{
	int P_I, newPI;
	int P_V;												//pivot value, 그 위치에 있는 값
	int temp;												// 값 자리바꾸기 하기 위한 임시저장 변수

	if (left >= right)					// 만약 left가 right보다 크거나 같다면 newPI반환 중지, 거의 left가 1혹은 0일때이다..
		return;

	else if (left < right)
	{
		P_I = (left + right) / 2;							// 중간값, 만약 홀수인경우 내림값으로 나누기위치값 산출
	}

	P_V = array[P_I];
	array[P_I] = array[right];
	array[right] = P_V;
	// 맨 처음 P_I에 있던 값을 맨 오른쪽(혹은 P_I-1위치에 있는 값)과 바꾼다

	newPI = left;						// 이제 새로운 피벗위치를 설정해주는데 초기값은 맨 왼쪽(혹은 P_I + 1위치)으로 설정
	for (int i = left; i <= right - 1; i++)
	// 맨뒤로 가게된 P_V는 빼고 나머지 배열들을 범위로 잡는다.
	{
		if (array[i] <= P_V)								//만약 맨뒤로 간 P_V보다 값이 작다면
		{
			temp = array[i];
			array[i] = array[newPI];
			array[newPI] = temp;							// 현재(i)위치에 있는 값을 newPI에 있는 값과와 바꿔준다.
			newPI += 1;
		}
	}
	// 결론적으로 처음 P_V값을 기준으로 왼쪽은 P_V보다 작은 값들의 배열, 오른쪽은 P_V보다 큰 값들의 배열이 형성되었다.
	P_V = array[right];
	array[right] = array[newPI];
	array[newPI] = P_V;

	// 이렇게 왼쪽, 오른쪽 순서대로 작은덩이 → 큰덩이
	if (left < (newPI - 1))									// 이제 newPI기준으로 왼쪽부분
	{
		quickSort(array, SIZE, left, newPI - 1);
		// 다시 newPI를 산출하면서 크기정렬을 쭉해준다.
	}
	if ((newPI + 1) < right)								// 다음, 왼쪽이 quickSort를 진행후, newPI기준 오른쪽 부분
	{
		quickSort(array, SIZE, newPI + 1, right);
		// 오른쪽으로 newPI산출및 크기순으로 정렬해준다.
	}
}

// 병합정렬, 퀵정렬 모두 재귀함수의 형식을 띠고 있기에 재귀함수의 동작방식을 이해하고 있으면 이해가 빨리 될 것이다. 
// 안그러면 이해가 좀 안될것
