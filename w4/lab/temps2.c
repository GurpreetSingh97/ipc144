#include<stdio.h>


int main(void){
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
	     printf("Day %d - Low: ",i+1);
	     scanf("%d",&low[i]);
	    
	}
	printf("\n");
	printf("Day Hi Low\n");
	int j;        
	for(j=0;j<days;j++){
	     printf("%d   %d   %d\n",j+1,high[j],low[j]);
	}
	return 0;
}
