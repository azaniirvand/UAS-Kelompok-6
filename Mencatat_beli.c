// Fungsi untuk mencatat pembelian
void MencatatPembelian(Barang daftarPembelian[], int jumlahPembelian) {
    FILE *pembelianFile = fopen("pembelian.txt", "a");
    if (pembelianFile == NULL) {
        printf("Gagal membuka file pembelian.txt.\n");
        return;
    }

    fprintf(pembelianFile, "Pembelian baru:\n");
    for (int i = 0; i < jumlahPembelian; i++) {
        fprintf(pembelianFile, "%s - Jumlah: %d - Harga: %.2f\n", daftarPembelian[i].nama, daftarPembelian[i].jumlah, daftarPembelian[i].harga);
    }
    fprintf(pembelianFile, "\n");

    fclose(pembelianFile);
}
