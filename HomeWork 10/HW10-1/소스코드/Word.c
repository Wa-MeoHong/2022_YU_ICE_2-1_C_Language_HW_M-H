#include "word.h" 

void FprintWords(FILE* fout, char words[][WORD_LENS], int* word_len, int num_words)		// 파일출력함수
{
	fprintf(fout, "Input words list : \n");

	for (int i = 0; i < num_words; i++)													// 반복문을 통해 출력
	{
		fprintf(fout, "(%2d)th-words : %-10s (word_length: %d)\n", i + 1, words[i], word_len[i]);
		// 1번째부터 10번째까지 출력, %-15s : 15자리만큼 왼쪽정렬해서 출력
	}
	fprintf(fout, "\n"); 
}

void SelectionSortWords(char words[][WORD_LENS], int num_words)				// 단어 선택 정렬 함수
{
	char temp[WORD_LENS] = { 0 };											// 단어를 바꾸기 위한 임시 문자열 배열
	int sort_IDX = 0, min_IDX = 0;											// 정렬 기준 인덱스, 최소값 인덱스

	while (1)
	{
		if (sort_IDX == num_words)											//만약 정렬 인덱스가 단어의 개수만큼 했다면 중지
			break;
		strcpy(temp, words[sort_IDX]);										// 정렬 기준 인덱스에 있는 단어를 복사
		min_IDX = sort_IDX;													// 최소값 인덱스 초기값 설정

		for (int i = sort_IDX + 1; i < num_words; i++)						// 정렬 기준인덱스 + 1부터 단어배열 끝까지
		{
			if (strcmp(temp, words[i]) == 1)								// 만약 단어가 temp보다 크다면( 아스키코드 기준 )
			{
				strcpy(temp, words[i]);										// 최소값 단어 갱신
				min_IDX = i;												// 최소값 인덱스 갱신
			}
		}

		//값 바꾸기
		strcpy(words[min_IDX], words[sort_IDX]);
		strcpy(words[sort_IDX], temp);
		sort_IDX++; // 정렬 인덱스 증가
	}
}
