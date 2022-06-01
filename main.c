#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "User.h"
#include "Admin.h"

int kesempatan=2;
char user[50], pass[50],adminU[20],adminP[20],cariA[30],cariB[30];

//MENU MENU DALAM PROGRAM
void registrasi();
void login_user();
void masuk_admin();

int menuawal;
void main () {
	system("cls");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("\t\t\t\tSELAMAT DATANG DI PROGRAM PEMESANAN KONSER MUSIK (D CONCERT)");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("Menu D Concert :");
	puts ("1. User");
	puts ("2. Admin");
	puts ("3. Exit");
	printf ("\nPilihan	:");
	scanf("%d",&menuawal);
	getchar();
	system ("cls");
	switch (menuawal) {
		case 1:
//			registrasi();
			MainUser();
			main();
			break;
		case 2:
//			masuk_admin();
			MainAdmin();
			main();
			break;
		case 3:
			return;
			system("cls");
			break;
		default :
			printf("ERROR!!!\nTidak ada menu yang kamu pilih.");
			break;
	}
}
void registrasi () {
	system("cls");
	puts("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++");
	puts("\t\t\t\t\t\t  REGISTRASI AKUN ");
	puts("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++");
	printf ("\nUsername\t : ");
	gets(user);
	printf ("Password\t : ");
	gets(pass);
	printf("\nRegistrasi Sukses!");
	getchar();
	system("cls");
	kesempatan=3;
	login_user();
}

void login_user() {
	system("cls");
	puts("\t\t\t\t\t========================================");
	puts("\t\t\t\t\t\t    LOGIN AKUN USER");
	puts("\t\t\t\t\t========================================");

	if (kesempatan>0) {
		printf("Kesempatan login kamu %d kali",kesempatan);
	}

	printf ("\nUsername\t : ");
	gets(cariA);
	printf ("Password\t : ");
	gets(cariB);
	if (kesempatan>1) {
		if (strcmp(user,cariA)==0&&strcmp(pass,cariB)==0) {
			printf("\nLogin sukses\n");
			printf("Lanjutkan");
			getchar();
		}
		if (strcmp(user,cariA)!= 0 || strcmp(pass,cariB)!= 0) {
			system("cls");
			printf("Login Gagal\n");
			kesempatan--;
			login_user();
		}
	} else {
		system("cls");
		printf("Kesempatan login habis. Silahkan registrasi akun ulang!");
		getchar();
		main();
	}
}


//MENU MENU ADMIN


void masuk_admin() {

	puts("\t\t\t\t\t================================");
	puts ("\t\t\t\t\t\t  LOGIN ADMIN");
	puts("\t\t\t\t\t================================");
	printf ("\nUsername\t : ");
	gets(adminU);
	printf ("Password\t : ");
	gets(adminP);
	if (strcmp(adminU,"admin")==0&&strcmp(adminP,"admin")==0) {
		printf("\nLogin sukses");
		getchar();
		system("cls");
	} else {
		printf("\nlogin gagal");
		getchar();
		system("cls");
		main();
	}

}
