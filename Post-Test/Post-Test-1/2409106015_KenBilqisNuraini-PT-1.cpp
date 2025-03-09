#include <iostream>
using namespace std;

int main() {
    string username, nim;
    int kesempatan = 0;

    cout << "======================" << endl;
    cout << "==  SELAMAT DATANG  ==" << endl;
    cout << "==    DI PROGRAM    ==" << endl;
    cout << "==     KONVERSI     ==" << endl;
    cout << "======================" << endl;
    cout << "\nSilahkan login terlebih dahulu" << endl;
    cout << "-------------------------------" << endl;
    
    do
    {
        cout << "\nMasukkan Nama: ";
        getline(cin, username);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (username == "Ken Bilqis Nuraini" && nim == "2409106015") {
            cout << "\n=======================" << endl;
            cout << "=  Login berhasil :D  =" << endl;
            cout << "=======================" << endl;
            break;
        }
        else {
            cout << "\n!!!Nama atau NIM yang dimasukkan terdapat kesalahan!!!" << endl;
            kesempatan++;
        }
    } while (kesempatan < 3);

    if (kesempatan == 3) {
        cout << "\n===========================================" << endl;
        cout << "==  Maaf kesempatan login anda habis :(  ==" << endl;
        cout << "===========================================" << endl;
        return 0;
    }
    
    int pilihan;
    do
    {
        cout << "\n===========================================" << endl;
        cout << "==         MENU PILIHAN KONVERSI         ==" << endl;
        cout << "==  1. Meter --> Centimeter, Mile, Foot  ==" << endl;
        cout << "==  2. Centimeter --> Meter, Mile, Foot  ==" << endl;
        cout << "==  3. Mile --> Meter, Centimeter, Foot  ==" << endl;
        cout << "==  4. Foot --> Meter, Centimeter, Mile  ==" << endl;
        cout << "==  5. Keluar dari program               ==" << endl;
        cout << "===========================================" << endl;
        cout << "\nMasukkan pilihan[1-5]: ";
        cin >> pilihan;

        double nilai;
        switch (pilihan)
        {
        case 1:
            cout << "\nMasukkan nilai dalam Meter: ";
            cin >> nilai;
            cout << nilai << " Meter = " << nilai * 100 << " Centimeter" << endl;
            cout << nilai << " Meter = " << nilai / 1609.34 << " Mile" << endl;
            cout << nilai << " Meter = " << nilai * 3.28084 << " Foot" << endl;
            break;
        case 2:
            cout << "\nMasukkan nilai dalam Centimeter: ";
            cin >> nilai;
            cout << nilai << " Centimeter = " << nilai / 100 << " Meter" << endl;
            cout << nilai << " Centimeter = " << nilai / 160934 << " Mile" << endl;
            cout << nilai << " Centimeter = " << nilai / 30.48 << " Foot" << endl;
            break;
        case 3:
            cout << "\nMasukkan nilai dalam Mile: ";
            cin >> nilai;
            cout << nilai << " Mile = " << nilai * 1609.34 << " Meter" << endl;
            cout << nilai << " Mile = " << nilai * 160934 << " Centimeter" << endl;
            cout << nilai << " Mile = " << nilai * 5280 << " Foot" << endl;
            break;
        case 4:
            cout << "\nMasukkan nilai dalam Foot: ";
            cin >> nilai;
            cout << nilai << " Foot = " << nilai / 3.28084 << " Meter" << endl;
            cout << nilai << " Foot = " << nilai * 30.48 << " Centimeter" << endl;
            cout << nilai << " Foot = " << nilai / 5280 << " Mile" << endl;
            break;
        case 5:
            cout << "\n=================================================" << endl;
            cout << "==  Terimakasih Telah Menggunakan Program ini  ==" << endl;
            cout << "==  Mohon maaf apabila terdapat kekurangan :)  ==" << endl;
            cout << "=================================================" << endl;
            break;
        default:
            cout << "\n=======================================" << endl;
            cout << "==  Mohon Maaf Pilihan Tidak Ada :(  ==" << endl;
            cout << "=======================================" << endl;
            break;
        }
    } while (pilihan != 5);
    return 0;
}