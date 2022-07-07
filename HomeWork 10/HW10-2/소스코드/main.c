#include "hexadecimal.h" 

int main(void)
{
	char* hexStr;							// 숫자로 변환할 문자열 입력
	char* hexConvertStr;					// 변환된 숫자를 다시 문자열로 변환하여 담아줄 문자열
	unsigned int value_int;					// 변환한 숫자를 담는 변수
	while (1)
	{
		hexStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));			// 동적할당
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN + 1, sizeof(char));	// 동적할당

		// 변환할 16진수 문자열 입력
		printf("input hexadecimal number : ");								
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)									// 만약 '.'을 입력하면 종료
			break;

		value_int = atox(hexStr);										// 숫자변환
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int); // 출력 1
		xtoa(value_int, hexConvertStr);									// 변환한 숫자를 다시 문자열로 변환
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re-converted hexadecimal string(%s)\n", \
			hexStr, value_int, value_int, hexConvertStr);				//출력 2

		// 동적할당 해제
		free(hexStr);
		free(hexConvertStr);
	}
	return 0;
}
