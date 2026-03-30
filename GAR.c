#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int isEmpty;
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

	printf("Please enter the size of the library:\n");
	scanf("%d", &passAmount);

	accPass = (AccountsT*)malloc(passAmount * sizeof(AccountsT));

	if (accPass == NULL)
	{
		printf("The memory could not be allocated\n");
		return;
	}

	for (i = 0; i < passAmount; i++)
	{
		(accPass + i)->isEmpty = 0;
	}

	printf("\nPlease 1 to view email and password for a game\n");
	printf("Please 2 to add email and passowrd for a game\n");
	printf("Please -1 to exit\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
			viewPasses(accPass, passAmount);
		else if (choice == 2)
			addPasses(accPass, passAmount);

		printf("\nPlease 1 to view email and password for a game\n");
		printf("Please 2 to add email and passowrd for a game\n");
		printf("Please -1 to exit\n");
		scanf("%d", &choice);
	}

}

void viewPasses(AccountsT* myArray, int arraySize)
{
	int i;
	char searchGame[40];
	int gameFound = 0;

	printf("\nPlease enter the game you are looking for(use _ as spaces between the words)\n");
	scanf("%s", &searchGame);

	for (i = 0; i < arraySize; i++)
	{
		if ((myArray + i)->isEmpty == 1)
		{
			if (strcmp((myArray + i)->game, searchGame) == 0)
			{
				printf("\nGame Found!\n");
				printf("game: %s\n", (myArray + i)->game);
				printf("email: %s\n", (myArray + i)->email);
				printf("password: %s\n", (myArray + i)->password);
				gameFound = 1;
				return;
			}

		}
		else if ((myArray + i)->isEmpty)
		{
			printf("There is no games added, please try adding some games first\n");
			return;
		}

		if (!gameFound)
		{
			printf("Game not found.\n");
			return;
		}
	}

}

void addPasses(AccountsT* myArray, int arraySize)
{
	int i;

	for (i = 0; i < arraySize; i++)
	{
		if ((myArray + i)->isEmpty == 0)
		{
			printf("\nEnter the name of the game:\n");
			scanf("%s", (myArray + i)->game);

			printf("Enter the email for that game:\n");
			scanf("%s", (myArray + i)->email);

			printf("Enter the password for that game:\n");
			scanf("%s", (myArray + i)->password);

			(myArray + i)->isEmpty = 1;
			return;
		}
	}
	printf("Your Details have been allocated!\n");
}

