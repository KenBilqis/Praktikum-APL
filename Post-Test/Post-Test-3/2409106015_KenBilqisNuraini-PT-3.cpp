#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxPesanan = 100;

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
    Pesanan pesanan[maxPesanan]; // Nested struct untuk menyimpan pesanan
    int totalPesanan = 0;
};

int main() {
    Akun akun[maxPesanan]; // Array of struct untuk menyimpan data akun
    int totalAkun = 0; 
    int kesempatan = 0;
    bool loggedIn = false;
    int currentUserIndex = -1; // Indeks akun yang sedang login
    int nomorPesanan;

    string merchandiseInfo[3][2] = {
        {"T-Shirt", "Rp 150.000"},
        {"Hoodie", "Rp 300.000"},
        {"Topi", "Rp 80.000"}
    };

    while (true) {
        // Menu awal
        cout << "\n==========================================" << endl;
        cout << "==  SELAMAT DATANG DI PROGRAM PREORDER  ==" << endl;
        cout << "==     MERCHANDISE BAND THE JANSEN      ==" << endl;
        cout << "==========================================" << endl;
        cout << "\nSilahkan pilih menu:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan[1-3]: ";
        int pilihanAwal;
        cin >> pilihanAwal;
        cin.ignore();

        if (pilihanAwal == 1) {
            // Register
            if (totalAkun < maxPesanan) {
                cout << "\nMasukkan Username: ";
                getline(cin, akun[totalAkun].username);
                cout << "Masukkan Password: ";
                getline(cin, akun[totalAkun].password);
                totalAkun++;
                cout << "\n==================================" << endl;
                cout << "==  Akun berhasil didaftarkan  ==" << endl;
                cout << "==================================" << endl;
            } else {
                cout << "\n==================================" << endl;
                cout << "==  Kuota akun sudah penuh!  ==" << endl;
                cout << "==================================" << endl;
            }
        } else if (pilihanAwal == 2) {
            // Login
            string username, password;
            cout << "\nMasukkan Username: ";
            getline(cin, username);
            cout << "Masukkan Password: ";
            getline(cin, password);
            bool found = false;
            for (int i = 0; i < totalAkun; i++) {
                if (akun[i].username == username && akun[i].password == password) {
                    loggedIn = true;
                    currentUserIndex = i;
                    found = true;
                    break;
                }
            }
            if (found) {
                cout << "\n=======================" << endl;
                cout << "=  Login berhasil :D  =" << endl;
                cout << "=======================" << endl;
                break;
            } else {
                cout << "\n==============================================================" << endl;
                cout << "==  !!!Username atau Password yang dimasukkan salah!!!  ==" << endl;
                cout << "==============================================================" << endl;
                kesempatan++;
            }
            if (kesempatan == 3) {
                cout << "\n===========================================" << endl;
                cout << "==  Maaf kesempatan login anda habis :(  ==" << endl;
                cout << "===========================================" << endl;
                return 0;
            }
        } else if (pilihanAwal == 3) {
            // Keluar dari program
            cout << "\n=================================================" << endl;
            cout << "==  Terimakasih Telah Menggunakan Program ini  ==" << endl;
            cout << "==  Mohon maaf apabila terdapat kekurangan :)  ==" << endl;
            cout << "=================================================" << endl;
            return 0;
        } else {
            cout << "\n=======================================" << endl;
            cout << "==  Mohon Maaf Pilihan Tidak Ada :(  ==" << endl;
            cout << "=======================================" << endl;
        }
    }

    // Menu utama
    int pilihan;
    do {
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
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                cout << "\n==   Informasi Merchandise   ==" << endl;
                cout << "\n" << setw(10) << "Item" << setw(15) << "Harga\n";
                for (int i = 0; i < 3; i++) {
                    cout << setw(10) << merchandiseInfo[i][0] << setw(15) << merchandiseInfo[i][1] << "\n";
                }
                cout << "\n== Ukuran Tersedia: S/M/L/XL ==\n";
                break;
            }
            case 2: {
                if (akun[currentUserIndex].totalPesanan < maxPesanan) {
                    cout << "\n==   Buat Pesanan    ==" << endl;
                    cout << "\nMasukkan Nama Pemesan: ";
                    getline(cin, akun[currentUserIndex].pesanan[akun[currentUserIndex].totalPesanan].namaPemesan);
                    cout << "Masukkan Nama Item: ";
                    cin >> akun[currentUserIndex].pesanan[akun[currentUserIndex].totalPesanan].namaItem;
                    cin.ignore();
                    cout << "Masukkan Ukuran [S/M/L/XL]: ";
                    getline(cin, akun[currentUserIndex].pesanan[akun[currentUserIndex].totalPesanan].ukuranPesanan);
                    akun[currentUserIndex].totalPesanan++;
                    cout << "\n====================================================" << endl;
                    cout << "==  Terimakasih, Pesanan Berhasil ditambahkan :D  ==" << endl;
                    cout << "====================================================" << endl;
                } else {
                    cout << "\n================================================" << endl;
                    cout << "==  Mohon Maaf Kuota Pesanan Sudah Penuh  :(  ==" << endl;
                    cout << "================================================" << endl;
                }
                break;
            }
            case 3: {
                cout << "\n================== Daftar Pesanan ==================\n";
                if (akun[currentUserIndex].totalPesanan == 0) {
                    cout << "\n=======================================" << endl;
                    cout << "==  Mohon Maaf Belum Ada Pesanan :(  ==" << endl;
                    cout << "=======================================" << endl;
                } else {
                    cout << setw(5) << "No" << setw(20) << "Nama Pemesan" << setw(15) << "Jumlah" << setw(10) << "Ukuran\n";
                    for (int i = 0; i < akun[currentUserIndex].totalPesanan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << akun[currentUserIndex].pesanan[i].namaPemesan << setw(15) << akun[currentUserIndex].pesanan[i].namaItem << setw(10) << akun[currentUserIndex].pesanan[i].ukuranPesanan << "\n";
                    }
                }
                break;
            }
            case 4: {
                cout << "\n================== Daftar Pesanan ==================\n";
                if (akun[currentUserIndex].totalPesanan == 0) {
                    cout << "\n=======================================" << endl;
                    cout << "==  Mohon Maaf Belum Ada Pesanan :(  ==" << endl;
                    cout << "=======================================" << endl;
                } else {
                    cout << setw(5) << "No" << setw(20) << "Nama Pemesan" << setw(15) << "Jumlah" << setw(10) << "Ukuran\n";
                    for (int i = 0; i < akun[currentUserIndex].totalPesanan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << akun[currentUserIndex].pesanan[i].namaPemesan << setw(15) << akun[currentUserIndex].pesanan[i].namaItem << setw(10) << akun[currentUserIndex].pesanan[i].ukuranPesanan << "\n";
                    }
                }
                cout << "\n=== Ubah Pesanan ===\n";
                cout << "\nMasukkan Nomor Pesanan yang ingin diubah: ";
                cin >> nomorPesanan;
                cin.ignore();
                if (nomorPesanan > 0 && nomorPesanan <= akun[currentUserIndex].totalPesanan) {
                    cout << "\nMasukkan Nama Pemesan Baru: ";
                    getline(cin, akun[currentUserIndex].pesanan[nomorPesanan - 1].namaPemesan);
                    cout << "Masukkan Nama Item Baru: ";
                    cin >> akun[currentUserIndex].pesanan[nomorPesanan - 1].namaItem;
                    cin.ignore();
                    cout << "Masukkan Ukuran Baru (S/M/L/XL): ";
                    getline(cin, akun[currentUserIndex].pesanan[nomorPesanan - 1].ukuranPesanan);
                    cout << "\n==================================" << endl;
                    cout << "==  Pesanan berhasil diubah :D  ==" << endl;
                    cout << "==================================" << endl;
                } else {
                    cout << "\n==================================" << endl;
                    cout << "==  Nomor pesanan tidak valid!  ==" << endl;
                    cout << "==================================" << endl;
                }
                break;
            }
            case 5: {
                cout << "\n================== Daftar Pesanan ==================\n";
                if (akun[currentUserIndex].totalPesanan == 0) {
                    cout << "\n=======================================" << endl;
                    cout << "==  Mohon Maaf Belum Ada Pesanan :(  ==" << endl;
                    cout << "=======================================" << endl;
                } else {
                    cout << setw(5) << "No" << setw(20) << "Nama Pemesan" << setw(15) << "Jumlah" << setw(10) << "Ukuran\n";
                    for (int i = 0; i < akun[currentUserIndex].totalPesanan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << akun[currentUserIndex].pesanan[i].namaPemesan << setw(15) << akun[currentUserIndex].pesanan[i].namaItem << setw(10) << akun[currentUserIndex].pesanan[i].ukuranPesanan << "\n";
                    }
                }
                cout << "\n=== Hapus Pesanan ===\n";
                cout << "\nMasukkan Nomor Pesanan yang ingin dihapus: ";
                cin >> nomorPesanan;
                cin.ignore();
                if (nomorPesanan > 0 && nomorPesanan <= akun[currentUserIndex].totalPesanan) {
                    for (int i = nomorPesanan - 1; i < akun[currentUserIndex].totalPesanan - 1; i++) {
                        akun[currentUserIndex].pesanan[i] = akun[currentUserIndex].pesanan[i + 1];
                    }
                    akun[currentUserIndex].totalPesanan--;
                    cout << "\n===================================" << endl;
                    cout << "==  Pesanan berhasil dihapus :D  ==" << endl;
                    cout << "===================================" << endl;
                } else {
                    cout << "\n==================================" << endl;
                    cout << "==  Nomor pesanan tidak valid!  ==" << endl;
                    cout << "==================================" << endl;
                }
                break;
            }
            case 6: {
            cout << "\n=================================================" << endl;
            cout << "==  Terimakasih Telah Menggunakan Program ini  ==" << endl;
            cout << "==  Mohon maaf apabila terdapat kekurangan :)  ==" << endl;
            cout << "=================================================" << endl;
                loggedIn = false;
                currentUserIndex = -1;
                break;
            }
            default: {
                cout << "\n=======================================" << endl;
                cout << "==  Mohon Maaf Pilihan Tidak Ada :(  ==" << endl;
                cout << "=======================================" << endl;
                break;
            }
        }
    } while (loggedIn);

    return 0;
}