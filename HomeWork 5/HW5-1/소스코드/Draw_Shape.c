#include "Draw_Shape.h"
#define Space 1
 
void draw_rectangle(int width, int length)				//직사각형 만들기
{
	for (int i = 0; i < width; i++)						// 가로 모서리 표시
	{
		printf("* ");									// 1칸씩 띄우는 이유 : 세로 모서리와 맞추기 위함
	}
	printf("\n");
	for (int j = Space; j <= length - Space; j++)		// 세로모서리 표시
	{
		printf("* ");									// 양끝쪽만 별표시하고 나머지는 칸띄우기
		for (int k = Space; k < width - Space; k++)		// 양쪽끝의 별표시빼고(-2) 전부 빈칸 
		{
			printf("  ");
		}
		printf("*\n");
	}
	for (int i = 0; i < width; i++)						// 맨 아래줄 표시
		printf("* ");
	printf("\n");
}

void draw_right_triangle(int base)						// 직각삼각형 그리기
{
	printf("\n");
	for (int i = 0; i < base; i++)						// 아래로 내려감
	{
		for (int j = 0; j <= i; j++)					//가로, 내려갈수록 1칸씩 늘리면서 그림
			printf("*");
		printf("\n");
	}
}

void draw_reverse_right_triangle(int base)				// 대각선반전된 직각삼각형
{
	for (int i = 0; i < base; i++)						// 아래로 내려감
	{
		for (int j = 0; j < i; j++)						// 아래로 내려가면서 빈칸 갯수를 늘림
		{
			printf(" ");
		}
		for (int k = 0; k < base - i; k++)				//빈칸 띄운후 별찍기, 맨위가 젤 길고 내려가면서 찍는개수 적어짐
		{
			printf("*"); 
		}
		printf("\n");
	}
}


void draw_diamond(int width)							//다아아몬드(마름모)
{	
	//윗부분 만들기
	for (int i = 1; i <= (width + Space) / 2; i++)	// 윗부분을 가운데까지 포함시키기 
	{	
		for (int j = (width + Space) / 2; j > i; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 - 1); k++)
		{
			printf("*");
		}
		printf("\n");
	}

	//아래부분 만들기
	for (int i = (width - Space) / 2; i >= 0; i--)  //아래부분은 윗부분에서 만든 젤 긴부분을 제외하므로 -1개를 해준후 시작
	{
		for (int j = i; j < (width - Space) / 2 + Space; j++)	//밑으로갈수록 빈칸 갯수 많아짐
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 - 1); k++)					//갈수록 별 줄어듦
		{
			printf("*");
		}
		printf("\n");
	}
}
