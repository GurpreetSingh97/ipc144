
#include <stdio.h>


// ---------------------------------------
// place function PROTOTYPES below here...
// ---------------------------------------

 
// user interface tools function PROTOTYPES:

void welcome(void); 
void printTitle(void);
void printFooter(double gTotal); 
void flushKeyboard(void); 
void pause(void); 
int getInt(void); 
int getIntLimited(int lowerLimit, int upperLimit); 
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit); 
 

// application user interface function PROTOTYPES:
int yes(void);
int menu(void);
void GroceryInventorySystem(void);




// ----------------------------------------
// place function DEFINITIONS below here...
// ----------------------------------------

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
//        else if(character=='n'||character =='N'){
  //              return 0;
    //    }
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
//        printf("\n");
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



	
