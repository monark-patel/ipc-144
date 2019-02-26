
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
int searchInventory(const struct Book book[],const int isbn,const int size);
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
				displayInventory(book,size); // call displayInventory function
				break;
			case 2:
				addBook(book,&size); // call addBook function
				break;
			case 3:
				checkPrice(book,size);
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
// to search the book
int searchInventory(const struct Book book[], const int isbn, const int size)
{
	int i;
	int j=-1;
	for(i=0;i<size;i++)//loop to search isbn number
	{
		if(book[i].isbn==isbn)
		{
			j=0;// if isbn found return j as 0  
			break;
		}
	}
	return j; //return j 
}

// function to add a book
void addBook(struct Book book[], int *size)
{
	int i;
	int j;
    printf("ISBN:");
	scanf("%d",&book[*size].isbn); // to get book isbn 
	i=book[*size].isbn; // to assign book isbn to a variable
	printf("Quantity:");
	scanf("%d",&book[*size].qty);  // to get book quantity
	j=searchInventory(book,i,(*size)); //to call function searchInventory for same isbn 
	if(j!=-1)//if isbn is present then add new quantity 
	{
		book[j].qty = book[*size].qty+book[j].qty;
		printf("The book exists in the repository, quantity is updated.\n\n");
	}
	else // if isbn number is absent
	{
		if(*size==MAX_BOOKS) //  if inventory is full
		{
			printf("The inventory is full\n");
		}
		else 
		{
			printf("Title:");
			scanf(" %[^\n]",book[*size].title);	// add title as a string
			printf("Year:");
			scanf("%d",&book[*size].year); //add year
			printf("Price:");
			scanf("%f",&book[*size].price);// add price
			printf("The book is successfully added to the inventory.\n");
			printf("\n");
			(*size)++;// increment size by 1
		}
	}
}
// to check price of a book
void checkPrice(const struct Book book[], const int size)
{
	int i;
	int j;
	printf("Please input the ISBN number of the book:\n");
	printf("\n");
	scanf("%d",&i); // to enter isbn number of a book 
	j=searchInventory(book,i,size); // to call function searchInventory 
	if (j!=-1) // if isbn is found then print its information
	{
		printf("Book %d costs $%.2f\n\n",book[j].isbn,book[j].price);
	}
	else // if isbn not found then print valid massage
	{
		printf("Book does not exist in the bookstore! Please try again.\n");
		printf("\n");
	}
}
