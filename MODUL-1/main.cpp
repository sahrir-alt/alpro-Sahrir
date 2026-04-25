#include <iostream>
using namespace std;
int main (){
    // Deklarasi variabel
    int hargaBeras, hargaTelur, hargaMinyakGoreng, totalBelanja, totalPajak, totalAkhirBelanja, uangPelanggan, kembalian, sisa;
    int seratus = 100000, limaPuluh = 50000, duapuluh = 20000, sepuluh = 10000, limaribu = 5000, seribuKertas = 1000, seribuKoin = 1000, limaratusKoin = 500, duaratusKoin = 200, seratusKoin = 100;
    int n100k, n50k, n20k, n10k, n5k, n1k, k1k, k500, k200, k100;

    cout << "=====================================" << endl;
    cout << "|      TOKO SEMBAKO JAYA ABADI      |" << endl;
    cout << "=====================================" << endl;
    cout << "[Bina]: Than, masukan harga barangnya Rendy di program ini!" << endl;

    cout << "masukan harga Beras (Rp.)         : ";
    cin >> hargaBeras;
    cout << "masukan harga Telur (Rp.)         : ";
    cin >> hargaTelur;
    cout << "masukan harga Minyak Goreng (Rp.) : ";
    cin >> hargaMinyakGoreng;
    cout << "---------------------------------------" << endl;

    // Hitung total belanja, total pajak, dan total akhir belanja. 
    totalBelanja = (hargaBeras + hargaTelur + hargaMinyakGoreng) * 25/100;
    // totalAkhirBelanja = totalBelanja + totalPajak;
    
    cout << "Total Belanja (+ PPN 25%) : " << totalBelanja << endl;
    cout << "---------------------------------------" << endl;

    cout << "Terima uang dari pelanggan (Rp.) : ";
    cin >> uangPelanggan;

    kembalian = uangPelanggan - totalAkhirBelanja;

    cout << "=====================================" << endl;
    cout << "|          STRUK KEMBALIAN          |" << endl;
    cout << "=====================================" << endl;

    cout << "hasil kembalian : Rp. " << kembalian << endl;
    sisa = kembalian;
    n100k = sisa / seratus; sisa %= seratus;
    n50k = sisa / limaPuluh; sisa %= limaPuluh;
    n20k = sisa / duapuluh; sisa %= duapuluh;
    n10k = sisa / sepuluh; sisa %= sepuluh;
    n5k = sisa / limaribu; sisa %= limaribu;
    n1k = sisa / seribuKertas; sisa %= seribuKertas;

    k1k = sisa / seribuKoin; sisa %= seribuKoin;
    k500 = sisa / limaratusKoin; sisa %= limaratusKoin;
    k200 = sisa / duaratusKoin; sisa %= duaratusKoin;
    k100 = sisa / seratusKoin; sisa %= seratusKoin;

    cout << "---------------------------------------" << endl;
    cout << "- Rp 100.000  : " << n100k << " lembar" << endl;
    cout << "- Rp 50.000   : " << n50k << " lembar" << endl;
    cout << "- Rp 20.000   : " << n20k << " lembar " << endl;
    cout << "- Rp 10.000   : " << n10k<< " lembar" << endl;
    cout << "- Rp 5.000    : " << n5k << " lembar" << endl;
    cout << "- Rp 1.000    : " << n1k << " lembar" << endl;
    cout << "- Rp 1.000    : " << k1k << " koin" << endl;
    cout << "- Rp 500      : " << k500 << " koin" << endl;
    cout << "- Rp 200      : " << k200 << " koin" << endl;
    cout << "- Rp 100      : " << k100 << " koin" << endl;
    cout << "---------------------------------------" << endl;

    cout << "Aman! sisa Receh tak terpercaya : " << sisa << endl;
    cout << "ini mau di dinasikan gak?" << endl;
    cout << "GAS" << endl;
    cout << "---------------------------" << endl;
    return 0;
}