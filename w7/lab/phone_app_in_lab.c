/*
Name:
Student number:
Email:
Workshop:
Section:
Date:
*/

#include <stdio.h>

#define SIZE 3

void decompose(long long number,int *areaCode, int *prefix, int *lineNumber);

/* main program */
int main(void) {

long long phoneNumber[SIZE] = {0ll,0ll,0ll};
	int option;
	int count =0;
	int areaCode=0;
	int prefix=0;
	int lineNumber=0;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0: // Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
		break;

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			int i =0;
			for(i=0;i<count;i++){
				decompose(phoneNumber[i],&areaCode,&prefix,&lineNumber);
				 printf("(%3d)-%3d-%4d\n",areaCode,prefix,lineNumber);
			}
			
			printf("\n");


		break;

		case 2: // Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
			
			if(count>=SIZE){
				printf("ERROR!!! Phone Number List is Full\n\n");
			}       
			else{
			
				scanf("%lld",&phoneNumber[count]);
				printf("\n");
				count ++;
			}
	
		break;
		default:
		break;
		}

	} while (option != 0);

	return 0;
}
void decompose(long long number,int *areaCode, int *prefix, int *lineNumber){   
	int i,j,k;
	int l=0;
	int p=0;
	int a=0;
	int rem=0;
	int x=1;
	for(i=0;i<4;i++){
		rem = number%10;
		number = number/10;
		l = l + (rem*x);
		x = x*10;
	}
	*lineNumber = l;
	x=1;
	for(j=0;j<3;j++){
		rem = number%10;
		number = number/10;
		p = p + (rem*x);
		x = x*10;
	}
	*prefix = p;
	x =1;
	for(k=0;k<3;k++){
		rem = number%10;
		number = number/10;
		a = a + (rem*x);
		x = x*10;
	}
	*areaCode = a;
	
      //  printf("(%3d)-%3d-%4d\n",*areaCode,*prefix,*lineNumber);
	
}
