#include "header.h"

void beliBarang(Barang daftarBarang[], int jumlahBarang, Barang daftarPembelian[], int *jumlahPembelian) {
    tampilkanBarang(daftarBarang, jumlahBarang);

    int pilihan;
    printf("Pilih barang yang ingin dibeli (nomor): ");
    scanf("%d", &pilihan);
    if (pilihan >= 1 && pilihan <= jumlahBarang) {
        strcpy(daftarPembelian[*jumlahPembelian].nama, daftarBarang[pilihan-1].nama);
        printf("Masukkan jumlah barang yang ingin dibeli: ");
        scanf("%d", &daftarPembelian[*jumlahPembelian].jumlah);
        daftarPembelian[*jumlahPembelian].harga = daftarBarang[pilihan-1].harga;
        (*jumlahPembelian)++;
    } else {
        printf("Nomor barang tidak valid.\n");
    }
}