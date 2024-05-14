// Fungsi untuk menampilkan pembelian
void MenampilkanPembelian(Barang daftarPembelian[], int jumlahPembelian) {
    printf("Barang yang dibeli:\n");
    for (int i = 0; i < jumlahPembelian; i++) {
        printf("%s - Jumlah: %d - Harga: %.2f\n", daftarPembelian[i].nama, daftarPembelian[i].jumlah, daftarPembelian[i].harga);
    }
}

