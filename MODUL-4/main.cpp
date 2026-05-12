#include <iostream>
using namespace std;

int jawaban1;
bool loop1 = false;

void banner1(string header){
	cout << "|====================================|\n";
	cout << "|                                    |\n";
	cout << "[         "<< header <<"        ]\n"; 
	cout << "|                                    |\n";
	cout << "|====================================|\n\n";
    cout << "1. TIVAIZ STORE\n";
    cout << "2. Kalkulator TIVAIZ\n";
    cout << "0. keluar\n";
    cout << "===========================================\n";

} 
void banner2(string a){
    cout << "#==========================#\n";
    cout << "|       "<< a << "         |\n"; 
    cout << "#==========================#";
}

void tugas1 (){  
        cout << "Pilih menu: ";
        cin >> jawaban1;

        if (jawaban1 < 0 || jawaban1 > 2 ){
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2\n";
            cin.clear();
            cin.ignore();
            system("pause");
            system("cls");
        }
        else if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Gagal] Input harus berupa angka\n";
            system("pause");
            system("cls");
        }
        else {
            loop1 = true;
        }
}

void kalkulator (string a){
    cout << "+==========================-\n";
    cout << "|       "<< a << "         |\n"; 
    cout << "x==========================/\n\n";
    cout << "1. Operasi Dasar\n";
    cout << "2. Faktorial\n";
    cout << "0. kembali\n";
    cout << "=============================";
}
   
int main(){
    
    
    do {
        banner1("MODULE 4 - FUNCTION");
        tugas1();
    }
    while (!loop1);
    if (jawaban1 == 1){
        
    }
    else if (jawaban1 == 2 ) {
        system("cls");
        kalkulator("K4LKUL4T0R");
    } 


    return 0;
}