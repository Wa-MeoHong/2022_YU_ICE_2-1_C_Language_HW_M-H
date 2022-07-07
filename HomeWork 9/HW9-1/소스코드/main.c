#include "Cmplx.h"

int main(void)
{
	Cmplx clxs[CmplxNUM];											//º¹¼Ò¼ö ¹è¿­ 

	clxs[0] = InputCmplx();											// ÀÔ·Â
	clxs[1] = InputCmplx();

	printf("\nclxs[0] = "); printCmplxNum(clxs[0]); printf("\n");
	printf("clxs[1] = "); printCmplxNum(clxs[1]); printf("\n");		//º¹¼Ò¼ö ÀÔ·Â°ª Ãâ·Â

	clxs[2] = cmplxAdd(clxs[0], clxs[1]);							// º¹¼Ò¼ö µ¡¼À
	printf("clxs[2] = clxs[0] + clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[2], ADD);

	clxs[3] = cmplxSub(clxs[0], clxs[1]);							// º¹¼Ò¼ö »¬¼À
	printf("clxs[3] = clxs[0] - clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[3], SUB);

	clxs[4] = cmplxMul(clxs[0], clxs[1]);							// º¹¼Ò¼ö °ö¼À
	printf("clxs[4] = clxs[0] * clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[4], MUL);

	clxs[5] = cmplxDiv(clxs[0], clxs[1]);							// º¹¼Ò¼ö ³ª´°¼À
	printf("clxs[5] = clxs[0] / clxs[1] = \n");
	printCplxresult(clxs[0], clxs[1], clxs[5], DIV);

	clxs[6] = cmplxMul(clxs[1], clxs[5]);							// º¹¼Ò¼ö °ö¼À(clxs[1]*clxs[5])
	printf("clxs[6] = clxs[1] * clxs[5] = \n");
	printCplxresult(clxs[1], clxs[5], clxs[6], MUL);

	printf("\nBefore sorting complexs : \n");						// ÄüÁ¤·Ä Àü Ãâ·Â
	printCmplxs(clxs, CmplxNUM);

	quickSortCmplx(clxs, CmplxNUM);									// ÄüÁ¤·Ä
	printf("After sorting complexs : \n");							// ÄüÁ¤·Ä ÈÄ Ãâ·Â
	printCmplxs(clxs, CmplxNUM);

	return 0;
}