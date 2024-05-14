// Fungsi untuk menghitung total pembayaran
double hitungTotalPembayaran(Barang daftarPembelian[], int jumlahPembelian) {
    double total = 0;
    for (int i = 0; i < jumlahPembelian; i++) {
        total += daftarPembelian[i].jumlah * daftarPembelian[i].harga;
    }
    return total;
}
