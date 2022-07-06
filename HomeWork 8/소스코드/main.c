#include "Matrix.h"
#include "Mtrx_GJ.h" 

#define INPUTDATA "InputData.txt"
#define OUTPUT "Output.txt"

int main(void)
{
	FILE* fin, * fout;
	int row_SIZE, col_SIZE;
	double* Sol;
	double** AugMtrx = NULL;
	int solExist;

	if ((fin = fopen(INPUTDATA, "r")) == NULL)
	{
		printf("Error! it doesn't opening InputData.txt file!!\n");
		exit(-1);
	} // 입력 파일 오픈

	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("Error! it doesn't opening Output.txt file!!\n");
		exit(-1);
	} // 출력 파일 오픈

	AugMtrx = fGetMtrx(fin, &row_SIZE, &col_SIZE);						// 선형 방정식 배열을 파일에서 가져옴
	PrintMtrx("Augmented Matrix", AugMtrx, row_SIZE, col_SIZE);			// 선형 방정식 초기 상수값들 출력
	fPrintMtrx(fout, "Augmented Matrix", AugMtrx, row_SIZE, col_SIZE);	// 파일 출력
	Sol = (double*)calloc(row_SIZE, sizeof(double));					// 해의 개수는 선형방정식의 개수와 같아서 SIZE_N개의 배열을 만들어줌

	Diagnolize(fout, AugMtrx, row_SIZE, &solExist);						//가우스-조던 소거법 계산

	if (solExist)														//해가 나왔음
	{
		fprintf(fout, "The Solution of given Linear System : \n");
		for (int i = 0; i < row_SIZE; i++)
		{
			Sol[i] = AugMtrx[i][row_SIZE];								//결과를 배열에 담음
			fprintf(fout, "x[%d](I%d) = %4.4lf\n", i, i + 1, Sol[i]);	//결과 출력
			printf("x[%d](I%d) = % 4.4lf\n", i, i + 1, Sol[i]);
		}
		printf("\n");
	}
	else																//해가 안나옴 (혹은 해가 없음)
	{
		fprintf(fout, "No Solutions! \n");
		printf("No Solutions! \n");
	}

	DeleteDynMtrx(AugMtrx, row_SIZE);									//동적할당 해제
	free(Sol);
	fclose(fin); fclose(fout);											// 파일 종료
	return 0;
}
