#include "User.h"

int menuUser;
void MainUser()
{
	system("cls");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("\t\t\t\t(D CONCERT) MENU USER");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("Menu D Concert :");
	puts ("1. Booking");
	puts ("2. Topup");
	puts ("3. Logout");
	printf ("\nPilihan	:");
	scanf("%d",&menuUser);
	getchar();
	system ("cls");
	switch (menuUser) {
//		case 1:
//			registrasi();
//			break;
//		case 2:
//			masuk_admin();
//			break;
		case 3:
			system("cls");
			printf("Anda akan logout dari sistem...");
			return;
			break;
		default :
			printf("ERROR!!!\nTidak ada menu yang kamu pilih.");
			break;
	}
}
