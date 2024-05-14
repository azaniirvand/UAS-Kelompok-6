#include <stdlib.h>
#include "header.h"
#include "fungsi.c"

int main() {
    Barang daftarBarang[MAX_BARANG];
    Barang daftarPembelian[MAX_BARANG];
    Login loginInfo[MAX_LOGIN];
    int jumlahBarang = 0;
    int jumlahLogin = 0;
    int jumlahPembelian = 0;
    int isLoggedIn = 0;

    FILE *barangFile = fopen("daftar_barang.txt", "r");
    if (barangFile != NULL) {
        while (fscanf(barangFile, "%s %d %lf", daftarBarang[jumlahBarang].nama, &daftarBarang[jumlahBarang].jumlah, &daftarBarang[jumlahBarang].harga) != EOF) {
            jumlahBarang++;
        }
        fclose(barangFile);
    }

    FILE *loginFile = fopen("login.txt", "r");
    if (loginFile != NULL) {
        while (fscanf(loginFile, "%s %s", loginInfo[jumlahLogin].username, loginInfo[jumlahLogin].password) != EOF) {
            jumlahLogin++;
        }
        fclose(loginFile);
    }

    int choice;
    while (1) { 
        printf("silahkan Login\n");
        isLoggedIn = login(loginInfo, &jumlahLogin);
                if (isLoggedIn){               
                    printf("Login berhasil!\n");
                    printf("\nMenu:\n");
                    printf("1. Tambah Barang\n");
                    printf("2. Lihat Daftar Barang\n");
                    printf("3. Beli Barang\n");
                    printf("4. Lihat Pembelian\n");
                    printf("5. Melakukan Pembayaran\n");
                    printf("6. Keluar\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &choice);
                }else
                    printf("Login gagal. Coba lagi.\n");
        

        switch(choice) {
            case 1:
                if (isLoggedIn)
                    tambahBarang(daftarBarang, &jumlahBarang);
                else
                    printf("Login terlebih dahulu!\n");
                break;
            case 2:
                if (isLoggedIn)
                    tampilkanBarang(daftarBarang, jumlahBarang);
                else
                    printf("Login terlebih dahulu!\n");
                break;
            case 3:
                if (isLoggedIn)
                    beliBarang(daftarBarang, jumlahBarang, daftarPembelian, &jumlahPembelian);
                else
                    printf("Login terlebih dahulu!\n");
                break;
            case 5:
                if (isLoggedIn)
                    tampilkanPembelian(daftarPembelian, jumlahPembelian);
                else
                    printf("Login terlebih dahulu!\n");
                break;
            case 6:
                if (isLoggedIn) {
                    catatPembelian(daftarPembelian, jumlahPembelian);
                    double total = hitungTotalPembayaran(daftarPembelian, jumlahPembelian);
                    printf("Total pembayaran: %.2f\n", total);
                } else {
                    printf("Login terlebih dahulu!\n");
                }
                break;
            case 7:
                // Simpan perubahan ke file
                barangFile = fopen("daftar_barang.txt", "w");
                for (int i = 0; i < jumlahBarang; i++) {
                    fprintf(barangFile, "%s %d %.2f\n", daftarBarang[i].nama, daftarBarang[i].jumlah, daftarBarang[i].harga);
                }
                fclose(barangFile);
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}