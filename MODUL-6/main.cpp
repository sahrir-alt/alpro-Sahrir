#include <iostream>
using namespace std;

int pilihan;
void menu_utama (){
    cout << "     CYRON TERMINAL: DIVINE SUPPRESSION\n";
    cout << "\n------------------------------------------------\n";
    cout << "1. View Neural Map (Status)\n";
    cout << "2. Inject Neural Thread (Add)\n";
    cout << "3. Purge Corrupted Link (Delete)\n";
    cout << "4. Expand Willpower (Resize)\n";
    cout << "0. Surrender (Exit)\n";
    cout << "------------------------------------------------\n";
    cout << "Select Operation: ";
    cin >> pilihan;
    
}

int main(int argc, char const *argv[]){
    if (argc < 2){
        cout << "Error: Too many parameters. Connection unstable.\n";
        return 1;
    }

    string NIM[1] = argv[11];    
    if (){

    menu_utama();
    return 0;
}
