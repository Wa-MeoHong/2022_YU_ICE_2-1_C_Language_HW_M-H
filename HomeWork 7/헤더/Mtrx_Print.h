#ifndef MATRIX_PRINT_H 
#define MATRIX_PRINT_H

#include "Matrix.h"

void fgetMtrxandprint(FILE* fin, double** mA, int* row_SIZE, int* col_SIZE, char a);
void AddMtrxprint(double** mA, double** mB, double** mD, int* row_SIZE, int* col_SIZE, char a);
void SubMtrxprint(double** mA, double** mB, double** mE, int* row_SIZE, int* col_SIZE, char a);
void MulMtrxprint(double** mA, double** mB, double** mF, int* row_SIZE, int* col_SIZE, int k_SIZE, char a);

#endif
