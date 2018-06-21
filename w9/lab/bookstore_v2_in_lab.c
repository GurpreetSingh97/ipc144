// ---------------------------------------
// Name:Gurpreet Singh
// ID:145795167
// Email:gsingh520@myseneca.ca
// ---------------------------------------

#include <stdio.h>

#define MAX_TITLE_SIZE 20


//Type the struct here
struct Book {
	int _isbn;
	float _price;
	int _year;
	int _qty;
	char _title[MAX_TITLE_SIZE];
	
	
};

//Type the function prototypes here
void menu();
void displayInventory(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[],const int isbn2find);
void searchInventory(FILE *fp,const int isbn2find);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);



int main()
{
   //Type your code here:
   struct Book myBook;
   char filename[] = "144_w9_inventory.txt";
   printf("Welcome to the Book Store\n");
   printf("=========================\n");
   
   int select;
   do{
	menu();
	
	printf("Select: ");
	scanf("%d",&select);
      
	
	switch (select){
		case 1:
			displayInventory(filename);
		break;
			
		case 2:
			addBook(filename,&myBook);

			
		break;
			
		case 3:
			printf("Not implemented!\n");
		break;
	
		case 4:
			printf("The total capital is: $%0.2f.\n",  calculateCapital(filename));
		break;
			
		case 0:
			printf("Goodbye!\n");
		break;  
	       
	   }
   }while(select!=0);
   
    return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");
}


void displayInventory(const char filename[])
{
    //Define an object of struct Book
    struct Book book;
    
    FILE *fp= NULL;
    //Open the file, and check for null pointer
    fp = fopen(filename,"r");
    
    if(fp!=NULL){
	  printf("\n\n");
	printf("Inventory\n");
    //If the file is properly opened, display headers, similar to workshop 8
	printf("===================================================\n");
	printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
	  
   
     //Use a while loop to call readRecord and display the records.
	       
		while(readRecord(fp,&book)==5){
		
	//display the record
		printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book._isbn,book._title,book._year,book._price,book._qty);
	       
	}
    //Display the footer
		printf("===================================================\n\n");
    
    //Close the file
		fclose(fp);
	
	}
	else{
		printf("Failed to open file\n");
	}
}




void addBook(const char filename[], struct Book *b2Add)
{
	printf("Not implemented!\n");
 //Not implemented!
}

void checkPrice(const char filename[],const int isbn2find)
{   
 //Not implemented!
}

void searchInventory(FILE *fp,const int isbn2find)
{
 //Not implemented!
}


float calculateCapital(const char filename[])
{  
    //Define an object of struct Book
    struct Book item;
    
    //Define and initialize total_capital
    float total_capital =0;
    
    FILE *fp = NULL;
    //Open the file, and check for null pointer
    fp = fopen(filename,"r");
    if(fp!=NULL){
    //If the file is properly opened, use a while loop to call readRecord
		 while(readRecord(fp,&item)==5){
			total_capital = total_capital + (item._price*item._qty);
	//Accumulate the multiplication of the price of each item to its quantity
	
		}
		
		//Display the footer
//        printf("===================================================\n");
	
    //Close the file
	fclose(fp);
 
    }
	
    
    //return the total_capital
    return total_capital;
    
}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
    int rv =0;
    
    rv = fscanf(fp,"%d;%f;%d;%d;%[^\n]\n",&(*b2read)._isbn,&(*b2read)._price,&(*b2read)._year,&(*b2read)._qty,(*b2read)._title);
   
    //return rv;
	return rv;
}
