#include <iostream>
using namespace std;
int main (){
    // Deklarasi variabel.
    int hargaBeras, hargaTelur, hargaMinyakGoreng, totalBelanja, totalPajak, totalAkhirBelanja, uangPelanggan, kembalian;
    int n100k, n50k, n20k, n10k, n5k, n1k, k1k, k500, k200, k100;

    cout << "============================================\n";
    cout << "|         TOKO SEMBAKO JAYA ABADI          |\n";
    cout << "============================================\n";
    cout << "[Bina]: Than, masukan harga barangnya Rendy di program ini!\n";

    // Input Harga Beras, Telur, dan Minyak goreng dari pelanggan.
    cout << "Harga Beras (Rp.)         : ";
    cin >> hargaBeras;
    cout << "Harga Telur (Rp.)         : ";
    cin >> hargaTelur;
    cout << "Harga Minyak Goreng (Rp.) : ";
    cin >> hargaMinyakGoreng;
    cout << "--------------------------------------------\n";

    // Hitung total belanja, total pajak, dan total akhir belanja. 
    totalBelanja = hargaBeras + hargaTelur + hargaMinyakGoreng; totalPajak = totalBelanja * 25 / 100;
    totalAkhirBelanja = totalBelanja + totalPajak;
    
    // Menampilkan Total akhir Belanja + Pajak.
    cout << "Total Belanja (+ PPN 25%)     : " << totalAkhirBelanja << "\n";
    cout << "[Fathan]: Ren, totalnya segitu. Uang lu berapa?\n";
    cout << "[Rendy]: hmmmmmmmm, pajaknya gede juga ya.\n";
    // Hitung uang kembalian.
    cout << "--------------------------------------------\n";
    cout << "Nominal uang Rendy (Rp.)      : ";
    cin >> uangPelanggan;
    kembalian = uangPelanggan - totalAkhirBelanja;

    // Menampilkan Stuk Kembalian
    cout << "============================================\n" ;
    cout << "|              STRUK KEMBALIAN             |\n" ;
    cout << "============================================\n" ;
    cout << "[Bina]: Nih, Than. Rincian kembaliannya : "; 
    cout << "Total Kembalian : Rp. "  << kembalian << "\n";
    
    n100k = kembalian / 100000; kembalian %= 100000;
    n50k = kembalian / 50000; kembalian %= 50000;
    n20k = kembalian / 20000; kembalian %= 20000;
    n10k = kembalian / 10000; kembalian %= 10000;
    n5k = kembalian / 5000; kembalian %= 5000;
    n1k = kembalian / 1000; kembalian %= 1000;
    k1k = kembalian / 1000; kembalian %= 1000;
    k500 = kembalian / 500; kembalian %= 500;
    k200 = kembalian / 200; kembalian %= 200;
    k100 = kembalian / 100; kembalian %= 100;
    cout << "--------------------------------------------\n";

    cout << "- Rp 100.000  : " << n100k << " lembar\n";
    cout << "- Rp 50.000   : " << n50k << " lembar\n";
    cout << "- Rp 20.000   : " << n20k << " lembar\n" ;
    cout << "- Rp 10.000   : " << n10k<< " lembar\n";
    cout << "- Rp 5.000    : " << n5k << " lembar\n";
    cout << "- Rp 1.000    : " << n1k << " lembar\n";
    cout << "- Rp 1.000    : " << k1k << " koin\n";
    cout << "- Rp 500      : " << k500 << " koin\n";
    cout << "- Rp 200      : " << k200 << " koin\n";
    cout << "- Rp 100      : " << k100 << " koin\n";
    cout << "--------------------------------------------\n";

    cout << "[Fathan]: Aman! Sisa Receh tak terpercaya: Rp. " << kembalian << "\n";
    cout << "ini mau di Donasikan ga Ren?" << "\n";
    cout << "[Rendy]: GAS" << "\n";
    cout << "============================================\n";
    return 0;
}