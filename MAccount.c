#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "MAccount.h"

char db_name_account[20] = "db_akun.dat";
FILE *db_account;
int count_account = 0;
struct Account
{
	char email[32], name[32], username[32], password[32], phone[23];
	long int balance;
} account, accounts[];

void init()
{
	db_account = fopen(db_name_account, "rb+");
	while (fread(&account, sizeof(account), 1, db_account) == 1){
		count_account++;
		accounts[count_account] = account;
	}
	fclose(db_account);
}
struct Account getAll[]()
{
	init();
	return accounts;
}
