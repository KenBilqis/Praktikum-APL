#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maksimalPesanan = 100;

// Struct data pesanan
struct Pesanan {
    string namaPemesan;
    string namaItem;
    string ukuranPesanan;
};

// Struct data akun
struct Akun {
    string username;
    string password;
    Pesanan daftarPesanan[maksimalPesanan]; // Nested struct untuk menyimpan pesanan
    int itemPesanan = 0;
};

// Mendklarasikan fungsi dan prosedur dengan pointer
void tampilkanMenuAwal();
void prosesRegistrasi(Akun* daftarAkun, int* totalAkun); // Menggunakan pointer
bool prosesLogin(Akun* daftarAkun, int totalAkun, int* indeksPenggunaAktif, int* kesempatanLogin); // Menggunakan pointer
void tampilkanMenuUtama();
void tampilkanInformasiMerchandise();
void buatPesananBaru(Akun* akunPengguna); // Menggunakan pointer
void lihatDaftarPesanan(const Akun* akunPengguna); // Menggunakan pointer
void ubahPesanan(Akun* akunPengguna); // Menggunakan pointer
void hapusPesanan(Akun* akunPengguna); // Menggunakan pointer
void tampilkanPesanKeluar();
void tampilkanPesanError();
int hitungTotalPesananRekursif(const Akun* akunPengguna, int indeks); // Menggunakan pointer
void tampilkanPesanan(const Pesanan* pesanan); // Menggunakan pointer (dereference)
void tampilkanPesanan(const Pesanan* pesanan, int nomor); // Overloading dengan pointer

// Prosedur menampilkan menu awal
void tampilkanMenuAwal() {
    cout << "\n==========================================" << endl;
    cout << "==  SELAMAT DATANG DI PROGRAM PREORDER  ==" << endl;
    cout << "==     MERCHANDISE BAND THE JANSEN      ==" << endl;
    cout << "==========================================" << endl;
    cout << "\nSilahkan pilih menu:" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukkan pilihan[1-3]: ";
}

// Prosedur proses registrasi (menggunakan pointer)
void prosesRegistrasi(Akun* daftarAkun, int* totalAkun) {
    if (*totalAkun < maksimalPesanan) {
        cout << "\nMasukkan Username: ";
        getline(cin, daftarAkun[*totalAkun].username);
        cout << "Masukkan Password: ";
        getline(cin, daftarAkun[*totalAkun].password);
        (*totalAkun)++;
        cout << "\n==================================" << endl;
        cout << "==  Akun berhasil didaftarkan  ==" << endl;
        cout << "==================================" << endl;
    } else {
        cout << "\n==================================" << endl;
        cout << "==  Kuota akun sudah penuh!  ==" << endl;
        cout << "==================================" << endl;
    }
}

// Fungsi proses login (menggunakan pointer)
bool prosesLogin(Akun* daftarAkun, int totalAkun, int* indeksPenggunaAktif, int* kesempatanLogin) {
    string username, password;
    cout << "\nMasukkan Username: ";
    getline(cin, username);
    cout << "Masukkan Password: ";
    getline(cin, password);
    
    for (int i = 0; i < totalAkun; i++) {
        if (daftarAkun[i].username == username && daftarAkun[i].password == password) {
            *indeksPenggunaAktif = i;
            cout << "\n=======================" << endl;
            cout << "=  Login berhasil :D  =" << endl;
            cout << "=======================" << endl;
            return true;
        }
    }
    
    cout << "\n==============================================================" << endl;
    cout << "==  !!!Username atau Password yang dimasukkan salah!!!  ==" << endl;
    cout << "==============================================================" << endl;
    (*kesempatanLogin)++;
    
    if (*kesempatanLogin == 3) {
        cout << "\n===========================================" << endl;
        cout << "==  Maaf kesempatan login anda habis :(  ==" << endl;
        cout << "===========================================" << endl;
        exit(0);
    }
    
    return false;
}

// Prosedur menampilkan menu utama
void tampilkanMenuUtama() {
    cout << "\n================================" << endl;
    cout << "==     MENU UTAMA PROGRAM     ==" << endl;
    cout << "==  1. Informasi Merchandise  ==" << endl;
    cout << "==  2. Buat Pesanan           ==" << endl;
    cout << "==  3. Lihat Pesanan          ==" << endl;
    cout << "==  4. Ubah Pesanan           ==" << endl;
    cout << "==  5. Hapus Pesanan          ==" << endl;
    cout << "==  6. Logout                 ==" << endl;
    cout << "================================" << endl;
    cout << "\nMasukkan pilihan[1-6]: ";
}

// Prosedur menampilkan informasi merchandise
void tampilkanInformasiMerchandise() {
    string infoMerchandise[3][2] = {
        {"T-Shirt", "Rp 150.000"},
        {"Hoodie", "Rp 300.000"},
        {"Topi", "Rp 80.000"}
    };
    
    cout << "\n==   Informasi Merchandise   ==" << endl;
    cout << "\n" << setw(10) << "Item" << setw(15) << "Harga\n";
    for (int i = 0; i < 3; i++) {
        cout << setw(10) << infoMerchandise[i][0] << setw(15) << infoMerchandise[i][1] << "\n";
    }
    cout << "\n== Ukuran Tersedia: S/M/L/XL ==\n";
}

// Prosedur membuat pesanan baru (menggunakan pointer)
void buatPesananBaru(Akun* akunPengguna) {
    if (akunPengguna->itemPesanan < maksimalPesanan) {
        cout << "\n==   Buat Pesanan    ==" << endl;
        cout << "\nMasukkan Nama Pemesan: ";
        getline(cin, akunPengguna->daftarPesanan[akunPengguna->itemPesanan].namaPemesan);
        cout << "Masukkan Nama Item: ";
        cin >> akunPengguna->daftarPesanan[akunPengguna->itemPesanan].namaItem;
        cin.ignore();
        cout << "Masukkan Ukuran [S/M/L/XL]: ";
        getline(cin, akunPengguna->daftarPesanan[akunPengguna->itemPesanan].ukuranPesanan);
        akunPengguna->itemPesanan++;
        cout << "\n====================================================" << endl;
        cout << "==  Terimakasih, Pesanan Berhasil ditambahkan :D  ==" << endl;
        cout << "====================================================" << endl;
    } else {
        cout << "\n================================================" << endl;
        cout << "==  Mohon Maaf Kuota Pesanan Sudah Penuh  :(  ==" << endl;
        cout << "================================================" << endl;
    }
}

// Prosedur melihat daftar pesanan (menggunakan pointer)
void lihatDaftarPesanan(const Akun* akunPengguna) {
    cout << "\n================== Daftar Pesanan ==================\n";
    if (akunPengguna->itemPesanan == 0) {
        cout << "\n=======================================" << endl;
        cout << "==  Mohon Maaf Belum Ada Pesanan :(  ==" << endl;
        cout << "=======================================" << endl;
    } else {
        cout << setw(5) << "No" << setw(20) << "Nama Pemesan" << setw(15) << "item" << setw(10) << "Ukuran\n";
        for (int i = 0; i < akunPengguna->itemPesanan; i++) {
            tampilkanPesanan(&(akunPengguna->daftarPesanan[i]), i+1); // Menggunakan address-of
        }
    }
}

// Prosedur mengubah pesanan (menggunakan pointer)
void ubahPesanan(Akun* akunPengguna) {
    lihatDaftarPesanan(akunPengguna);
    
    if (akunPengguna->itemPesanan == 0) return;
    
    cout << "\n=== Ubah Pesanan ===\n";
    cout << "\nMasukkan Nomor Pesanan yang ingin diubah: ";
    int nomorPesanan;
    cin >> nomorPesanan;
    cin.ignore();
    
    if (nomorPesanan > 0 && nomorPesanan <= akunPengguna->itemPesanan) {
        cout << "\nMasukkan Nama Pemesan Baru: ";
        getline(cin, akunPengguna->daftarPesanan[nomorPesanan - 1].namaPemesan);
        cout << "Masukkan Nama Item Baru: ";
        cin >> akunPengguna->daftarPesanan[nomorPesanan - 1].namaItem;
        cin.ignore();
        cout << "Masukkan Ukuran Baru (S/M/L/XL): ";
        getline(cin, akunPengguna->daftarPesanan[nomorPesanan - 1].ukuranPesanan);
        cout << "\n==================================" << endl;
        cout << "==  Pesanan berhasil diubah :D  ==" << endl;
        cout << "==================================" << endl;
    } else {
        cout << "\n==================================" << endl;
        cout << "==  Nomor pesanan tidak valid!  ==" << endl;
        cout << "==================================" << endl;
    }
}

// Prosedur menghapus pesanan (menggunakan pointer)
void hapusPesanan(Akun* akunPengguna) {
    lihatDaftarPesanan(akunPengguna);
    
    if (akunPengguna->itemPesanan == 0) return;
    
    cout << "\n=== Hapus Pesanan ===\n";
    cout << "\nMasukkan Nomor Pesanan yang ingin dihapus: ";
    int nomorPesanan;
    cin >> nomorPesanan;
    cin.ignore();
    
    if (nomorPesanan > 0 && nomorPesanan <= akunPengguna->itemPesanan) {
        for (int i = nomorPesanan - 1; i < akunPengguna->itemPesanan - 1; i++) {
            akunPengguna->daftarPesanan[i] = akunPengguna->daftarPesanan[i + 1];
        }
        akunPengguna->itemPesanan--;
        cout << "\n===================================" << endl;
        cout << "==  Pesanan berhasil dihapus :D  ==" << endl;
        cout << "===================================" << endl;
    } else {
        cout << "\n==================================" << endl;
        cout << "==  Nomor pesanan tidak valid!  ==" << endl;
        cout << "==================================" << endl;
    }
}

// Prosedur menampilkan pesan keluar
void tampilkanPesanKeluar() {
    cout << "\n=================================================" << endl;
    cout << "==  Terimakasih Telah Menggunakan Program ini  ==" << endl;
    cout << "==  Mohon maaf apabila terdapat kekurangan :)  ==" << endl;
    cout << "=================================================" << endl;
}

// Prosedur menampilkan pesan error
void tampilkanPesanError() {
    cout << "\n=======================================" << endl;
    cout << "==  Mohon Maaf Pilihan Tidak Ada :(  ==" << endl;
    cout << "=======================================" << endl;
}

// Fungsi rekursif menghitung total pesanan (menggunakan pointer)
int hitungTotalPesananRekursif(const Akun* akunPengguna, int indeks) {
    if (indeks >= akunPengguna->itemPesanan) {
        return 0;
    }
    return 1 + hitungTotalPesananRekursif(akunPengguna, indeks + 1);
}

// Fungsi overloading menampilkan pesanan (dereference pointer)
void tampilkanPesanan(const Pesanan* pesanan) {
    cout << setw(20) << pesanan->namaPemesan << setw(15) << pesanan->namaItem << setw(10) << pesanan->ukuranPesanan << "\n";
}

// Fungsi overloading menampilkan pesanan (dereference pointer dengan nomor)
void tampilkanPesanan(const Pesanan* pesanan, int nomor) {
    cout << setw(5) << nomor << setw(20) << pesanan->namaPemesan << setw(15) << pesanan->namaItem << setw(10) << pesanan->ukuranPesanan << "\n";
}

// Fungsi utama
int main() {
    Akun daftarAkun[maksimalPesanan];
    int totalAkun = 0; 
    int kesempatanLogin = 0;
    int indeksPenggunaAktif = -1;
    
    while (true) {
        tampilkanMenuAwal();
        int pilihanAwal;
        cin >> pilihanAwal;
        cin.ignore();

        if (pilihanAwal == 1) {
            prosesRegistrasi(daftarAkun, &totalAkun); // Menggunakan address-of
        } else if (pilihanAwal == 2) {
            if (prosesLogin(daftarAkun, totalAkun, &indeksPenggunaAktif, &kesempatanLogin)) { // Menggunakan address-of
                break;
            }
        } else if (pilihanAwal == 3) {
            tampilkanPesanKeluar();
            return 0;
        } else {
            tampilkanPesanError();
        }
    }

    // Menu utama setelah login
    int pilihan;
    do {
        tampilkanMenuUtama();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tampilkanInformasiMerchandise();
                break;
            case 2:
                buatPesananBaru(&daftarAkun[indeksPenggunaAktif]); // Menggunakan address-of
                break;
            case 3:
                lihatDaftarPesanan(&daftarAkun[indeksPenggunaAktif]); // Menggunakan address-of
                break;
            case 4:
                ubahPesanan(&daftarAkun[indeksPenggunaAktif]); // Menggunakan address-of
                break;
            case 5:
                hapusPesanan(&daftarAkun[indeksPenggunaAktif]); // Menggunakan address-of
                break;
            case 6:
                tampilkanPesanKeluar();
                indeksPenggunaAktif = -1;
                break;
            default:
                tampilkanPesanError();
                break;
        }
    } while (indeksPenggunaAktif != -1);

    return 0;
}