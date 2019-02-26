#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);

// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


void welcome(void)   // to start the program
{
	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");
}
void printTitle(void)  //to print the lines 
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void printFooter(double gTotal)  // to get a total thats assummes
{
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal>0){
	printf("					   Grand Total: |%12.2lf\n",gTotal);
	}
}
void flushKeyboard(void) //to clear the entrence fo a value
{
	char a;
	while((a=getchar() != '\n' && a != EOF));
}
void pause(void)  // to pause the execution for the user
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}
int getInt(void)   // get an number
{	
	int x;
	char a;
	do{
		scanf("%d%c",&x,&a);   // accept anything as an input
		if(a!='\n') // check if input is ineger
		{
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}while(a!='\n');
	return x;
}
int getIntLimited(int lowerLimit, int upperLimit) //check limitation of ineger value
{
	int x;
	char a;
	do{
		scanf("%d%c",&x,&a);
		if(a!='\n')
		{
			flushKeyboard();
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
		
		else if(x<lowerLimit || x>upperLimit)
		{
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
	}while(a!='\n' || x<lowerLimit || x>upperLimit);
	return x;
}
double getDouble(void)   //get a number works as getint function
{	
	double y;
	char a;
	do{
		scanf("%lf%c",&y,&a);
		if(a!='\n')
		{
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}while(a!='\n');
	return y;
}
double getDoubleLimited(double lowerLimit, double upperLimit)  //works as getintlimited
{
	double y;
	char a;
	do{
		scanf("%lf%c",&y,&a);
		if(a!='\n')
		{
			flushKeyboard();
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
		
		else if(y<lowerLimit || y>upperLimit)
		{
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
	}while(a!='\n' || y<lowerLimit || y>upperLimit);
	return y;
	
}
int yes(void)  //to promt and ask user for exit function
{
	int z=0;
	char m;
	do{
		scanf("%c",&m);
		if(m=='Y' || m=='y')
		{
			z= 1;
		}
		else if(m=='N' || m=='n')
		{
			z=0;
		}	
		else if(m!='Y' && m!='y' && m!='N' && m!='n')
		{
			flushKeyboard();
			printf("Only (Y)es or (N)o are acceptable: ");
		}
	}while(m!='Y' && m!='y' && m!='N' && m!='n');
	return z;
}
int menu(void)  // to display the options
{
	
	int choice;
	
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	choice=getIntLimited(0,7); // to give limits in case of wrong choice
	return choice;
}
void GroceryInventorySystem(void)  // to accept choice and print accordingly
{
	int minput;
	int end=0;
	welcome();
	do{
		minput=menu();

		switch(minput)
		{
			case 1:
				printf("List Items under construction!\n");
				pause();
				break;
			case 2:
				printf("Search Items under construction!\n");
				pause();
				break;
			case 3:
				printf("Checkout Item under construction!\n");
				pause();
				break;
			case 4:
				printf("Stock Item under construction!\n");
				pause();
				break;
			case 5:
				printf("Add/Update Item under construction!\n");
				pause();
				break;
			case 6:
				printf("Delete Item under construction!\n");
				pause();
				break;
			case 7:
				printf("Search by name under construction!\n");
				pause();
				break;
			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				end=yes(); // call yes function to ask user if sure to exit
				break;
			
		}
	}while(end != 1);
}
