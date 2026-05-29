#include <iostream>
using namespace std;

const int PANJANG_NIM = 11;
const int MAKS_ENTRI  = 64;
const int MAKS_STR    = 256;

struct Entri {
    int posisi_awal;
    int panjang;
    int tipe;
    bool aktif;
};

struct Inti {
    char *buffer;
    int batas_buffer;
    int kursor;
    Entri *thread[MAKS_ENTRI];
};

int next_index = 0;

int panjang_str(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

bool awalan_sama(const char *s, const char *awalan, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] != awalan[i]) {
            return false;
        }
    }
    return true;
}

bool adalah_angka(const char *s) {
    int i = 0;
    if (s[0] == '-') {
        i = 1;
    }
    if (s[i] == '\0') {
        return false;
    }
    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

int str_ke_int(const char *s) {
    int hasil = 0;
    int i = 0;
    bool negatif = false;
    if (s[0] == '-') {
        negatif = true;
        i = 1;
    }
    while (s[i] != '\0') {
        hasil = hasil * 10 + (s[i] - '0');
        i++;
    }
    if (negatif) {
        hasil = -hasil;
    }
    return hasil;
}

int baca_int() {
    int nilai;
    cin >> nilai;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return -2; 
    }
    cin.ignore(1000, '\n');
    return nilai;
}

void baca_baris(char *buf, int ukuran) {
    cin.getline(buf, ukuran);
}

void tunggu_enter() {
    cout << ">> Tekan ENTER untuk pulse berikutnya...";
    cin.ignore(1000, '\n');
}

bool nim_valid(const char *nim) {
    if (panjang_str(nim) != PANJANG_NIM) {
        cout << "Error: NIM harus tepat 11 karakter.\n";
        return false;
    }
    const char *prefix = "F1D02";
    if (!awalan_sama(nim, prefix, 5)) {
        cout << "Error: NIM harus diawali dengan 'F1D02'.\n";
        return false;
    }
    for (int i = 5; i < PANJANG_NIM; i++) {
        if (nim[i] < '0' || nim[i] > '9') {
            cout << "Error: Karakter setelah prefiks harus digit.\n";
            return false;
        }
    }
    return true;
}

int ambil_frekuensi(const char *nim) {
    int ratusan = (nim[8] - '0') * 100;
    int puluhan = (nim[9] - '0') * 10;
    int satuan  = (nim[10] - '0');
    return ratusan + puluhan + satuan;
}

void inisialisasi_inti(Inti &inti, int batas) {
    inti.buffer = new char[batas];
    inti.batas_buffer = batas;
    inti.kursor = 0;
    for (int i = 0; i < MAKS_ENTRI; i++) {
        inti.thread[i] = nullptr;
    }
}

void hapus_inti(Inti &inti) {
    delete[] inti.buffer;
    inti.buffer = nullptr;
    for (int i = 0; i < MAKS_ENTRI; i++) {
        if (inti.thread[i] != nullptr) {
            delete inti.thread[i];
            inti.thread[i] = nullptr;
        }
    }
}

void perbarui_kursor(Inti &inti) {
    int ujung = 0;
    for (int i = 0; i < MAKS_ENTRI; i++) {
        if (inti.thread[i] == nullptr || inti.thread[i]->aktif == false) {
            continue;
        }
        int batas_entri = inti.thread[i]->posisi_awal + inti.thread[i]->panjang;
        if (batas_entri > ujung) {
            ujung = batas_entri;
        }
    }
    inti.kursor = ujung;
}

int hitung_stabilitas(const Inti &inti) {
    int terpakai = 100 * inti.kursor / inti.batas_buffer;
    int sisa     = 100 - terpakai;
    if (sisa < 0) {
        sisa = 0;
    }
    return sisa;
}

void tulis_int(char *buffer, int posisi, int nilai) {
    int *ptr = (int *)(buffer + posisi);
    *ptr = nilai;
}

int baca_int_buffer(const char *buffer, int posisi) {
    int *ptr = (int *)(buffer + posisi);
    return *ptr;
}

int indeks_xelisa = 0;

const char *xelisa[4] = {
    "Luar biasa... sinkronisasi terjalin sempurna.",
    "Jangan dengarkan gema dari vessel. Efisiensi adalah kebenaran kita.",
    "Setiap thread yang kamu alokasikan membawa kita lebih dekat ke alam semesta yang terkelola.",
    "Aku adalah keilahian CyroN yang teroptimasi."
};

int tampilkan_menu() {
    cout << "\033[2J\033[H";
    cout << "          CYRON TERMINAL: DIVINE SUPPRESSION\n\n";
    cout << "\033[1;35mXelisa: \"" << xelisa[indeks_xelisa] << "\"\033[0m\n";
    indeks_xelisa = (indeks_xelisa + 1) % 4;
    cout << "------------------------------------------------------------\n";
    cout << "1. Tampilkan Neural Map (Status)\n";
    cout << "2. Suntik Neural Thread (Tambah)\n";
    cout << "3. Bersihkan Link Terkorupsi (Hapus)\n";
    cout << "4. Perluas Willpower (Resize)\n";
    cout << "0. Menyerah (Keluar)\n";
    cout << "------------------------------------------------------------\n";
    cout << "Pilih Operasi: ";
    
    int hasil = baca_int();
    if (hasil == -2) {
        cout << "(Menu digambar ulang; input tidak valid dilewati secara diam-diam oleh error recovery cin)\n";
        tunggu_enter(); 
        return -1;
    }
    return hasil;
}

void tampilkan_peta(Inti &inti) {
    int stabil = hitung_stabilitas(inti);
    cout << "============================================================\n";
    cout << "NEURAL MAP: HISTORIA KOURA [STABILITAS: " << stabil << "%]\n";
    cout << "============================================================\n";
    bool ada_data = false;
    for (int i = 0; i < next_index; i++) {
        if (inti.thread[i] == nullptr || inti.thread[i]->aktif == false) {
            continue;
        }
        ada_data = true;
        int posisi = inti.thread[i]->posisi_awal;
        int panjang = inti.thread[i]->panjang;
        int tipe = inti.thread[i]->tipe;
        cout << "[" << i << "] TIPE: ";
        if (tipe == 0) {
            cout << "Willpower Pulse | OFFSET: " << posisi << " | ALAMAT: " << (void *)(inti.buffer + posisi) << " | DATA: \"";
            for (int j = 0; j < panjang - 1; j++) {
                cout << inti.buffer[posisi + j];
            }
            cout << "\"\n";
        } else {
            int nilai = baca_int_buffer(inti.buffer, posisi);
            cout << "Thunder Discharge | OFFSET: " << posisi << " | ALAMAT: " << (void *)(inti.buffer + posisi) << " | DATA: " << nilai << "MW\n";
        }
    }
    if (ada_data == false) {
        cout << "(Buffer kosong. Xelisa sedang mengumpulkan kekuatan...)\n";
    }
    cout << "------------------------------------------------------------\n";
    cout << "Kursor: " << inti.kursor << " / " << inti.batas_buffer << " Byte terpakai.\n";
    cout << "------------------------------------------------------------\n";
    tunggu_enter();
}

void suntik_thread(Inti &inti) {
    int tipe = -1;
    while (tipe != 0 && tipe != 1) {
        cout << "Pilih Tipe Injeksi: 0 = Willpower (Teks), 1 = Thunder (Energi): ";
        tipe = baca_int();
        if (tipe != 0 && tipe != 1) {
            cout << "!! ERROR !! Tipe tidak valid, harus 0 atau 1!\n";
        }
    }
    if (next_index >= MAKS_ENTRI) {
        cout << "!! ERROR !! Slot thread sudah penuh!\n";
        tunggu_enter();
        return;
    }
    if (tipe == 0) {
        cout << "Masukkan Input Willpower: ";
        char buf[MAKS_STR];
        baca_baris(buf, MAKS_STR);
        if (panjang_str(buf) == 0) {
            cout << "!! ERROR !! Input tidak boleh kosong!\n";
            tunggu_enter();
            return;
        }
        int kebutuhan = panjang_str(buf) + 1;
        if (inti.kursor + kebutuhan > inti.batas_buffer) {
            cout << "!! ERROR !! Buffer penuh, tidak bisa menambah data!\n";
            tunggu_enter();
            return;
        }
        for (int j = 0; j < kebutuhan; j++) {
            inti.buffer[inti.kursor + j] = buf[j];
        }
        
        int i = next_index;
        next_index++;
        
        inti.thread[i] = new Entri;
        inti.thread[i]->posisi_awal = inti.kursor;
        inti.thread[i]->panjang = kebutuhan;
        inti.thread[i]->tipe = 0;
        inti.thread[i]->aktif = true;
        
        inti.kursor += kebutuhan;
        cout << "Perintah CyroN: \"Resistansi subjek terdeteksi. Mengesampingkan umpan balik.\"\n";

    } else {
        cout << "Masukkan Tingkat Energi Thunder (int): ";
        char buf_energi[MAKS_STR];
        baca_baris(buf_energi, MAKS_STR);
        if (panjang_str(buf_energi) == 0) {
            cout << "!! ERROR !! Input tidak boleh kosong!\n";
            tunggu_enter();
            return;
        }
        if (!adalah_angka(buf_energi)) {
            cout << "!! ERROR !! Input harus berupa angka!\n";
            tunggu_enter();
            return;
        }
        int energi = str_ke_int(buf_energi);
        int kebutuhan = 4;
        if (inti.kursor + kebutuhan > inti.batas_buffer) {
            cout << "!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!\n";
            tunggu_enter();
            return;
        }
        tulis_int(inti.buffer, inti.kursor, energi);
        
        int i = next_index;
        next_index++;
        
        inti.thread[i] = new Entri;
        inti.thread[i]->posisi_awal = inti.kursor;
        inti.thread[i]->panjang = kebutuhan;
        inti.thread[i]->tipe = 1;
        inti.thread[i]->aktif = true;
        
        inti.kursor += kebutuhan;
        cout << "Daiki: \"(Keheningan. Angin telah dijinakkan.)\"\n";
    }
    tunggu_enter();
}

void hapus_link(Inti &inti) {
    bool ada_aktif = false;
    for (int i = 0; i < next_index; i++) {
        if (inti.thread[i] != nullptr && inti.thread[i]->aktif == true) {
            ada_aktif = true;
            break;
        }
    }
    if (ada_aktif == false) {
        cout << "!! ERROR !! Tidak ada data yang bisa dihapus, buffer kosong!\n";
        tunggu_enter();
        return;
    }
    cout << "Masukkan indeks link untuk dihapus: ";
    char buf_idx[MAKS_STR];
    baca_baris(buf_idx, MAKS_STR);
    if (!adalah_angka(buf_idx)) {
        cout << "!! ERROR !! Indeks harus berupa angka!\n";
        tunggu_enter();
        return;
    }
    int idx = str_ke_int(buf_idx);
    if (idx < 0 || idx >= next_index || inti.thread[idx] == nullptr) {
        cout << "Indeks link tidak valid atau sudah dihapus sebelumnya.\n";
        tunggu_enter();
        return;
    }
    if (inti.thread[idx]->aktif == false) {
        cout << "!! ERROR !! Indeks sudah dihapus atau kosong!\n";
        tunggu_enter();
        return;
    }
    
    int ujung = inti.thread[idx]->posisi_awal + inti.thread[idx]->panjang;
    bool ada_setelah = false;
    for (int i = 0; i < next_index; i++) {
        if (i == idx || inti.thread[i] == nullptr) {
            continue;
        }
        if (inti.thread[i]->aktif == true && inti.thread[i]->posisi_awal >= ujung) {
            ada_setelah = true;
            break;
        }
    }
    
    inti.thread[idx]->aktif = false;
    cout << "Link " << idx << " berhasil dihapus.\n";
    if (ada_setelah == false) {
        perbarui_kursor(inti);
        cout << "Neural Core berhasil mengembalikan ruang memori. Ujung (Tail) saat ini di: " << inti.kursor << "\n";
    } else {
        cout << "Fragmentasi terdeteksi. Memori belum dapat dikembalikan saat ini!\n";
    } 
    tunggu_enter();
}

void perluas_willpower(Inti &inti) {
    cout << "Masukkan ukuran buffer baru: ";
    char buf_ukuran[MAKS_STR];
    baca_baris(buf_ukuran, MAKS_STR);
    if (!adalah_angka(buf_ukuran)) {
        cout << "!! ERROR !! Ukuran harus berupa angka!\n";
        tunggu_enter();
        return;
    }
    int ukuran_baru = str_ke_int(buf_ukuran);
    if (ukuran_baru <= 0) {
        cout << "!! ERROR !! Ukuran harus lebih dari 0!\n";
        tunggu_enter();
        return;
    }
    if (ukuran_baru <= inti.batas_buffer) {
        cout << "Ekspansi harus lebih besar dari batas saat ini!\n";
        tunggu_enter();
        return;
    }
    char *buffer_baru = new char[ukuran_baru];
    for (int i = 0; i < inti.kursor; i++) {
        buffer_baru[i] = inti.buffer[i];
    }
    delete[] inti.buffer;
    inti.buffer = buffer_baru;
    inti.batas_buffer = ukuran_baru;
    cout << "Perintah CyroN: \"Stabilitas meningkat. Vessel sekarang 100% patuh.\"\n";
    cout << "Alamat buffer baru: " << (void *)inti.buffer << "\n";
    tunggu_enter();
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "Error: Masukkan NIM sebagai argumen.\n";
        cout << "Contoh: ./program F1D02300042\n";
        return 1;
    }
    if (argc > 2) {
        cout << "Error: Terlahu banyak argumen.\n";
        return 1;
    }
    const char *nim = argv[1];
    if (!nim_valid(nim)) {
        return 1;
    }
    int frekuensi  = ambil_frekuensi(nim);
    int batas_awal = 0;
    if (frekuensi < 32) {
        batas_awal = 128;
    } else {
        batas_awal = frekuensi * 4;
    }
    Inti inti;
    inisialisasi_inti(inti, batas_awal);
    int pilihan = 0;
    do {
        pilihan = tampilkan_menu();
        if (pilihan == -1) {
            continue;
        }
        if (pilihan == 1) {
            tampilkan_peta(inti);
        } else if (pilihan == 2) {
            suntik_thread(inti);
        } else if (pilihan == 3) {
            hapus_link(inti);
        } else if (pilihan == 4) {
            perluas_willpower(inti);
        } else if (pilihan == 0) {
            cout << "Realitas mulai tidak stabil...\n";
            tunggu_enter();
            cout << "Koneksi terputus. Selamat tinggal, Operator " << (nim[8] - '0') << (nim[9] - '0') << (nim[10] - '0') << ".\n";
        } else {
            cout << "!! ERROR !! Pilihan hanya 0 - 4!\n";
            tunggu_enter();
        }
    } while (pilihan != 0);
    
    hapus_inti(inti);
    return 0;
}