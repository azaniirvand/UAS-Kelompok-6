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

void TenambahBarang(Barang daftarBarang[], int *jumlahBarang);
void MengurangiBarang(Barang daftarBarang[], int jumlahBarang);
void MenampilkanBarang(Barang daftarBarang[], int jumlahBarang);
void MembeliBarang(Barang daftarBarang[], int jumlahBarang, Barang daftarPembelian[], int *jumlahPembelian);
void MenampilkanPembelian(Barang daftarPembelian[], int jumlahPembelian);
double MenghitungTotalPembayaran(Barang daftarPembelian[], int jumlahPembelian);
int login(Login loginInfo[], int *jumlahLogin);
void MengcatatPembelian(Barang daftarPembelian[], int jumlahPembelian);

#endif /* FUNCTIONS_H */
