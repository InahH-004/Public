#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct kategori {
    int umur;
    string nik;
    string jabatan;
};

struct nama {
    string depan;
    string tengah;
    string belakang;
};

void tampilkanPengaturan();
void tampilkanData(const kategori data[], const nama data2[], int n);
void hapusData(kategori data[], nama data2[], string nik, int &n);
void memintaInput(kategori data[], nama data2[], int &n);
void editData(kategori data[], nama data2[], string n, int j);
void simpanDataBaru(const kategori& dataKategori, const nama& dataNama);
void tulisUlangData(const kategori data[], const nama data2[], int n);

int main(){
    const int jumlahKaryawan = 5;
    int count = 0;

    kategori data[jumlahKaryawan];
    nama data2[jumlahKaryawan];

    ifstream inputFile("dataKaryawan.txt"); //baca file
    if (!inputFile){
        cout << "Tidak Dapat Membuka File" << endl;
        return 1;
    } else {
        string line;
        while(getline(inputFile, line) && count < jumlahKaryawan){
            stringstream ss(line); //baca file per spasi dan per enter
            ss >> data2[count].depan >> data2[count].tengah >> data2[count].belakang >> data[count].umur >> data[count].nik >> data[count].jabatan;
            
            count ++;
        }
    } inputFile.close(); //tutup file

    cout << "\n==============================================\n";
    cout << "\n----- Selamat Datang di Katalog Karyawan -----\n";
    cout << "\n==============================================\n";
    int answer;
    do {
        tampilkanPengaturan();
        cin >> answer;
        switch(answer) {
            case 1: {
                tampilkanData(data, data2, count);
                break;
            }
            case 2: {
                memintaInput(data, data2, count);
                break;
            }
            case 3: {
                string nikHapus;
                cout << "\nMasukkan NIK Karyawan yang Ingin Dihapus : ";
                cin >> nikHapus;
                hapusData(data,data2, nikHapus, count);
                break;
            }
            case 4: {
                string edit;
                cout << "\nMasukkan NIK Karyawan yang Ingin Diedit : ";
                cin >> edit;
                editData(data, data2, edit, count);
                break;
            }
            case 5: {
                cout << "\n----- Program Selesai -----\n" << endl;
                break;
            }
        }
    } while (answer != 5);
}

void tampilkanPengaturan(){
    cout << "Pengaturan :" << endl;
    cout << "1. Tampilkan Data" << endl;
    cout << "2. Tambah Data" << endl;
    cout << "3. Hapus Data" << endl;
    cout << "4. Edit Data" << endl;
    cout << "5. Selesai" << endl;
    cout <<"\nPilihan (1-5) : ";
}

void memintaInput(kategori data[], nama data2[], int &n){
    cout << "Nama depan : ";
    cin >> data2[n].depan;
    cout << "Nama tengah : ";
    cin >> data2[n].tengah;
    cout << "Nama belakang : ";
    cin >> data2[n].belakang;
    cout << "Umur : ";
    cin >> data[n].umur;
    cout << "NIK : ";
    cin >> data[n].nik;
    cout << "Jabatan : ";
    cin >> data[n].jabatan;
    cout << endl;
    simpanDataBaru(data[n], data2[n]);
    n++;
    cout << "----- Data Berhasil di Tambahkan -----"<< endl;

    char answer2;
    cout << "\nIngin Menampilkan Data Terbaru?(y/n) : ";
    cin >> answer2;
    if(answer2 == 'y'){
        cout << endl;
        tampilkanData(data, data2, n);
    }
    if(answer2 == 'n'){
        cout << "\n-----Program Selesai-----\n";
    }
}

void hapusData(kategori data[], nama data2[], string nik, int &n){
    int indexHapus;
    for(int i = 0; i < n; i++){
        if(nik == data[i].nik){
            indexHapus = i;
                for(int j = indexHapus; j < n - 1; j++){
                    data2[j] = data2[j+1];
                    data[j]  = data[j+1];
                }
            cout << "\n -----  Data Karyawan dengan NIK " << nik << " Berhasil Dihapus -----" << endl;
            n--;
            tulisUlangData(data, data2, n);
            break;
            }
        }
    char answer2;
    cout << "\nIngin Menampilkan Data Terbaru?(y/n) : ";
    cin >> answer2;
    if(answer2 == 'y'){
        cout << endl;
        tampilkanData(data, data2, n);
    }
    if(answer2 == 'n'){
        cout << "\n-----Program Selesai-----\n";
    }
}

void editData(kategori data[], nama data2[], string n, int j){
    int pilihanEdit;
    int indexEdit;
    for(int i = 0; i < j; i++){
        if( n == data[i].nik){
            indexEdit = i;
        }
    }
        cout << "\n1. Nama Depan\n";
        cout << "2. Nama Tengah\n";
        cout << "3. Nama Belakang\n";
        cout << "4. Umur\n";
        cout << "5. NIK\n";
        cout << "6. Jabatan\n";
        cout << "\nApa yang ingin diedit? (1-6) : ";
        cin >> pilihanEdit;
                switch (pilihanEdit){
                case 1 :
                    cout << "\nMasukkan Nama Depan : ";
                    cin >> data2[indexEdit].depan;
                    break;
                case 2 :
                    cout << "\nMasukkan Nama Tengah : ";
                    cin >> data2[indexEdit].tengah;
                    break;
                case 3 :
                    cout << "\nMasukkan Nama Belakang : ";
                    cin >> data2[indexEdit].belakang;
                    break;
                case 4 :
                    cout << "\nMasukkan Umur : ";
                    cin >> data[indexEdit].umur;
                    break;
                case 5 :
                    cout << "\nMasukkan NIK : ";
                    cin >> data[indexEdit].nik;
                    break;
                case 6 :
                    cout << "\nMasukkan Jabatan : ";
                    cin >> data[indexEdit].jabatan;
                    break;
                default:
                     cout << "\nInput Tidak Valid" << endl;
                    return;
                }
    tulisUlangData(data, data2, j);
    cout << "\n----- Data Berhasil Diedit -----\n";

    char answer2;
    cout << "\nIngin Menampilkan Data Terbaru?(y/n) : ";
    cin >> answer2;
    if(answer2 == 'y'){
        cout << endl;
        tampilkanData(data, data2, j);
    }
    if(answer2 == 'n'){
        cout << "\n-----Program Selesai-----\n";
    }
}

void tampilkanData(const kategori data[], const nama data2[], int n){
    cout << "\nData Karyawan : " << endl;
    if ( n == 0){
        cout << "Belum Ada Data" << endl;
    }
    for (int i = 0; i < n; i++){
        cout << "Karyawan " << i+1 << ": " << endl;
        cout << "Nama : " << data2[i].depan <<" "<< data2[i].tengah <<" "<< data2[i].belakang << endl;
        cout << "Umur : " << data[i].umur << endl;
        cout << "NIK : " << data[i].nik << endl;
        cout << "Jabatan : " << data[i].jabatan << endl;
        cout << endl;
    }
}

void simpanDataBaru(const kategori& dataKategori, const nama& dataNama) {
    ofstream outputFile("dataKaryawan.txt", ios::app); //Buat nulis ke file yang awal
    //output file == buat berinteraksi dengan file
    //ios::app == mode untuk membuka file, app (append/menambahkan), dengan kursor di bagian akhir sehingga tidak menimpa
    if (outputFile.is_open()) { //tidak pakai perulangan, karena hanya memasukkan 1 data terbaru saja
        outputFile << dataNama.depan << " " << dataNama.tengah << " " << dataNama.belakang << " "
                   << dataKategori.umur << " " << dataKategori.nik << " " << dataKategori.jabatan << endl;
        outputFile.close();
    } else {
        cout << "Gagal menyimpan data ke file." << endl;
    }
}

void tulisUlangData(const kategori data[], const nama data2[], int n){
    ofstream outputFile("dataKaryawan.txt"); //miripdengan function simpandata, function ini tidak pakai ios::app sehingga data akan terhapus lalu di tulis ulang
    if (outputFile.is_open()) {
        for(int i = 0; i < n; i++){ //pakai peprulangan karena untuk menulis kembali seluruh data 
            outputFile << data2[i].depan << " " << data2[i].tengah << " " << data2[i].belakang << " "
                       << data[i].umur << " " << data[i].nik << " " << data[i].jabatan << endl;
        }
        outputFile.close();
    } else {
        cout << "Gagal menulis ulang data file." << endl;
    }
}