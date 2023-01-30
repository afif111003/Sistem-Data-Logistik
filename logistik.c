#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAMA_LENGTH 100
#define MAX_KODE_LENGTH 10
#define MAX_BENDA_LENGTH 100
#define MAX_LETAK_LENGTH 100
#define MAX_PINJAM_LENGTH 100

typedef struct
{
   char nama[MAX_NAMA_LENGTH];
   char kode[MAX_KODE_LENGTH];
   char benda[MAX_BENDA_LENGTH];
   char letak[MAX_LETAK_LENGTH];
   int stok;
   int nim;
}Logistik;

void add(Logistik x[],int JumlahSemua){
    for(int a = 0; a < JumlahSemua; a++){
        fflush(stdin);
        printf("Nama Lengkap Peminjam ke-%d : ", a + 1);
        scanf("%[^\n]s", x[a].nama);
        fflush(stdin);
        printf("Kode Barang : ");
        scanf("%[^\n]s", x[a].kode);
        fflush(stdin);
        printf("Nama Barang : ");
        scanf("%[^\n]s", x[a].benda);
        fflush(stdin);
        printf("Letak Barang : ");
        scanf("%[^\n]s", x[a].letak);
        fflush(stdin);
        printf("Stok Barang : ");
        scanf("%d", &x[a].stok);
        fflush(stdin);
        printf("NIM : ");
        scanf("%d", &x[a].nim);
        printf("\n");
    }
}

void read(Logistik* x, int* JumlahSemua) {
    FILE* logistiks = fopen("databarang.txt", "r");
    if (logistiks == NULL) {
        perror("Gagal membuka File: ");
        return;
    }
    *JumlahSemua = 0;
    
    while
    (fscanf(logistiks, "%[^,], %[^,], %[^,], %[^,], %d, %d", 
    x[*JumlahSemua].nama, x[*JumlahSemua].kode, x[*JumlahSemua].benda, x[*JumlahSemua].letak, &x[*JumlahSemua].stok, &x[*JumlahSemua].nim) == 6) {
      (*JumlahSemua)++;  
    }
    fclose(logistiks);
}

void show(Logistik x[], int c){
    for(int a = 0; a < c; a++){
        printf("Nomor Barang : %d\n", a+1);
        printf("Nama Lengkap : %s\n", x[a].nama);
        printf("Kode Barang : %s\n", x[a].kode);
        printf("Nama Barang : %s\n", x[a].benda);
        printf("Letak Barang : %s\n", x[a].letak);
        printf("Stok Barang : %d\n", x[a].stok);
        printf("NIM : %d\n", x[a].nim);
        printf("\n");
    }
}

void save(Logistik* x, int JumlahSemua){
    FILE* logistiks = fopen("databarang.txt", "a");

    for(int a = 0; a < JumlahSemua; a++){
        fprintf(logistiks, "%s, %s, %s, %s, %d, %d\n",
        x[a].nama, x[a].kode, x[a].benda, x[a].letak, x[a].stok, x[a].nim);
    }
    fclose(logistiks);
    printf("\nData Peminjaman tersimpan!");
}

void edit(Logistik x[], int c){
    int row;
    fflush(stdin);
    printf("Masukkan Nomor Barang : ");
    scanf("%d", &row);
    fflush(stdin);

    printf("Ganti Nama : ");
    scanf("%[^\n]s", x[row - 1].nama);
    fflush(stdin);
    printf("Ganti Kode Barang : ");
    scanf("%[^\n]s", x[row - 1].kode);
    fflush(stdin);
    printf("Ganti Nama Barang : ");
    scanf("%[^\n]s", x[row - 1].benda);
    fflush(stdin);
    printf("Ganti Letak Barang : ");
    scanf("%[^\n]s", x[row - 1].letak);
    fflush(stdin);
    printf("Ganti Jumlah Stok Barang : ");
    scanf("%d", &x[row - 1].stok);
    fflush(stdin);
    printf("Ganti NIM : ");
    scanf("%d", &x[row - 1].nim);
    fflush(stdin);

    printf("\nData Peminjaman tersimpan!");
}

void search(Logistik x[], int JumlahSemua){
    fflush(stdin);
    int search, found = 0;
    printf("Cari Berdasarkan NIM : \n");
    scanf("%d", &search);

    for(int a = 0; a < JumlahSemua; a++){
        if(search == x[a].nim){
            printf("Data ditemukan pada Peminjaman logistiks ke : %d\n", a+1);
            printf("Nama Lengkap : %s\n", x[a].nama);
            printf("Kode Barang : %s\n", x[a].kode);
            printf("Nama Barang : %s\n", x[a].benda);
            printf("Letak Barang : %s\n", x[a].letak);
            printf("Stok Barang : %d\n", x[a].stok);
            printf("NIM : %d\n", x[a].nim);
            found = 1;
        }
    }
    if(!found){
        printf("Data tidak ada");
    }
}


void sort(Logistik x[], int JumlahSemua){
    for(int i = 0; i < JumlahSemua; i++){
        for(int j = 1 + i; j < JumlahSemua; j++){
            if(strcmp(x[i].benda, x[j].benda) > 0){
                Logistik temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    for(int i = 0; i < JumlahSemua; i++){
        printf("Nomor Barang : %d\n", i+1);
        printf("Nama Lengkap : %s\n", x[i].nama);
        printf("Kode Barang : %s\n", x[i].kode);
        printf("Nama Barang : %s\n", x[i].benda);
        printf("Letak Barang : %s\n", x[i].letak);
        printf("Stok Barang : %d\n", x[i].stok);
        printf("NIM : %d\n", x[i].nim);
        printf("\n");
    }
}

int main() {
    Logistik logis[MAX_PINJAM_LENGTH];
    FILE* logistiks;
    int menu1, total, totalpeminjam;

    do{
        printf("\t\t\t\t==============================================================\n");
        printf("\t\t\t\t||========= SELAMAT DATANG DI DATA LOGISTIK ITTS ===========||\n");
        printf("\t\t\t\t||================== SEDIA BERBAGAI BARANG =================||\n");
        printf("\t\t\t\t==============================================================\n");
        printf("\t\t\t\t                         MENU PILIHAN                         \n");
        printf("\t\t\t\t==============================================================\n");
        printf("\t\t\t\t1. Tambah Data \n");
        printf("\t\t\t\t2. Lihat Data \n");
        printf("\t\t\t\t3. Edit Data \n");
        printf("\t\t\t\t4. Cari Data \n");
        printf("\t\t\t\t5. Urutkan Data \n");
        printf("\t\t\t\t6. Keluar \n");
        printf("\t\t\t\t==============================================================\n\n");
        scanf("%d", &menu1);
                system("cls");

            switch (menu1){
            case 1:
                system("cls");
                printf("\nMau Pinjam Barang berapa kali : ");
                scanf("%d", &total);
                fflush(stdin);
                add(logis, total);
                save(logis, total);
                break;
            case 2:
                system("cls");
                read(logis, &total);
                show(logis, total);
                break;
            break;
            case 3:
                system("cls");
                logistiks = fopen("databarang.txt", "w");
                edit(logis, total);
                    if(logistiks == NULL){
                        perror("Data tidak ada!");
                    }
                    for(int a = 0; a < total; a++){
                        fprintf(logistiks, "%s, %s, %s, %s, %d, %d",
                        logis[a].nama, logis[a].kode, logis[a].benda, logis[a].letak, logis[a].stok, logis[a].nim);
                    }
                    fclose(logistiks);
                break;
            case 4:
                system("cls");
                search(logis, total);
               break;
            case 5:
                system("cls");
                sort(logis, total);
                break;
            case 6:
                printf("\t\t\t\t==============================================================\n");
                printf("\t\t\t\t||===================== TERIMAKASIH :D =====================||\n");
                printf("\t\t\t\t==============================================================\n");
            break;
            default:
                printf("Pilih Menu diatas ini!\n");
                break;
            }
        }while (menu1 != 6);
    
    return 0;
}