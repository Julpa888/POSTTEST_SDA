/* Soal 1 
Kompleksitas Waktu  Analisis Algoritma
Perhatikan algoritma pencarian elemen minimum dalam sebuah array berikut (dalam pseudocode):

procedure FindMin(A : array of n elements)
    min ← A[0]
    for i ← 1 to n - 1 do
        if A[i] < min then
            min ← A[i]
        end if
    end for
    return min
end procedure

Berdasarkan algoritma di atas, implementasikan dan analisis kompleksitasnya

• Implementasikan fungsi FindMin di C++ menggunakan array bertipe integer dengan 8 elemen, diisi dengan bilangan Fibonacci (1, 1, 2, 3, 5, 8, 13, 21).
• Hitung Tmin(n) dan Tmax(n) secara manual seperti contoh pada modul (tabel pseudocode + cost).
• Tuliskan hasil analisis sebagai komentar di dalam kode (Big-O dari best case dan worst case).
Jalankan program dan tampilkan nilai minimum beserta indeksnya. */

#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indexMinimum;

    cout << "(｡˃ ᵕ < )✧ Welcome to FindMin Analyzer" << endl;

    cout << "\nArray Fibonacci kita adalah :" << endl;
    for(int i = 0; i < n; i++) {
        cout << fibonacci[i] << " ";
    }

    cout << "\n\n✧ Mencari nilai minimum sedang dalam proses...\n\n";

    int minimum = FindMin(fibonacci, n, indexMinimum);

    cout << "(≧◡≦) ♡ Tadaaa! Ini hasilnya ya~" << endl;
    cout << "Nilai minimum  : " << minimum << endl;
    cout << "Indeks minimum : " << indexMinimum << endl;
    cout << "\n(づ｡◕‿‿◕｡)づ Analisis selesai!";
    return 0;
}