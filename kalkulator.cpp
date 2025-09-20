#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    cout << "==============================" << endl;

    int operasi ;
    cout << "Selamat Datang di Kalkulator" << endl;
    cout << "==============================" << endl;
    cout << "Pilih Operasi" << endl;
    cout << "1. Penjumlahan " << endl << "2. Pengurangan" << endl;

    do {
        cout << "Pilihan : ";
        cin >> operasi; 
    } while (operasi < 1 || operasi > 2);
    

    cout << "==============================" << endl;
    int input1;
    cout << "Input 1 : ";
    cin >> input1;

    int input2;
    cout << "Input 2 : ";
    cin >> input2;

    cout << "==============================" << endl;
    if (operasi == 1){
        cout << "Hasil : " << input1 + input2 << endl;
    } else {
        cout << "Hasil : " << input1 - input2 << endl;
    }

    cout << "==============================" << endl;
    return 0;
}