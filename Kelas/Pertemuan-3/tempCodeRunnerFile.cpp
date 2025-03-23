#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    struct mahasiswa
    {
        string nama;
        int umur;
        string jurusan;
    };
    
    mahasiswa mhs;
    mhs.nama = "Muthe";
    mhs.umur = 20;
    mhs.jurusan = "bisdig";

    cout << "Nama: " << mhs.nama << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "Jurusan: " << mhs.jurusan << endl;
}