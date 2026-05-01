#include <iostream>
using namespace std;

int main() {
    int umur;
    int perlindungan = 3, menit = 10, kesalahan = 2, langkah = 0;
    char strategi1, strategi2;
    int strategi3, strategi4;
    bool telur_emas = false, sandera = false, cahaya = false, diamond = false;

    cout << "=== GOBLET OF FIRE : TURNAMEN TRIWIZARD ===\n";
    cout << "Masukan umur Anda: ";
    cin >> umur;

    if (umur >= 17) {
        cout << "Piala Api menyala! Anda terpilih sebagai Triwizard Champions.\n\n";
    } 
    else {
        cout << "Piala Api menolak Anda! Umur terlalu kecil\n";
        system("pause");
        system("cls");
        return 0;
    }

    //  TUGAS 1
    while (!telur_emas) {
        if (perlindungan == 3){
            cout << "--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---\n";
            cout << "Sisa perlindungan sihir: " << perlindungan << " kali.\n";
        }
        cout << "Pilih strategi (a: Sembunyi, b: Panggil Sapu): ";
        cin >> strategi1;

        if (strategi1 == 'b' || strategi1 == 'B') {
            cout << "Berhasil! Anda mengambil Telur Emas!\n";
            telur_emas = true;
            system("pause");
            system("cls");
        } 
        else if (strategi1 == 'a' || strategi1 == 'A') {
            perlindungan--;
            cout << "Naga menyemburkan api! Anda terluka.\n";

            if (perlindungan <= 0) {
                cout << ">> KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga.\n";
                cout << ">> MENGULANG TUGAS 1 DARI AWAL...\n";
                perlindungan = 3;
                system("pause");
                system ("cls");
            } else {
                cout << "Sisa perlindungan sihir: " << perlindungan << " kali.\n";
            }
        } 
        else {
            cout << "Pilihan tidak valid! Ulangi pilihan.\n";
            system("pause");
            system("cls");
            perlindungan = 3;
        }
    }

    // TUGAS 2
    cout << "--- TUGAS 2: DANAU HITAM ---\n";
    while (!sandera){
        cout << "Menit " << menit << "..... Ada Grindylow! (l: Lawan, h: Hindari): ";
        cin >> strategi2;
        if (strategi2 == 'h' || strategi2 == 'H'){
            cout << "Lolos dari Grindylow.\n";
            menit += 10;
        }
        else if (strategi2 == 'l' || strategi2 == 'L'){
            cout << "Oksigen Anda habis karena kelelahan bertarung!\n";
            cout << ">> WAKTU/OKSIGEN HABIS! Putri duyung membawa anda ke permukaan.\n";
            cout << ">> MENGULANG TUGAS 2 DARI AWAAL.....\n";
            system ("pause");
            system ("cls");
            menit = 10;
            cout << "--- TUGAS 2: DANAU HITAM ---\n";
        } 
        else {
            cout << "Pilihan tidak valid! ulangi pilihan.\n";
            system ("pause");
            system("cls");
            menit = 10;
            cout << "--- TUGAS 2: DANAU HITAM ---\n";
        }
        if (menit == 60){
            cout << "Tepat " << menit << " menit! Anda menyelamatkan sandera.\n";
            sandera = true;
            system("pause");
            system ("cls");
        }
    }

    // TUGAS 3
    cout << "--- TUGAS 3: LABIRIN ---\n";
    cout << "Sisa toleransi kesalahan: " << kesalahan <<"\n";
    cout << "Langkah ditempuh: " << langkah << "\n";
    cout << "Pilih arah (1: kiri, 2: Kanan, 3: lurus): ";
    cin >> strategi3;

    while (!cahaya){
        if (strategi3 == 2){
            langkah ++;
            cout << "Jalan aman, Anda semakin dalam.\n";
            cout << "Langkah ditempuh: " << langkah << "\n";

            if (langkah >= 3){
                cout << "Anda melihat Cahaya..... Oh tunggu.... apa itu....\n";
                cahaya = true;
                system ("pause");
                system("cls");
                continue;
            }
            else {
                system ("pause");
            }
            } else if (strategi3 == 1){
                kesalahan--;
                cout << "Terkena Akar Berbisa! Sisa toleransi kesalahan: " << kesalahan << "\n";
                system("pause");
                if (kesalahan <= 0){
                    cout << ">> KESEMPATAN HABIS! Labirin berubah bentuk dan  menendang Anda ke pintu masuk.\n";
                    cout << ">> MENGULANG TUGAS 3 DARI AWAL.....\n";
                    kesalahan = 2;
                    system("pause");
                    system("cls");
                }
            } else if (strategi3 == 3){
                cout << "Anda melihat Cahaya..... Oh tunggu.... apa itu....\n";
                system("pause");
                system("cls");
                break;
            } else {
                cout << "Anda tidak berada di jalur pilihan! Ulangin pilihan!\n";
                system("pause");
                system("cls");
            }
            cout << "--- TUGAS 3: LABIRIN ---\n";
            cout << "Sisa toleransi kesalahan: " << kesalahan <<"\n";
            cout << "Langkah ditempuh: " << langkah << "\n";
            cout << "Pilih arah (1: kiri, 2: Kanan, 3: lurus): ";
            cin >> strategi3;       
    }

    // JALAN KELUAR 
    cout << "--- JALAN KELUAR ---\n";
    cout << "Anda melihat sesuatu yang bersinar di tengah arena......\n";
    cout << "Terdapat sesuatu yang terkurung di dalamnya, dan terdapat mesin yang meminta ada unntuk memasukan sebuah angka....\n\n";
    cout << "Masukan angka (Minimmal 5): ";
    cin >> strategi4;

    while (!diamond){
    if (strategi4 >= 5){
            cout << "Sebuah cahaya bersinar dan di tanganmu kini terdapat sebuah diamond besar!\n";
            for (int i = 1; i <= strategi4; i++) {
                for (int j = 1; j <= strategi4 - i; j++) {
                    cout << " ";
                }
                for (int k = 1; k <= (2 * i - 1); k++) {
                    cout << "*";
                }
                cout << "\n";
            }
            for (int i = strategi4 - 1; i >= 1; i--) {
                for (int j = 1; j <= strategi4 - i; j++) {
                    cout << " ";
                }
                for (int k = 1; k <= (2 * i - 1); k++) {
                    cout << "*";
                }
                cout << "\n";
            }
            diamond = true;
            cout << "\n";
            cout << "*** SELAMAT! ANDA ADALAH PEMENANG TURNAMEN TRIWIZARD! ***\n";
        }
        else {
            cout << "Masukan angka (Minimmal 5): ";
            cin >> strategi4;
        }
    }
    return 0;
}