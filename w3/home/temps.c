#include<stdio.h>

#define NUMS 4


int main(void){


	printf("---=== IPC Temperature Analyzer ===---\n");
	
	int i;
	int sum;
	float average;
	int arr[4];

	int max =-42;
	int min = 42;

	int max_day;
	int min_day;
	for(i=0;i<NUMS;i++){
		int high;
		int low;
		int check=1;

		while(check!=0){

			printf("Enter the high value for day %d: ",i+1);
			
			scanf("%d",&high);
			printf("\n");
			printf("Enter the low value for day %d: ",i+1);
			scanf("%d",&low);
			printf("\n");
			if(high>low && high < 40 && low > - 40){
				 check =0;
			 }
			else if(check ==1){
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			}
		}

			if(high>max){
			max = high;
			max_day = i+1;
			}
			if(low<min){
			min = low;
			min_day = i+1;
			}

			arr[i] = high + low;
	}
	     sum= arr[0] + arr[1] + arr[2] + arr[3];
	     average = (float)sum/8;
	       
	     printf("The average (mean) temperature was: %0.2f\n",average);
		printf("The highest temperature was %d, on day %d\n",max,max_day);
		printf("The lowest temperature was %d, on day %d\n",min,min_day);
	 return 0;               
}
