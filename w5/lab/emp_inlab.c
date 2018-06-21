/*
Name:Gurpreet Singh
Student number:145795167
Email:gsingh520@myseneca.ca
Workshop:workshop_5
Section:J
Date:16JUNE2017
*/

#include <stdio.h>

#define SIZE 2                


struct employee{
	int id;
	int age;
	double salary;

};

int main (void){
	int count =0;
	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	
	struct employee emp[SIZE];
	int i =0;
	for(i=0;i<SIZE;i++){
		emp[i].id=0;
		emp[i].age =0;
		emp[i].salary =0;


	}        
	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		case 0:
			
			break;
		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
		int j=0;
		for(j=0;j<count;j++){
			printf("%6d%9d%11.2lf\n",emp[j].id,emp[j].age,emp[j].salary);
		}

		    printf("\n");   
			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");

			if(count <2){
					printf("Enter Employee ID: ");
					scanf("%d",&emp[count].id);
					printf("Enter Employee Age: ");
					scanf("%d",&emp[count].age);
					printf("Enter Employee Salary: ");
					scanf("%lf",&emp[count].salary);
					count ++;
					printf("\n");                        
		}
			else{
		      
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
	 
			}


			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);
       
	printf("Exiting Employee Data Program. Good Bye!!!\n");


	return 0; 
}
//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---
1. Display Employee Information
2. Add Employee
0. Exit
Please select from the above options: 2
Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88
1. Display Employee Information
2. Add Employee
0. Exit
Please select from the above options: 2
Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000
1. Display Employee Information
2. Add Employee
0. Exit
Please select from the above options: 2
Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached
1. Display Employee Information
2. Add Employee
0. Exit
Please select from the above options: 1
EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00
1. Display Employee Information
2. Add Employee
0. Exit
Please select from the above options: 0
Exiting Employee Data Program. Good Bye!!!
*/
