// -------------------------------------------
//  Name:
//  ID:
//  Email:
//  Description: Milestone #2
// -------------------------------------------

#include <stdio.h>

// Copy your milestone #1 source code below


void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
	
}

void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
	
}

void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal>0){
		printf("                                           Grand Total: |%12.2lf\n",gTotal);
	}

}

void flushKeyboard(void){
	char clearKeyboard;
	do{
		scanf("%c",&clearKeyboard);
	}while(clearKeyboard!='\n');
	
}

void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

int getInt(void){
	int value;
	char NL = 'x';
	while(NL!='\n'){
		scanf("%d%c",&value,&NL);
		
		if(NL!='\n'){
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit){
	int limit;
	do{

		limit = getInt();
		if(limit <lowerLimit || limit > upperLimit){
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
	
	}while(limit<lowerLimit || limit>upperLimit);
	
	return limit;
}

double getDouble(void){
	double value;
	char NL = 'x';
	while(NL!='\n'){
		scanf("%lf%c",&value,&NL);
		
		if(NL!='\n'){
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return value;
}


double getDoubleLimited(double lowerLimit, double upperLimit){
		double limit;
	do{

		limit = getDouble();
		if(limit <lowerLimit || limit > upperLimit){
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
	
	}while(limit<lowerLimit || limit>upperLimit);
	
	return limit;   
}





int yes(void){
	char character;
	do{
		scanf("%c",&character);
		flushKeyboard();
		
		if(character!='y' && character!='Y' && character!= 'n' && character!='N'){
			printf("Only (Y)es or (N)o are acceptable: ");
		}
		
	}while(character!='y'&& character !='Y' &&character != 'n' &&character!='N');
	
	if(character=='y'||character =='Y'){
		return 1;
	}
      return 0;  
}

int menu(void){
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- Delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	
	int option = getIntLimited(0,7);
	return option;
}

void GroceryInventorySystem(void){
	welcome();

	int menuOption = 1;
	while(menuOption!=0){
	
	menuOption =menu();
	
	
	if(menuOption==1){
		printf("List Items under construction!\n");
	}
	else if(menuOption==2){
		printf("Search Items under construction!\n");
	}
	else if(menuOption==3){
		printf("Checkout Item under construction!\n");
	}
	else if(menuOption==4){
		printf("Stock Item under construction!\n");
	}
	else if(menuOption==5){
		printf("Add/Update Item under construction!\n");
	}
	else if(menuOption==6){
		printf("Delete Item under construction!\n");
	}
	else if(menuOption==7){
		printf("Search by name under construction!\n");
	}
	

	if(menuOption ==0){
		printf("Exit the program? (Y)es/(N)o: ");
		int exitAnswer = yes();
		if(exitAnswer!=1){
			menuOption =1;
		}
		
	}
	else{
		pause();
	}


	}       
}


// - Add new function prototypes and definitions
//   for milestone #2 as per the directions


#define LINEAR 1
#define FORM 0

const double TAX = 0.13;


struct Item {
 double price;
 int sku;
 int isTaxed;
 int quantity;
 int minQuantity;
 char name[21];
};



double totalAfterTax(struct Item item){
	double total;
	if(item.isTaxed ==1){
	
		total = (item.price * item.quantity)+((item.price * item.quantity)*TAX);
	}
	else{
		total = (item.price * item.quantity);
	}
	return total;
}


int isLowQuantity(struct Item item){
	if(item.quantity< item.minQuantity){
		return 1;
	}
	else{
		return 0;
	}
	
}


struct Item itemEntry(int sku){
	
	struct Item item;
	
	item.sku = sku;
	printf("        SKU: %d\n",sku);
 
       printf("       Name: ");
	scanf("%20[^\n]c",&*item.name);
	flushKeyboard();
   
	printf("      Price: ");
	item.price = getDouble();

	printf("   Quantity: ");
	item.quantity = getInt();

	printf("Minimum Qty: ");
	item.minQuantity = getInt();

	printf("   Is Taxed: ");
	item.isTaxed = yes();
	
	return item;
		
}
void displayItem(struct Item item,int linear){
	int x;
	if(linear ==1){
	printf("|");
	printf("%3d",item.sku);
	printf("|");
	printf("%-20s",item.name);
	printf("|");
	printf("%8.2lf",item.price);
	printf("|  ");
	
	if(item.isTaxed==1){
		printf("Yes");

	}
	else if(item.isTaxed==0){
	printf(" No");
		
	}
	
	printf("| ");
	printf("%3d",item.quantity);
	printf(" | ");
	printf("%3d",item.minQuantity);
	printf(" |");
	double totalprice = totalAfterTax(item);
	printf("%12.2f",totalprice);
	printf("|");
		
	x = isLowQuantity(item);
	if(x==1){
		printf("***");
	}
	
		printf("\n");   
	}
	else{
	printf("        SKU: %d\n",item.sku);
	printf("       Name: %s\n",item.name);
	printf("      Price: %.2lf\n",item.price);
	printf("   Quantity: %d\n",item.quantity);
	printf("Minimum Qty: %d\n",item.minQuantity);
		if(item.isTaxed==1){
		printf("   Is Taxed: Yes\n");
	}
	else{
		printf("   Is Taxed: No\n");
	}
		if(item.quantity<item.minQuantity && item.isTaxed==1){
		printf("WARNING: Quantity low, please order ASAP!!!\n");
	}       
	}
}


void listItems(const struct Item item[], int noOfItems){
	int i;
	double grandTotal =0;
	double totalprice;
	
	printTitle();
	
	for(i=0;i<noOfItems;i++){
	printf("%-4d",i+1);
	displayItem(item[i],LINEAR);
	totalprice = totalAfterTax(item[i]);
	
	grandTotal=grandTotal+totalprice;
	}
	printFooter(grandTotal);
}



int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
	int i =0;
	for(i =0;i<NoOfRecs;i++){
		if(sku == item[i].sku){
			*index = i;
			return 1;
		}
	}
	
	return 0;
}



