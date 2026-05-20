#include <iostream>
using namespace std;

string nama_user[1000];
string kata_kunci[1000];
int jumlah_user = 0;

bool cek_user(string input_nama) {
    for (int i = 0; i < jumlah_user; i++) {
        if (nama_user[i] == input_nama) {
            return true;
        }
    }
    return false;
}

void menu_register() {
    string input_nama, input_kata;
    cout << "\n==== REGISTER ====\n";
    cout << "Masukkan Username : ";
    cin >> input_nama;
    if (cek_user(input_nama)) {
        cout << "Username sudah digunakan, coba yang lain!\n";
        return;
    }

    cout << "Masukkan Password : ";
    cin >> input_kata;

    nama_user[jumlah_user] = input_nama;
    kata_kunci[jumlah_user] = input_kata;
    jumlah_user++;
    cout << "Register berhasil!\n";
}

void menu_login() {
    cout << "\n=== LOGIN ===\n";
    string input_nama, input_kata;
    cout << "Masukkan Username : ";
    cin >> input_nama;

    int posisi = -1;
    for (int i = 0; i < jumlah_user; i++) {
        if (nama_user[i] == input_nama) {
            posisi = i;
            break;
        }
    }
    int posisi = 0;
    bool ketemu = false;
        for (int i = 0; i < jumlah_user; i++) {
            if (nama_user[i] == input_nama) {
                posisi = i;
                ketemu = true;
                break;
            }
        }
    if (!ketemu) {
        cout << "Username tidak terdaftar!\n";
        return;
    }

    cout << "Login berhasil!\n";

    int pilihan;
    do {
        cout << "\n===== HALAMAN USER =====\n";
        cout << "Nomor Registrasi : " << posisi + 1 << "\n";
        cout << "Username         : " << nama_user[posisi] << "\n";
        cout << "\n0. Sign Out\n";
        cout << "Pilih : ";
        cin >> pilihan;
    } while (pilihan != 0);
    cout << "Sign out berhasil!\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            menu_register();
        } else if (pilihan == 2) {
            menu_login();
        }
    } while (pilihan != 3);

    cout << "Terima kasih!\n";
    return 0;
}