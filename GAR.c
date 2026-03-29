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

