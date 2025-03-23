#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct mahasiswa
{
    string nama;
    int umur;
    string jurusan;
};

int main() {
    mahasiswa mhs;
    mhs.nama = "Muthe";
    mhs.umur = 20;
    mhs.jurusan = "bisdig";

    cout << "Nama: " << mhs.nama << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "Jurusan: " << mhs.jurusan << endl;
}