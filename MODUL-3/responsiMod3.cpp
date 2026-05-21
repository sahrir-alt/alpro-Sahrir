#include <iostream>
using namespace std;

int main() {
    string petunjuk;
    cout << "Masukkan petunjuk: ";
    getline(cin, petunjuk);

    int kunci = 9;
    string terdekripsi = "";
    for (int i = 0; i < (int)petunjuk.length(); i++) {
        char c = petunjuk[i];
        if (c >= 'A' && c <= 'Z')
            terdekripsi += (char)(((c - 'A') - kunci + 26) % 26 + 'A');
        else if (c >= 'a' && c <= 'z')
            terdekripsi += (char)(((c - 'a') - kunci + 26) % 26 + 'a');
        else
            terdekripsi += c;
    }

    int total_ASCII = 0;
    for (int i = 0; i < (int)petunjuk.length(); i++)
        total_ASCII += (int)petunjuk[i];

    int posisi      = total_ASCII % 25;
    char petakHarta = (char)('A' + posisi);

    char peta[5][5];
    bool terbuka[5][5];
    int huruf = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            peta[i][j]    = (char)('A' + huruf++);
            terbuka[i][j] = false;
        }

    cout << "\nSelamat datang di Perburuan Harta!";
    cout << "Temukan harta sebelum nyawa habis!" << endl;
    cout << "Anda memiliki 5 nyawa.\n" << endl;

    auto tampilPeta = [&]() {
        for (int i = 0; i < 5; i++) {
            cout << "     |    |    |    |" << endl;
            cout << "  " << peta[i][0];
            for (int j = 1; j < 5; j++)
                cout << "  | " << peta[i][j];
            cout << endl;
            cout << " ____|____|____|____|____" << endl;
        }
        cout << endl;
    };

    tampilPeta();
    int  nyawa     = 5;
    bool ditemukan = false;

    while (nyawa > 0 && !ditemukan) {
        char inputPetak;
        cout << "Enter your move (A to Y): ";
        cin  >> inputPetak;
        inputPetak = toupper(inputPetak);

        if (inputPetak < 'A' || inputPetak > 'Y') {
            cout << "Input tidak valid! Masukkan huruf A sampai Y.\n\n";
            tampilPeta();
            continue;
        }

        int posisiInput = (int)(inputPetak - 'A');
        int barisInput  = posisiInput / 5;
        int kolomInput  = posisiInput % 5;

        if (terbuka[barisInput][kolomInput]) {
            cout << "Petak ini sudah dibuka! Coba petak lain.\n\n";
            tampilPeta();
            continue;
        }

        terbuka[barisInput][kolomInput] = true;

        if (inputPetak == petakHarta) {
            ditemukan = true;
        } else {
            nyawa--;
            peta[barisInput][kolomInput] = '-';
            cout << "No treasure here! You lose 1 health." << endl;
            cout << "Remaining health: " << nyawa << "\n" << endl;
            tampilPeta();
        }
    }

    if (ditemukan) {
        cout << "\n+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|   Congratulations!                       |" << endl;
        cout << "|   You found the treasure at: " << petakHarta << "           |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "You win the game!" << endl;
    } else {
        cout << "\n+------------------------------------------+" << endl;
        cout << "|                                          |" << endl;
        cout << "|   Game Over!                             |" << endl;
        cout << "|   You failed to find the treasure...     |" << endl;
        cout << "|                                          |" << endl;
        cout << "+------------------------------------------+" << endl;
        cout << "You lose the game!" << endl;
    }

    return 0;
}