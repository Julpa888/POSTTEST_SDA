/* Soal 4. Pointer pada Fungsi
Buat fungsi untuk menukar dua variabel integer.
· gunakan pointer dalam fungsi untuk melakukan pertukaran nilai.
· Uji fungsi tersebut dengan dua nilai input dan tampilkan hasil sebelum dan sesudah pertukaran. */

#include <iostream>
using namespace std;

int tukar(int *a, int *b){
    int ubah;
    ubah = *a;
    *a = *b;
    *b = ubah;
    return 0;
}

int main(){
    int a;
    int b;

    cout << " ⸜(｡˃ ᵕ < )⸝♡ Welcome cutie! let's swap some numbers using pointers!" << endl;
    cout << "\nInput the first number ( a ): ";
    cin >> a;
    cout << "Input the second number ( b ): ";
    cin >> b;

    cout << "\nNilai a sebelum ditukar adalah: " << a << ", dan nilai b adalah: " << b << endl;
    cout << "\nSwapping numbers in progress......" << endl;
    tukar (&a, &b);
    cout << "\nTadaaa~ Sekarang nilai a menjadi: " << a << ", dan nilai b menjadi: " << b << endl;
}