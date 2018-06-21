// -------------------------------------------
//  Name: Gurpreet Singh
//  ID:145795167
//  Email: gsingh520@myseneca.ca
//  Description: Milestone #3
// -------------------------------------------

#include <stdio.h>


#define LINEAR 1
#define FORM 0

#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

//#define MAX_ITEM_NO 500
#define DATAFILE "144_fp_items.txt"



struct Item {
 double price;
 int sku;
 int isTaxed;
 int quantity;
 int minQuantity;
 char name[21];
};

// Copy your milestone #1 source code below

void welcome(void); 
void printTitle(void);
void printFooter(double gTotal); 
void flushKeyboard(void); 
void pause(void); 
int getInt(void); 
int getIntLimited(int lowerLimit, int upperLimit); 
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit); 
 
int yes(void);
int menu(void);
void GroceryInventorySystem(void);


// prototypes for milestone2

double totalAfterTax(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// prototypes for milestone3
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoOfRec , int sku);
void addOrUpdateItem(struct Item item[], int *NoOfRec);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

//prototypes for milestone 4
void saveItem(struct Item item, FILE *dataFile);
int loadItem(struct Item* item,FILE* dataFile);
int saveItems(const struct Item item[],char fileName[],int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr);






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


const double TAX = 0.13;


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
	item.price = getDoubleLimited(0.01,1000.00);

	printf("   Quantity: ");
	item.quantity = getIntLimited(1,MAX_QTY);

	printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0,100);

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
		if(item.quantity<=item.minQuantity){
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



int locateItem(const struct Item item[], int NoOfRecs, int sku, int *index){
	int i =0;
	for(i =0;i<NoOfRecs;i++){
		if(sku == item[i].sku){
			*index = i;
			return 1;
		}
	}       
	return 0;
}

//milestone3

void search(const struct Item item[], int NoOfRecs){
	int sku;
	printf("Please enter the SKU: ");
	scanf("%d",&sku);
	flushKeyboard();
	int i;
	int ans;
	ans = locateItem(item,NoOfRecs,sku,&i);
	
	if(ans ==1){
		
	displayItem(item[i],0);
	
		}else{
			printf("Item not found!\n");
		}
}

void updateItem(struct Item *itemptr){
	struct Item item;
	printf("Enter new data:\n");

	struct Item copy = *itemptr;

	item = itemEntry(copy.sku);
	int answer;
	printf("Overwrite old data? (Y)es/(N)o: ");
	answer = yes();
	
	if(answer ==1){ 
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else{
		printf("--== Aborted! ==--\n");
	}
	
}

void addItem(struct Item item[], int *NoOfRec , int sku){
	struct Item itm;
	if(*NoOfRec == MAX_ITEM_NO){
		printf("Can not add new item; Storage Full!\n");
	}
	else{
		itm = itemEntry(sku);
		int answer;
		printf("Add Item? (Y)es/(N)o: ");
		answer = yes();
		if(answer==1){
			item[*NoOfRec] = itm;
			*NoOfRec = *NoOfRec+1;
			printf("--== Added! ==--\n");
		}
		else{
			printf("--== Aborted! ==--\n");
		}
	}       
}
void addOrUpdateItem(struct Item item[], int *NoOfRec){
	printf("Please enter the SKU: ");
	int sku = getIntLimited(SKU_MIN,SKU_MAX);
	int i;
	int number;
	number =locateItem(item, *NoOfRec,sku,&i);
	
	if(number ==1){
		
		displayItem(item[i],0);
		int answer;
		printf("Item already exists, Update? (Y)es/(N)o: ");
		answer = yes();
		if(answer ==1){
			updateItem(&item[i]);
		}
		else{
			printf("--== Aborted! ==--\n");
		}
	
	}
	else{
		addItem(item,NoOfRec,sku);
	}
	
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
      printf("Please enter the SKU: ");
      int sku;
      sku = getIntLimited(SKU_MIN, SKU_MAX);
      int answer;
      int i;
      answer = locateItem(item, NoOfRecs,sku,&i);
      if(answer ==0){
              printf("SKU not found in storage!\n");
      }
      else{
             displayItem(item[i],0);
              int number;
              if(stock == STOCK){
              	printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ","to stock" , MAX_QTY- item[i].quantity);
				number = getIntLimited(0,MAX_QTY-item[i].quantity);			 
			  }
			  else{
			  	printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ","to checkout",item[i].quantity);
			  	number = getIntLimited(0,item[i].quantity);	
			  }
			  
			  if(number ==0){
			  	printf("--== Aborted! ==--\n");
			  }
			  else{
			  	if(stock ==STOCK){
			  		item[i].quantity+= number;
			  		printf("--== Stocked! ==--\n");
				  }
				  else{
				  	item[i].quantity-= number;
				  	printf("--== Checked out! ==--\n");
				  }
				  if(item[i].quantity < item[i].minQuantity){		  
				  printf("Quantity is low, please reorder ASAP!!!\n");
			  }
		}
	}

}




void saveItem(struct Item item, FILE *dataFile){
	fprintf(dataFile,"%d,%d,%d,%.2lf,%d,%s\n",item.sku,item.quantity,item.minQuantity,item.price,item.isTaxed,item.name);
}


int loadItem(struct Item* item,FILE* dataFile){
	int number;
	number =fscanf(dataFile,"%d,%d,%d,%lf,%d,%[^\n]\n",&(*item).sku,&(*item).quantity,&(*item).minQuantity,&(*item).price,&(*item).isTaxed,(*item).name);
	
	if(number ==6){
		return 1;
	}	
		return 0;
	
}



int saveItems(const struct Item item[],char fileName[],int NoOfRecs){
	FILE *fp;
	fp = fopen(fileName,"w");
	
	if(fp!=NULL){
		int i=0;
		for(i=0;i<NoOfRecs;i++){
			saveItem(item[i],fp);
		}
		fclose(fp);
		return 1;
	}
	
	return 0;
}


int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr){
	FILE *fp;
	fp = fopen(fileName,"r");
	int count =0;
	
	if(fp!=NULL){
	//	int d=0;
		int i =0;
		while(loadItem(&item[i],fp)!=0){
		
	//	loadItem(&item[i],fp);
		count ++;
		i++;
	//	d++;
		}
	
		*NoOfRecsPtr = count;
		fclose(fp);
		return 1;
	}
	return 0;
}









