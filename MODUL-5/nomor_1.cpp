#include <iostream>
using namespace std;
 
const int MAX_PASIEN = 50;
int pilihan;
int id_pasien = 1;
int tanggal = 21, bulan = 5, tahun = 2026;
 
void clearScreen() {
    system("cls");
}
 
void pauseScreen() {
    cout << "Press any key to continue . . . ";
    cin.get();
}
 
struct Alergi {
    char nama_alergen[100];
    char reaksi[100];
};
 
struct Pasien {
    int id;
    char jenis_kelamin;
    char status_bpjs;
    char gol_darah[5];
    int tgl_lahir, bln_lahir, thn_lahir;
    int kode_pos;
    char no_telepon[30];
    char nik[1000];
    char nama[1000];
    char jalan[1000];
    char kelurahan[1000];
    char kota[1000];
    char provinsi[1000];
    int jumlah_alergi;
    Alergi daftar_alergi[5];
    int tgl_masuk, bln_masuk, thn_masuk;
};
 
Pasien daftar_pasien[MAX_PASIEN];
int total_pasien = 0;
 
bool cekNamaSama(char nama1[], char nama2[]) {
    int i = 0;
    while (nama1[i] != '\0' && nama2[i] != '\0') {
        if (nama1[i] != nama2[i]) return false;
        i++;
    }
    return (nama1[i] == '\0' && nama2[i] == '\0');
}
 
bool cekTahunKabisat(int thn) {
    return (thn % 4 == 0 && thn % 100 != 0) || (thn % 400 == 0);
}
 
int ambilHariBulan(int bln, int thn) {
    if (bln == 2) return cekTahunKabisat(thn) ? 29 : 28;
    if (bln == 4 || bln == 6 || bln == 9 || bln == 11) return 30;
    return 31;
}
 
long hitungTotalHari(int tgl, int bln, int thn) {
    long total = tgl;
    for (int i = 1; i < thn; i++) total += cekTahunKabisat(i) ? 366 : 365;
    for (int i = 1; i < bln; i++) total += ambilHariBulan(i, thn);
    return total;
}
 
int hitungLamaRawat(int tgl_masuk, int bln_masuk, int thn_masuk,
                    int tgl_keluar, int bln_keluar, int thn_keluar) {
    long hari_masuk  = hitungTotalHari(tgl_masuk,  bln_masuk,  thn_masuk);
    long hari_keluar = hitungTotalHari(tgl_keluar, bln_keluar, thn_keluar);
    return (int)(hari_keluar - hari_masuk);
}
 
void tampilkanDataPasien(int indeks) {
    cout << "ID       : " << daftar_pasien[indeks].id;
    cout << "\t\t\t\tTgl Masuk "<< daftar_pasien[indeks].tgl_masuk << "/"
         << daftar_pasien[indeks].bln_masuk << "/"
         << daftar_pasien[indeks].thn_masuk << "\n";
    cout << "NIK      : " << daftar_pasien[indeks].nik   << "\n";
    cout << "Nama     : " << daftar_pasien[indeks].nama  << "\n";
    cout << "JK       : " << daftar_pasien[indeks].jenis_kelamin << "\n";
    cout << "Tgl Lahir\n";
    cout << "    Tanggal  : ";
    if (daftar_pasien[indeks].tgl_lahir < 10) cout << "0";
    cout << daftar_pasien[indeks].tgl_lahir << "\n";
    cout << "    Bulan    : ";
    if (daftar_pasien[indeks].bln_lahir < 10) cout << "0";
    cout << daftar_pasien[indeks].bln_lahir << "\n";
    cout << "    Tahun    : " << daftar_pasien[indeks].thn_lahir << "\n";
 
    cout << "Gol      : " << daftar_pasien[indeks].gol_darah   << "\n";
    cout << "Telp     : " << daftar_pasien[indeks].no_telepon  << "\n";
    cout << "BPJS     : "
         << ((daftar_pasien[indeks].status_bpjs == 'y' || daftar_pasien[indeks].status_bpjs == 'Y')
             ? "Ya" : "Tidak") << "\n";
 
    cout << "Alamat\n";
    cout << "    Jalan     : " << daftar_pasien[indeks].jalan     << "\n";
    cout << "    Kelurahan : " << daftar_pasien[indeks].kelurahan << "\n";
    cout << "    Kota      : " << daftar_pasien[indeks].kota      << "\n";
    cout << "    Provinsi  : " << daftar_pasien[indeks].provinsi  << "\n";
    cout << "    Kode Pos  : " << daftar_pasien[indeks].kode_pos  << "\n";
 
    cout << "Alergi   :\n";
    if (daftar_pasien[indeks].jumlah_alergi == 0) {
        cout << "    Tidak ada\n";
    } else {
        for (int j = 0; j < daftar_pasien[indeks].jumlah_alergi; j++) {
            cout << "    "
                 << daftar_pasien[indeks].daftar_alergi[j].nama_alergen
                 << " -> "
                 << daftar_pasien[indeks].daftar_alergi[j].reaksi << "\n";
        }
    }
    cout << "---------------------------------------------------------\n";
}
void tampilkanMenuUtama() {
    while (true) {
        cout << "=========================================================\n";
        cout << "   SISTEM MANAJEMEN RS GAZACARE PLUS\t\t"
             << tanggal << "/" << bulan << "/" << tahun << "\n";
        cout << "=========================================================\n";
        cout << "[1]  Daftarkan Pasien Baru\n";
        cout << "[2]  Lihat Semua Pasien\n";
        cout << "[3]  Cari Pasien\n";
        cout << "[4]  Pulangkan Pasien\n";
        cout << "[0]  Keluar\n";
        cout << "=========================================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;
 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Pilihan tidak valid!\n";
            pauseScreen();
            clearScreen();
        } 
        else if (pilihan < 0 || pilihan > 4) {
            cin.ignore(1000, '\n');
            cout << "[!] Pilihan tidak valid!\n";
            pauseScreen();
            clearScreen();
        } 
        else {
            cin.ignore(1000, '\n');
            break;
        }
    }
}
 
void daftarkanPasienBaru() {
    cout << "=========================================================\n";
    cout << "   PENDAFTARAN PASIEN BARU\t\t\t" << tanggal << "/" << bulan << "/" << tahun << "\n";
    cout << "=========================================================";
    Pasien pasien_baru;
    pasien_baru.id        = id_pasien;
    pasien_baru.tgl_masuk = tanggal;
    pasien_baru.bln_masuk = bulan;
    pasien_baru.thn_masuk = tahun;
    while (true) {
        cout << "\nNIK (16 digit)    : ";
        cin.getline(pasien_baru.nik, 1000);
 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "       [!] Input terlalu panjang atau tidak valid! Silakan ulangi.";
            continue;
        }
        int panjang_nik  = 0;
        bool semua_angka = true;
        while (pasien_baru.nik[panjang_nik] != '\0') {
            if (pasien_baru.nik[panjang_nik] < '0' || pasien_baru.nik[panjang_nik] > '9')
                semua_angka = false;
            panjang_nik++;
        }
        if (panjang_nik == 0) {
            cout << "       [!] NIK tidak boleh kosong! Silakan ulangi.";
        } else if (!semua_angka) {
            cout << "       [!] NIK tidak boleh mengandung huruf atau simbol! Silakan ulangi.";
        } else if (panjang_nik < 16) {
            cout << "       [!] NIK minimal harus 16 digit! (Input Anda: "
                 << panjang_nik << " digit). Silakan ulangi.";
        } else {
            break;
        }
    }
    cout << "Nama              : ";
    cin.getline(pasien_baru.nama, 1000);
    cout << "Tgl Lahir\n";
    while (true) {
        cout << "       Tanggal    : ";
        cin >> pasien_baru.tgl_lahir;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "       [!] Input harus berupa angka! Silakan ulangi.\n";
        } else if (pasien_baru.tgl_lahir < 1 || pasien_baru.tgl_lahir > 31) {
            cout << "       [!] Tanggal tidak valid (harus 1-31)! Silakan ulangi.\n";
        } else { break; }
    }
    while (true) {
        cout << "       Bulan      : ";
        cin >> pasien_baru.bln_lahir;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "       [!] Input harus berupa angka! Silakan ulangi.\n";
        } else if (pasien_baru.bln_lahir < 1 || pasien_baru.bln_lahir > 12) {
            cout << "       [!] Bulan tidak valid (harus 1-12)! Silakan ulangi.\n";
        } else { break; }
    }
    while (true) {
        cout << "       Tahun      : ";
        cin >> pasien_baru.thn_lahir;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "       [!] Input harus berupa angka! Silakan ulangi.\n";
        } else if (pasien_baru.thn_lahir < 1900 || pasien_baru.thn_lahir > tahun) {
            cout << "       [!] Tahun tidak valid! Silakan ulangi.\n";
        } else { break; }
    }
    while (true) {
        cout << "Jenis Kelamin(L/P): ";
        cin >> pasien_baru.jenis_kelamin;
        cin.ignore(1000, '\n');
        if (pasien_baru.jenis_kelamin == 'l') { pasien_baru.jenis_kelamin = 'L'; break; }
        if (pasien_baru.jenis_kelamin == 'L') { break; }
        if (pasien_baru.jenis_kelamin == 'p') { pasien_baru.jenis_kelamin = 'P'; break; }
        if (pasien_baru.jenis_kelamin == 'P') { break; }
        cout << "       [!] Pilihan tidak valid! Masukkan 'L' atau 'P'.\n";
    }
    cout << "Gol. Darah        : ";
    cin.getline(pasien_baru.gol_darah, 5);
    while (true) {
        cout << "No. Telepon       : ";
        cin.getline(pasien_baru.no_telepon, 30);
        int panjang      = 0;
        bool semua_angka = true;
        while (pasien_baru.no_telepon[panjang] != '\0') {
            if (pasien_baru.no_telepon[panjang] < '0' || pasien_baru.no_telepon[panjang] > '9') {
                semua_angka = false;
                break;
            }
            panjang++;
        }
 
        if (panjang == 0) {
            cout << "       [!] Nomor telepon tidak boleh kosong! Silakan ulangi.\n";
        } else if (!semua_angka) {
            cout << "       [!] Nomor telepon harus berupa angka saja! Silakan ulangi.\n";
        } else { break; }
    }
    cout << "Alamat\n";
    cout << "       Jalan      : "; cin.getline(pasien_baru.jalan,     1000);
    cout << "       Kelurahan  : "; cin.getline(pasien_baru.kelurahan, 1000);
    cout << "       Kota       : "; cin.getline(pasien_baru.kota,      1000);
    cout << "       Provinsi   : "; cin.getline(pasien_baru.provinsi,  1000);
    while (true) {
        cout << "       Kode Pos   : ";
        cin >> pasien_baru.kode_pos;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "       [!] Kode pos harus berupa angka! Silakan ulangi.\n";
        } else { cin.ignore(1000, '\n'); break; }
    }
 
    while (true) {
        cout << "Peserta BPJS(y/n) : ";
        cin >> pasien_baru.status_bpjs;
        cin.ignore(1000, '\n');
        if (pasien_baru.status_bpjs == 'y' || pasien_baru.status_bpjs == 'Y' ||
            pasien_baru.status_bpjs == 'n' || pasien_baru.status_bpjs == 'N') { break; }
        cout << "       [!] Pilihan tidak valid! Masukkan 'y' atau 'n'.\n";
    }
 
    while (true) {
        cout << "Jumlah Alergi(0-5): ";
        cin >> pasien_baru.jumlah_alergi;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "       [!] Masukkan angka saja! Silakan ulangi.\n";
        } else if (pasien_baru.jumlah_alergi < 0 || pasien_baru.jumlah_alergi > 5) {
            cout << "       [!] Jumlah alergi harus antara 0 sampai 5! Silakan ulangi.\n";
        } else { cin.ignore(1000, '\n'); break; }
    }
 
    for (int i = 0; i < pasien_baru.jumlah_alergi; i++) {
        cout << "[Alergi " << i + 1 << "]\n";
        cout << "  Alergen         : ";
        cin.getline(pasien_baru.daftar_alergi[i].nama_alergen, 100);
        cout << "  Reaksi          : ";
        cin.getline(pasien_baru.daftar_alergi[i].reaksi, 100);
    }
    daftar_pasien[total_pasien] = pasien_baru;
    total_pasien++;
    cout << "\n[OK] Pasien ID-" << id_pasien << " berhasil didaftarkan!\n";
    id_pasien++;
    pauseScreen();
}
 
void lihatSemuaPasien() {
    cout << "=========================================================\n";
    cout << "                  LIHAT SEMUA PASIEN\n";
    cout << "=========================================================\n";
    if (total_pasien == 0) {
        cout << "Belum ada data pasien yang terdaftar di dalam sistem.\n";
        cout << "---------------------------------------------------------\n";
    } else {
        for (int i = 0; i < total_pasien; i++) {
            tampilkanDataPasien(i);
        }
    }
    pauseScreen();
}
 
void cariPasien() {
    char nama_dicari[1000];
    cout << "=========================================================\n";
    cout << "                      CARI PASIEN\n";
    cout << "=========================================================\n";
    cout << "Masukkan nama: ";
    cin.getline(nama_dicari, 1000);
    cout << "=========================================================\n\n";
    bool ditemukan = false;
    for (int i = 0; i < total_pasien; i++) {
        if (cekNamaSama(daftar_pasien[i].nama, nama_dicari)) {
            ditemukan = true;
            cout << "          DAFTAR PASIEN\n";
            cout << "=========================================================\n";
            tampilkanDataPasien(i);
            break;
        }
    }
    if (!ditemukan) {
        cout << "Pasien tidak ditemukan.\n";
    }
    pauseScreen();
}
void pulangkanPasien() {
    cout << "=========================================================\n";
    cout << "               HAPUS / PULANGKAN PASIEN\n";
    cout << "=========================================================\n";
    cout << "Daftar Pasien:\n";
    cout << "---------------------------------------------------------\n";
    if (total_pasien == 0) {
        cout << "Tidak ada pasien rawat inap aktif yang terdaftar.\n";
        cout << "=========================================================\n";
        pauseScreen();
        return;
    }
    for (int i = 0; i < total_pasien; i++) {
        cout << "ID-" << daftar_pasien[i].id << " \t| " << daftar_pasien[i].nama << "\n";
    }
    cout << "---------------------------------------------------------\n";
    int id_dicari;
    while (true) {
        cout << "Masukkan ID pasien yang ingin dipulangkan: ";
        cin >> id_dicari;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Input harus berupa angka ID pasien! Silakan ulangi.\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }
    int indeks_ditemukan = -1;
    for (int i = 0; i < total_pasien; i++) {
        if (daftar_pasien[i].id == id_dicari) {
            indeks_ditemukan = i;
            break;
        }
    }
    if (indeks_ditemukan == -1) {
        cout << "\n[!] Pasien dengan ID tersebut tidak ditemukan di sistem.\n";
        pauseScreen();
        return;
    }
    Pasien pasien_dipilih = daftar_pasien[indeks_ditemukan];
    int lama_rawat = hitungLamaRawat(
        pasien_dipilih.tgl_masuk, pasien_dipilih.bln_masuk, pasien_dipilih.thn_masuk,
        tanggal, bulan, tahun
    );
    if (lama_rawat < 0) lama_rawat = 0;
    long tarif_per_hari  = 75000;
    long total_tagihan   = 0;
    bool peserta_bpjs    = (pasien_dipilih.status_bpjs == 'y' || pasien_dipilih.status_bpjs == 'Y');
    if (!peserta_bpjs) {
        total_tagihan = (long)lama_rawat * tarif_per_hari;
    }
    cout << "\n=========================================================\n";
    cout << "                     RINCIAN TAGIHAN\n";
    cout << "=========================================================\n";
    cout << "Nama         : " << pasien_dipilih.nama       << "\n";
    cout << "NIK          : " << pasien_dipilih.nik        << "\n";
    cout << "BPJS         : " << (peserta_bpjs ? "Ya" : "Tidak") << "\n";
    cout << "---------------------------------------------------------\n";
    cout << "Tgl Masuk    : " << pasien_dipilih.tgl_masuk  << "/" << pasien_dipilih.bln_masuk  << "/" << pasien_dipilih.thn_masuk  << "\n";
    cout << "Tgl Keluar   : " << tanggal << "/" << bulan << "/" << tahun << "\n";
    cout << "Lama Rawat   : " << lama_rawat    << " hari\n";
    cout << "Tarif/Hari   : Rp " << tarif_per_hari << "\n";
    cout << "---------------------------------------------------------\n";
    if (peserta_bpjs) {
        cout << "Total Tagihan : Rp 0 (Ditanggung BPJS)\n";
    } else {
        cout << "Total Tagihan : Rp " << total_tagihan << "\n";
    }
    cout << "=========================================================\n\n";
 
    if (!peserta_bpjs) {
        cout << "Pasien wajib melunasi tagihan sebelum dipulangkan.\n";
    }
    char konfirmasi;
    while (true) {
        cout << "Yakin ingin memulangkan pasien ini? (y/n): ";
        cin >> konfirmasi;
        cin.ignore(1000, '\n');
        if (konfirmasi == 'y' || konfirmasi == 'Y' ||
            konfirmasi == 'n' || konfirmasi == 'N') { break; }
        cout << "       [!] Masukkan 'y' untuk Ya atau 'n' untuk Batal.\n";
    }
 
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = indeks_ditemukan; i < total_pasien - 1; i++) {
            daftar_pasien[i] = daftar_pasien[i + 1];
        }
        total_pasien--;
        cout << "\n[OK] Pasien ID-" << id_dicari << " berhasil dipulangkan.\n";
        cout << "     Sisa pasien terdaftar: " << total_pasien << "\n";
    } else {
        cout << "\n[!] Pemulangan pasien dibatalkan.\n";
    }
    pauseScreen();
}
 
void inisialisasiDataAwal() {
    daftar_pasien[0].id            = 1;
    daftar_pasien[0].jenis_kelamin = 'P';
    daftar_pasien[0].status_bpjs   = 'y';
    daftar_pasien[0].tgl_lahir = 5;  daftar_pasien[0].bln_lahir = 3;  daftar_pasien[0].thn_lahir = 1998;
    daftar_pasien[0].kode_pos  = 11530;
    daftar_pasien[0].tgl_masuk = 10; daftar_pasien[0].bln_masuk = 5;  daftar_pasien[0].thn_masuk = 2026;
 
    char nik1[]  = "F1D02410xxx34567";    for (int i = 0; nik1[i];  i++) daftar_pasien[0].nik[i]        = nik1[i];
    char nm1[]   = "Salsabila Nailafahdi";for (int i = 0; nm1[i];   i++) daftar_pasien[0].nama[i]       = nm1[i];
    char gol1[]  = "A";                   for (int i = 0; gol1[i];  i++) daftar_pasien[0].gol_darah[i]  = gol1[i];
    char tlp1[]  = "08533321xxxx";        for (int i = 0; tlp1[i];  i++) daftar_pasien[0].no_telepon[i] = tlp1[i];
    char jl1[]   = "Jl. Mawar No. 12";    for (int i = 0; jl1[i];   i++) daftar_pasien[0].jalan[i]      = jl1[i];
    char kel1[]  = "Kebon Jeruk";          for (int i = 0; kel1[i];  i++) daftar_pasien[0].kelurahan[i]  = kel1[i];
    char kot1[]  = "Jakarta Barat";       for (int i = 0; kot1[i];  i++) daftar_pasien[0].kota[i]       = kot1[i];
    char prov1[] = "DKI Jakarta";         for (int i = 0; prov1[i]; i++) daftar_pasien[0].provinsi[i]   = prov1[i];
 
    daftar_pasien[0].jumlah_alergi = 2;
    char alg1a[] = "Aspirin";     for (int i = 0; alg1a[i]; i++) daftar_pasien[0].daftar_alergi[0].nama_alergen[i] = alg1a[i];
    char rks1a[] = "Sesak napas"; for (int i = 0; rks1a[i]; i++) daftar_pasien[0].daftar_alergi[0].reaksi[i]      = rks1a[i];
    char alg1b[] = "Seafood";     for (int i = 0; alg1b[i]; i++) daftar_pasien[0].daftar_alergi[1].nama_alergen[i] = alg1b[i];
    char rks1b[] = "Gatal-gatal"; for (int i = 0; rks1b[i]; i++) daftar_pasien[0].daftar_alergi[1].reaksi[i]      = rks1b[i];
 
    daftar_pasien[1].id            = 2;
    daftar_pasien[1].jenis_kelamin = 'L';
    daftar_pasien[1].status_bpjs   = 'n';
    daftar_pasien[1].tgl_lahir = 12; daftar_pasien[1].bln_lahir = 5;  daftar_pasien[1].thn_lahir = 1985;
    daftar_pasien[1].kode_pos  = 60243;
    daftar_pasien[1].tgl_masuk = 10; daftar_pasien[1].bln_masuk = 5;  daftar_pasien[1].thn_masuk = 2026;
 
    char nik2[]  = "F1D02410xxx45678";           for (int i = 0; nik2[i];  i++) daftar_pasien[1].nik[i]        = nik2[i];
    char nm2[]   = "I Kadek Mahesa Permana Putra";for (int i = 0; nm2[i];   i++) daftar_pasien[1].nama[i]       = nm2[i];
    char gol2[]  = "B";                          for (int i = 0; gol2[i];  i++) daftar_pasien[1].gol_darah[i]  = gol2[i];
    char tlp2[]  = "08133716xxxx";                for (int i = 0; tlp2[i];  i++) daftar_pasien[1].no_telepon[i] = tlp2[i];
    char jl2[]   = "Jl. Melati No. 7";            for (int i = 0; jl2[i];   i++) daftar_pasien[1].jalan[i]      = jl2[i];
    char kel2[]  = "Wonokromo";                   for (int i = 0; kel2[i];  i++) daftar_pasien[1].kelurahan[i]  = kel2[i];
    char kot2[]  = "Surabaya";                    for (int i = 0; kot2[i];  i++) daftar_pasien[1].kota[i]       = kot2[i];
    char prov2[] = "Jawa Timur";                  for (int i = 0; prov2[i]; i++) daftar_pasien[1].provinsi[i]   = prov2[i];
    daftar_pasien[1].jumlah_alergi = 0;
 
    daftar_pasien[2].id            = 3;
    daftar_pasien[2].jenis_kelamin = 'L';
    daftar_pasien[2].status_bpjs   = 'y';
    daftar_pasien[2].tgl_lahir = 20; daftar_pasien[2].bln_lahir = 7;  daftar_pasien[2].thn_lahir = 1992;
    daftar_pasien[2].kode_pos  = 55225;
    daftar_pasien[2].tgl_masuk = 11; daftar_pasien[2].bln_masuk = 5;  daftar_pasien[2].thn_masuk = 2026;
 
    char nik3[]  = "F1D02410xxx56789"; for (int i = 0; nik3[i];  i++) daftar_pasien[2].nik[i]        = nik3[i];
    char nm3[]   = "Azizurrifki";      for (int i = 0; nm3[i];   i++) daftar_pasien[2].nama[i]       = nm3[i];
    char gol3[]  = "O";                for (int i = 0; gol3[i];  i++) daftar_pasien[2].gol_darah[i]  = gol3[i];
    char tlp3[]  = "08967590xxxx";     for (int i = 0; tlp3[i];  i++) daftar_pasien[2].no_telepon[i] = tlp3[i];
    char jl3[]   = "Jl. Flamboyan No. 3"; for (int i = 0; jl3[i];   i++) daftar_pasien[2].jalan[i]      = jl3[i];
    char kel3[]  = "Baciro";           for (int i = 0; kel3[i];  i++) daftar_pasien[2].kelurahan[i]  = kel3[i];
    char kot3[]  = "Yogyakarta";       for (int i = 0; kot3[i];  i++) daftar_pasien[2].kota[i]       = kot3[i];
    char prov3[] = "DI Yogyakarta";    for (int i = 0; prov3[i]; i++) daftar_pasien[2].provinsi[i]   = prov3[i];
 
    daftar_pasien[2].jumlah_alergi = 1;
    char alg3[] = "Ibuprofen";       for (int i = 0; alg3[i]; i++) daftar_pasien[2].daftar_alergi[0].nama_alergen[i] = alg3[i];
    char rks3[] = "Mual dan muntah"; for (int i = 0; rks3[i]; i++) daftar_pasien[2].daftar_alergi[0].reaksi[i]      = rks3[i];
 
    daftar_pasien[3].id            = 4;
    daftar_pasien[3].jenis_kelamin = 'L';
    daftar_pasien[3].status_bpjs   = 'n';
    daftar_pasien[3].tgl_lahir = 2;  daftar_pasien[3].bln_lahir = 10; daftar_pasien[3].thn_lahir = 1975;
    daftar_pasien[3].kode_pos  = 50249;
    daftar_pasien[3].tgl_masuk = 18; daftar_pasien[3].bln_masuk = 5;  daftar_pasien[3].thn_masuk = 2026;
 
    char nik4[]  = "F1D02410xxx89012";    for (int i = 0; nik4[i];  i++) daftar_pasien[3].nik[i]        = nik4[i];
    char nm4[]   = "Rendy Wahyu Islami";  for (int i = 0; nm4[i];   i++) daftar_pasien[3].nama[i]       = nm4[i];
    char gol4[]  = "B";                   for (int i = 0; gol4[i];  i++) daftar_pasien[3].gol_darah[i]  = gol4[i];
    char tlp4[]  = "08234136xxxx";        for (int i = 0; tlp4[i];  i++) daftar_pasien[3].no_telepon[i] = tlp4[i];
    char jl4[]   = "Jl. Pandanaran No. 20"; for (int i = 0; jl4[i];   i++) daftar_pasien[3].jalan[i]      = jl4[i];
    char kel4[]  = "Mugassari";           for (int i = 0; kel4[i];  i++) daftar_pasien[3].kelurahan[i]  = kel4[i];
    char kot4[]  = "Semarang";            for (int i = 0; kot4[i];  i++) daftar_pasien[3].kota[i]       = kot4[i];
    char prov4[] = "Jawa Tengah";          for (int i = 0; prov4[i]; i++) daftar_pasien[3].provinsi[i]   = prov4[i];
 
    daftar_pasien[3].jumlah_alergi = 1;
    char alg4[] = "Latex";                  for (int i = 0; alg4[i]; i++) daftar_pasien[3].daftar_alergi[0].nama_alergen[i] = alg4[i];
    char rks4[] = "Kulit memerah dan gatal";for (int i = 0; rks4[i]; i++) daftar_pasien[3].daftar_alergi[0].reaksi[i]      = rks4[i];
 
    daftar_pasien[4].id            = 5;
    daftar_pasien[4].jenis_kelamin = 'L';
    daftar_pasien[4].status_bpjs   = 'y';
    daftar_pasien[4].tgl_lahir = 26; daftar_pasien[4].bln_lahir = 6;  daftar_pasien[4].thn_lahir = 1968;
    daftar_pasien[4].kode_pos  = 95111;
    daftar_pasien[4].tgl_masuk = 19; daftar_pasien[4].bln_masuk = 5;  daftar_pasien[4].thn_masuk = 2026;
 
    char nik5[]  = "F1D02410xxx01234";       for (int i = 0; nik5[i];  i++) daftar_pasien[4].nik[i]        = nik5[i];
    char nm5[]   = "Wimar Aryasmarta Prakasa";for (int i = 0; nm5[i];   i++) daftar_pasien[4].nama[i]       = nm5[i];
    char gol5[]  = "A";                       for (int i = 0; gol5[i];  i++) daftar_pasien[4].gol_darah[i]  = gol5[i];
    char tlp5[]  = "08582964xxxx";            for (int i = 0; tlp5[i];  i++) daftar_pasien[4].no_telepon[i] = tlp5[i];
    char jl5[]   = "Jl. Sam Ratulangi No. 11";for (int i = 0; jl5[i];   i++) daftar_pasien[4].jalan[i]      = jl5[i];
    char kel5[]  = "Wenang";                  for (int i = 0; kel5[i];  i++) daftar_pasien[4].kelurahan[i]  = kel5[i];
    char kot5[]  = "Manado";                  for (int i = 0; kot5[i];  i++) daftar_pasien[4].kota[i]       = kot5[i];
    char prov5[] = "Sulawesi Utara";          for (int i = 0; prov5[i]; i++) daftar_pasien[4].provinsi[i]   = prov5[i];
    daftar_pasien[4].jumlah_alergi = 0;
    total_pasien = 5;
    id_pasien    = 6;
}
 
int main() {
    inisialisasiDataAwal();
    while (true) {
        clearScreen();
        tampilkanMenuUtama();
 
        if (pilihan == 0) {
            cout << "\nTerima kasih! Sistem ditutup.\n";
            break;
        } else if (pilihan == 1) {
            clearScreen();
            daftarkanPasienBaru();
        } else if (pilihan == 2) {
            clearScreen();
            lihatSemuaPasien();
        } else if (pilihan == 3) {
            clearScreen();
            cariPasien();
        } else if (pilihan == 4) {
            clearScreen();
            pulangkanPasien();
        }
    }
    return 0;
}