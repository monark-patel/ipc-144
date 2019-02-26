/*
Name:Monark Patel
Student number:135845162
Email:mypatel2@myseneca.ca
Workshop:7
Section:0
Date:3/16/2017
*/

#include <stdio.h>

#define SIZE 3
//to decompose all the variable's whose adresses we got
void decompose(long long phoneno,int *areacode,int *prefix ,int *linenumber)
{
	*linenumber = phoneno % 10000;
	*prefix = ((phoneno-*linenumber)/10000)%1000;
	*areacode=(phoneno-*prefix * 10000 -*linenumber)/10000000; 
}
int isValid(long long valid) // to catch a number to check if valid 
{
	int area,prefix,line;
	int q=0;
	line = valid % 10000;
	prefix = ((valid-line)/10000)%1000;
	area = (valid-prefix*10000-line)/10000000;
	if(area == 416 || area == 647 || area == 905) //to check if area is valid in data
	{
		if(prefix >= 100 && prefix <= 999)  //if area is valid check if prefix is valid
		{
			q = 1;
		}
	} 
	else
	{
		q = 0;;
	}
	return q;
}
struct numbers // using same logic as one of earlier workshop to get variables
{
	long long phoneno;
	int areacode;
	int prefix;
	int linenumber;
};
/* main program */
int main(void) {

	int option,x;
	long long phno; // to get a number
	int count=0; 
	long long phone; // to get the number temprary for working with
	struct numbers phoneNumber[SIZE]={{0LL,0,0,0}}; 
	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;
        case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for(x=0;x<count;x++)
			{
				printf("(%3d)-%3d-%4d\n",phoneNumber[x].areacode,phoneNumber[x].prefix,phoneNumber[x].linenumber);
			}
			printf("\n");
			break;
		case 2:	// Add a Phone Number
				
			printf("Add a Number\n");
			printf("============\n");
			
			if(count<SIZE) //to check if array is full
			{
				scanf("%lld",&phno);				// to get the number
				phone=isValid(phno); // to give the number to valid to check
				if (phone>0)
				{
					printf("\n");
					phoneNumber[count].phoneno=phno;
					//to catch the variables from decompose as numbers/values from pointers
					decompose(phoneNumber[count].phoneno,&phoneNumber[count].areacode,&phoneNumber[count].prefix,&phoneNumber[count].linenumber);
					count++;
					
				}
				else // print error if invalid 
				{
					printf("ERROR!!! Phone Number is not Valid\n");
					printf("\n");
				}
				break;
			}
			else 
			{
				printf("ERROR!!! Phone Number List is Full\n");
				//printf("\n");
			}
			printf("\n");
			break;
		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n");
			printf("\n");
			break;
		}

	} while (option != 0);
	return 0;
}
 


