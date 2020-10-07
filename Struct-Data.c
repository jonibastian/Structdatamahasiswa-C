#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa{
	char nama[50];
	char npm[12];
	char alamat[50];
	char email[50];
	char nohp[15];
	char doswal[50];
	char smt[5];
	
};
typedef struct mahasiswa mhs;
mhs data_mhs[]={
		{"Joni Bastian", 
		"19081010071", 
		"Jl. Sunaryo KM. 04", 
		"19081010071@student.upnjatim.ac.id" ,
		"082284664698", 
		"Made Hanindia Prami Swari", 
		"3"}
	};	
	
int data=0;

void insert(char nama[50],
			char npm[12],
			char alamat[50], 
			char email[30], 
			char nohp[15], 
			char doswal[50], 
			char smt[5]){
	
	strcpy(data_mhs[data].nama, nama);
	strcpy(data_mhs[data].npm, npm);
	strcpy(data_mhs[data].alamat, alamat);
	strcpy(data_mhs[data].email, email);
	strcpy(data_mhs[data].nohp, nohp);
	strcpy(data_mhs[data].doswal, doswal);
	strcpy(data_mhs[data].smt, smt);
	data++;
}

void update(int nomor,
			char nama[50],
			char npm[12],
			char alamat[50], 
			char email[30], 
			char nohp[15], 
			char doswal[50], 
			char smt[5]){
	
	strcpy(data_mhs[nomor].nama, nama);
	strcpy(data_mhs[nomor].npm, npm);
	strcpy(data_mhs[nomor].alamat, alamat);
	strcpy(data_mhs[nomor].email, email);
	strcpy(data_mhs[nomor].nohp, nohp);
	strcpy(data_mhs[nomor].doswal, doswal);
	strcpy(data_mhs[nomor].smt, smt);
}

void delete(int nomor){
	
	int i=0;
	for(i=0;i<data;i++){
		if(i==nomor){
			int y=0;
			for(y=i;y<data-1;y++){
				data_mhs[y]=data_mhs[y+1];
			}
			data--;
			break;
		}
	}
}

void view(){
	
	int i;
	if(data>0){
		
		for(i=0;i<data;i++){
			printf("Mahasiswa ke \t\t: %d\n",i+1);
			printf("Nama \t\t\t: %s\n",data_mhs[i].nama);	
			printf("NPM \t\t\t: %s\n",data_mhs[i].npm);
			printf("Alamat \t\t\t: %s\n",data_mhs[i].alamat);
			printf("Email \t\t\t: %s\n",data_mhs[i].email);
			printf("Nomor HP\t\t: %s\n",data_mhs[i].nohp);
			printf("Dosen Wali \t\t: %s\n",data_mhs[i].doswal);
			printf("Semester \t\t: %s\n\n",data_mhs[i].smt);
		}
	}else{
		printf("TIDAK ADA DATA\n");
	}
}


int main() {
	
	data = sizeof(data_mhs)/sizeof(data_mhs[0]);
	int i=0;
	int pilih=0;
	char nama[50],npm[12],alamat[50],email[30],nohp[15],doswal[30],smt[5];
	awal:
	
	printf("*********************************************************************\n");
	printf("=========================== Data Mahasiswa ==========================\n");
	printf("*********************************************************************\n");
	printf("List Data Mahasiswa saat ini: \n\n");
	view();
	printf("Menu :\n1. Insert Data\n2. Update Data\n3. Delete Data\n\nPilih menu : ");
	scanf("%d",&pilih);
	
	if(pilih==1){
		printf("\nNama : ");
		scanf(" %[^\n]s",&nama);
		printf("NPM : ");
		scanf("%s",&npm);
		printf("Alamat : ");
		scanf(" %[^\n]s",&alamat);
		printf("Email : ");
		scanf("%s",&email);
		printf("Nomor HP : ");
		scanf("%s",&nohp);
		printf("Dosen Wali : ");
		scanf(" %[^\n]s",&doswal);
		printf("Semester : ");
		scanf("%s",&smt);
		insert(nama, npm, alamat, email, nohp, doswal, smt);
		system("cls");
		goto awal;	
		
	}else if(pilih==2){
		int no=-1;
		printf("Masukkan nomor data yang akan diedit : ");
		input_edit:
		scanf("%d",&no);
		
		if(no>data){
			printf("Data dengan nomor %d tidak ditemukan, mohon masukkan kembali : ");
			goto input_edit;
		}else{
			printf("Nama : ");
			scanf("%s",&nama);
			printf("NPM : ");
			scanf(" %[^\n]s",&npm);
			printf("Alamat : ");
			scanf("%s",&alamat);
			printf("Email : ");
			scanf("%s",&email);
			printf("Nomor HP : ");
			scanf("%s",&nohp);
			printf("Dosen Wali : ");
			scanf("%s",&doswal);
			printf("Semester : ");
			scanf("%s",&smt);
			update(no-1, nama, npm, alamat, email, nohp, doswal, smt);
			system("cls");
			goto awal;
		}
		
	}else if(pilih==3){
		int no=-1;
		printf("Masukkan nomor data yang akan dihapus : ");
		input_delete:
		scanf("%d",&no);
		if(no>data){
			printf("Data dengan nomor %d tidak ditemukan, mohon masukkan kembali : ");
			goto input_delete;
		}else{
			delete(no-1);
			system("cls");
			goto awal;
		}
		
	}else{
		printf("Inputan Anda Invalid.");
	}
	
	return 0;
}
