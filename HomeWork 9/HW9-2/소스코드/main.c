#include "Time.h" 

int main(void)
{
	Time t1, t2;							// 시간 입력 변수
	Time times[NUM_Time] = { {23, 59, 59}, {9, 0, 5}, {13, 30, 0}, {3, 59, 59}, {0, 0 ,0} };
	// 시간 배열 초기값 
	int incr_secs, diff_sec;

	// 1. t1, t2를 입력받고, t2를 증가시킨후, t1과 t2사이의 시간차를 구함
	t1 = t2 = InputTime();					// 시간을 입력받은 후, t1, t2에 저장
	printf("Input time t1 = "); printTime(&t1); printf("\n");
	printf("Input seconds to increment : ");
	scanf("%d", &incr_secs);				// 변화 시킬 초를 입력
	incrementTime(&t2, incr_secs);			//t2를 변화시킨다.
	printf("After incrementing %d secs, t2 = ", incr_secs); printTime(&t2); printf("\n"); // t2출력
	diff_sec = compareTime(&t1, &t2);		// t1, t2의 차이를 계산해줌
	printf("Difference between t1 and t2 is %d secs\n", abs(diff_sec)); //시간차를 출력

	// 2. 배열의 값을 선택정렬한 후 출력
	printf("\nBefore sorting times : \n");				//시간 배열 정렬 전 출력
	printTimes(times, NUM_Time);
	SSTime(times, NUM_Time);							//시간 배열 정렬
	printf("After selection sorting of times : \n");	//시간 배열 정렬 후 출력
	printTimes(times, NUM_Time);

	return 0;
}
