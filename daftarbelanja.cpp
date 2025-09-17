#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct daftar {
        string nama;
        int jumlah;
        int harga;
    };

int main(){
    
    int total_barang;
    
    cout << "=====================================" << endl;
    cout << "Mau Beli apa aja?" << endl ;
    cout << endl;
    cout << "jumlah barang yang ingin dibeli : " ;
    cin >> total_barang;

    cout << "=====================================" << endl;

    struct daftar barang[total_barang];

    for (int i=0; i < total_barang; i++){
        cout << endl;
        cout << "Masukkan Detail Barang ke-" << i+1 << endl;
        cout << "Nama Barang : ";
        cin >> barang[i].nama;
        cout << "Jumlah : ";
        cin >> barang[i].jumlah;
        cout << "Harga : ";
        cin >> barang[i].harga;
    }

    cout << "=====================================" << endl;

    int harga_akhir = 0; 
    for (int i= 0; i < total_barang ; i++){
        int total_harga = barang[i].jumlah * barang[i].harga ;
        harga_akhir += total_harga ;

        cout << "nama : " << barang[i].nama << " - jumlah : " << barang[i].jumlah << " - harga : " << barang[i].harga << endl;
        cout << "Total Harga : " << total_harga << endl;

    } cout << endl;  

    cout << "=====================================" << endl;
    cout << "Harga Akhir : " << harga_akhir << endl;
    cout << "=====================================" << endl;
}