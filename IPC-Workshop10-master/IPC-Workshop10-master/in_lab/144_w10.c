/*
Monark patel 
135845162
mypatel2@myseneca.ca
w10 lab part 
13-04-2017
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) 
{
	int isJedi = 0;
	char Jedi[50];	
	FILE *pf;
    pf=fopen("jedi_master.txt","r");
	while(fscanf(pf,"%[^\n]%*c",Jedi)>0)
	{	
		if(strcmp(Jedi, name) == 0)
		{
			isJedi++;
		}
	}
	fclose(pf);
	
  return isJedi;
}
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) 
{
	int a=0,b=0,c;
	char name[20]={0};
	
	a=strlen(fullName);
	strcpy(formattedRecord,fullName);
	if(a > 16 )
	{
		for(a=0;a<14;a++)
		{
			name[a]=fullName[a];
		}
		strcpy(formattedRecord,name);
		strcat(formattedRecord,"..");
	}
	else if(a < 16 )
	{
		b=16-a;
		for(c=0;c<b;c++)
		{
			strcat(formattedRecord," ");
		}
	}	
	strcat(formattedRecord," (");	
	strcat(formattedRecord,npa);	
	strcat(formattedRecord,") ");	
	strcat(formattedRecord,co);	
	strcat(formattedRecord,"-");	
	strcat(formattedRecord,number);
	if(isJediMaster(fullName)==1)
	{
		strcat(formattedRecord," Jedi Master");
	}
}


/* formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/