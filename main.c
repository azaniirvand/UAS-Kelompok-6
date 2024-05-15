#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "login.c"
#include "mengurangi_brg.c"
#include "Membeli_brg.c"
#include "MenampilkanBarang.c"

int main() {
    Barang daftarBarang[MAX_BARANG];
    Barang daftarPembelian[MAX_BARANG];
    Login InformasiLogin[MAX_LOGIN];
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
        while (fscanf(loginFile, "%s %s", InformasiLogin[jumlahLogin].username, InformasiLogin[jumlahLogin].password) != EOF) {
            jumlahLogin++;
        }
        fclose(loginFile);
    }

    //Lakukan login csebelum masuk ke menu
    while (!isLoggedIn) {
        printf("Silahkan Login\n");
        isLoggedIn = login(InformasiLogin, &jumlahLogin);
        if (!isLoggedIn) {
            printf("Login gagal. Coba lagi.\n");
        } else {
            printf("Login berhasil!\n");
        }
    }

    // Menu loop
    int pilihan;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Beli Barang\n");
        printf("4. Tampilkan Pembelian\n");
        printf("5. Hitung Total Pembayaran\n");
        printf("6. Kurangi Jumlah Barang\n");
        printf("7. Catat Pembelian\n");
        printf("8. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                MenambahBarang(daftarBarang, &jumlahBarang);
                break;
            case 2:
                MenampilkanBarang(daftarBarang, jumlahBarang);
                break;
            case 3:
                MembeliBarang(daftarBarang, jumlahBarang, daftarPembelian, &jumlahPembelian);
                break;
            case 4:
                MenampilkanPembelian(daftarPembelian, jumlahPembelian);
                break;
            case 5:
                printf("Total Pembayaran: %.2f\n", MenghitungTotalPembayaran(daftarPembelian, jumlahPembelian));
                break;
            case 6:
                MengurangiBarang(daftarBarang, jumlahBarang);
                break;
            case 7:
                MengcatatPembelian(daftarPembelian, jumlahPembelian);
                break;
            case 8:
                // Simpan perubahan ke file
                barangFile = fopen("daftar_barang.txt", "w");
                for (int i = 0; i < jumlahBarang; i++) {
                    fprintf(barangFile, "%s %d %.2f\n", daftarBarang[i].nama, daftarBarang[i].jumlah, daftarBarang[i].harga);
                }
                fclose(barangFile);
                exit(0);
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
