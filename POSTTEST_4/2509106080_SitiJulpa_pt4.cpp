#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

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

struct NodeKereta {
    Kereta data;
    NodeKereta* next;
};

struct NodeAntrian {
    Penumpang data;
    NodeAntrian* next;
};

struct NodeRiwayat {
    Penumpang data;
    NodeRiwayat* next;
};

struct Antrian {
    NodeAntrian* depan;
    NodeAntrian* belakang;
};

struct Riwayat {
    NodeRiwayat* atas;
};

NodeKereta* headKereta = nullptr;
int n = 0;

Antrian antrianTiket;
Riwayat riwayatTransaksi;

void inisialisasiAntrian(Antrian *q) {
    q->depan = nullptr;
    q->belakang = nullptr;
}

void inisialisasiRiwayat(Riwayat *s) {
    s->atas = nullptr;
}

bool antrianKosong(Antrian *q) {
    return q->depan == nullptr;
}

bool riwayatKosong(Riwayat *s) {
    return s->atas == nullptr;
}

void masukAntrian(Antrian *q, Penumpang p) {
    NodeAntrian* newNode = new NodeAntrian;
    newNode->data = p;
    newNode->next = nullptr;
    
    if (antrianKosong(q)) {
        q->depan = newNode;
        q->belakang = newNode;
    } else {
        q->belakang->next = newNode;
        q->belakang = newNode;
    }
    cout << "\n(✧◡✧) " << p.nama << " berhasil masuk antrian!" << endl;
}

Penumpang keluarAntrian(Antrian *q) {
    Penumpang kosong = {"", 0, "", 0};
    if (antrianKosong(q)) {
        cout << "\n(｡•́︿•̀｡) Antrian kosong!" << endl;
        return kosong;
    }
    NodeAntrian* temp = q->depan;
    Penumpang p = temp->data;
    cout << "\n[PROSES TIKET] Penumpang: " << p.nama << endl;
    cout << "Rute: " << p.rute << endl;
    cout << "Harga: ¥ " << p.harga << endl;
    
    q->depan = q->depan->next;
    if (q->depan == nullptr) {
        q->belakang = nullptr;
    }
    delete temp;
    return p;
}

void simpanRiwayat(Riwayat *s, Penumpang p) {
    NodeRiwayat* newNode = new NodeRiwayat;
    newNode->data = p;
    newNode->next = s->atas;
    s->atas = newNode;
    cout << "\n(✧◡✧) Transaksi dicatat ke riwayat!" << endl;
}

Penumpang hapusRiwayat(Riwayat *s) {
    Penumpang kosong = {"", 0, "", 0};
    if (riwayatKosong(s)) {
        cout << "\n(｡•́︿•̀｡) Riwayat kosong!" << endl;
        return kosong;
    }
    NodeRiwayat* temp = s->atas;
    Penumpang p = temp->data;
    cout << "\n[BATALKAN] Transaksi terakhir dibatalkan:" << endl;
    cout << "Penumpang: " << p.nama << ", Rute: " << p.rute << endl;
    s->atas = s->atas->next;
    delete temp;
    return p;
}

void intipAntrian(Antrian *q) {
    if (antrianKosong(q)) {
        cout << "\n(｡•́︿•̀｡) Antrian kosong!" << endl;
        return;
    }
    Penumpang p = q->depan->data;
    cout << "\n[PEEK] Penumpang terdepan:" << endl;
    cout << "Nama: " << p.nama << ", Rute: " << p.rute << ", Harga: ¥ " << p.harga << endl;
}

void intipRiwayat(Riwayat *s) {
    if (riwayatKosong(s)) {
        cout << "\n(｡•́︿•̀｡) Riwayat kosong!" << endl;
        return;
    }
    Penumpang p = s->atas->data;
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
    
    NodeAntrian* ptr = q->depan;
    int no = 1;
    while (ptr != nullptr) {
        cout << "| " << setw(4) << no << " "
            << "| " << left << setw(16) << ptr->data.nama << " "
            << "| " << left << setw(20) << ptr->data.rute << " "
            << "| " << "¥ " << right << setw(8) << ptr->data.harga << " |" << endl;
        ptr = ptr->next;
        no++;
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
    
    NodeRiwayat* ptr = s->atas;
    int no = 1;
    while (ptr != nullptr) {
        cout << "| " << setw(4) << no << " "
            << "| " << left << setw(16) << ptr->data.nama << " "
            << "| " << left << setw(20) << ptr->data.rute << " "
            << "| " << "¥ " << right << setw(8) << ptr->data.harga << " |" << endl;
        ptr = ptr->next;
        no++;
    }
    cout << "+------+------------------+----------------------+-------------+" << endl;
}

void tukar(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

bool cekNomorDuplikat(int nomor) {
    NodeKereta* curr = headKereta;
    while (curr != nullptr) {
        if (curr->data.nomor == nomor) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void tampil(NodeKereta* head, int jumlah) {
    if (jumlah == 0) {
        cout << "\n(｡•́︿•̀｡) Belum ada data kereta." << endl;
        return;
    }

    cout << "\n";
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    cout << "| No.  | Kode   | Nama Kereta      | Rute                 | Jam    | Harga       |" << endl;
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    
    NodeKereta* ptr = head;
    int i = 1;
    while (ptr != nullptr) {
        string rute = ptr->data.asal + " -> " + ptr->data.tujuan;
        
        cout << "| " << setw(4) << i << " "
            << "| " << setw(6) << ptr->data.nomor << " "
            << "| " << left << setw(16) << ptr->data.nama << " "
            << "| " << left << setw(20) << rute << " "
            << "| " << setw(6) << ptr->data.jam << " "
            << "| " << "¥ " << right << setw(8) << ptr->data.harga << " |" << endl;
        ptr = ptr->next;
        i++;
    }
    cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
}

void tambah(NodeKereta* &head, int &jumlah) {
    cout << "\n=== Input Data Kereta Baru ===" << endl;
    
    int nomorInput;
    cout << "Nomor Kereta: ";
    cin >> nomorInput;
    
    if (cekNomorDuplikat(nomorInput)) {
        cout << "(>_<) Nomor kereta sudah digunakan!" << endl;
        return;
    }
    
    NodeKereta* newNode = new NodeKereta;
    newNode->data.nomor = nomorInput;
    cin.ignore();

    cout << "Nama Kereta: ";
    getline(cin, newNode->data.nama);
    cout << "Stasiun Asal: ";
    getline(cin, newNode->data.asal);
    cout << "Stasiun Tujuan: ";
    getline(cin, newNode->data.tujuan);
    cout << "Jam Keberangkatan (HH:MM): ";
    cin >> newNode->data.jam;
    cout << "Harga Tiket: ";
    cin >> newNode->data.harga;
    
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        NodeKereta* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    jumlah++;
    cout << "\n(✧◡✧) Data berhasil ditambahkan!" << endl;
}

void cariRute(NodeKereta* head, int jumlah) {
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

    NodeKereta* ptr = head;
    int i = 1;
    while (ptr != nullptr) {
        if (ptr->data.asal == asal && ptr->data.tujuan == tujuan) {
            string rute = ptr->data.asal + " -> " + ptr->data.tujuan;
            cout << "| " << setw(4) << i << " "
                << "| " << setw(6) << ptr->data.nomor << " "
                << "| " << left << setw(16) << ptr->data.nama << " "
                << "| " << left << setw(20) << rute << " "
                << "| " << setw(6) << ptr->data.jam << " "
                << "| " << "¥ " << right << setw(8) << ptr->data.harga << " |" << endl;
            ketemu = true;
        }
        ptr = ptr->next;
        i++;
    }
    
    if (ketemu) {
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "\n(✧ω✧) Ditemukan kereta untuk rute ini!" << endl;
    } else {
        cout << "| Tidak ditemukan                                                                |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "\n(｡•́︿•̀｡) Rute tidak tersedia." << endl;
    }}

void cariNomorJump(NodeKereta* &head, int jumlah) {
    if (jumlah == 0) {
        cout << "\n(｡•́︿•̀｡) Data masih kosong." << endl;
        return;
    }

    Kereta* backup = new Kereta[jumlah];
    NodeKereta* curr = head;
    for(int i = 0; i < jumlah; i++) {
        backup[i] = curr->data;
        curr = curr->next;
    }

    for (int i = 0; i < jumlah-1; i++) {
        NodeKereta* minNode = head;
        NodeKereta* ptr = head;
        for (int j = 0; j < jumlah-i-1; j++) {
            if (ptr->data.nomor > ptr->next->data.nomor) {
                tukar(&ptr->data, &ptr->next->data);
            }
            ptr = ptr->next;
        }}

    int cari;
    cout << "\n=== Cari Berdasarkan Nomor (Jump Search) ===" << endl;
    cout << "Masukkan Nomor Kereta: ";
    cin >> cari;

    int step = sqrt(jumlah);
    int prev = 0;
    int posisi = -1;
    
    Kereta* arrSorted = new Kereta[jumlah];
    curr = head;
    for(int i = 0; i < jumlah; i++) {
        arrSorted[i] = curr->data;
        curr = curr->next;
    }

    while (prev < jumlah && arrSorted[min(step, jumlah) - 1].nomor < cari) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) break;
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (arrSorted[i].nomor == cari) {
            posisi = i;
            break;
        }}

    if (posisi != -1) {
        cout << "\n(✧ω✧) Data Ditemukan!" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        cout << "| No.  | Kode   | Nama Kereta      | Rute                 | Jam    | Harga       |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
        
        string rute = arrSorted[posisi].asal + " -> " + arrSorted[posisi].tujuan;
        cout << "| " << setw(4) << (posisi+1) << " "
            << "| " << setw(6) << arrSorted[posisi].nomor << " "
            << "| " << left << setw(16) << arrSorted[posisi].nama << " "
            << "| " << left << setw(20) << rute << " "
            << "| " << setw(6) << arrSorted[posisi].jam << " "
            << "| " << "¥ " << right << setw(8) << arrSorted[posisi].harga << " |" << endl;
        cout << "+------+--------+------------------+----------------------+--------+-------------+" << endl;
    } else {
        cout << "\n(｡•́︿•̀｡) Nomor kereta " << cari << " tidak ditemukan." << endl;
    }

    delete[] arrSorted;
    delete[] backup;
}

void merge(Kereta arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

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
    }
    
    delete[] L;
    delete[] R;
}

void mergeSort(Kereta arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }}

void sortHarga(NodeKereta* head, int jumlah) {
    if (jumlah < 2) {
        cout << "\n(◕‿◕) Minimal 2 data untuk diurutkan." << endl;
        return;
    }

    for (int i = 0; i < jumlah-1; i++) {
        NodeKereta* minNode = head;
        NodeKereta* ptr = head;
        for (int j = 0; j < jumlah-i-1; j++) {
            if (ptr->next != nullptr && ptr->data.harga > ptr->next->data.harga) {
                tukar(&ptr->data, &ptr->next->data);
            }
            ptr = ptr->next;
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
            tampil(headKereta, n);
        } else if (pilihJadwal == 2) {
            tambah(headKereta, n);
        } else if (pilihJadwal == 3) {
            cariRute(headKereta, n);
        } else if (pilihJadwal == 4) {
            cariNomorJump(headKereta, n);
        } else if (pilihJadwal == 5) {
            Kereta* arrTemp = new Kereta[n];
            NodeKereta* curr = headKereta;
            for(int i = 0; i < n; i++) {
                arrTemp[i] = curr->data;
                curr = curr->next;
            }
            mergeSort(arrTemp, 0, n-1);
            curr = headKereta;
            for(int i = 0; i < n; i++) {
                curr->data = arrTemp[i];
                curr = curr->next;
            }
            delete[] arrTemp;
            cout << "\n(✧◡✧) Data berhasil diurutkan berdasarkan nama (A-Z)!" << endl;
            tampil(headKereta, n);
        } else if (pilihJadwal == 6) {
            sortHarga(headKereta, n);
            tampil(headKereta, n);
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
                tampil(headKereta, n);
                int nomorPilih;
                cout << "\nMasukkan Kode Kereta yang ingin dibeli: ";
                cin >> nomorPilih;
                
                bool ketemu = false;
                NodeKereta* curr = headKereta;
                while (curr != nullptr) {
                    if (curr->data.nomor == nomorPilih) {
                        cin.ignore();
                        Penumpang baru;
                        cout << "Nama Penumpang: ";
                        getline(cin, baru.nama);
                        baru.nomorKereta = curr->data.nomor;
                        baru.rute = curr->data.asal + " -> " + curr->data.tujuan;
                        baru.harga = curr->data.harga;
                        masukAntrian(&antrianTiket, baru);
                        ketemu = true;
                        break;
                    }
                    curr = curr->next;
                }
                if (!ketemu) {
                    cout << "\n(>_<) Nomor kereta tidak ditemukan!" << endl;
                }}}
        else if (pilihTiket == 2) {
            if (!antrianKosong(&antrianTiket)) {
                Penumpang proses = keluarAntrian(&antrianTiket);
                if (proses.nama != "") {
                    simpanRiwayat(&riwayatTransaksi, proses);
                }}}
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
    headKereta = new NodeKereta{Kereta{101, "Nozomi", "Tokyo", "Shin-Osaka", "06:00", 15000}, nullptr};
    headKereta->next = new NodeKereta{Kereta{102, "Hikari", "Tokyo", "Nagoya", "07:00", 12000}, nullptr};
    headKereta->next->next = new NodeKereta{Kereta{103, "Kodama", "Tokyo", "Shizuoka", "08:00", 8000}, nullptr};
    headKereta->next->next->next = new NodeKereta{Kereta{104, "Kagayaki", "Tokyo", "Kanazawa", "09:00", 14000}, nullptr};
    headKereta->next->next->next->next = new NodeKereta{Kereta{105, "Hayabusa", "Tokyo", "Shin-Hakodate", "10:00", 22000}, nullptr};
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