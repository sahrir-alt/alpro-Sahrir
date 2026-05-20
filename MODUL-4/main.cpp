#include <iostream>
using namespace std;

void clear_screen() {
    system("cls");
}

void banner_utama(string header) {
    cout << "|====================================|\n";
    cout << "|                                    |\n";
    cout << "|         " << header << "        |\n";
    cout << "|                                    |\n";
    cout << "|====================================|\n\n";
    cout << "1. TIVAIZ Store\n";
    cout << "2. Kalkulator TIVAIZ\n";
    cout << "0. Keluar\n";
    cout << "========================================\n";
}

void banner_store() {
    cout << "#==============================#\n";
    cout << "|         TIVAIZ STORE         |\n";
    cout << "#==============================#\n\n";
    cout << "1. Input Barang\n";
    cout << "2. Hapus Barang\n";
    cout << "3. Edit Barang\n";
    cout << "4. Lihat Barang\n";
    cout << "0. Kembali\n";
    cout << "================================\n";
}

void banner_kalkulator() {
    cout << "+==============================-\n";
    cout << "|         K4LKUL4T0R           |\n";
    cout << "x==============================/\n\n";
    cout << "1. Operasi Dasar (+, -, *, /)\n";
    cout << "2. Faktorial\n";
    cout << "0. Kembali\n";
    cout << "================================\n";
}

void banner_sub(string judul) {
    cout << "#==============================#\n";
    cout << "|         TIVAIZ STORE         |\n";
    cout << "#==============================#\n";
    cout << "--------------------------------\n";
    cout << "         " << judul << "\n";
    cout << "--------------------------------\n";
}

void operasi_dasar(float a, float b, char op) {
    float hasil;
    if (op == '+') {
        hasil = a + b;
        cout << a << " + " << b << " = " << hasil << endl;
    } else if (op == '-') {
        hasil = a - b;
        cout << a << " - " << b << " = " << hasil << endl;
    } else if (op == '*') {
        hasil = a * b;
        cout << a << " * " << b << " = " << hasil << endl;
    } else if (op == '/') {
        if (b == 0) {
            cout << "[Gagal] Tidak bisa dibagi nol!\n";
        } else {
            hasil = a / b;
            cout << a << " / " << b << " = " << hasil << endl;
        }
    } else {
        cout << "[Gagal] Operator tidak valid!\n";
    }
}

long long hitung_faktorial(int n) {
    if (n == 0) return 1;
    return n * hitung_faktorial(n - 1);
}

void menu_kalkulator() {
    bool loop_kalkulator = true;
    while (loop_kalkulator) {
        clear_screen();
        banner_kalkulator();
        cout << "Pilih menu: ";

        int pilihan_kalk;
        cin >> pilihan_kalk;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka\n";
            system("pause");
            continue;
        }
        cin.ignore(1000, '\n');

        if (pilihan_kalk < 0 || pilihan_kalk > 2) {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2\n";
            system("pause");
        } else if (pilihan_kalk == 0) {
            loop_kalkulator = false;
        } else if (pilihan_kalk == 1) {
            bool loop_ops = true;
            while (loop_ops) {
                clear_screen();
                cout << "+==============================-\n";
                cout << "|         K4LKUL4T0R           |\n";
                cout << "x==============================/\n\n";
                cout << "--------------------------------\n";

                char op;
                cout << "Operator (+, -, *, /): ";
                cin >> op;

                if (op != '+' && op != '-' && op != '*' && op != '/') {
                    cin.ignore(1000, '\n');
                    cout << "[Gagal] Operator tidak valid!\n";
                    system("pause");
                    continue;
                }
                cin.ignore(1000, '\n');

                float angka_1, angka_2;
                cout << "Angka pertama : ";
                cin >> angka_1;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "[Gagal] Input harus berupa angka\n";
                    system("pause");
                    continue;
                }

                cout << "Angka kedua   : ";
                cin >> angka_2;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "[Gagal] Input harus berupa angka\n";
                    system("pause");
                    continue;
                }
                cin.ignore(1000, '\n');

                operasi_dasar(angka_1, angka_2, op);
                system("pause");
                loop_ops = false;
            }
        } else if (pilihan_kalk == 2) {
            bool loop_fakt = true;
            while (loop_fakt) {
                clear_screen();
                cout << "+==============================-\n";
                cout << "|         K4LKUL4T0R           |\n";
                cout << "x==============================/\n\n";
                cout << "--------------------------------\n";

                int n;
                cout << "N : ";
                cin >> n;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "[Gagal] Input harus berupa angka\n";
                    system("pause");
                    continue;
                }
                cin.ignore(1000, '\n');

                if (n < 0) {
                    cout << "[Gagal] Faktorial tidak bisa untuk angka negatif!\n";
                } else {
                    cout << n << "! = " << hitung_faktorial(n) << endl;
                }
                system("pause");
                loop_fakt = false;
            }
        }
    }
}

void input_barang(string nama_barang[], int stok_barang[], float harga_barang[], int &total) {
    clear_screen();
    banner_sub("INPUT BARANG");

    string nama;
    int stok;
    float harga;

    cout << "Nama Barang  : ";
    getline(cin, nama);

    cout << "Stok (unit)  : ";
    cin >> stok;
    if (cin.fail() || stok < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Stok harus berupa angka!\n";
        system("pause");
        return;
    }

    cout << "Harga (Rp)   : ";
    cin >> harga;
    if (cin.fail() || harga < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Harga harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');

    nama_barang[total]  = nama;
    stok_barang[total]  = stok;
    harga_barang[total] = harga;
    total++;

    cout << "[Berhasil] " << nama << " ditambahkan! (Total barang: " << total << ")\n";
    system("pause");
}

void hapus_barang(string nama_barang[], int stok_barang[], float harga_barang[], int &total) {
    clear_screen();
    banner_sub("HAPUS BARANG");

    if (total == 0) {
        cout << "Belum ada barang!\n";
        system("pause");
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "No           : " << i + 1 << "\n";
        cout << "Nama Barang  : " << nama_barang[i] << "\n";
        cout << "Stok Barang  : " << stok_barang[i] << "\n";
        cout << "Harga/Stok   : Rp " << harga_barang[i] << "\n";
        cout << "--------------------------------\n";
    }

    int pilih_hapus;
    cout << "Pilih nomor barang yang dihapus (1-" << total << "): ";
    cin >> pilih_hapus;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');

    if (pilih_hapus < 1 || pilih_hapus > total) {
        cout << "[Gagal] Nomor tidak valid! Pilih antara 1 sampai " << total << "\n";
        system("pause");
        return;
    }

    string nama_hapus = nama_barang[pilih_hapus - 1];

    for (int i = pilih_hapus - 1; i < total - 1; i++) {
        nama_barang[i]  = nama_barang[i + 1];
        stok_barang[i]  = stok_barang[i + 1];
        harga_barang[i] = harga_barang[i + 1];
    }
    total--;

    cout << "[Berhasil] " << nama_hapus << " dihapus! (Total barang: " << total << ")\n";
    system("pause");
}

void edit_harga(float &harga) {
    float harga_baru;
    cout << "Harga baru (Rp): ";
    cin >> harga_baru;
    if (cin.fail() || harga_baru < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');
    float lama = harga;
    harga = harga_baru;
    cout << "[Berhasil] Harga Rp " << lama << " -> Rp " << harga << "\n";
    system("pause");
}

void tambah_stok(int &stok) {
    int tambah;
    cout << "Jumlah Tambah: ";
    cin >> tambah;
    if (cin.fail() || tambah < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');
    int lama = stok;
    stok += tambah;
    cout << "[Berhasil] Stok " << lama << ": " << lama << " + " << tambah << " = " << stok << "\n";
    system("pause");
}

void kurangi_stok(int &stok) {
    int kurang;
    cout << "Jumlah Kurang: ";
    cin >> kurang;
    if (cin.fail() || kurang < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');

    if (stok - kurang <= 0) {
        cout << "[Gagal] Stok tidak boleh menyentuh nol! (stok saat ini: " << stok << ")\n";
        system("pause");
        return;
    }

    int lama = stok;
    stok -= kurang;
    cout << "[Berhasil] Stok " << lama << ": " << lama << " - " << kurang << " = " << stok << "\n";
    system("pause");
}

void edit_barang(string nama_barang[], int stok_barang[], float harga_barang[], int &total) {
    clear_screen();
    banner_sub("EDIT BARANG");

    if (total == 0) {
        cout << "Belum ada barang!\n";
        system("pause");
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "No           : " << i + 1 << "\n";
        cout << "Nama Barang  : " << nama_barang[i] << "\n";
        cout << "Stok Barang  : " << stok_barang[i] << "\n";
        cout << "Harga/Stok   : Rp " << harga_barang[i] << "\n";
        cout << "--------------------------------\n";
    }

    int pilih_edit;
    cout << "Pilih nomor barang yang diedit (1-" << total << "): ";
    cin >> pilih_edit;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[Gagal] Input harus berupa angka!\n";
        system("pause");
        return;
    }
    cin.ignore(1000, '\n');

    if (pilih_edit < 1 || pilih_edit > total) {
        cout << "[Gagal] Nomor tidak valid! Pilih antara 1 sampai " << total << "\n";
        system("pause");
        return;
    }

    int indeks = pilih_edit - 1;

    bool loop_edit = true;
    while (loop_edit) {
        clear_screen();
        cout << "#==============================#\n";
        cout << "|         TIVAIZ STORE         |\n";
        cout << "#==============================#\n";
        cout << "--------------------------------\n";
        cout << "         EDIT BARANG\n";
        cout << "--------------------------------\n";
        cout << "Barang: " << nama_barang[indeks] << "\n";
        cout << "--------------------------------\n";
        cout << "1. Edit Harga\n";
        cout << "2. Tambah Stok\n";
        cout << "3. Kurangi Stok\n";
        cout << "0. Kembali\n";
        cout << "================================\n";
        cout << "Pilih opsi: ";

        int opsi_edit;
        cin >> opsi_edit;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka!\n";
            system("pause");
            continue;
        }
        cin.ignore(1000, '\n');

        if (opsi_edit == 0) {
            loop_edit = false;
        } else if (opsi_edit == 1) {
            edit_harga(harga_barang[indeks]);
        } else if (opsi_edit == 2) {
            tambah_stok(stok_barang[indeks]);
        } else if (opsi_edit == 3) {
            kurangi_stok(stok_barang[indeks]);
        } else {
            cout << "[Gagal] Opsi tidak valid!\n";
            system("pause");
        }
    }
}

void lihat_barang(string nama_barang[], int stok_barang[], float harga_barang[], int total) {
    clear_screen();
    banner_sub("LIHAT BARANG");

    if (total == 0) {
        cout << "Belum ada barang!\n";
    } else {
        for (int i = 0; i < total; i++) {
            float total_harga = stok_barang[i] * harga_barang[i];
            cout << "No           : " << i + 1 << "\n";
            cout << "Nama Barang  : " << nama_barang[i] << "\n";
            cout << "Stok Barang  : " << stok_barang[i] << "\n";
            cout << "Harga/Stok   : Rp " << harga_barang[i] << "\n";
            cout << "Total Harga  : Rp " << total_harga << "\n";
            cout << "\n";
        }
        cout << "\nTotal barang : " << total << " jenis\n";
    }
    cout << "================================\n";
    system("pause");
}

void menu_store(string nama_barang[], int stok_barang[], float harga_barang[], int &total) {
    bool loop_store = true;
    while (loop_store) {
        clear_screen();
        banner_store();
        cout << "Pilih menu: ";

        int pil_store;
        cin >> pil_store;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka\n";
            system("pause");
            continue;
        }
        cin.ignore(1000, '\n');

        if (pil_store < 0 || pil_store > 4) {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 4\n";
            system("pause");
        } else if (pil_store == 0) {
            loop_store = false;
        } else if (pil_store == 1) {
            input_barang(nama_barang, stok_barang, harga_barang, total);
        } else if (pil_store == 2) {
            hapus_barang(nama_barang, stok_barang, harga_barang, total);
        } else if (pil_store == 3) {
            edit_barang(nama_barang, stok_barang, harga_barang, total);
        } else if (pil_store == 4) {
            lihat_barang(nama_barang, stok_barang, harga_barang, total);
        }
    }
}


int main() {
    string nama_barang[100];
    int    stok_barang[100];
    float  harga_barang[100];
    int    total = 0;

    bool loop_main = true;
    while (loop_main) {
        clear_screen();
        banner_utama("MODULE 4 - FUNCTION");

        int jawaban;
        cout << "Pilih menu: ";
        cin >> jawaban;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka\n";
            system("pause");
            continue;
        }
        cin.ignore(1000, '\n');

        if (jawaban < 0 || jawaban > 2) {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2\n";
            system("pause");
        } else if (jawaban == 0) {
            loop_main = false;
        } else if (jawaban == 1) {
            menu_store(nama_barang, stok_barang, harga_barang, total);
        } else if (jawaban == 2) {
            menu_kalkulator();
        }
    }

    cout << "Program selesai. Sampai jumpa!\n";
    return 0;
}