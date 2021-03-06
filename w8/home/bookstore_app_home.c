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
int  searchInventory(const struct Book book[],const int isbn,const int size);
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
int searchInventory(const struct Book book[],const int isbn,const int size){
	int i;
	for(i =0;i<size;i++){
		if(isbn == book[i]._isbn){
			return i;
		}
	}
	
	return -1;
}

void addBook(struct Book book[], int *size){
	int isbn;       
	int quantity;
	
	printf("ISBN:");
	scanf("%d",&isbn);
	flushKeyboard();
	printf("Quantity:");
	scanf("%d",&quantity);
	flushKeyboard();
	
	int index =searchInventory(book,isbn,*size);
	
	if(index!=-1){
		book[index]._qty = book[index]._qty + quantity;
		printf("The book exists in the repository, quantity is updated.\n\n");
	}
	
	else{
	
	if(*size==MAX_BOOKS){
		printf("the inventory is full\n");
	
	}
	else{
	book[*size]._isbn = isbn;
	book[*size]._qty = quantity;
		
		printf("Title:");
		scanf("%[^\n]",book[*size]._title);
		flushKeyboard();
		
		printf("Year:");
		scanf("%d",&book[*size]._year);
		flushKeyboard();
		
		printf("Price:");
		scanf("%f",&book[*size]._price);
		flushKeyboard();
		

		
		printf("The book is successfully added to the inventory.\n\n");
		*size = *size+1;
	}
}
}

void checkPrice(const struct Book book[],const int size){
	int isbn;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d",&isbn);

	int index =searchInventory(book,isbn,size);
	if(index!=-1){
	printf("Book %d costs $%.2f\n\n",isbn,book[index]._price);
	}
	else{
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}

	
}



void flushKeyboard(void){
	char clearKeyboard;
	do{
		scanf("%c",&clearKeyboard);
	}while(clearKeyboard!='\n');
	
}

