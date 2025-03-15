#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string nama, nim;
    int kesempatan = 0;
    const int maxPesanan = 100;
    string namaPemesan[maxPesanan];
    string namaItem[maxPesanan];
    string ukuranPesanan[maxPesanan];
    int totalPesanan = 0;

    string merchandiseInfo[3][2] = {
        {"T-Shirt", "Rp 150.000"},
        {"Hoodie", "Rp 300.000"},
        {"Topi", "Rp 80.000"}
    };

    cout << "==========================================" << endl;
    cout << "==  SELAMAT DATANG DI PROGRAM PREORDER  ==" << endl;
    cout << "==     MERCHANDISE BAND THE JANSEN      ==" << endl;
    cout << "==========================================" << endl;
    cout << "\nSilahkan login terlebih dahulu" << endl;
    cout << "-------------------------------" << endl;

    while (kesempatan < 3) {
        cout << "\nMasukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == "Ken Bilqis Nuraini" && nim == "2409106015") {
            cout << "\n=======================" << endl;
            cout << "=  Login berhasil :D  =" << endl;
            cout << "=======================" << endl;
            break;
        } else {
            cout << "\n==============================================================" << endl;
            cout << "==  !!!Nama atau NIM yang dimasukkan terdapat kesalahan!!!  ==" << endl;
            cout << "==============================================================" << endl;
            kesempatan++;
        }

        if (kesempatan == 3) {
            cout << "\n===========================================" << endl;
            cout << "==  Maaf kesempatan login anda habis :(  ==" << endl;
            cout << "===========================================" << endl;
            return 0;
        }
    }

    int pilihan;
    do {
        cout << "\n================================" << endl;
        cout << "==     MENU UTAMA PROGRAM     ==" << endl;
        cout << "==  1. Informasi Merchandise  ==" << endl;
        cout << "==  2. Buat Pesanan           ==" << endl;
        cout << "==  3. Lihat Pesanan          ==" << endl;
        cout << "==  4. Ubah Pesanan           ==" << endl;
        cout << "==  5. Hapus Pesanan          ==" << endl;
        cout << "==  6. Keluar                 ==" << endl;
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
                if (totalPesanan < maxPesanan) {
                    cout << "\n==   Buat Pesanan    ==" << endl;
                    cout << "\nMasukkan Nama Pemesan: ";
                    getline(cin, namaPemesan[totalPesanan]);
                    cout << "Masukkan Nama Item: ";
                    cin >> namaItem[totalPesanan];
                    cin.ignore();
                    cout << "Masukkan Ukuran [S/M/L/XL]: ";
                    getline(cin, ukuranPesanan[totalPesanan]);
                    totalPesanan++;
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
                if (totalPesanan == 0) {
                    cout << "\n=======================================" << endl;
                    cout << "==  Mohon Maaf Belum Ada Pesanan :(  ==" << endl;
                    cout << "=======================================" << endl;
                } else {
                    cout << setw(5) << "No" << setw(20) << "Nama Pemesan" << setw(15) << "Jumlah" << setw(10) << "Ukuran\n";
                    for (int i = 0; i < totalPesanan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << namaPemesan[i] << setw(15) << namaItem[i] << setw(10) << ukuranPesanan[i] << "\n";
                    }
                }
                break;
            }
            case 4: {
                int nomorPesanan;
                cout << "\n=== Ubah Pesanan ===\n";
                cout << "\nMasukkan Nomor Pesanan yang ingin diubah: ";
                cin >> nomorPesanan;
                cin.ignore();

                if (nomorPesanan > 0 && nomorPesanan <= totalPesanan) {
                    cout << "\nMasukkan Nama Pemesan Baru: ";
                    getline(cin, namaPemesan[nomorPesanan - 1]);
                    cout << "Masukkan Nama Item Baru: ";
                    cin >> namaItem[nomorPesanan - 1];
                    cin.ignore();
                    cout << "Masukkan Ukuran Baru (S/M/L/XL): ";
                    getline(cin, ukuranPesanan[nomorPesanan - 1]);
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
                int nomorPesanan;
                cout << "\n=== Hapus Pesanan ===\n";
                cout << "\nMasukkan Nomor Pesanan yang ingin dihapus: ";
                cin >> nomorPesanan;
                cin.ignore();

                if (nomorPesanan > 0 && nomorPesanan <= totalPesanan) {
                    for (int i = nomorPesanan - 1; i < totalPesanan - 1; i++) {
                        namaPemesan[i] = namaPemesan[i + 1];
                        namaItem[i] = namaItem[i + 1];
                        ukuranPesanan[i] = ukuranPesanan[i + 1];
                    }
                    totalPesanan--;
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
                break;
            }
            default: {
                cout << "\n=======================================" << endl;
                cout << "==  Mohon Maaf Pilihan Tidak Ada :(  ==" << endl;
                cout << "=======================================" << endl;
                break;
            }
        }
    } while (pilihan != 6);

    return 0;
}