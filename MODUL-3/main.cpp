#include <iostream>
using namespace std;

int main (){
    int key;
    bool loop1 = false, loop2 = false;
    string teks;

    // tugas 1
    cout << "[TASK 1/3] DECODE SIGNAL - Communication Romm\n";
    cout << ">> Kirim Sinyal terenskripsi dan deskripsi balasan dari Bumi!\n\n";
    cout << "[ ENSKRIPSI ]\n\n";

    cout << "Masukan key              : ";
    cin >> key;
    while (!loop1) {
        if (key <= 0){
            cout << "   [!] Key harus bilangan bulat positif. Coba lagi.\n";
            cout << "Masukan key           : ";
            cin >> key;
            break;
        }
        else loop1 = true;
    }
    
    // 
    do {
        cout << "Masukan teks           :  \n";
        getline(cin, teks);
        if (teks.empty()){
            cin.ignore();
            cin.clear();
        }
        else loop2 = true;
    } 
    while (!loop2);
    return 0;
}