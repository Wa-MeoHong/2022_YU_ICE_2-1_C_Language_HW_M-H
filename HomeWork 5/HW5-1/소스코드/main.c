#include "draw_shape.h"
#include <windows.h>
#include <conio.h>

int main(void) 
{
	int choose; // 선택지 변수
	int width, length; // 가로, 세로
	int base; // 밑변(높이도 같이씀)

	while (1)
	{
		printf("만들고 싶은 도형을 선택하시오. (1 : rectangle, 2 : right triangle \
3 : reverse triangle, 4 : diamond, 0 : END) : ");	// 선택지 
		scanf("%d", &choose);						//choose 변수로 값 입력

		if (choose == 0)							// 0일때 종료
			break;

		switch (choose)								// 선택에 따라 
		{
			case 1:									// 직사각형 만들기
			{	
				printf("Rectangle / width, length : ");
				scanf("%d %d", &width, &length);
				draw_rectangle(width, length);
				break; 
			}

			case 2:									// 직각삼각형 만들기
			{	
				printf("Right_Triangle / base : ");
				scanf("%d", &base);
				draw_right_triangle(base);
				break; 
			}

			case 3:									//역 직각삼각형 만들기
			{	
				printf("Reverse Right_Triangle / base : ");
				scanf("%d", &base);
				draw_reverse_right_triangle(base);
				break;
			}

			case 4:									//다이아몬드 만들기
			{
				printf("Diamond / width : ");
				scanf("%d", &width);
				draw_diamond(width);
				break; 
			}

			default:								//다른거 입력시 다시입력하도록 하게함
			{	
				printf("wrong choose! input again!\n");
				_getch(); 
				system("cls");
				continue;
			}
		}
		printf("\n Printing Complete! Press Any Key to back!");
		_getch();
		system("cls");
	}
	return 0;
}
