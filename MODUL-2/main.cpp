#include <iostream>
using namespace std;

int main() {
    int umur;
    int perlindungan = 3;
    char strategi1;

    cout << "=== GOBLET OF FIRE : TURNAMEN TRIWIZARD ===\n";
    cout << "masukan umur Anda: ";
    cin >> umur;

    if (umur >= 17){
        cout << "Piala Api menyala! Anda terpilih sebagai Triwizard Champions.\n";
    }
    else {
        cout << "Piala Api menolak Anda! Umur terlau kecil\n";
    }
    bool telur_emas = false;

    while (!telur_emas){
        cout << "--- TUGAS 1 NAGA HUNGARIAN HORNTAIL ---\n";
        cout << "Sisa perlindungan sihir : " << perlindungan << " kali\n";
        cout << "Pilih strategi (a: sembunyi, b: Panggil Sapu) : ";
        cin >> strategi1;
        }
            if (strategi1 == 'A' || strategi1 == 'a'){
                cout << "Naga menyemburkan api! Anda terluka.\n";
                cout << "Pilih strategi (a: sembunyi, b: Panggil Sapu) : ";
                cin >> strategi1;
                telur_emas = false;
                --perlindungan;
        }
        if (strategi1 == 'b' || strategi1 == 'B'){
            cout << "Berhasil! Anda mengambil Telur Emas! \n"; 
            system("pause");
            telur_emas = true;
        }
    return 0;
}