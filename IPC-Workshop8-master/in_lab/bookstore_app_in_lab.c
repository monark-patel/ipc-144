/*
Name:Monark Patel 
Student number:
Email:mypatel2@myseneca.ca
Workshop:8
Section:in lab
Date:
*/
#include <stdio.h>
#define MAX_BOOKS 10   //declare book size of 10 
#define MAX_TITLE_SIZE 20     //declare book name size of 20 characters



struct Book //struct to represent inventory of books
{
    int isbn;
    float price;
    int year;
    char title[MAX_TITLE_SIZE];
    int qty;
};
void menu();
void displayInventory(const struct Book book[],const int size);
void searchInventory(const struct Book book[],const int isbn,const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[],const int size);
int main(void)
{
	struct Book book[MAX_BOOKS];//An array of Book representing the inventory
	int size =0;; //Number of books in the inventory. The inventory is initially empty.
	int choice;
	printf("Welcome to the Book Store\n");
	printf("=========================\n");
	do
	{
		menu(); // to call menu function for working on choices
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:
				displayInventory(book, size); // call displayInventory function
				break;
			case 2:
				addBook(book, &size); // call addBook function
				break;
			case 3:
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
	printf("0) Exit.\n");
	printf("\n");
	printf("Select: ");

}
// function to disllpay inventory
void displayInventory(const struct Book book[],const int size)
{
	int i;
	if(size==0) //print if inventory is empty
	{
		printf("The inventory is empty!\n");
		printf("===================================================\n");
		printf("\n");
	}
	else // to print the inventory 
	{
		printf("\n");
		printf("\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for(i=0;i<size;i++) // loop to add the information in system
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book[i].isbn,book[i].title,book[i].year,book[i].price,book[i].qty);
		}
		printf("===================================================\n");
		printf("\n");
	}
	
}
// function to add a book
void addBook(struct Book book[], int *size)
{
	if(*size==MAX_BOOKS) //  if inventory is full
	{
		printf("The inventory is full\n");
	}
	else 
	{
		printf("ISBN:");
		scanf("%d",&book[*size].isbn); //add book isbn
		printf("Title:");
		scanf(" %[^\n]",book[*size].title);	// add title as a string
		printf("Year:");
		scanf("%d",&book[*size].year); //add year
		printf("Price:");
		scanf("%f",&book[*size].price);// add price
		printf("Quantity:");
		scanf("%d",&book[*size].qty);// add quantity
		printf("The book is successfully added to the inventory.\n");
		printf("\n");
		(*size)++;// increment size by 1
	}
}
