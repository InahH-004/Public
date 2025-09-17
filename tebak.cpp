#include <iostream>
#include <cstdlib> //untuk memanggil rand dan srand
#include <ctime> //memanggil time(0)

using namespace std;

int main()
{
    srand(time(0));     //mengacak angka awal lalu dimasukkan ke variabel angkaRahasia, tanpa ini angka yg disimpan akan urut
    int angkaRahasia = rand() % 100 + 1;  //%100 itu modulus 100  yang sisa pembagiannya selalu antara 1--99, +1 agar genap hingga 1--100
    int tebakan;    //variabel untuk tebakan dari user

    cout << "Selamat Datang di Tebak Angka!\n";
    cout << "Saya sudah memilih angka dari 1 hingga 100.\n";
    cout << "Silahkan Tebak!\n\n";

    do  //bentuk looping untuk mengarahkan user memasukkan input sesuai angkaRahasia
    {
        cout << "Masukkan Tebakan Anda : "; //meminta input dari user
        cin >> tebakan;    //memasukkan nilai dari input tadi ke variabel tebakan

        if (tebakan > angkaRahasia)  //jika nilai tebakan lebih rendah dari nilai pada angkaRahasia
            cout << "Terlalu Tinggi, coba yang lebih rendah\n";
        else if (tebakan < angkaRahasia)
            cout << "Terlalu Rendah, coba naikkan sedikit\n";
        else //else berarti selain daripada kondisi diatas 
            cout << "Selamat!!! Tebakan Kamu benar..\n";

    } while ( tebakan != angkaRahasia); //looing akan terus berlangsung selama nilai tebakan tidak sama dengan niai pada variabel angkaRahasia

    return 0;
}