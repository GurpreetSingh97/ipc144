#include<stdio.h>


int main(void){
	int maxTemp = -2000;
	int maxDays;
	int minTemp = 2000;
	int minDays;


	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	int days;
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d",&days);
	printf("\n");
	
	while(days<3 || days>10){
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d",&days);
		printf("\n");
	}

	int high[days];
	int low[days];

	int i;
	for(i=0;i<days;i++){

	     printf("Day %d - High: ",i+1);
	     scanf("%d",&high[i]);

		if(high[i]>maxTemp){
		maxTemp = high[i];
		maxDays = i+1;
		}

	     printf("Day %d - Low: ",i+1);
	     scanf("%d",&low[i]);
		if(low[i]<minTemp){
		      minTemp = low[i];
		      minDays = i+1;                
		}           
	}
	printf("\n");
	printf("Day  Hi  Low\n");
	int j;        
	for(j=0;j<days;j++){
	     printf("%d    %d    %d\n",j+1,high[j],low[j]);
	}
	printf("\n");
	printf("The highest temperature was %d, on day %d\n",maxTemp,maxDays);
	printf("The lowest temperature was %d, on day %d\n",minTemp,minDays);
	printf("\n");
	int averageDay=1;
	int sum;
	float average;
 
	while(averageDay>=0){
	sum =0;
	printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",days);
	scanf("%d",&averageDay);
	printf("\n");
		while(averageDay==0 || averageDay > days){
			printf("Invalid entry, please enter a number between 1 and %d, inclusive: ",days);
			scanf("%d",&averageDay);
			printf("\n");
		}
		if(averageDay <0){
			printf("Goodbye!\n");
			return 0;
		}
 
		int k;
		for(k=0;k<averageDay;k++){      
			sum = sum+high[k]+low[k];
		}
		
	 average = (float)sum/(averageDay*2);
	printf("The average temperature up to day %d is: %0.2f\n",averageDay,average);
	printf("\n");
	}
	
return 0;
}
