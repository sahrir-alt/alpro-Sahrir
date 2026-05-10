#include <iostream>
using namespace std;

int main (){
    int key, shift, baris, baris_dek;
    int panjang2 = 0, kolom = 4, indeks1 = 0, indeks2 = 0, panjang2_dek = 0;
    char teks[1000];
    char matriks[100][100];

    // TASK 1
    cout << "[TASK 1/3] DECODE SIGNAL - Communication Romm\n";
    cout << ">> Kirim Sinyal terenskripsi dan deskripsi balasan dari Bumi!\n\n";
    cout << "[ ENSKRIPSI ]\n\n";

    cout << "Masukan key              : ";
    cin >> key;

    while (key <= 0 || !(cin)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Key harus bilangan bulat positif. Coba lagi.\n";
        cout << "Masukan key              : ";
        cin >> key;
    }
    cin.ignore();

    do {
        cout << "Masukkan teks            : ";
        cin.getline(teks, 1000);
        if (teks[0] == '\0')
            cout << "[!] Input tidak boleh kosong.\n";
    } while (teks[0] == '\0');

    while (teks[panjang2] != '\0') 
    panjang2++;
    baris = (panjang2 + kolom - 1) / kolom;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            matriks[i][j] = '_';
        }
    }
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (indeks1 < panjang2) {
                matriks[i][j] = teks[indeks1++];
            }
        }
    }
    cout << "\nMatriks enkripsi:\n\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << "\n";
    }

    //ENSKRIPSI
    char enskripsi_sebelum[1000];
    for (int j = 0; j < kolom; j++){
        for (int i = 0; i < baris; i++){
            enskripsi_sebelum[indeks2++] = matriks[i][j];
        }
    }
    enskripsi_sebelum[indeks2] = '\0';

    cout << "\nEnkripsi sebelum ditambah key: " << enskripsi_sebelum << "\n";
    cout << "Enkripsi setelah ditambah key: ";

    for (int i = 0; i < indeks2; i++) {
        char enskripsi_setelah = enskripsi_sebelum[i] + key;
        cout << enskripsi_setelah;
    }
    cout << "\n\n";

    // DEKRIPSI 
    cout << "[ DEKRIPSI ]\n\n";

    char teks_terenkripsi[1000];
    do {
        cout << "Masukkan teks terenkripsi     : ";
        cin.getline(teks_terenkripsi, 1000);
        if (teks_terenkripsi[0] == '\0'){
            cout << "[!] Input tidak boleh kosong. Coba lagi.\n";
        }         
    } while (teks_terenkripsi[0] == '\0');

    
    while (teks_terenkripsi[panjang2_dek] != '\0'){
        panjang2_dek++;
    }

    baris_dek = (panjang2_dek + kolom - 1) / kolom; 

    cout << "Dekripsi setelah dikurang key : ";

    char shift_balik[1000];
    for (int i = 0; i < panjang2_dek; i++) {
        shift_balik[i] = teks_terenkripsi[i] - key;
        cout << shift_balik[i];
    }
    shift_balik[panjang2_dek] = '\0';
    cout << "\n";

    char matriks_dek[100][100];
    int hitung = 0;
    for (int j = 0; j < kolom; j++) { 
        for (int i = 0; i < baris_dek; i++) { 
            if (hitung < panjang2_dek) {
                matriks_dek[i][j] = shift_balik[hitung++];
            } else {
                matriks_dek[i][j] = '_';
            }
        }
    }
    cout << "\nMatriks Dekripsi:\n\n";
     
    for (int i = 0; i < baris_dek; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks_dek[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nHasil Dekripsi final           : ";
    
    for (int i = 0; i < baris_dek; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks_dek[i][j] != '_') {
                cout << matriks_dek[i][j];
            }
        }
    }
    cout << "\n";
    cout << "\n\n>> [TASK 1/3] COMPLETE - Signal channel restored.\n";
    cout << ">> Tekan ENTER untuk melanjutkan ke [ TASK 2 ]..";
    cin.get();
    system("cls");


    //TASK 2
    int panjang3 = 0, indeks3 = 0;
    char ulang;
    char inputan[1000];
    char tanpa_spasi[1000];
    char swap[1000];

    cout << "[TASK 2/3] REPAIR TEXT CONSOLE - Captain's bridge\n";
    cout << ">> Konsol teks mengalami interferensi kosmik.\n";
    cout << ">> Verifikasi integritas data teks sebelum terlambat!\n\n";

    do {
        cout << "[ Verifikasi Teks ]\n\n";
        for (int kalimat = 1; kalimat <= 3; kalimat++){
            indeks3 = 0;    
            panjang3 = 0;   

            cout << "Masukan kalimat ke-" << kalimat << "      : ";
            cin.getline(inputan, 1000);
            cout << "---------------------------------------\n";

            for (int i = 0; inputan[i] != '\0'; i++) { 
                if (inputan[i] != ' ') {
                    tanpa_spasi[indeks3++] = inputan[i];
                }
            }
            cout << "Masukan kalimat ke-" << kalimat << "      : ";
            tanpa_spasi[indeks3] = '\0';
            panjang2 = indeks3;
            cout << "Hasil untuk Kalimat ke-" << kalimat << ":\n";
            cout << "Jumlah Huruf             : " << panjang2 << "\n";

            cout << "1. Asli                  : ";
            for (int i = 0; i < panjang2; i++) {
                cout << tanpa_spasi[i];
                if (i < panjang2 - 1) cout << ", ";
            }
            cout << "\n";

            cout << "2. Inverse               : ";
            for (int i = panjang2 - 1; i >= 0; i--) {
                cout << tanpa_spasi[i];
                if (i > 0) cout << ", ";
            }
            cout << "\n";

            cout << "3. Swap Awal-Akhir       : ";
            if (panjang2 == 0) {

            } else if (panjang2 == 1) {
                cout << tanpa_spasi[0];
            } else {
                for (int i = 0; i < panjang2; i++) swap[i] = tanpa_spasi[i];
                    swap[panjang2] = '\0';
                    char tmp   = swap[0];

                    swap[0]    = swap[panjang2 - 1];
                    swap[panjang2 - 1] = tmp;
                    cout << swap;
            }
            cout << "\n";

            cout << "4. Palindrome?           : ";
            bool palindrome = true;
            for (int i = 0; i < panjang2 / 2; i++) {
                char a = tanpa_spasi[i];
                char b = tanpa_spasi[panjang2 - 1 - i];
                if (a >= 'A' && a <= 'Z') a = a + 32;
                if (b >= 'A' && b <= 'Z') b = b + 32;
                if (a != b) {
                    palindrome = false;
                    break;
                }
            }
            cout << (palindrome ? "YES" : "NO") << "\n";
 
            if (kalimat < 3) cout << "\n";
        }   
                cout << "\n================================================\n";
        do {
            cout << "Verifikasi Teks Lain? (y/n): ";
            cin.get(ulang);
            cin.ignore(1000, '\n');
            if (ulang != 'y'|| ulang != 'Y' && ulang != 'n'|| ulang != 'N') {
                cout << "   [!] Input tidak valid. Masukkan y atau n.\n";
            }
        } while (ulang != 'y' && ulang != 'n');
 
        if (ulang == 'y' || 'Y') cout << "\n";
 
    } while (ulang == 'y');
 
    cout << "\n>> [TASK 2/3] COMPLETE - Text console back online.\n";
    cout << ">> Tekan ENTER untuk melanjutkan ke [ TASK 3 ]!.";
    cin.get();
    system("cls");

    int matrix;
    int matrix_genap[5][5];
    int matrix_ganjil[5][5];

    cout << "[Task matrix/matrix] ALIGN NAVIGATION MATRIX - Engine Core\n";
    cout << ">> Sistem navigasi mati total akibat sabotase.\n";
    cout << "Rekontruksi matriks koordinat sekarang!\n";

    cout << "\n[ MATRIX NAVIGATION ]\n";
    cout << "Masukan ukuran Matrix (min 3, max 5) : ";
    cin >> matrix;
   
    while (matrix < 3 || matrix > 5 || !(cin)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[!] Input tidak valid. Masukan ukuran antara 3 sampai 5.\n";
        cout << "Masukan Ukuran Matrix (min 3, max 5): ";
        cin >> matrix;
    }
    cout << "--------------------------------------------\n";
    cout << "Odd Coordinate Matrix (Ganjil): \n";
    int angka_ganjil = 1;
    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            matrix_ganjil[i][j] = angka_ganjil;
            angka_ganjil += 2;
        }
    }
    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            if (matrix_ganjil[i][j] < 10)
                cout << "0";       
            cout << matrix_ganjil[i][j] << " ";
        }
        cout << "\n";
    }
    int angka_genap = 2;
    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            matrix_genap[i][j] = angka_genap;
            angka_genap += 2;
        }
    }
    cout << "\n";
    cout << "Even Coordinate Matrix (Genap): \n";
    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            if (matrix_genap [i][j] < 10)
                cout << "0";       
            cout << matrix_genap[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------------------------------------\n";
    cout << "\nMatriks koordinat telah di pulihkan\n";
    cout << "Lakukan prose-proses berikut ini untuk membuat matriks koordinat lebih akurat!\n";
    cout << "1.  Coordinat Matrix Integration\n";
    cout << "2.  Matrix Transpose\n";
    cout << "3.  Snake Traverse\n";
    system("pause");

    cout << "COORDINAT MATRIX INTEGRATION: \n";
    cout << "--------------------------------------------\n";

    int matrix_integrasi[5][5];
    for (int i = 0; i < matrix; i++) {       
        for (int j = 0; j < matrix; j++) {   
            matrix_integrasi[i][j] = matrix_ganjil[i][j] + matrix_genap[i][j];
        }
    }
    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            if (matrix_integrasi[i][j] < 10)
                cout << "0";           
            cout << matrix_integrasi[i][j] << " ";
        }
        cout << "\n";               
    }
    int matrix_transpose[5][5];

    cout << "\nMATRIX TRANSPOSE:\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < matrix; i++)
        for (int j = 0; j < matrix; j++)
            matrix_transpose[i][j] = matrix_integrasi[j][i];

    for (int i = 0; i < matrix; i++) {
        for (int j = 0; j < matrix; j++) {
            if (matrix_transpose[i][j] < 10) cout << "0";
            cout << matrix_transpose[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nSNAKE TRAVERSE:\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < matrix; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < matrix; j++) {
                if (matrix_transpose[i][j] < 10) cout << "0";
                cout << matrix_transpose[i][j] << " ";
            }
        } else {
            for (int j = matrix - 1; j >= 0; j--) {
                if (matrix_transpose[i][j] < 10) cout << "0";
                cout << matrix_transpose[i][j] << " ";
            }
        }
        cout << "\n";

        
    }
    cout << "\n--------------------------------------------\n";
    cout << ">> [TASK 3/3] COMPLETE - Navigation matrix aligned.\n";
    cout << "============================================\n";
    cout << "ALL TASKS COMPLETE - SHIP SYSTEMS RESTORED\n";
    cout << "============================================\n";
    return 0;
}