#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAX 100

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    string jam;
    int harga;
};

struct Penumpang {
    string nama;
    int nomorKereta;
    string rute;
    int harga;
};

struct Antrian {
    Penumpang data[MAX];
    int depan;
    int belakang;
};

struct Riwayat {
    Penumpang data[MAX];
    int atas;
};

Kereta dataKereta[MAX];
int n = 0;

Antrian antrianTiket;
Riwayat riwayatTransaksi;

void inisialisasiAntrian(Antrian *q) {
    q->depan = -1;
    q->belakang = -1;
}

void inisialisasiRiwayat(Riwayat *s) {
    s->atas = -1;
}

bool antrianKosong(Antrian *q) {
    return q->depan == -1;
}

bool antrianPenuh(Antrian *q) {
    return q->belakang == MAX - 1;
}

bool riwayatKosong(Riwayat *s) {
    return s->atas == -1;
}

bool riwayatPenuh(Riwayat *s) {
    return s->atas == MAX - 1;
}

void masukAntrian(Antrian *q, Penumpang p) {
    if (antrianPenuh(q)) {
        cout << "\n(>_<) Antrian penuh!" << endl;
        return;
    }
    if (antrianKosong(q)) {
        q->depan = 0;
    }
    q->belakang++;
    q->data[q->belakang] = p;
    cout << "\n(✧◡✧) " << p.nama << " berhasil masuk antrian!" << endl;
}

Penumpang keluarAntrian(Antrian *q) {
    Penumpang kosong = {"", 0, "", 0};
    if (antrianKosong(q)) {
        cout << "\n(｡•́︿•̀｡) Antrian kosong!" << endl;
        return kosong;
    }
    Penumpang p = q->data[q->depan];
    cout << "\n[PROSES TIKET] Penumpang: " << p.nama << endl;
    cout << "Rute: " << p.rute << endl;
    cout << "Harga: ¥ " << p.harga << endl;
    
    if (q->depan == q->belakang) {
        q->depan = -1;
        q->belakang = -1;
    } else {
        q->depan++;
    }
    return p;
}

void simpanRiwayat(Riwayat *s, Penumpang p) {
    if (riwayatPenuh(s)) {
        cout << "\n(>_<) Riwayat penuh!" << endl;
        return;
    }
    s->atas++;
    s->data[s->atas] = p;
    cout << "\n(✧◡✧) Transaksi dicatat ke riwayat!" << endl;
}

Penumpang hapusRiwayat(Riwayat *s) {
    Penumpang kosong = {"", 0, "", 0};
    if (riwayatKosong(s)) {
        cout << "\n(｡•́︿•̀｡) Riwayat kosong!" << endl;
        return kosong;
    }
    Penumpang p = s->data[s->atas];
    cout << "\n[BATALKAN] Transaksi terakhir dibatalkan:" << endl;
    cout << "Penumpang: " << p.nama << ", Rute: " << p.rute << endl;
    s->atas--;
    return p;
}

void intipAntrian(Antrian *q) {
    if (antrianKosong(q)) {
        cout << "\n(｡•́︿•̀｡) Antrian kosong!" << endl;
        return;
    }
    Penumpang p = q->data[q->depan];
    cout << "\n[PEEK] Penumpang terdepan:" << endl;
    cout << "Nama: " << p.nama << ", Rute: " << p.rute << ", Harga: ¥ " << p.harga << endl;
}

void intipRiwayat(Riwayat *s) {
    if (riwayatKosong(s)) {
        cout << "\n(｡•́︿•̀｡) Riwayat kosong!" << endl;
        return;
    }
    Penumpang p = s->data[s->atas];
    cout << "\n[PEEK] Transaksi terakhir:" << endl;
    cout << "Nama: " << p.nama << ", Rute: " << p.rute << ", Harga: ¥ " << p.harga << endl;
}

void tampilAntrian(Antrian *q) {
    if (antrianKosong(q)) {
        cout << "\n(｡•́︿•̀｡) Antrian kosong." << endl;
        return;
    }
    cout << "\n=== ANTRIAN PEMBELIAN TIKET ===" << endl;
    cout << "+------+------------------+----------------------+-------------+" << endl;
    cout << "| No.  | Nama Penumpang   | Rute                 | Harga       |" << endl;
    cout << "+------+------------------+----------------------+-------------+" << endl;
    
    Penumpang *ptr = q->data + q->depan;
    for (int i = q->depan; i <= q->belakang; i++, ptr++) {
        cout << "| " << setw(4) << (i - q->depan + 1) << " "
            << "| " << left << setw(16) << ptr->nama << " "
            << "| " << left << setw(20) << ptr->rute << " "
            << "| " << "¥ " << right << setw(8) << ptr->harga << " |" << endl;
    }
    cout << "+------+------------------+----------------------+-------------+" << endl;
}

void tampilRiwayat(Riwayat *s) {
    if (riwayatKosong(s)) {
        cout << "\n(｡•́︿•̀｡) Riwayat kosong." << endl;
        return;
    }
    cout << "\n=== RIWAYAT TRANSAKSI ===" << endl;
    cout << "+------+------------------+----------------------+-------------+" << endl;
    cout << "| No.  | Nama Penumpang   | Rute                 | Harga       |" << endl;
    cout << "+------+------------------+----------------------+-------------+" << endl;
    
    Penumpang *ptr = s->data + s->atas;
    for (int i = s->atas; i >= 0; i--, ptr--) {
        cout << "| " << setw(4) << (s->atas - i + 1) << " "
            << "| " << left << setw(16) << ptr->nama << " "
            << "| " << left << setw(20) << ptr->rute << " "
            << "| " << "¥ " << right << setw(8) << ptr->harga << " |" << endl;
    }
    cout << "+------+------------------+----------------------+-------------+" << endl;
}

// Ini pointer buat swap
void tukar(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// Ini biar nomor kereta ga duplikat, karna disini saya pakai logic nomor keberangkatan kereta itu harus berbeda-beda. walaupun nama keretanya sama tapi bisa saja dia berangkat lebih dari 1x pada hari itu
bool cekNomorDuplikat(int nomor) {
    for (int i = 0; i < n; i++) {
        if (dataKereta[i].nomor == nomor) {
            return true;
        }
    }
    return false;
}

void tampil(Kereta *arr, int jumlah) {
    if (jumlah == 0) {
        cout << "\n(｡•́︿•̀｡) Belum ada data kereta." << endl;
        return;
    }

    cout << "\n";
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    cout << "| No.  | Kode   | Nama Kereta      | Rute                 | Jam    | Harga       |" << endl;
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        string rute = (arr+i)->asal + " -> " + (arr+i)->tujuan;
        
        cout << "| " << setw(4) << (i+1) << " "
            << "| " << setw(6) << (arr+i)->nomor << " "
            << "| " << left << setw(16) << (arr+i)->nama << " "
            << "| " << left << setw(20) << rute << " "
            << "| " << setw(6) << (arr+i)->jam << " "
            << "| " << "¥ " << right << setw(8) << (arr+i)->harga << " |" << endl;
    }
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
}

void tambah(Kereta *arr, int &jumlah) {
    if (jumlah >= MAX) {
        cout << "\n(>_<) Data sudah penuh." << endl;
        return;
    }

    cout << "\n=== Input Data Kereta Baru ===" << endl;
    
    int nomorInput;
    cout << "Nomor Kereta: ";
    cin >> nomorInput;
    
    if (cekNomorDuplikat(nomorInput)) {
        cout << "(>_<) Nomor kereta sudah digunakan!" << endl;
        return;
    }
    
    arr[jumlah].nomor = nomorInput;
    cin.ignore();

    cout << "Nama Kereta: ";
    getline(cin, arr[jumlah].nama);
    cout << "Stasiun Asal: ";
    getline(cin, arr[jumlah].asal);
    cout << "Stasiun Tujuan: ";
    getline(cin, arr[jumlah].tujuan);
    cout << "Jam Keberangkatan (HH:MM): ";
    cin >> arr[jumlah].jam;
    cout << "Harga Tiket: ";
    cin >> arr[jumlah].harga;

    jumlah++;
    cout << "\n(✧◡✧) Data berhasil ditambahkan!" << endl;
}

void cariRute(Kereta *arr, int jumlah) {
    if (jumlah == 0) {
        cout << "\n(｡•́︿•̀｡) Data masih kosong." << endl;
        return;
    }

    string asal, tujuan;
    cin.ignore();
    
    cout << "\n=== Cari Berdasarkan Rute (Linear Search) ===" << endl;
    cout << "Stasiun Asal: ";
    getline(cin, asal);
    cout << "Stasiun Tujuan: ";
    getline(cin, tujuan);

    bool ketemu = false;
    cout << "\nHasil Pencarian:" << endl;
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    cout << "| No.  | Kode   | Nama Kereta      | Rute                 | Jam    | Harga       |" << endl;
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;

    for (int i = 0; i < jumlah; i++) {
        if ((arr+i)->asal == asal && (arr+i)->tujuan == tujuan) {
            string rute = (arr+i)->asal + " -> " + (arr+i)->tujuan;
            cout << "| " << setw(4) << (i+1) << " "
                << "| " << setw(6) << (arr+i)->nomor << " "
                << "| " << left << setw(16) << (arr+i)->nama << " "
                << "| " << left << setw(20) << rute << " "
                << "| " << setw(6) << (arr+i)->jam << " "
                << "| " << "¥ " << right << setw(8) << (arr+i)->harga << " |" << endl;
            ketemu = true;
        }}
    
    if (ketemu) {
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "\n(✧ω✧) Ditemukan kereta untuk rute ini!" << endl;
    } else {
        cout << "| Tidak ditemukan                                                                |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "\n(｡•́︿•̀｡) Rute tidak tersedia." << endl;
    }}

void cariNomorJump(Kereta *arr, int jumlah) {
    if (jumlah == 0) {
        cout << "\n(｡•́︿•̀｡) Data masih kosong." << endl;
        return;
    }

    Kereta backup[MAX];
    for(int i = 0; i < jumlah; i++) {
        backup[i] = *(arr + i);
    }

    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if ((arr + j)->nomor > (arr + j + 1)->nomor) {
                tukar((arr + j), (arr + j + 1));
            }}}

    int cari;
    cout << "\n=== Cari Berdasarkan Nomor (Jump Search) ===" << endl;
    cout << "Masukkan Nomor Kereta: ";
    cin >> cari;

    int step = sqrt(jumlah);
    int prev = 0;
    int posisi = -1;

    while (prev < jumlah && (arr + min(step, jumlah) - 1)->nomor < cari) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) break;
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if ((arr + i)->nomor == cari) {
            posisi = i;
            break;
        }}

    if (posisi != -1) {
        cout << "\n(✧ω✧) Data Ditemukan!" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "| No.  | Kode   | Nama Kereta      | Rute                 | Jam    | Harga       |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        
        string rute = (arr + posisi)->asal + " -> " + (arr + posisi)->tujuan;
        cout << "| " << setw(4) << (posisi+1) << " "
            << "| " << setw(6) << (arr + posisi)->nomor << " "
            << "| " << left << setw(16) << (arr + posisi)->nama << " "
            << "| " << left << setw(20) << rute << " "
            << "| " << setw(6) << (arr + posisi)->jam << " "
            << "| " << "¥ " << right << setw(8) << (arr + posisi)->harga << " |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    } else {
        cout << "\n(｡•́︿•̀｡) Nomor kereta " << cari << " tidak ditemukan." << endl;
    }

    for(int i = 0; i < jumlah; i++) {
        *(arr + i) = backup[i];
    }}

void merge(Kereta arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    Kereta L[100], R[100];

    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }}

void mergeSort(Kereta arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }}

void sortHarga(Kereta *arr, int jumlah) {
    if (jumlah < 2) {
        cout << "\n(◕‿◕) Minimal 2 data untuk diurutkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah-1; i++) {
        int min = i;
        for (int j = i+1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }
        if (min != i) {
            tukar((arr + i), (arr + min));
        }}

    cout << "\n(✧ω✧) Data berhasil diurutkan berdasarkan harga (termurah)!" << endl;
}

void menuJadwal() {
    int pilihJadwal;
    do {
        cout << "\n=== MENU JADWAL KERETA ===" << endl;
        cout << "1. Tampil Jadwal Semua Kereta" << endl;
        cout << "2. Tambah Data Kereta Baru" << endl;
        cout << "3. Cari Berdasarkan Rute (Linear Search)" << endl;
        cout << "4. Cari Berdasarkan Nomor (Jump Search)" << endl;
        cout << "5. Urutkan Nama Kereta (Merge Sort A-Z)" << endl;
        cout << "6. Urutkan Harga Tiket (Selection Sort)" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu (0-6): ";
        cin >> pilihJadwal;

        if (pilihJadwal == 1) {
            tampil(dataKereta, n);
        } else if (pilihJadwal == 2) {
            tambah(dataKereta, n);
        } else if (pilihJadwal == 3) {
            cariRute(dataKereta, n);
        } else if (pilihJadwal == 4) {
            cariNomorJump(dataKereta, n);
        } else if (pilihJadwal == 5) {
            mergeSort(dataKereta, 0, n-1);
            cout << "\n(✧◡✧) Data berhasil diurutkan berdasarkan nama (A-Z)!" << endl;
            tampil(dataKereta, n);
        } else if (pilihJadwal == 6) {
            sortHarga(dataKereta, n);
            tampil(dataKereta, n);
        } else if (pilihJadwal == 0) {
            break;
        } else {
            cout << "\n(>_<) Pilihan tidak valid!" << endl;
        }
    } while(true);
}

void menuTiket() {
    int pilihTiket;
    do {
        cout << "\n=== MENU TIKET & TRANSAKSI ===" << endl;
        cout << "1. Beli Tiket" << endl;
        cout << "2. Proses Tiket" << endl;
        cout << "3. Tampil Antrian" << endl;
        cout << "4. Intip Penumpang Terdepan" << endl;
        cout << "5. Batalkan Transaksi Terakhir" << endl;
        cout << "6. Tampil Riwayat" << endl;
        cout << "7. Intip Transaksi Terakhir Riwayat" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilih menu (0-7): ";
        cin >> pilihTiket;

        if (pilihTiket == 1) {
            if (n == 0) {
                cout << "\n(｡•́︿•̀｡) Belum ada data kereta tersedia!" << endl;
            } else {
                tampil(dataKereta, n);
                int nomorPilih;
                cout << "\nMasukkan Kode Kereta yang ingin dibeli: ";
                cin >> nomorPilih;
                
                bool ketemu = false;
                for (int i = 0; i < n; i++) {
                    if (dataKereta[i].nomor == nomorPilih) {
                        cin.ignore();
                        Penumpang baru;
                        cout << "Nama Penumpang: ";
                        getline(cin, baru.nama);
                        baru.nomorKereta = dataKereta[i].nomor;
                        baru.rute = dataKereta[i].asal + " -> " + dataKereta[i].tujuan;
                        baru.harga = dataKereta[i].harga;
                        masukAntrian(&antrianTiket, baru);
                        ketemu = true;
                        break;
                    }}
                if (!ketemu) {
                    cout << "\n(>_<) Nomor kereta tidak ditemukan!" << endl;
                }}}
        else if (pilihTiket == 2) {
            if (!antrianKosong(&antrianTiket)) {
                Penumpang proses = keluarAntrian(&antrianTiket);
                if (proses.nama != "") {
                    simpanRiwayat(&riwayatTransaksi, proses);
                }
            }
        }
        else if (pilihTiket == 3) {
            tampilAntrian(&antrianTiket);
        }
        else if (pilihTiket == 4) {
            intipAntrian(&antrianTiket);
        }
        else if (pilihTiket == 5) {
            hapusRiwayat(&riwayatTransaksi);
        }
        else if (pilihTiket == 6) {
            tampilRiwayat(&riwayatTransaksi);
        }
        else if (pilihTiket == 7) {
            intipRiwayat(&riwayatTransaksi);
        }
        else if (pilihTiket == 0) {
            break;
        } else {
            cout << "\n(>_<) Pilihan tidak valid!" << endl;
        }
    } while(true);
}

int main() {
    dataKereta[0] = {101, "Nozomi", "Tokyo", "Shin-Osaka", "06:00", 15000};
    dataKereta[1] = {102, "Hikari", "Tokyo", "Nagoya", "07:00", 12000};
    dataKereta[2] = {103, "Kodama", "Tokyo", "Shizuoka", "08:00", 8000};
    dataKereta[3] = {104, "Kagayaki", "Tokyo", "Kanazawa", "09:00", 14000};
    dataKereta[4] = {105, "Hayabusa", "Tokyo", "Shin-Hakodate", "10:00", 22000};
    n = 5;

    inisialisasiAntrian(&antrianTiket);
    inisialisasiRiwayat(&riwayatTransaksi);

    int pilih;
    
    cout << "\n==========================================" << endl;
    cout << "   SISTEM INFORMASI KERETA API JEPANG" << endl;
    cout << "==========================================" << endl;
    cout << "\n(◕‿◕) Selamat datang di sistem manajemen kereta Jepang!" << endl;
    
    do {
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Jadwal Kereta" << endl;
        cout << "2. Tiket & Transaksi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu (0-2): ";
        cin >> pilih;

        if (pilih == 1) {
            menuJadwal();
        } else if (pilih == 2) {
            menuTiket();
        } else if (pilih == 0) {
            cout << "\n(｡•́︿•̀｡) Yakin mau keluar?" << endl;
            cout << "Terima kasih telah menggunakan sistem ini! (◕‿◕)" << endl;
            cout << "Semoga perjalananmu menyenangkan~" << endl;
            break;
        } else {
            cout << "\n(>_<) Pilihan tidak valid!" << endl;
        }

    } while(true);

    return 0;
}