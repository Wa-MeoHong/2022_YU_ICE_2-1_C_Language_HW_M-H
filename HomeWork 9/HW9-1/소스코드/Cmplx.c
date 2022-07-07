#include "Cmplx.h"

Cmplx InputCmplx()						// 복소수 입력 및 초기값 설정
{
	Cmplx input;						

	// 복소수 입력
	printf("Input Complex Number (rrr.ddd iii.ddd (실수, 허수)) : ");
	scanf("%lf %lf", &input.real, &input.imagin);

	// 복소수의 크기 = √(실수값² + 허수값²)
	input.magnitude = sqrt(pow(input.real, 2) + pow(input.imagin, 2));

	return input;						// 값 반환
}

void printCmplxNum(const Cmplx c)		// 복소수 출력 함수 (기본형), 출력형식 : "a + jb (magnitude = 크기)"
{
	// 실수부분 출력
	printf("%7.3lf", c.real);						

	// 허수 출력
	if (c.imagin < 0)								// 만약 허수부분이 음수이면 - 출력, 아니면 + 출력
		printf(" - ");
	else
		printf(" + ");
	printf("j%7.3lf", fabs(c.imagin));				// 이미 -가 나왔으므로 절댓값 출력

	// 복소수 크기 출력
	printf(" (magnitude = %7.3lf)", c.magnitude);	
}

void printCplxresult(const Cmplx c1, const Cmplx c2, const Cmplx res, Oper num) //복소수 연산 결과 출력
{
	// 복소수 1 출력
	printCmplxNum(c1);					

	// 연산에 따라 switch문을 통해 연산기호 출력
	switch (num)
	{
		case ADD:
		{
			printf(" + ");	break;
		}
		case SUB:
		{
			printf(" - ");	break;
		}
		case MUL:
		{
			printf(" * ");	break;
		}
		case DIV:
		{
			printf(" / ");	break;
		}
	}
	
	// 복소수 2 출력
	printCmplxNum(c2); printf(" = ");
	// 결과 출력
	printCmplxNum(res);
	printf("\n");
}

void printCmplxs(const Cmplx* cmplxs, int SIZE)				// 복소수 배열 출력 함수
{
	for (int i = 0; i < SIZE; i++)							//복소수 개수 만큼 반복
	{
		//출력형식: "(cmplxs[i] = a + jb (magnitude = 크기))"
		printf("(cmplxs[%d] = ", i); printCmplxNum(cmplxs[i]);
		printf(")\n");										
	}
	printf("\n");
}

// c1 = a + bj, c2 = c + dj
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2)				// 복소수 덧셈
{
	Cmplx result;

	result.real = c1.real + c2.real;						// (a + c), 실수끼리 계산
	result.imagin = c1.imagin + c2.imagin;					// (b + d)j, 허수끼리 계산
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2)); // magnitude 계산 (복소수 크기 계산)
	

	return result;											// (a + c) + (b + d)j
}

Cmplx cmplxSub(const Cmplx c1, const Cmplx c2)				// 복소수 뺄셈
{
	Cmplx result;

	result.real = c1.real - c2.real;						// (a - c)
	result.imagin = c1.imagin - c2.imagin;					//(b - d)i
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude 계산 (복소수 크기 계산)

	return result;											// (a - c) + (b - d)j
}

Cmplx cmplxMul(const Cmplx c1, const Cmplx c2)				// 복소수 곱셈
{
	Cmplx result;

	result.real = (c1.real * c2.real) - (c1.imagin * c2.imagin);	// (ac - bd)
	result.imagin = (c1.real * c2.imagin) + (c1.imagin * c2.real);	// (ad + bc)i
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude 계산 (복소수 크기 계산)

	return result;											// (ac - bd) + (ad + bc)i
}

Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2)				// 복소수 나눗셈
{
	Cmplx result;

	result.real = (c1.real * c2.real + c1.imagin * c2.imagin) / (pow(c2.real, 2) + pow(c2.imagin, 2));		// (ac + bd) / (c² + d²)
	result.imagin = (c1.imagin * c2.real - c1.real * c2.imagin) / (pow(c2.real, 2) + pow(c2.imagin, 2));	// (bc - ad) / (c² + d²)
	result.magnitude = sqrt(pow(result.real, 2) + pow(result.imagin, 2));
	// magnitude 계산 (복소수 크기 계산)

	return result;											// ((ac + bd) + (bc - ad)i) / (c² + d²)
}

double CmpCmplx(const Cmplx c1, const Cmplx c2)				// 복소수 비교 함수
{
	// 계산해둔 magnitude의 크기로 두 복소수의 크기를 비교함 ( c1 기준 )
	if (c1.magnitude > c2.magnitude)				
		return 1;
	else if (c1.magnitude < c2.magnitude)
		return -1;
	else
		return 0;
}

// 퀵정렬 함수 
void quickSortCmplx(Cmplx* cmplxs, int SIZE)					// 퀵정렬 최초함수
{
	quickSort(cmplxs, SIZE, 0, SIZE - 1);
	//처음 할때는 left = 위치값이 0, right = size-1
}

void quickSort(Cmplx* cmplxs, int SIZE, int left, int right)	// 퀵정렬 본함수
{
	int P_I, newPI;
	if (left >= right)
		// 만약 left가 right보다 크거나 같다면 newPI반환 중지, 거의 left가 1혹은 0일때이다..
		return;

	else if (left < right)
	{
		P_I = (left + right) / 2;						// 중간값, 만약 홀수인경우 내림값으로 나누기위치값 산출
	}

	newPI = _partition(cmplxs, SIZE, left, right, P_I); //새로운 P_I(나누기위치값) 산출 및, 정렬

	// 이렇게 왼쪽, 오른쪽 순서대로 작은덩이 → 큰덩이
	if (left < (newPI - 1))								// 이제 newPI기준으로 왼쪽부분
	{
		quickSort(cmplxs, SIZE, left, newPI - 1);
		// 다시 newPI를 산출하면서 크기정렬을 쭉해준다.
	}
	if ((newPI + 1) < right)							// 다음, 왼쪽이 quickSort를 진행후, newPI기준 오른쪽 부분
	{
		quickSort(cmplxs, SIZE, newPI + 1, right);
		// 오른쪽으로 newPI산출및 크기순으로 정렬해준다.
	}
}

int _partition(Cmplx* cmplxs, int SIZE, int left, int right, int P_I) //파티션 위치값 반환 함수
{
	Cmplx P_V;							//pivot value, 그 위치에 있는 값
	Cmplx temp;							// 값 자리바꾸기 하기 위한 임시저장 변수
	int newPI;							// new pivot index, 새로운 위치값

	// 1. 정중앙과 마지막 두 개를 위치교환
	P_V = cmplxs[P_I];
	cmplxs[P_I] = cmplxs[right];
	cmplxs[right] = P_V; // 맨 처음 P_I에 있던 값을 맨 오른쪽(혹은 P_I-1위치에 있는 값)과 바꾼다

	// 2. newPI(새로운 중앙값 설정)
	newPI = left;										// 이제 새로운 피벗위치를 설정해주는데 초기값은 맨 왼쪽(혹은 P_I + 1위치)으로 설정
	for (int i = left; i <= right - 1; i++)				// 맨뒤로 가게된 P_V는 빼고 나머지 배열들을 범위로 잡는다.
	{
		if (CmpCmplx(cmplxs[i], P_V) == -1)				//만약 맨뒤로 간 P_V보다 값이 작다면
		{
			temp = cmplxs[i];
			cmplxs[i] = cmplxs[newPI];
			cmplxs[newPI] = temp;						// 현재(i)위치에 있는 값을 newPI에 있는 값과와 바꿔준다.
			newPI += 1;
		}
	}
	// 결론적으로 처음 P_V값을 기준으로 왼쪽은 P_V보다 작은 값들의 배열, 오른쪽은 P_V보다 큰 값들의 배열이 형성되었다.

	// 3. 1에서 했던것처럼 맨마지막과 정중앙을 교환
	P_V = cmplxs[right];
	cmplxs[right] = cmplxs[newPI];
	cmplxs[newPI] = P_V;

	return newPI; //새로운 PI의 값을 반환해준다.
}
