/*
Name:Gurpreet Singh
Student number:145795167
Email:gsingh520@myseneca.ca
Workshop:workshop_5
Section:J
Date:17JUNE2017
*/

#include <stdio.h>

#define SIZE 4                

int update_id =0;

int target=0;

double currentSalary;

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
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
			if(count <SIZE){
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
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			printf("Enter Employee ID: ");
			scanf("%d",&update_id);
			int f =0;
			for(f =0;f<count;f++){
				if(emp[f].id == update_id){
					target = f;
					break;
				}
			}
			printf("The current salary is ");
			scanf("%lf",&currentSalary);
			printf("Enter Employee New Salary: ");
			scanf("%lf",&emp[target].salary);
			printf("\n");
			break;
			case 4:
				printf("Remove Employee\n");
				printf("===============\n");
				printf("Enter Employee ID: ");
				scanf("%d",&update_id);
				int r =0;
				for(r =0;r<count;r++){
				if(emp[r].id == update_id){
					target = r;
					break;
				}
			}
			int a =target;
				for(a=target;a<count-1;a++){
				emp[a].id = emp[a+1].id;
				emp[a].age = emp[a+1].age;
				emp[a].salary = emp[a+1].salary;
				
				}
		      
				count --;                       
				printf("Employee %d will be removed\n\n",update_id);
				break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}
	} while (option != 0);
       
	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
