#include <stdio.h>
// #include <string.h>
#include "header.h"

// Fungsi untuk menambahkan barang
void MenambahBarang(Barang daftarBarang[], int *jumlahBarang) {
    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", daftarBarang[*jumlahBarang].nama); // %[^\n] digunakan untuk membaca string dengan spasi
    printf("Masukkan jumlah barang: ");
    scanf("%d", &daftarBarang[*jumlahBarang].jumlah);
    printf("Masukkan harga barang: ");
    scanf("%lf", &daftarBarang[*jumlahBarang].harga);
    (*jumlahBarang)++;
}
