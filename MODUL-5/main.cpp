#include <iostream>
using namespace std;

int pilihan;
int tanggal = 21, bulan = 5, tahun = 2025;
void clearScreen() {
    cout << "\033[2J\033[H";
}

struct Identitas{
    char jenis_kelamin, bpjs, gol_darah;
    int tanggal, bulan, tahun, kode_pos, no_tlp;
    char NIK[1000];
    char nama[1000];
    char jalan[1000];
    char kelurahan[1000];
    char kota[1000];
    char provinsi[1000];
};

void menu_awal(){
    cout << "=========================================================\n";
    cout << "   SISTEM MANAJEMEN RS GAZACARE PLUS\t\t" << tanggal << "/" << bulan << "/" << tahun << "\n";
    cout << "=========================================================\n";
    cout << "[1]  Daftarkan Pasien Baru\n";
    cout << "[2]  Lihat Semua Pasien\n";
    cout << "[3]  Cari Pasien \n";
    cout << "[4]  Pulangkan Pasien\n";
    cout << "[0]  Keluar\n";
    cout << "=========================================================\n";
    cout << "Pilihan: ";
    cin >> pilihan;
}

void banner_pendaftaran(){
    cout << "=========================================================\n";
    cout << "   PENDAFTARAN PASIEN BARU\t\t\t" << tanggal << "/" << bulan << "/" << tahun << "\n";
    cout << "=========================================================";
}
void pendaftaran(){
    banner_pendaftaran();
    Identitas pasien1;

    cout << "\nNIK (16 digit)    :";
    cin.getline(pasien1.NIK, 1000);
    cout << "\n";
    cout << "Nama              :";
    cin.getline(pasien1.nama, 1000);
    cout << "Tgl Lahir\n";
    cout << "       Tanggal    :";
    cin >> pasien1.tanggal;
    cout << "       Bulan      :";
    cin >> pasien1.bulan;
    cout << "       Tahun      :";
    cin >> pasien1.tahun;
    cout << "Jenis Kelamin(L/P):";
    cin >> pasien1.jenis_kelamin;
    cout << "Gol. Darah        :";
    cin >> pasien1.gol_darah;
    cout << "No. Telp          :";
    cin >> pasien1.no_tlp;
    cout << "Alamat\n";
    cout << "       Jalan      :";
    cin >> pasien1.jalan[0];
    cout << "       Kelurahan  :";
    cin >> pasien1.kelurahan[0];
    cout << "       Provinsi   :";
    cin >> pasien1.provinsi[0];
    cout << "       Kode Pos   :";
    cin >> pasien1.kode_pos;
    cout << "Peserta BPJS (y/n):";
    cin >> pasien1.bpjs; 

    cout << pasien1.nama;
}

int main() {
    menu_awal();
    if (pilihan == 1){
        clearScreen();
        pendaftaran();
    }


 return 0;
}