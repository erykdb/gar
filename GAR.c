#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//libraries needed to run the code

typedef struct//struct for data that will be saved in a file
{
	int isEmpty;
	char game[40];
	char email[30];
	char password[30];
}AccountsT;
//introducing all of the functions so that they can work afterwards since C reads code from top to bottom
void viewPasses(AccountsT* myArray, int arraySize);
void addPasses(AccountsT* myArray, int arraySize);
void saveDataToFile(AccountsT* myArray, int arraySize);
void appendDataToFile(AccountsT* myArray, int arraySize);
void deleteDataFromFile(AccountsT* myArray, int arraySize);

void main() 
{
	//introducing variables for main function
	AccountsT* accPass;
	FILE* fp;
	int i;
	int passAmount;
	int choice;
	
	//user input for the amount of accounts they want to save
	printf("Please enter the size of the library:\n");
	scanf("%d", &passAmount);

	accPass = (AccountsT*)malloc(passAmount * sizeof(AccountsT));

	if (accPass == NULL)//checks if you can acctually allocate said memory or no
	{
		printf("The memory could not be allocated\n");
		return;
	}

	for (i = 0; i < passAmount; i++)// gives every struct an ID of 0, so that I can find them and verify them as empty structs
	{
		(accPass + i)->isEmpty = 0;
	}

	//this is the menu of the app, here you have printf's and a while loop, to add, show, save or delete data as you wish
	printf("\nPlease write 1 to view email and password for a game\n");
	printf("Please write 2 to add email and passowrd for a game\n");
	printf("Please write 3 to save your local data to a file\n");
	printf("Please write 4 to append your local data to a file\n");
	printf("Please write 5 to delete currently stored data in a file\n");
	printf("Please write -1 to exit\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
			viewPasses(accPass, passAmount);
		else if (choice == 2)
			addPasses(accPass, passAmount);
		else if (choice == 3)
			saveDataToFile(accPass, passAmount);
		else if (choice == 4)
			appendDataToFile(accPass, passAmount);
		else if (choice == 5)
			deleteDataFromFile(accPass, passAmount);

		printf("\nPlease write 1 to view email and password for a game\n");
		printf("Please write 2 to add email and passowrd for a game\n");
		printf("Please write 3 to save your local data to a file\n");
		printf("Please write 4 to append your local data to a file\n");
		printf("Please write 5 to delete currently stored data in a file\n");
		printf("Please write -1 to exit\n");
		scanf("%d", &choice);
	}

}

/*
* This is a viewPasses() function that shows you login and password  
* of any locally written games and their details.
*/
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
	}

	if (!gameFound)
	{
		printf("Game not found.\n");
		return;
	}
}

/*
* This is a addPasses() function, which adds locally 
* games and their details which the user would have entered.
*/
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

/*
* This is saveDataToFile() function, which as the name suggests
* creates a new file, including writing over any old user data,
* and saves any locally written data in accounts.txt file.
*/
void saveDataToFile(AccountsT* myArray, int arraySize)
{
	FILE* fp;
	int i;

	fp = fopen("accounts.txt", "w");

	for (i = 0; i < arraySize; i++)
	{
		if ((myArray + i)->isEmpty == 1)
		{

			fprintf(fp, "%s %s %s\n", (myArray + i)->game, (myArray + i)->email, (myArray + i)->password);

		}
	}
	fclose(fp);
	printf("Data successfully saved to accounts.txt!\n");
}

/*
* This is appendDataToFile and it works similarly to saveDataToFile() function,
* but instead of writing over old file, it appends meaning that it adds data
* instead of creating new data.
*/
void appendDataToFile(AccountsT* myArray, int arraySize)
{
	FILE* fp;
	int i;

	fp = fopen("accounts.txt", "a");

	for (i = 0; i < arraySize; i++)
	{
		if ((myArray + i)->isEmpty == 1)
		{

			fprintf(fp, "%s %s %s\n", (myArray + i)->game, (myArray + i)->email, (myArray + i)->password);

		}
	}
	fclose(fp);
	printf("Data successfully appended to accounts.txt!\n");
}

/*
* This simple little function called deletaDataFromFile() opens a file in write mode
* which deletes all previous data and because it doesn't add anything, leaves it empty.
*/
void deleteDataFromFile(AccountsT* myArray, int arraySize)
{
	FILE* fp;

	fp = fopen("accounts.txt", "w");

	fclose(fp);

	printf("Data successfully deleted from accounts.txt!\n");
}

