#include "header.h"

// Fungsi untuk mengurangi jumlah barang
void MengurangiBarang(Barang daftarBarang[], int jumlahBarang) {
    tampilkanBarang(daftarBarang, jumlahBarang);

    int pilihan, jumlahKurang;
    printf("Pilih barang yang ingin dikurangi jumlahnya (nomor): ");
    scanf("%d", &pilihan);
    if (pilihan >= 1 && pilihan <= jumlahBarang) {
        printf("Masukkan jumlah barang yang ingin dikurangi: ");
        scanf("%d", &jumlahKurang);
        if (jumlahKurang > 0 && jumlahKurang <= daftarBarang[pilihan-1].jumlah) {
            daftarBarang[pilihan-1].jumlah -= jumlahKurang;
            printf("Jumlah barang berhasil dikurangi.\n");
        } else {
            printf("Jumlah yang dimasukkan tidak valid.\n");
        }
    } else {
        printf("Nomor barang tidak valid.\n");
    }
}
