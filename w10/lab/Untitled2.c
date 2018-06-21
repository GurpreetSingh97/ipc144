#include <stdio.h>
#include <string.h>

int main()
{
	char fullName[12] = "ancdefghijkl";

	
		
		char dotFullname[18];
	
		fullName[7] = "\0";
		strcpy(dotFullname,fullName);
			printf("1st %s\n",dotFullname);
		strcat(dotFullname,"..");
	//	strcpy(formattedRecord,dotFullname);
		
		
		
	printf("2nd %s",dotFullname);
	
	
	return 0;
}
