#include <iostream>
using namespace std;

int main(){

    cout << "=================================" << endl;
    cout << "Selamat Datang di Kalkulator v.2" << endl;
    cout << "=================================" << endl;

    cout << "Pilih Operasi" << endl;
    cout << "1. Penjumlahan " << endl;
    cout << "2. Pengurangan " << endl;
    cout << "3. Pembagian " << endl;
    cout << "4. Perkalian " << endl;

    int operasi;
    do {
        cout << "Pilihan : " ;
        cin >> operasi;
    } while (operasi < 1 || operasi > 4);

    cout << "=================================" << endl;

    double input1;
    double input2;

    cout << "Input 1 : " ;
    cin >> input1 ;
    cout << "Input 2 : " ;
    cin >> input2;

    cout << "=================================" << endl;
    if (operasi == 1){
        cout << "Hasil : " << input1 + input2 << endl;
    } else if ( operasi == 2) {
        cout << "Hasil : " << input1 - input2 << endl;
    } else if ( operasi == 3) {
        cout << "Hasil : " << input1 / input2 << endl;
    } else {
        cout << "Hasil : " << input1 * input2 << endl;
    }

    cout << "=================================" << endl;
    return 0; 
}