#include "Big_Array.h"

void genBigRandArray(int* array, int SIZE)	 				// 난수 생성 함수
{
	char* flag = NULL;									// 중복되는 난수 값을 확인하기 위해 만들어둠
	int count = 0;										// while 초기식
	unsigned int bigRand = 0;							// 임시저장 공간

	flag = (char*)calloc(SIZE, sizeof(char));				// 발생시킬 개수만큼 동적메모리 할당, 실패시 그대로 종료
	if (flag == NULL)
	{
		printf("Error in Dynamic memory allocation for character array of size (%d)\n ", SIZE);
		exit(-1);
	} 

	while (count < SIZE)								// 발생시킬 개수만큼
	{
		bigRand = (((unsigned int)rand() << 15) | rand()) % SIZE; //SIZE보다 작아야하는 이유 : 그래야 중복값을 찾을 배열에 값을 맞춰 넣을 수 있음..

		if (flag[bigRand] == 1)							//만약 bigRand가 이미 나온 난수라면 다시 생성
		{
			continue;
		}
		else
		{
			flag[bigRand] = 1;							// 아니면 체크해주고
			array[count++] = bigRand;					// array에 값을 대입해준후, count를 ++한다.
		}
	}
	free(flag);											// 다끝나면 동적메모리 반환해줌 ( 중복 수를 체크하기 위한 동적 배열 ) 
	suffleBigArray(array, SIZE);						// 섞기
}

void suffleBigArray(int* array, int SIZE)				// 난수 순서 변경(셔플)
{
	int i1, i2, d, k = 0;								// 순서를 변경할 인덱스 i1, i2, 임시변수 d, while 초기식 k

	while (k < SIZE)									// k = SIZE가 되기 까지
	{
		i1 = (((unsigned int)rand() << 15) | rand()) % SIZE; // 순서변경할 1번 난수 
		i2 = (((unsigned int)rand() << 15) | rand()) % SIZE; // 2번 난수

		// 스와핑 ( 위치 바꾸기 )
		d = array[i1];									// 먼저 임시저장용 변수 d에 인덱스 i1번에 담긴 수를 저장
		array[i1] = array[i2];							// i2번에 담긴 수를 i1번에 저장
		array[i2] = d;									// i1의 내용을 옮겨담은 d를 i2로 옮김
		k++;											// k증가
	}
}


void printBigarraySample(int* array, int SIZE, int line_size, int num_sample_lines) //큰 배열 출력 함수
{
	int count = 0;
	printf("Generate Big array(SIZE of % d) : \n", SIZE);
	for (int i = 0; i < num_sample_lines; i++)				 //처음 30개 출력
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count == SIZE)
				break;
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}

	printf("\n . . . . . .\n");
	count = SIZE - (line_size * num_sample_lines);			// count(배열인덱스 번호)를 뒤에서 30번째 번호로 바꾸기

	for (int i = 0; i < num_sample_lines; i++)				// 마지막 30개 출력
	{
		for (int j = 0; j < line_size; j++)
		{
			printf("%8d", array[count]);
			count++;
		}
		printf("\n");
	}
	printf("\n");
}

void fprintBigarraySample(FILE* fout, int* array, int SIZE, int line_size, int num_sample_lines) // 파일용 큰함수 출력 함수
{ 
	int count = 0;

	fprintf(fout, "Generate Big array (SIZE of %d) : \n", SIZE);
	for (int i = 0; i < num_sample_lines; i++)				// 파일에다가 입력 (맨처음 배열원소 30개 출력)
	{
		for (int j = 0; j < line_size; j++)
		{
			if (count == SIZE)
				break;
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}

	fprintf(fout, "\n . . . . . .\n");
	count = SIZE - (line_size * num_sample_lines);			// count(배열인덱스 번호)를 뒤에서 30번째 번호로 바꾸기

	for (int i = 0; i < num_sample_lines; i++)				// 파일에다가 입력 (맨뒤의 배열원소 30개 출력)
	{
		for (int j = 0; j < line_size; j++)
		{
			fprintf(fout, "%8d", array[count]);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "\n");

}
