/* Soal 2  
Struct + Array Data Mahasiswa
Buat program C++ menggunakan struct Mahasiswa yang memiliki field: nama (string), nim (string), dan ipk (float).
Deklarasikan array of struct sesuai jumlah mahasiswa yang diminta, lakukan input data, lalu tampilkan hasil sesuai ketentuan.

• Input data 5 mahasiswa (nama, NIM, IPK).
• Cari dan tampilkan mahasiswa dengan IPK tertinggi. */

#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float ipk;
};

int main(){
    Mahasiswa mhs[5];

    cout << "Silahkan input data mahasiswa terlebih dahulu! ⸜(｡˃ ᵕ < )⸝♡" << endl;
    for(int i = 0; i < 5; i++){
    cout << "\nMahasiswa ke-" << i+1 << endl;
    cout << "Nama : ";
    cin >> mhs[i].nama;
    cout << "NIM  : ";
    cin >> mhs[i].nim;
    cout << "IPK  : ";
    cin >> mhs[i].ipk;
    }

    int ipkTertinggi = 0;
    for(int i = 1; i < 5; i++){
        if(mhs[i].ipk > mhs[ipkTertinggi].ipk){
            ipkTertinggi = i;
        }
    }

    cout << "\n~Mahasiswa dengan IPK tertinggi adalah: " << endl;
    cout << "Nama : " << mhs[ipkTertinggi].nama << endl;
    cout << "NIM  : " << mhs[ipkTertinggi].nim << endl;
    cout << "IPK  : " << mhs[ipkTertinggi].ipk << endl;
    cout << "\nSelamat kepada " << mhs[ipkTertinggi].nama << " you did a great job!(..◜ᴗ◝..)";
    return 0;
}