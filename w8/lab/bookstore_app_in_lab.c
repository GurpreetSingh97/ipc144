/*
Name:Gurpreet Singh
Student number:145795167
Email:gsingh520@myseneca.ca
Workshop:8
Date:14 July 2017
*/

#include<stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book{
	int _isbn;
	float _price;
	int  _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};


void menu();
void displayInventory(const struct Book book[],const int size);
void searchInventory(const struct Book book[],const int isbn,const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[],const int size);
void flushKeyboard(void);


int main(void){
	struct Book book[MAX_BOOKS];
	int size =0;
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	
	int option;
		
	
	

	do {
	menu();
	printf("Select: ");
	scanf("%d",&option);
	
	
	switch (option) {
		case 1:
			displayInventory(book,size);
		break;
		
		case 2:
			addBook(book,&size);
		break;
			
		case 3:
			checkPrice(book,size);
		break;
		
		case 0:         
			printf("Goodbye!\n");
		break;
		
		default:
			printf("Invalid input, try again:\n");
		break;
	}
	
}while(option!=0);
	
	return 0;
}




void menu(){
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");
}

void displayInventory(const struct Book book[],const int size){
	if(size==0){
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}
	else{

	printf("\n\nInventory\n");
	int i;
	printf("===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");
	
	for(i =0;i<size;i++){
		printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book[i]._isbn,book[i]._title,book[i]._year,book[i]._price,book[i]._qty);
	}
       
	printf("===================================================\n\n");
	 
}
}

void searchInventory(const struct Book book[],const int isbn,const int size){
	printf("Not implemented\n");
}

void addBook(struct Book book[], int *size){
	
	if(*size==MAX_BOOKS){
		printf("the inventory is full\n");
	
	}
	else{
		printf("ISBN:");
		scanf("%d",&book[*size]._isbn);
		flushKeyboard();
		
		printf("Title:");
		scanf("%[^\n]",book[*size]._title);
		flushKeyboard();
		
		printf("Year:");
		scanf("%d",&book[*size]._year);
		flushKeyboard();
		
		printf("Price:");
		scanf("%f",&book[*size]._price);
		flushKeyboard();
		
		printf("Quantity:");
		scanf("%d",&book[*size]._qty);
		flushKeyboard();
		
		printf("The book is successfully added to the inventory.\n\n");
		*size = *size+1;
	}
	
}

void checkPrice(const struct Book book[],const int size){
	printf("Not implemented\n");
}


void flushKeyboard(void){
	char clearKeyboard;
	do{
		scanf("%c",&clearKeyboard);
	}while(clearKeyboard!='\n');
	
}

