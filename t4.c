#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
   char nama[100];
   char kode[10];
   char benda[100];
   char letak[100];
   int stok;
   int nim;
}data;

data logistik[100];
char kode, bd[100], user[10], pass[10], yt;
int pil, pil1, pil2, cuy, x, i, j, jml, hari, bayar;

// Fungsi untuk Menambahkan Data
void input(){
system("clear");
FILE* fp;
fp = fopen("Data Barang.txt", "w");
if(fp == NULL){
printf("Error opening file");
exit(1);
}
x = x+1;
printf(" Input Data Logistik \n");
printf("=======================\n\n");
printf("Kode Barang\t : ");
scanf("%s", logistik[x]. kode);


fprintf(fp, "Kode Barang %s\n", logistik[x]. kode);
printf("Benda\t\t : "); fflush(stdin); 
scanf("%s",logistik[x]. benda);
fprintf(fp, "Benda %s\n", logistik[x]. benda);
printf("Stok Barang\t : "); scanf("%d", &logistik[x]. stok);
fprintf(fp, "Stok Barang %d\n", logistik[x]. stok);
printf("Letak Barang\t : "); fflush(stdin); scanf("%s",logistik[x]. letak);
fprintf(fp, "Letak Barang %s\n", logistik[x]. letak);
fclose(fp);
}

// Fungsi untuk Lihat Data
void output(){
   system("clear"); 
   for (i = 1; i <= x; i++)
   {
      printf("       Data Logistik     \n");
      printf("=======================\n\n");
      printf("\tKode Barang\t : %s\n", logistik[i]. kode);
      printf("\tBenda\t\t : %s\n", logistik[i]. benda);
      printf("\tStok Barang\t : %d\n", logistik[i]. stok);
      printf("\tLetak Barang\t : %s\n", logistik[i]. letak);
   }
}

// Fungsi untuk Edit Data
void edit_record(){
   char kode_barang[10];
   int index = -1;
   system("cls");
   printf("   Edit Data Logistik   \n");
   printf("=======================\n\n");
   printf("Masukkan Kode Barang yang ingin di edit : ");
   scanf("%s", kode_barang);
   for(i = 1; i <= x; i++){
      if(strcmp(kode_barang, logistik[i].kode) == 0){
         index = i;
         break;
      }
   }
   if(index == -1){
      printf("Kode Barang tidak ditemukan\n");
   }else{
      printf("Masukkan Data Baru\n");
      printf("Kode Barang\t : ");
      scanf("%s", logistik[index].kode);
      printf("Benda\t\t : ");
      scanf("%s", logistik[index].benda);
      printf("Stok Barang\t : ");
      scanf("%d", &logistik[index].stok);
      printf("Letak Barang\t : ");
      scanf("%s", logistik[index].letak);
      printf("Data berhasil diubah\n");
   }
}

// Fungsi Pemgurutan
void sort_record(){
    int sort_by;
    printf("Sort by: \n1. Kode Barang \n");
    printf("Pilih : ");
    scanf("%d", &sort_by);
    if(sort_by == 1){
    for ( i = 1; i < x; i++){
        for ( j = 1; j <= x-i; j++){
            if (strcmp(logistik[j].kode, logistik[j+1].kode) > 0)
            {
                printf("Benda\t\t\t\t : %s\n", logistik[i]. benda);
                printf("Stok Barang\t\t\t : %d\n", logistik[i]. stok);
                printf("Letak Barang\t\t\t : %s\n", logistik[i]. letak);
                data temp = logistik[j];
                    logistik[j] = logistik[j+1];
                    logistik[j+1] = temp;
            }
            
        }
        
    }
    }
}
/*void sort_record(){
    int sort_by;
    printf("Sort by: \n1. Kode Barang \n2. Benda \n3. Stok Barang\n4. Letak Barang\n");
    printf("Pilih : ");
    scanf("%d", &sort_by);
    if(sort_by == 1){
        for(i = 1; i <= x; i++){
            for(j = 1; j <= x-i; j++){
                if(strcmp(logistik[j].kode, logistik[j+1].kode) > 0){
                    data temp = logistik[j];
                    logistik[j] = logistik[j+1];
                    logistik[j+1] = temp;
                }
            }
        }
    }else if(sort_by == 2){
        for(i = 1; i <= x; i++){
            for(j = 1; j <= x-i; j++){
                if(strcmp(logistik[j].benda, logistik[j+1].benda) > 0){
                    data temp = logistik[j];
                    logistik[j] = logistik[j+1];
                    logistik[j+1] = temp;
                }
            }
        }
    }else if(sort_by == 3){
        for(i = 1; i <= x; i++){
            for(j = 1; j <= x-i; j++){
                if(logistik[j].stok > logistik[j+1].stok){
                    data temp = logistik[j];
                    logistik[j] = logistik[j+1];
                    logistik[j+1] = temp;
                }
            }
        }
    }else if(sort_by == 4){
        for(i = 1; i <= x; i++){
            for(j = 1; j <= x-i; j++){
                if(strcmp(logistik[j].letak, logistik[j+1].letak) > 0){
                    data temp = logistik[j];
                    logistik[j] = logistik[j+1];
                    logistik[j+1] = temp;
                }
            }
        }
    }
    printf("Data berhasil diurutkan\n");
}*/

// Fungsi untuk Pencarian Data
void pencarian(){
   system("clear");
   printf("   Cari Data Logistik   \n");
   printf("=======================\n\n");
   printf("Masukkan Benda\t : "); fflush(stdin); scanf("%[^\n]s", bd);  //ada yg kurang [^\n]

   for ( i = 1; i <= x; i++)
   {
      if (strcmp(bd, logistik[i]. benda)== 0)
      {
         //cuy = i;
         printf("Kode Barang\t : %s\n", logistik[i]. kode);
         printf("Benda\t\t : %s\n", logistik[i]. benda);
         printf("Letak Barang\t : %s\n", logistik[i]. letak);
         if (logistik[i]. stok < 0){
            printf("\nStok Kosong ! ");
         }
         else if (logistik[i]. stok >= 0){
            printf("Stok Barang\t : %d\n",logistik[i]. stok);
         } 
      }
      
   }
} 

// Fungsi untuk Meminjam Barang
void pinjaman(){
   system("clear");
   printf("       Menu Pinjaman     \n");
   printf("=======================\n\n");
   printf("Nama Peminjam\t\t\t : "); fflush(stdin); 
   scanf("%s",logistik[j]. nama);
   printf("Nim Peminjam\t\t\t : "); scanf("%d", &logistik[j]. nim);
   printf("Masukkan Benda\t\t\t : "); fflush(stdin); scanf("%[^\n]s", bd); //ada yg kurang [^\n] 
   for ( i = 1; i <= x; i++){
      if (strcmp(bd, logistik[i]. benda)== 0)
      {
         printf("Benda\t\t\t\t : %s\n", logistik[i]. benda);
         printf("Stok Barang\t\t\t : %d\n", logistik[i]. stok);
         printf("Letak Barang\t\t\t : %s\n", logistik[i]. letak);
         printf("Jumlah dipinjam\t\t\t : "); scanf("%d", &jml);
         if (logistik[i]. stok >= jml){
            logistik[i]. stok -= jml;
         }
         else printf("Stok tidak mencukupi\n");
      }   
   }
   printf("Lama Meminjam\t\t\t :"); scanf("%d", &hari);
   /*bayar =  100000 * hari;
   printf("Biaya yang dibayarkan\t\t : Rp %d\n", bayar);*/
}

// Fungsi untuk  Mengembalikan Barang
void kembali(){
   system("clear");
   printf("       Menu Pengembalian     \n");
   printf("===========================\n\n");
   printf("Nama Peminjam\t\t\t : "); fflush(stdin); 
   scanf("%s",logistik[j]. nama);
   printf("Nim Peminjam\t\t\t : "); scanf("%d", &logistik[j]. nim);
   printf("Masukkan Benda\t\t\t : "); fflush(stdin); scanf("%[^\n]s", bd); //ada yg kurang [^\n] //
   for ( i = 1; i <= x; i++){
      if (strcmp(bd, logistik[i]. benda)== 0)
      {
         printf("Benda\t\t\t\t : %s\n", logistik[i]. benda);
         printf("Jumlah yang dipinjam\t\t : "); scanf("%d", &jml);
         printf("Lama Meninjam\t\t\t : "); scanf("%d",&hari);
         printf("Dengan Biaya : %d\n", bayar);
         if (logistik[i]. stok >= 0)
            logistik[i]. stok += jml;

      }  
   }
}

// Fungsi untuk Data Pinjam
void datapinjam(){
   for ( i = 1; i <= x; i++){
      if (strcmp(bd, logistik[i]. benda)== 0){
         system("clear");
         printf("       Data Pinjaman Barang     \n");
         printf("==============================\n\n");
         printf("Nama Peminjam\t\t\t : %s\n", logistik[j]. nama);
         printf("Benda yang dipinjam\t\t : %s\n",logistik[i]. benda); 
         printf("Letak Barang\t\t\t : %s\n", logistik[i]. letak);
         printf("Jumlah yang dipinjam\t\t : %d\n", jml); 
         printf("Dengan Biaya  %d\n", bayar);
      }
   }
}

// Fungsi  untuk Data Kembali
void datakembali(){
   for ( i = 1; i <= x; i++){
      if (strcmp(bd, logistik[i]. benda)== 0){
         system("clear");
         printf("     Data Pengembalian Barang   \n");
         printf("==============================\n\n");
         printf("Nama Pinjaman\t\t\t : %s\n", logistik[j]. nama);
         printf("Data pengembalian Barang\t : %s\n",logistik[i]. benda); 
         printf("Dengan Jumlah yang dikembalikan\t : %d\n", jml); 
      }
   }
}

int main()
{
   data logistik[50];
   int pil, pil1, pil2;
   FILE *file;
   do
   {
      system("cls");
      printf("\t\t\t\t==============================================================\n");
      printf("\t\t\t\t||========= SELAMAT DATANG DI DATA LOGISTIK ITTS ===========||\n");
      printf("\t\t\t\t||================== SEDIA BERBAGAI BARANG =================||\n");
      printf("\t\t\t\t==============================================================\n");
      printf("\n\n");
      printf("\t\t\t\t                         MENU PILIHAN                         \n");
      printf("\t\t\t\t==============================================================\n");
      printf("\t\tMasuk Sebagai : ");
      printf("\n\t\t\t1. Petugas : \n\t\t\t2. Peminjam : \n");
      printf("Pilihan : "); scanf("%d", &pil);
      if (pil1, pil2){
         btt :
         system("cls");
         printf("Username\t : "); scanf("%s", &user);
         printf("Password\t : "); scanf("%s", &pass);
         if (strcmp(user, "aaa") == 0 && strcmp(pass, "123") == 0)
            {
               do{
                  system("clear");
                  printf("\t\t\t\t                         MENU PILIHAN                         \n");
                  printf("\t\t\t\t==============================================================\n");
                  printf("\t\t1. Input Data Barang\n\t\t2. Lihat Data Barang\n\t\t3. Edit Data\n\t\t4. Pencarian Data\n\t\t5. Sort Data\n\t\t6. Pinjam Barang\n\t\t7. Kembalikan Barang\n\t\t8. Data Pinjam\n\t\t9. Data Kembali\n\t\t10. Exit\n");
                  printf("Pilihan : "); scanf("%d", &pil);
                  switch (pil){
                     case 1 :
                        input();
                        system("pause");
                        break;
                     case 2 :
                        output();
                        system("pause");
                        break;
                     case 3 :
                        edit_record();
                        break;
                     case 4 :
                        pencarian();
                        break;
                     case 5 :
                        sort_record();
                        break;
                     case 6 :
                        pinjaman();
                        break;
                     case 7 :
                        kembali();
                        break;   
                     case 8 :
                        datapinjam();
                        break;
                     case 9 :
                        datakembali();
                        break;
                     case 10 :
                        printf("\t\t\t\t==============================================================\n");
                        printf("\t\t\t\t||===================== TERIMAKASIH :D =====================||\n");
                        printf("\t\t\t\t==============================================================\n");
                        break;
                     }
                  }while(pil1 !=10);
            }
      }
      
   }
   while(pil !=2);
  return 0;
}

