#include "Admin.h"

int menuAdmin;
void MainAdmin()
{
	system("cls");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("\t\t\t\t(D CONCERT) MENU ADMIN");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("Menu D Concert :");
	puts ("1. Konser");
	puts ("2. Seat");
	puts ("3. Logout");
	printf ("\nPilihan	:");
	scanf("%d",&menuAdmin);
	getchar();
	system ("cls");
	switch (menuAdmin) {
//		case 1:
//			registrasi();
//			break;
//		case 2:
//			masuk_admin();
//			break;
		case 3:
			return;
			system("cls");
			break;
		default :
			printf("ERROR!!!\nTidak ada menu yang kamu pilih.");
			break;
	}
}
