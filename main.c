#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Auth.h"
#include "User.h"
#include "Admin.h"

int kesempatan=2;
char user[50], pass[50],adminU[20],adminP[20],cariA[30],cariB[30],cari[50],pilihanadmin[5];
struct type {
	char email[32], name[32], username[32], password[32], phone[23];
	long int balance;
} UserType;
//MENU MENU DALAM PROGRAM
void registrasi();
void login_user();
void masuk_admin();
void searching_user();

int menuawal;
void main () {
	system("cls");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("\t\t\t\tSELAMAT DATANG DI PROGRAM PEMESANAN KONSER MUSIK (D CONCERT)");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("Menu D Concert :");
	puts ("1. Login User");
	puts ("2. Login Admin");
	puts ("3. Registrasi Akun");
	puts ("4. Auth");
	puts ("5. Exit");
	printf ("\nPilihan	:");
	scanf("%d",&menuawal);
	getchar();
	system ("cls");
	switch (menuawal) {
		case 1:
			AuthLogin(3);
			getchar();
			main();
			break;
		case 2:
			masuk_admin();
			main();
			break;
		case 3:
			daftaruser();
			main();
			break;
		case 4:
			auth();
			main();
			break;
		case 5:
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
		MainAdmin();
	} else {
		printf("\nlogin gagal");
		getchar();
		system("cls");
		return;
	}

}

int menuAdmin;
void MainAdmin()
{
	system("cls");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("\t\t\t\t\t\t DASHBOARD MENU ADMIN (D CONCERT)");
	puts("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+");
	puts ("Menu D Concert :");
	puts ("1. Input Konser");
	puts ("2. List Konser");
	puts ("3. Tambah Konser");
	puts ("4. Update Seat");
	puts ("5. Searching User");
	puts ("6. Logout");
	printf ("\nPilihan	:");
	scanf("%d",&menuAdmin);
	getchar();
	system ("cls");
	switch (menuAdmin) {
//		case 1:
//			registrasi();
//			break;
		case 5:
		searching_user();
		break;
		case 6:
			return;
			system("cls");
			break;
		default :
			printf("ERROR!!!\nTidak ada menu yang kamu pilih.");
			break;
	}
}

void searching_user(){
	system("cls");
	
	FILE*akun;
 	printf("------LIST AKUN USER-----\n\n");
    int i = 1;
    akun = fopen("db_akun.dat", "rb");
    while (fread(&UserType, sizeof(UserType), 1, akun) == 1){
        printf("%d.\tEmail\t: %s\n", i, UserType.email);
        printf("\tNama\t: %s\n", UserType.name);
        printf("\tUsername\t: %s\n", UserType.username);
        printf("\tPassword: %s\n",UserType.password);
        printf("\tNo HP: %s\n",UserType.phone);
        UserType.balance = 0;
        i++;
    }
    
    printf("\nUsername yang dicari: ");
    scanf("%s", &cari);
    
    if(UserType.username==cari){
    printf("Akun ditemukan");
}
    else{
	printf("akun tidak ditemukan\n");
}
	fclose(akun);
	
	printf("\napakah ingin kembali ke menu utama?(y/t) :"); fflush(stdin); gets(pilihanadmin);
    if(strcmp(pilihanadmin,"y") ==0){
     return main();
     system("cls");
     
 }	else{
  	printf("logout berhasil");
 }
}
