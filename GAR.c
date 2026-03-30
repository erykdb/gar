#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
	char game[40];
	char email[30];
	char password[30];
}AccountsT;

void viewPasses(AccountsT* myArray, int arraySize);
void addPasses(AccountsT* myArray, int arraySize);

void main()
{
	AccountsT* accPass; 
	int i;
	int passAmount;
	int choice;

	printf("Please enter the size of the library\n");
	scanf("%d", &passAmount);

	accPass = (AccountsT*)malloc(passAmount * sizeof(AccountsT));

	if (accPass == NULL) 
	{
		printf("The memory could not be allocated\n");
		return;
	}

	printf("Please 1 to view email and password for a game\n");
	printf("Please 2 to add email and passowrd for a game\n");
	printf("Please -1 to exit\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
			viewPasses(accPass, passAmount);
		else if (choice == 2)
			addPasses(accPass, passAmount);

		printf("Please 1 to search for a book\n");
		printf("Please 2 to add for a book\n");
		printf("Please -1 to exit\n");
		scanf("%d", &choice);
	}

}

void viewPasses(AccountsT* myArray, int arraySize)
{

}

void addPasses(AccountsT* myArray, int arraySize)
{

}

