//library-library yang digunakan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


void menu();
void tampil_pegawai(); //prototype untuk membuat tampilkan data pegawai
void cari_pegawai();	//prototype untuk membuat cari data pegawai nantinya
void tambah_pegawai();	//prototype untuk membuat bagian tambah data pegawai
void hapus_pegawai();	//prototype untuk membuat bagian hapus data pegawai
void edit_pegawai();	//prototype untuk membuat bagian edit data pegawai
void close();           //prototype untuk program selesai

//struct yang berisi nama, umur,id,jk, gaji, bunus dan total dari gaji pegamai.
struct DATA {
	char nama[100];
	int umur,id;
	char jk[100];
	float gaji[100];
	float bonus [100];
	float total[100];

}tambah,cek,hapus,temp;

int main()
{
	{//membuat login password
	system("cls");
	char username[10];
    char password[10];

    LOGIN:
    printf("LOGIN:");
    printf("\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if((strcmp(username,"admin")== 0) && (strcmp(password,"root")== 0)){
        printf("Status: Login Berhasil");
    } else {
        printf("\nStatus: Username atau password salah\n\n");
        goto LOGIN;
    }
    menu();
	return 0;
}





	system("cls");
	menu();
	return 0;
}

//membuat menu pilihan
void menu(){ //fungsi utama
	int pilih;
	menu:
		system("cls");
		printf("Program CRUD data Pegawai Pabrik Makanan\n");
		printf("===========================================\n");
		printf("MENU :");
		printf("\n1 Tampil Data Pegawai");
		printf("\n2 Cari Data Pegawai");
		printf("\n3 Tambah Data Pegawai");
		printf("\n4 Hapus Data Pegawai");
		printf("\n5 Edit Data Pegawai");
		printf("\n6 Keluar");
		printf("\n===========================================");
		printf("\n\nPilih [1-6] : ");
		scanf("%d", &pilih);

		switch(pilih){
			case 1:tampil_pegawai();
				break;
			case 2:cari_pegawai();
				break;
			case 3:tambah_pegawai();
				break;
			case 4:hapus_pegawai();
				break;
			case 5:edit_pegawai();
				break;
			case 6:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");

		}
}
//prototype untuk menampilkan data
void tampil_pegawai()
{
	FILE *view;
	view = fopen("DATA/data.txt","r"); //membuka file text untuk dibaca yang berada dalam folder DATA
	int test=0;
	system ("cls"); //sistem untuk windows agar sistem pas compiler dimulai dari awal
	printf ("ID\t\tNAMA\t\tJK\t\tUMUR\t\tGAJI\t\tBONUS\t\tTOTAL\n");

	//kondisi untuk menampilkan data pegawai yang berada dalam pabrik makanan
	while (fscanf (view,"%d;%[^;];%[^;];%d;%f;%f;%f;\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.gaji[0],&tambah.bonus[1],&tambah.total[2])!=EOF)
	{
		printf("%d\t\t%s\t%s\t\t%d\t\t%f\t%f\t%f\t\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
		test++;
	}
	printf ("\nJumlah Data pegawai : %d",test);
	fclose(view);//menutup data file

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nTekan 1 untuk kembali ke menu utama dan 0 untuk keluar dari program : "); //tempat untuk user memilih angka berapa
    switch(getche()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
//prototype untuk mencaridata pegawai menggunakan id pegawai
void cari_pegawai()
{
	FILE *ptr;  //pointer untuk menunjuk kepada file
	int test=0;
	system("cls");
	ptr=fopen("DATA/data.txt","r");    //membuka data file yang berada dalam folder DATA
	system("cls");
	printf("Input ID Pegawai : ");  //tempat user memasukkan id pegawai yang ingin dicari
	scanf("%d", &cek.id);

	//kondisi untuk menambah data pegawai
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;%f;%f;%f;\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.gaji[0],&tambah.bonus[1],&tambah.total[2])!=EOF){
		if(tambah.id==cek.id){
			test=1;
			printf ("\nID\t\t: %d",tambah.id);
			printf("\nNama Pegawai\t: %s",tambah.nama);
			printf("\nJenis Kelamin\t: %s",tambah.jk);
			printf("\nUmur\t\t: %d",tambah.umur);
			printf("\nGaji Pokok\t: %.6f",tambah.gaji[0]);
			printf("\nBonus\t\t: %.6f",tambah.bonus[1]);
			printf("\nTotal\t\t: %.6f",tambah.total[2]);
		}
	}

	fclose(ptr); //menutup file
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData yang anda maksud tidak ada.\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :"); //tempat user untuk memilih angka berapa
        switch(getche()){
            case '0': cari_pegawai();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input.");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nTekan 1 untuk kembali ke menu utama dan 0 untuk keluar dari program :"); //tempat user untuk memilih angka
        switch(getche()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input.");
        		getche();
        		goto detail_valid;
       	}
    }

}
//prototype untuk tambah pegawai
void tambah_pegawai(){
	FILE *ptr,*ptr1; //pointer untuk menunjuk FILE
	int count=0;

	ptr =fopen("DATA/data.txt","a"); //membuka file yang ditunjuk oleh pointer ptr
		system("cls");
		ptr1 =fopen("DATA/data.txt","r");  //membuka file

		//kondisi untuk menambah data pegawai
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%f;%f;%f;\n",&tambah.id,&tambah.nama,&tambah.jk,&tambah.umur,&tambah.gaji[0],&tambah.bonus[1],&tambah.total[2])!=EOF)
		{
			tambah.id++;
		}
		fclose(ptr1);
		printf ("Masukan ID Pegawai : ");fflush(stdin);
		scanf ("%d",&tambah.id);
		printf ("Masukan Nama Pegawai : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("Masukan JK pegawai  : ");fflush(stdin);
		scanf ("%[^\n]",tambah.jk);
		printf ("Masukan Umur Pegawai : ");fflush(stdin);
		scanf ("%d",&tambah.umur);
		printf("Gaji Pokok\t     : ");
		scanf("%f",&tambah.gaji[0]);
		printf("Bonus\t\t: ");
		scanf("%f",&tambah.bonus[1]);
		tambah.total[2]=(tambah.gaji[0]+tambah.bonus[1]);

		fprintf(ptr,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
		fclose(ptr);

		printf("\n\nData Pegawai Sudah Disimpan.");
		add_invalid:
		printf("\n\n\tTekan 1 untuk kembali ke menu utama dan 0 untuk keluar dari program : "); //tempat user memilih angka

		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}
//prototype untuk hapus data pegawai
void hapus_pegawai()
{
	FILE *lama, *baru; //pointer untuk menunjuk FILE
	int test=0;
	lama = fopen("DATA/data.txt","r"); //buka file
	baru = fopen("DATA/new.txt","w"); //buka file baru
	system("cls");
	printf("Input No. ID Pegawai yang akan di hapus : "); //user memasukkan id pegawainya
	scanf("%d", &hapus.id);

	//kondisi untuk hapus pegawai
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.gaji[0],&tambah.bonus[1],&tambah.total[2])!=EOF)
	{
		if(tambah.id != hapus.id)
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
		}
		else{
			test++;
			printf("\nData Pegawai dengan No.ID : %d atas Nama : %s\n",tambah.id,tambah.nama);
			printf("Berhasil dihapus dari Daftar !");
		}
	}
	fclose(lama); //menutup file lama
	fclose(baru); //menutup file baru
	remove("DATA/data.txt");  //menghapus data
	rename("DATA/new.txt","DATA/data.txt"); //ubah nma data menjadi new
		if(test==0){
            printf("\nData Tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :"); //user untuk melilih angka mau lnjut atau tidak
			switch(getch()){
            	case '0': hapus_pegawai();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input.");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nTekan 1 untuk kembali ke menu utama dan 0 untuk keluar dari program :"); //tmpt user untuk memilih angka
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input.");
        		getche();
        		goto erase_valid;
        }
    }

}

//prototype untuk edit data pegawai
void edit_pegawai()
{
	FILE *lama,*baru, *gaji, *bonus; //pointer untuk menunjuk file
	int pilih,test=0;

	lama = fopen("DATA/data.txt","r"); //buka file lama
	baru = fopen ("DATA/new.txt","w");//buka file baru
	system("cls");

	printf ("Masukan ID pegawai : "); //user memasukkan id pegawai untuk diedit datanya
	scanf ("%d",&cek.id);

	//kondisi untuk edit data pegawai
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%f;%f;%f;\n",&tambah.id,tambah.nama,tambah.jk,&tambah.umur,&tambah.gaji[0],&tambah.bonus[1],&tambah.total[2])!=EOF)
	{
		if(tambah.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo.ID: %d dimiliki Pegawai dengan Nama: %s",tambah.id,tambah.nama); //datadata yang dpat diedit oleh user
				printf("\n\nData yang akan diganti : ");
				printf("\n1. Nama");
				printf("\n2. Jenis Kelamin");
				printf("\n3. Umur");
				printf("\n4. Gaji Pokok");
				printf("\n5. Bonus");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);

				//looping untuk melakukan edit data
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.nama);
					strcpy(tambah.nama,cek.nama);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Jenis Kelamin L/P : ");fflush(stdin);
					scanf ("%[^\n]",cek.jk);
					strcpy(tambah.jk,cek.jk);
						fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Umur Baru : ");
					scanf ("%d",&cek.umur);
					tambah.umur = cek.umur;
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
					printf ("\nPerubahan Sudah Disimpan !");
				}

                else if (pilih == 4)
				{
					printf ("\nMasukan Data Gaji Pokok Baru : ");
					scanf("%f",&cek.gaji[0]);
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
					printf ("\nPerubahan Sudah Disimpan !");
				}

                else if (pilih == 5)
				{
					printf ("\nMasukan Data Bonus Baru : ");
					scanf("%f",&cek.bonus[0]);
					fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
					printf ("\nPerubahan Sudah Disimpan !");
				}

				else{
					printf("\n\nMaaf Input Yang Anda Masukkan Salah.");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%d;%f;%f;%f;\n",tambah.id,tambah.nama,tambah.jk,tambah.umur,tambah.gaji[0],tambah.bonus[1],tambah.total[2]);
		}
	}

	fclose(lama); //menutup file lama
	fclose(baru); //menutup file baru
	remove("DATA/data.txt");    //menghapus data baru
	rename("DATA/new.txt","DATA/data.txt"); //mengubah nama datanya menjadi new.
	if(test!=1){
		system("cls");
        printf("\nData Tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_pegawai();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nTekan 1 untuk kembali ke menu utama dan 0 untuk keluar dari program :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

