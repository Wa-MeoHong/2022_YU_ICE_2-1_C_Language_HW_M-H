#include "Matrix.h"
#include "Mtrx_Print.h"
 
int main(void)
{
	FILE* fin;
	char a = 65; //'A'
	double** mA, ** mB, ** mC, ** mD, ** mE, ** mF;
	int a_row_SIZE = 0, a_col_SIZE = 0;
	int b_row_SIZE = 0, b_col_SIZE = 0;
	int c_row_SIZE = 0, c_col_SIZE = 0;

	if ((fin = fopen(MtrxDataFile, "r")) == NULL)				// 파일을 읽기모드로 연다. 실패시 종료
	{
		printf("\tError in opening input.txt FILE !!\n\n");
		exit(-1);
	}

	//행렬을 동적할당 해준 후, 출력 해주는 함수 fgetMtrxandprint
	fgetMtrxandprint(fin, &mA, &a_row_SIZE, &a_col_SIZE, a++);
	fgetMtrxandprint(fin, &mB, &b_row_SIZE, &b_col_SIZE, a++);
	fgetMtrxandprint(fin, &mC, &c_row_SIZE, &c_col_SIZE, a++);

	if ((a_row_SIZE != b_row_SIZE) || (a_col_SIZE != b_col_SIZE))
	{ //만약 둘 중 하나라도 같지 않다면 ( 행렬 덧셈, 뺄셈은 두개의 행,열이 같아야 성립)
		printf("\tError! row_SIZE and/or col_SIZE aren't equal!!\n ");
		fclose(fin);
		return; //하는이유 : 종료가 되더라도 다시 반복문을 해야하기 때문
	}

	//mD = mA + mB;
	AddMtrxprint(&mA, &mB, &mD, &a_row_SIZE, &a_col_SIZE, a++);
	//mE = mA - mB;
	SubMtrxprint(&mA, &mB, &mE, &a_row_SIZE, &a_col_SIZE, a++);
	//mF = mA * mC;
	MulMtrxprint(&mA, &mC, &mF, &a_row_SIZE, &c_col_SIZE, c_row_SIZE, a);

	DeleteDoubleMatrix(mA, a_row_SIZE); //동적할당 해제
	DeleteDoubleMatrix(mB, b_row_SIZE);
	DeleteDoubleMatrix(mC, c_row_SIZE);

	fclose(fin);
	return 0;
}
