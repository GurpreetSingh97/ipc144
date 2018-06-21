#include<stdio.h>

#define NUMS 3

int main(void){

	printf("---=== IPC Temperature Analyzer ===---\n");
	
	int i;
	int sum;
	float average;
	int arr[3];     
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
			arr[i] = high + low;
	}
	     sum= arr[0] + arr[1] + arr[2];
	     average = (float)sum/6;
	       
	     printf("The average (mean) temperature was: %0.2f\n",average);
	 return 0;               
}
