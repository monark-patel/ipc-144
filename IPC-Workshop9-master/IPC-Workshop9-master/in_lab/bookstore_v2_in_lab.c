
/* Name: Monark patel
  Student number: 135845162
  Email: mypatel2@myseneca.ca
  Workshop: 9
  Section:IPC144 SOO in lab
  Date:03/31/2017 
*/
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
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
int searchInventory(FILE *fp,const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[],const int isbn2find);

int main()
{
   //Type your code here:
    int choice;
	int isbn;
   // FILE *pf; 
	float capitalTotal;
	struct Book mybook;
	char filename[] = "144_w9_inventory.txt"; //Name of the file
    printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do
	{
		menu(); // to call menu function for working on choices
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:
				displayInventory(filename); // call displayInventory function
				break;
			case 2:
				//addBook(); // call addBook function
				break;
			case 3:
				//checkPrice();
				break;
			case 4:
				capitalTotal = calculateCapital(filename);
				printf("The total capital is: $%.2f.\n",capitalTotal);
				break;
			case 0:// exit the program
				printf("Goodbye!\n");
				break;
			default:
				printf("Invalid input, try again:\n");
				break;
	        }
		
	}while(choice != 0);
	
	return 0;
}

void menu()
{
	//display options
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n");
	printf("\n");
	printf("Select: ");
}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
	struct Book book;
    int i = 0;
    
    //Open the file, and check for null pointer
    FILE *fp = fopen(filename,"r");
    
    //If the file is properly opened, display headers, similar to workshop 8
	if(fp!= NULL)
	{
	//Use a while loop to call readRecord and display the records.
	    printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		while(readRecord(fp,&book)!=-1)
		{
			//readRecord(fp,&book);/*call readRecord and check its return value*/
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book._isbn, book._title, book._year, book._price, book._qty);
		}
		printf("===================================================\n\n");
	}
    //Display the footer
    
    //Close the file
	fclose(fp);
}

/*void addBook(const char filename[], struct Book *b2Add)
{
 //Not implemented!
}

void checkPrice(const char filename[],const int isbn2find)
{
    
 //Not implemented!

 
}

int searchInventory(FILE *fp,const int isbn2find)
{
	//Not implemented!
}
*/
float calculateCapital(const char filename[])
{
    
    
    //Define an object of struct Book
    struct Book book;
	int j = 0;
    //Define and initialize total_capital
    float total_capital=0;
    
    //Open the file, and check for null pointer
    FILE *fp = fopen(filename, "r");
    
    //If the file is properly opened, use a while loop to call readRecord
	if (fp != NULL)
	{
        for(j=0;j<3;j++)
	    {
			readRecord(fp,&book);/*call readRecord and check its return value*/
			total_capital = total_capital + (book._price * book._qty);
			//Accumulate the multiplication of the price of each item to its quantity
		}
	}
    //Display the footer
       
    //Close the file
        fclose(fp);
    //return the total_capital
	return total_capital;
    
}

int readRecord(FILE *fp, struct Book *b2read){
	char r;
	
	fscanf(fp,"%d %c",&(*b2read)._isbn, &r);
	if(r==';')
	{
		fscanf(fp,"%f %c", &(*b2read)._price, &r);
	}
	if(r==';')
	{
		fscanf(fp,"%d %c",&(*b2read)._year, &r);
	}
	if(r==';')
	{
		fscanf(fp,"%d %c",&(*b2read)._qty, &r);
	}
	if(r==';')
	{
		fscanf(fp,"%[^\n]",(*b2read)._title);
	}
	return 0;
}     