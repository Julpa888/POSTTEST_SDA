/* Soal 3 
Array & Pointer - Operasi Dasar
Buat program C++ yang menyimpan sejumlah data integer dalam array, lalu gunakan pointer untuk mengakses dan memanipulasi elemen-elemen tersebut.
Deklarasikan array sesuai ketentuan masing-masing, lalu buat fungsi dengan parameter pointer untuk operasi yang diminta.

• Deklarasikan array berisi 7 elemen yang diisi dengan bilangan prima (2, 3, 5, 7, 11, 13, 17).
• Buat fungsi reverseArray(int* arr, int n) menggunakan pointer (bukan indeks) untuk membalik urutan array.
• Tampilkan array sebelum dan sesudah dibalik.
Tampilkan pula alamat memori setiap elemen menggunakan pointer. */

#include <iostream>
using namespace std;

int reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1; 

    while(start < end) {
        int ubah = *start;
        *start = *end;
        *end = ubah;
        start++;
        end--;
    }
    return 0; 
}

int alamatMemori(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Nilai: " << *(arr + i)
            << "\tAlamat: " << (arr + i) << endl;
    }
    return 0;
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array awal sebelum dibalik yaa~" << endl;
    alamatMemori(prima, n);

    cout << "\n(｡˃ ᵕ < )✧ reverse array on progress..." << endl;

    reverseArray(prima, n);
    cout << "\nTadaaa~ Array setelah dibalik!" << endl;
    alamatMemori(prima, n);
    return 0;
}