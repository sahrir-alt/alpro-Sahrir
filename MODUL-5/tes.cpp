#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    cout << "Jumlah argumen : " << argc << endl;
    cout << "Nama program   : " << argv[0] << endl;

    for (int i = 1; i < argc; i++) {
        cout << "Argumen ke-" << i << "   : " << argv[i] << endl;
    }

    return 0;
}