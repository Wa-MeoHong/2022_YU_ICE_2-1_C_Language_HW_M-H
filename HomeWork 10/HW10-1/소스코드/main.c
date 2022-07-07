#include "word.h"

#define INPUT "words_input.txt"						// 입력 파일 
#define OUTPUT "words_output.txt"					// 출력 파일

int main(void)
{
	FILE* fin = NULL, * fout = NULL;			// 파일 포인터
	char words[NUM_WORDS][WORD_LENS] = { 0 };	// 배열이 작아서 따로 동적할당은 안함
	int word_len[NUM_WORDS];					// 단어의 길이를 담는 정수형 배열
	int count = 0;								// 단어의 개수를 셈

	if ((fin = fopen(INPUT, "r")) == NULL)
	{
		printf("Error! Not open words_input.txt File!!\n");
		exit(-1);
	} // 읽기 파일 오픈

	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("Error! Not open words_output.txt File!!\n");
		exit(-1);
	} // 출력 파일 오픈

	while (fscanf(fin, "%s", &words[count]) != EOF)		// 파일이 끝날때 까지, words배열에 저장
	{
		word_len[count] = strlen(words[count]);			// 읽은 단어의 길이를 구함 
		count++;										// 단어 개수 증가
	}

	FprintWords(fout, words, word_len, count);			// 파일출력
	SelectionSortWords(words, count);					// 단어 오름차순 정렬
	for (int i = 0; i < count; i++)						// 정렬한 단어 출력
	{
		if (i == count / 2)
			fprintf(fout, "\n");
		fprintf(fout, "%-10s", words[i]);
	}
	fprintf(fout, "\n");

	printf(" Please check words_output.txt File!\n");	// 확인용..
	fcloseall();										// 모든 작업이 끝난 후, 열려있는 파일을 모두 닫는다.

	return 0;

}