/*
	파일명 : "main.c" 
	프로그램의 목적 및 기본 기능:
		- main.c 코드파일
*/

#include "Big_Array.h"
#include "Big_Array_Sort.h"
#include <conio.h>

void Compare_Sorting_Algorithms_SmallIntArray();				// 적은 수의 난수 배열에 관한 메뉴
void Compare_Sorting_Algorithms_BigIntArray();					// 큰 수의 난수 배열에 관한 메뉴

int main(void)
{
	int menu;

	while (1)
	{
		printf("\nTest Array Algorithms   \n");
		printf("	1: Performance Comparison of Selection Sort and Quick Sort for \
Small Integer Array\n");
		printf("	2: Performance Comparison of Selection Sort and Quick Sort for \
BIG Integer Array\n");
		printf("Input menu (0 is exit): ");
		scanf("%d", &menu);										// 메뉴 입력

		if (menu == 0)											// 0입력시 while 종료
			break;
		switch (menu)											// 입력에 따라 실행 함수 달라진다.
		{
		case 1:
			Compare_Sorting_Algorithms_SmallIntArray();
			break;
		case 2:
			Compare_Sorting_Algorithms_BigIntArray();
			break;
		default:
			printf("\n\tWrong input! Please input again!");
			_getch();
			system("cls");
			continue;
		}
		printf("\n\tSorting is Complete! Press Any Key!");
		_getch();
		system("cls");
	}
	printf("\n\t\tClose Progarm..\n");
	return 0;
}

void Compare_Sorting_Algorithms_SmallIntArray() //적은 수의 배열 정렬 측정 
{
	int* array;
	int size, base = 0;
	LARGE_INTEGER freq, t_1, t_2;
	double t_diff;								//시간 차 계산

	double t_Selection, t_Merge, t_Quick;

	QueryPerformanceFrequency(&freq);
	// CPU의 클럭수를 측정, 클럭수는 거의 변하는 값이 아니므로 한번만 측정

	printf("\nCompare the performance of sorting algorithms for small array\n");
	printf("====================================================================\n");
	printf(" Array size	QuickSort[μs]	MergeSort[μs]	SelectionSort[μs]\n");
	printf("--------------------------------------------------------------------\n");

	for (size = 10; size <= 100; size += 10)
	{
		array = (int*)calloc(size, sizeof(int));
		if (array == NULL)
		{
			printf("Error in creation of array (size = %d)!\n", size);
			exit(1);
		}
		genBigRandArray(array, size, base);
		// 최초 난수 생성

		QueryPerformanceCounter(&t_1);						// 시간재기(함수시작전)
		_QUICKSORT(array, size);							// 퀵정렬
		QueryPerformanceCounter(&t_2);						// 시간재기(함수끝)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Quick = ((double)t_diff / (double)freq.QuadPart) * Micro; //μs단위 변환
		SuffleBigArray(array, size);
		// 다시 섞어준다.

		QueryPerformanceCounter(&t_1);						// 시간재기(함수시작전)
		mergeSort(array, size);								// 병합정렬
		QueryPerformanceCounter(&t_2);						// 시간재기(함수끝)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Merge = ((double)t_diff / (double)freq.QuadPart) * Micro; //μs단위 변환
		SuffleBigArray(array, size);
		// 다시 섞어준다.

		QueryPerformanceCounter(&t_1);						// 시간재기(함수시작전)
		selectionSort(array, size, 0, size - 1);			// 선택정렬
		QueryPerformanceCounter(&t_2);						// 시간재기(함수끝)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Selection = ((double)t_diff / (double)freq.QuadPart) * Micro; //μs단위 변환
		printf("%10d\t%11.2lf\t%11.2lf\t%14.2lf\n", size, t_Quick, t_Merge, t_Selection);

		free(array);
	}
}

void Compare_Sorting_Algorithms_BigIntArray()				// 많은 난수 정렬 시간 측정 함수
{
	int* array;
	int size, base = 0;
	int pow_num = 0;
	LARGE_INTEGER freq, t_1, t_2;
	double t_diff;											// 시간 차 계산

	double t_Selection, t_Merge, t_Quick;

	QueryPerformanceFrequency(&freq);
	// CPU의 클럭수를 측정, 클럭수는 거의 변하는 값이 아니므로 한번만 측정

	printf("\nCompare the performance of sorting algorithms for small array\n");
	printf("====================================================================\n");
	printf(" Array size	QuickSort[ms]	MergeSort[ms]	SelectionSort[ms]\n");
	printf("--------------------------------------------------------------------\n");

	while (1)
	{
		size = BIG_SIZE * (int)pow(2, pow_num);

		if (size >= StopSort)
			break;
		array = (int*)calloc(size, sizeof(int));
		if (array == NULL)
		{
			printf("Error in creation of array (size = %d)!\n", size);
			exit(1);
		}
		genBigRandArray(array, size, base);
		// 최초 난수 생성

		QueryPerformanceCounter(&t_1);						// 시간재기(함수시작전)
		_QUICKSORT(array, size);							// 퀵정렬
		QueryPerformanceCounter(&t_2);						// 시간재기(함수끝)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Quick = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms단위 변환
		SuffleBigArray(array, size);
		// 다시 섞어준다.

		QueryPerformanceCounter(&t_1);						// 시간재기(함수시작전)
		mergeSort(array, size);								// 병합정렬
		QueryPerformanceCounter(&t_2);						// 시간재기(함수끝)
		t_diff = t_2.QuadPart - t_1.QuadPart;
		t_Merge = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms단위 변환
		SuffleBigArray(array, size);
		// 다시 섞어준다.

		if (size < SELECTION_SORT_THRESHOLD)				// 5만개 이상일때는 선택정렬을 하지 않도록 if-else 구성
		{
			QueryPerformanceCounter(&t_1);					// 시간재기(함수시작전)
			selectionSort(array, size, 0, size - 1);		// 선택정렬
			QueryPerformanceCounter(&t_2);					// 시간재기(함수끝)
			t_diff = t_2.QuadPart - t_1.QuadPart;
			t_Selection = ((double)t_diff / (double)freq.QuadPart) * Milli; // ms단위 변환
			printf("%10d\t%11.2lf\t%11.2lf\t%14.2lf\n", size, t_Quick, t_Merge, t_Selection);
		}
		else
			printf("%10d\t%11.2lf\t%11.2lf\t\t-\n", size, t_Quick, t_Merge);
		pow_num += 1;
		free(array);
	}
	printf("====================================================================\n");
}
