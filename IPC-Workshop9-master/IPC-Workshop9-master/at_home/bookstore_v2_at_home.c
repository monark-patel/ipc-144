/* Name: Monark patel
 Student number: 135845162
 Email: mypatel2@myseneca.ca
 Workshop: 9
 Section:IPC144 SOO at home
 Date:4/06/2017
 */
#include <stdio.h>
#define MAX_BOOKS 10   //declare book size of 10
#define MAX_TITLE_SIZE 20     //declare book name size of 20 characters

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
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);

int main() {
	struct Book book; //An array of Book representing the inventory

	int size = 0;
	; //Number of books in the inventory. The inventory is initially empty.

	//Type your code here:
	int choice;
	// FILE *pf;
	float capitalTotal;
	int isbn;
//	struct Book mybook;
	char filename[] = "144_w9_inventory.txt"; //Name of the file
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do {
		menu(); // to call menu function for working on choices
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			displayInventory(filename); // call displayInventory function
			break;
		case 2:
			addBook(filename, &book); // call addBook function
			break;
		case 3:
			checkPrice(filename, isbn); // call checkPrice function
			break;
		case 4:
			capitalTotal = calculateCapital(filename); //call calculatecapital function
			printf("The total capital is: $%.2f.\n", capitalTotal);
			break;
		case 0: // exit the program
			printf("Goodbye!\n");
			break;
		default: // default error for invalid input
			printf("Invalid input, try again:\n");
			break;
		}

	} while (choice != 0);// to terminate when user wants to exit 

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
	FILE *fp = fopen(filename, "r");

	//If the file is properly opened, display headers, similar to workshop 8
	if (fp != NULL) 
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

void addBook(const char filename[], struct Book *b2Add) {
	//Open the file, and check for null pointer
	FILE *fp = fopen(filename, "r");
	printf("ISBN:");
	scanf("%d", &b2Add->_isbn);  // add isbn number of the book
	printf("Title:");
	scanf(" %[^\n]", b2Add->_title);	// add title as a string
	printf("Year:");
	scanf("%d", &b2Add->_year); //add year
	printf("Price:");
	scanf("%f", &b2Add->_price); // add price
	printf("Quantity:");
	scanf("%d", &b2Add->_qty);  // to get book quantity

	int index = searchInventory(fp, b2Add->_isbn); // call search inventory using isbn 
	if (index!=-1)  // if isbn matches 
	{
		printf("The book exists in the repository!\n");
		printf("\n");
	} 
	else // if isbn doesnt match
	{
		fp = fopen(filename, "a+"); // to append the file as well as read at same time 
		printf("The book is successfully added to the inventory.\n");
		printf("\n");
		fprintf(fp, "\n%d;%f;%d;%d;%s", b2Add->_isbn, b2Add->_price,b2Add->_year, b2Add->_qty, b2Add->_title); // print the data in the source file
	}
	fclose(fp);
}

void checkPrice(const char filename[], const int isbn2find) 
{
	int i;
	struct Book book;
	FILE *fp = fopen(filename, "r"); // open the source file to read 
	int j;
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &isbn2find); // to enter isbn number of a book
	int index = searchInventory(fp, isbn2find); // use isbn to search if book is present 
	if (index!=-1) 
	{
		fp = fopen(filename, "r"); 
		for (j = 0; j < index; j++)// to use index to find the file by calling readRecord  
		{
			readRecord(fp, &book);
		}
		printf("Book %d costs $%.2f\n\n", book._isbn, book._price);
	} 
	else // print if book is not there
	{
		printf("The book doesn't exists in the repository!\n");
	}
	fclose(fp);
}

int searchInventory(FILE *fp, const int isbn2find) 
{
	struct Book book;
	int j = 0;
	int index = 1;
	while (readRecord(fp, &book)!=-1) // call readRecord function to read from file
	{
		if (book._isbn == isbn2find)  
		{
			//fclose(fp);
			return index; // if isbn is found return 1 
		}
		index++;
	}
	//fclose(fp);
	return -1;   // else if not found return -1
}
float calculateCapital(const char filename[]) 
{

	//Define an object of struct Book
	struct Book book;
	int j = 0;
	//Define and initialize total_capital
	float total_capital = 0;

	//Open the file, and check for null pointer
	FILE *fp = fopen(filename, "r");

	//If the file is properly opened, use a while loop to call readRecord
	if (fp != NULL) 
	{
		for (j = 0; j < 5; j++) 
		{
			readRecord(fp, &book);/*call readRecord and check its return value*/
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

int readRecord(FILE *fp, struct Book *b2read)
{
    int rv=0;
    rv = fscanf(fp, "%d;%f;%d;%d;%[^\n]\n", &b2read->_isbn,&b2read->_price,&b2read->_year,&b2read->_qty,b2read->_title);
   return rv;
}