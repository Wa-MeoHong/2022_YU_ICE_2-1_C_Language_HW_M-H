#include "Big_Array.h"

int main(void)
{
	FILE* fout = NULL;							// 파일포인터 fout
	int* array = NULL;							// Bigarray생성할 배열 
	int SIZE = 0;								// 배열크기 SIZE

	if ((fout = fopen(OUT_DATA, "w")) == NULL)	// 쓰기모드로 파일 열기, 열지 못하면 그대로 종료
	{
		printf("Error in creation of %s !! \n", OUT_DATA);
		exit(-1);
	}

	printf("Input size of big array : ");				// 사이즈 입력 
	scanf("%d", &SIZE);
	array = (int*)calloc(SIZE, sizeof(int));			// 동적할당

	genBigRandArray(array, SIZE);						// 난수 발생 후 배열에 저장
	printBigarraySample(array, SIZE, LINE_SIZE, NUM_OF_LINES);			// 출력 함수
	fprintBigarraySample(fout, array, SIZE, LINE_SIZE, NUM_OF_LINES);	// 파일에 출력하는 함수
	free(array);								// 동적할당한 array 해제
}