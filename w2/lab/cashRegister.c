#include<stdio.h>

int main(void){

	double amount;
	int quarters;
	float balance1;
	int loonies;
	float balance2;

	printf("Please enter the amount to be paid: $");
	scanf("%lf",&amount);

	loonies = amount / 1;
	balance1 = amount - loonies;
	quarters = balance1 / 0.25;
	balance2 = balance1 - (quarters * 0.25);
 
	printf("Loonies required: %d, balance owing $%.2f\n", loonies , balance1);
	printf("Quarters required: %d, balance owing $%.2f\n",quarters, balance2 );
	
	return 0;


}
