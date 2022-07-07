#include "hexadecimal.h"

unsigned int TransperHex(char hex)				// 16진수의 문자열을 정수로 변환하는 함수
{
	unsigned int a = 0;

	if (hex >= '0' && hex <= '9')				// 16진수 0~9까지의 문자열일때
		a = hex - '0';							// 아스키코드값을 뺀다.
	else if (hex >= 'A' && hex <= 'F')			// 16진수 A~F까지의 문자열일때
		a = hex - 'A' + 10;						// 아스키코드값을 빼고 10을 더함.

	return a;
}

unsigned int atox(char* hexStr)					// 문자열을 16진수 정수로 변환하는 함수
{
	unsigned int a = 0;							// 반환시켜줄 변수 a
	int bits = 4;								// 비트 시프팅을 위한 변수 bits (4비트씩 옮겨줌)

	bits = bits * (strlen(hexStr) - 1);
	// hexStr 맨왼쪽의 문자열이 최상위 니블(4bit)이므로, 처음에 옮길 bits를 초기화
	// 만약 4자리의 16진수가 들어왔다면 bit shift는 12번 진행해줘야 hexStr[0]이 알맞게 자리가 들어감

	for (int i = 0; i < strlen(hexStr); i++, bits -= 4) // 문자열 개수만큼 진행, 시프팅할 비트수는 4씩 줄임
	{
		unsigned int bitshift = 0;				// 먼저 문자열의 문자를 변환시켜 담아줄 임시 변수 생성
		bitshift = TransperHex(hexStr[i]);		// 문자 한개를 숫자로 변환
		bitshift = bitshift << bits;			// 자리에 맞게 비트 시프트
		a |= bitshift;							// a와 bitshigt를 OR연산
	}

	return a;									// 모두 끝난 후, a를 반환
}

void xtoa(unsigned int hxd, char* strBuf)		// 숫자를 16진수 문자열로 변환
{
	int bits = 4;								// 비트 시프팅을 위한 변수 bits (4비트씩 옮겨줌)
	int bit_len = 0;							// 숫자의 비트 길이를 구하는 변수
	unsigned int Trans;							// 원본 숫자를 비트마스킹해서 담아줄 변수 Trans
	char a = 0;									// 변환한 숫자를 담아줄 문자형 변수

	// 숫자의 비트길이 구하기
	bit_len = (int)(log2((double)hxd)) + 1;		// 먼저 숫자에 log2를 취한다, 비트수는 1까지 고려하므로 1을 더한다.

	bits = ((int)(bit_len / 4) * bits);			// 비트마스킹 초기값을 설정한다. 비트수를 4로 나눈 후, 정수값에 4를 곱한다.
	if ((bit_len % 4) == 0 && bit_len != 0)		// 만약 4의 배수가 걸렸다면 (4, 8, 12, 16 등)
		bits -= 4;								// 비트마스킹할 횟수를 4를 뺀다. (비트마스킹 할때는 전부 하면 안되기때문)

	for (int i = 0; i < bit_len; i += 4, bits -= 4) // 숫자의 비트수만큼 진행, 그러나 증감식은 4씩( 이유는 4비트씩 변환하기때문)
	{
		Trans = hxd >> bits;					// 비트마스킹
		Trans &= 0xF;							// &로 변환할 비트만 딱 골라준다. 0xF = 0000 0000 0000 1111
		a = TransperStr(Trans);					//문자 변환
		strBuf[(int)(i / 4)] = a;
	}

	if (hxd == 0)								// 0000을 입력하면 0이 나오는데, 0이면 빈칸을 출력하기에 예외 처리를 해준다.
		strBuf[0] = '0';
}

char TransperStr(unsigned int hxd)				// 16진수 숫자를 문자로 변환시키는 함수
{
	char a = 0;

	if (hxd >= 0 && hxd <= 9)					// 숫자 0~ 9까지 일 때
		a = hxd + '0';							// 문자(아스키코드)로 변환
	else if (hxd >= 10 && hxd <= 15)			// 숫자 10 ~ 15까지 일 때
		a = hxd + 'A' - 10;						// 문자열 

	return a;
}
