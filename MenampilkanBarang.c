#include <stdlib.h>
#include <string.h>
#include "header.h"
// Fungsi untuk menampilkan daftar barang
void MenampilkanBarang(Barang daftarBarang[], int jumlahBarang) {
    printf("Daftar Barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. %s - Jumlah: %d - Harga: %.2f\n", i+1, daftarBarang[i].nama, daftarBarang[i].jumlah, daftarBarang[i].harga);
    }
}
