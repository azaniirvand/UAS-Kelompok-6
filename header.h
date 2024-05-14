#ifndef HEADER_H
#define HEADER_H

#define MAX_BARANG 100
#define MAX_LOGIN 100
#define MAX_NAMA_BARANG 50

typedef struct {
    char nama[MAX_NAMA_BARANG];
    int jumlah;
    double harga;
} Barang;

typedef struct {
    char username[50];
    char password[50];
} Login;

void tambahBarang(Barang daftarBarang[], int *jumlahBarang);
void tampilkanBarang(Barang daftarBarang[], int jumlahBarang);
void beliBarang(Barang daftarBarang[], int jumlahBarang, Barang daftarPembelian[], int *jumlahPembelian);
void tampilkanPembelian(Barang daftarPembelian[], int jumlahPembelian);
double hitungTotalPembayaran(Barang daftarPembelian[], int jumlahPembelian);
int login(Login loginInfo[], int *jumlahLogin);
void catatPembelian(Barang daftarPembelian[], int jumlahPembelian);

#endif /* FUNCTIONS_H */
