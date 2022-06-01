#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include "Auth.h"
#include "User.h"
//prototype fungsi
struct type {
	char email[32], name[32], username[32], password[32], phone[23];
	long int balance;
} UserType;
char email[50],pass[20],pilihan[50];
int menu,n,i,a;
char db_akun[20] = "db_akun.dat";

//fungsi
void loginadmin();
void loginuser();
void menuadmin();
void menuuser();
void loginuser();
int generateotp();
void forgetpw();
void daftaruser();

void auth() {
	system("cls");
	a=3;
	system("cls");
	printf("\n");
	printf("\t\t\t\tD'CONCERT'\t\t\n");
	printf("\n1. Admin\n");
	printf("2. User\n");
	printf("3. Exit\n");
	printf("\nPilih Menu: ");
	scanf("%d",&menu);
	system("cls");

	switch(menu) {
		case 1:
			loginadmin();
			break;

		case 2:
			loginuser();
			break;
		case 3:
			return;
			break;

		default:
			break;
	}
}
void loginadmin() {
	if(a>0) {
		printf("Email: ");
		fflush(stdin);
		gets(email);
		printf("Password: ");
		gets(pass);
		if(strcmp(email,"admin")==0 && strcmp(pass,"kece")==0) {
			printf("Login berhasil\n");

			menuadmin();
		} else {
			printf("Login gagal\n");
			getchar();
			system("cls");
			a--;
			return loginadmin();
		}
	} else {
		printf("kesempatan habis");
		getchar();
		system("cls");

		return auth();
	}
}
void menuadmin() {
	char cari[16];
	system("cls");

	FILE*akun;
	printf("------LIST AKUN-----\n\n");
	int i = 1;
	akun = fopen(db_akun, "rb");
	while (fread(&UserType, sizeof(UserType), 1, akun) == 1) {
		printf("%d.\tEmail\t: %s\n", i, UserType.email);
		printf("\tNama: %s\n",UserType.name);
		printf("\tUsername: %s\n",UserType.username);
		printf("\tPassword: %s\n",UserType.password);
		printf("\tNo. HP: %s\n",UserType.phone);
		printf("\tSaldo: %ld Rp\n",UserType.balance);
		i++;
	}

	printf("\nNo. HP yang dicari: ");
	scanf("%s", &cari);

// pencarian based on username
	if(strcmp(UserType.phone,cari)==0) {
		printf("\nAkun %s dengan No. HP %s, email %s dengan password %s\n", UserType.name, UserType.phone, UserType.email, UserType.password);
	} else {
		printf("akun dengan No. HP %s tidak ditemukan\n", cari);
	}
	fclose(akun);

	printf("\napakah ingin kembali ke menu utama?(y/t) :");
	fflush(stdin);
	gets(pilihan);
	if(strcmp(pilihan,"y") ==0) {
		return auth();
		system("cls");
	}	else {
		printf("logout berhasil");
	}
}
void AuthLogin(int try) {
	char username[32], password[32];
	system("cls");
	if (try>0) {
			FILE*akun;
			if (try>0) {
					printf("Kesempatan login anda %d kali",try);
				}
			printf("\nUsername: ");
			scanf("%s", &username);
			printf("\nPassword: ");
			scanf("%s", &password);


			int i = 1;
			akun = fopen(db_akun, "rb");
			while (fread(&UserType, sizeof(UserType), 1, akun) == 1) {
				i++;
			}
			if(strcmp(UserType.username,username)==0 && strcmp(UserType.password,password)==0) {
				MainUser();
//		printf("\nAkun %s dengan No. HP %s, email %s dengan password %s\n", UserType.name, UserType.phone, UserType.email, UserType.password);
			} else {
				AuthLogin(try - 1);
//				printf("akun dengan No. HP %s tidak ditemukan\n", cari);
			}
			fclose(akun);
		}
	else {
		system("cls");
		printf("Kesempatan login anda habis.");
		getchar();
//		return;
	}
}
void loginuser() {
	if(a>0) {
		printf("Email: ");
		fflush(stdin);
		gets(email);
		printf("Password: ");
		gets(pass);
		if(strcmp(email,"pasti")==0 && strcmp(pass,"bisa")==0) {
			printf("Login berhasil\n");

			menuuser();
		} else {
			printf("Login gagal\n");
			getchar();
			system("cls");
			a--;
			return loginuser();
		}
	} else {
		printf("kesempatan habis");
		getchar();
		system("cls");

		return auth();
	}
}
void menuuser() {
	int pilihan;
	system("cls");
	printf("\t\tMENU USER\t\t\n");
	printf("\n1. Registrasi Akun\n");
	printf("2. Login Akun\n");
	printf("Pilih Menu: ");
	scanf("%d",&pilihan);

	switch(pilihan) {
		case 1:
			daftaruser();
			break;

		case 2:
			forgetpw();
			break;

		default:
			break;
	}


}
void daftaruser() {
	system("cls");

	puts("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++");
	puts("\t\t\t\t\t\t  REGISTRASI AKUN ");
	puts("\t\t\t\t\t++++++++++++++++++++++++++++++++++++++");

	FILE *akun;
	akun = fopen(db_akun, "ab");
//	printf("Banyak akun yang akan didaftarkan: ");
//	scanf("%d", &n);
//	getchar();
//	for (i = 1; i <= n; i++) {
	printf("\tEmail\t: ");
	fflush(stdin);
	gets(UserType.email);
	printf("\tName: ");
	gets(UserType.name);
	printf("\tUserame: ");
	gets(UserType.username);
	printf("\tPassword: ");
	gets(UserType.password);
	printf("\tNo. HP: ");
	gets(UserType.phone);
	UserType.balance = 0;
	fwrite (&UserType, sizeof (UserType), 1, akun);
//	}
	printf("Pendaftaran akun berhasil\n");
	fclose(akun);
	printf("\nTekan enter untuk kembali");
	fflush(stdin);
	gets(pilihan);
	return;
//	if(strcmp(pilihan,"y") ==0) {
//		return auth();
//	}	else {
//		printf("logout berhasil");
//	}
}
void forgetpw() {
	int votp, otp = generateotp();
	FILE *akun;
	system("cls");
	akun = fopen(db_akun, "rb");

	while (fread(&UserType, sizeof(UserType), 1, akun) == 1) {
		printf("Untuk memverifikasi keaslian pengguna silahkan masukkan kode OTP yang dikirimkan ke nomor %ld.\n\t\t\tKode otp: %d\n", UserType.phone, otp);
		printf("Masukkan Kode OTP: ");
		scanf("%d", &votp);
		if(votp == otp) {
			printf("OTP anda benar\n");
		} else {
			printf("OTP yang anda masukkan salah\n");
			system("pause");
			return forgetpw();
			i++;
		}
	}
	fclose(akun);
	printf("\napakah ingin kembali ke menu utama?(y/t) :");
	fflush(stdin);
	gets(pilihan);
	if(strcmp(pilihan,"y") ==0) {
		return auth();
	}	else {
		printf("logout berhasil");
	}
}
int generateotp() {
	int otp;
	srand(time(NULL));
	otp = (rand() % (999999 - 100000 + 1)) + 100000;
	return otp;
}
