/*----------------------------------------
Name :Gurpreet Singh
ID   :145795167
Email:gsingh520@myseneca.ca
-----------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) {
	int isJedi = 0;
	FILE *fp;
	fp = fopen("jedi_master.txt","r");
	
	char jedi_name[31];
	
	while(fscanf(fp,"%[^\n]\n",jedi_name)>0){
		int number =strcmp(jedi_name,name);
		if(number ==0){
			isJedi =1;
			break;
		}
	}
	
  return isJedi;
}

void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {  
	char fullName2[17]="n";
	char newString[17];
	  
	if(strlen(fullName)>16){
		strncpy(fullName2,fullName,14);
		strcat(fullName2,"..");
		strcpy(formattedRecord,fullName2);
	}
	else{
		strcpy(newString,fullName);
		int i;
		for(i=16-strlen(fullName);i>0;i--){
		
		strcat(newString," ");
	}
		strcpy(formattedRecord,newString);
	}
	
	strcat(formattedRecord," (");
	strcat(formattedRecord,npa);
	strcat(formattedRecord,") ");
	strcat(formattedRecord,co);
	strcat(formattedRecord,"-");
	strcat(formattedRecord,number);
	
	if(isJediMaster(fullName)==1){
		strcat(formattedRecord," Jedi Master");
	}

}


/* Example formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/

