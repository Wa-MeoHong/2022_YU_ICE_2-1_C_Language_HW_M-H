#include "Mtrx_Print.h"

void fgetMtrxandprint(FILE* fin, double** mA, int* row_SIZE, int* col_SIZE, char a)
// 파일 입력 및 출력 함수 (main에 입력하는게 많아서 함수로 만들었음)
{
	*mA = fGetMtrx(fin, &(*row_SIZE), &(*col_SIZE));
	//동적할당 및 값 입력, 포인터 매개변수 mA가 아닌 원래 변수(메인에 있는)에 주소를 반환
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE); //출력 
	PrintMtrx(*mA, *row_SIZE, *col_SIZE);	printf("\n");
}

void AddMtrxprint(double** mA, double** mB, double** mD, int* row_SIZE, int* col_SIZE, char a)
// 행렬 덧셈 출력 ( 위의 함수와 조금 다른면이 있어 새로 작성, 아래 함수도 동일) 
{
	*mD = AddMtrx(*mA, *mB, *row_SIZE, *col_SIZE);					// 행렬 덧셈
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	//출력
	PrintMtrx(*mD, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mD, *row_SIZE);								// 동적할당 해제
}

void SubMtrxprint(double** mA, double** mB, double** mE, int* row_SIZE, int* col_SIZE, char a)
// 행렬 뺄셈 출력
{
	*mE = SubMtrx(*mA, *mB, *row_SIZE, *col_SIZE);					// 행렬 뺄셈
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	// 출력
	PrintMtrx(*mE, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mE, *row_SIZE);								// 동적할당 해제
}

void MulMtrxprint(double** mA, double** mB, double** mF, int* row_SIZE, int* col_SIZE, int k_SIZE, char a)
// 행렬 곱셈 (row_size = 행렬 F의 열 = 행렬 A(곱하는 행렬)의 열, F의 행 = 행렬 B(곱해지는 행렬)의 행, k_SIZE = 그 둘중 공통된 수를 가진 행/열)
{
	*mF = MulMtrx(*mA, *mB, *row_SIZE, k_SIZE, *col_SIZE);			// 행렬 곱셈
	printf("Mtrx_%c ( %d * %d ) : \n", a, *row_SIZE, *col_SIZE);	// 출력
	PrintMtrx(*mF, *row_SIZE, *col_SIZE);	printf("\n");
	DeleteDoubleMatrix(*mF, *row_SIZE);								// 동적할당 해제
}