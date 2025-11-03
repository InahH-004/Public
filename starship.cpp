#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>    //  Untuk rand() dan srand() random
#include <ctime>      // Untuk time() 
#include <windows.h>  //  Untuk warna konsol 
#include <thread>     //  Untuk std::this_thread::sleep_for, biar ada jedanya
#include <chrono>     // Untuk std::chrono::seconds
using namespace std;

int g_earthSavingScore = 0;
int g_spaceSampleScore = 0;

struct shipProperties{
    string nameShip;
    string type;
    int crew;
    int fluelLevel;
    int hullIntegrity;        
};

struct identity{
    string name;
    char gender;
    string specialize;
};

void license(identity &user);
void intro();
int readData (shipProperties ships[], int size);
void menu (shipProperties ships[], int size);
void showShips(shipProperties ships[], int size);
void update_Data(const shipProperties ships[], int count);
void workShop (shipProperties ships[], int &count, int size);
void reFueld (shipProperties ships[], int count);
void repair (shipProperties ships[], int count);
void newShips (shipProperties ships[], int &count, int size);
void controlPanel (shipProperties ships[], int &count);
void currentStatus(shipProperties ships[], int &count);
const int MAX_SHIP = 10;

int main(){
    srand(time(0));
    identity user;
    shipProperties allShip[MAX_SHIP];
    license(user);
    intro();
    menu (allShip, MAX_SHIP);
}

int readData (shipProperties ships[], int size){
    int count = 0;
    ifstream inputFile("starship_data.txt"); //baca file
    if (!inputFile){
        cout << "Cannot Open The File" << endl;
    } else {
        string line;
        while(getline(inputFile, line) && count < size){
            stringstream ss(line); //baca file per spasi dan per enter
            ss >> ships[count].nameShip >> ships[count].type >> ships[count].crew >>ships[count].fluelLevel >> ships[count].hullIntegrity;
            count ++;
        }
    } inputFile.close(); //tutup file
    return count;
}

void license(identity &user){
    
     cout << "\n================================\n";
     cout << "\nFor security reasons, we require your identification before accessing our facilities\n";
     cout << "Please enter your identification below.\n";
     cout << "\n================================\n";
     cout << "\nNickname : ";
     cin >> user.name;
     do {
          cout << "Gender(F/M) : ";
          cin >> user.gender;
     } while (user.gender != 'f' && user.gender != 'F' && user.gender != 'M' && user.gender != 'm');

     cout << "Spesialization : ";
     cin >> user.specialize;

     cout << "\n================================\n";
     if( user.gender == 'F' || user.gender == 'f'){
         cout << "\nWelcome, Mrs. " << user.name << endl;
     } else{
         cout << "\n Welcome, Mr. " << user.name << endl;
     }
     cout << "Thank You For Coming To The Astrophile Space Center\n";
 }

void intro(){
    cout << "\n==============================================" << endl;
    cout << "\n----- WELCOME TO ASTROPHILE SPACE CENTER -----" << endl;
    cout << "\n==============================================" << endl;
}

void menu (shipProperties ships[], int size){
    int input;
    int shipCount = readData (ships, size);
    do
    {
        cout << "\n------------ MAIN MENU --------------\n";
        cout << "1. Go To Workshop\n" ;
        cout << "2. Go To Control Panel\n";
        cout << "3. Exit\n";
        cout << "Input : ";
        cin >> input;
        switch (input){
        case 1: {
            workShop(ships, shipCount, size);
            break;
        }
        case 2: {
            controlPanel (ships, shipCount);
            break;
        }
        }
    } while (input != 3);
}

void showShips(shipProperties ships[], int count){
    cout << "\n------------ ALL SHIPS ------------\n";
    cout << endl;

    if (count == 0){
        cout << "The Is No Ships In The Fleet\n";
    }
    for(int i = 0; i < count; i++){
        cout << "SHIP-" << i+1 << endl;
        cout << "Ship Name         : " << ships[i].nameShip << endl;
        cout << "Type              : " << ships[i].type << endl;
        cout << "Crew Capacity     : " << ships[i].crew << endl;
        cout << "Fluel Level(%)    : " << ships[i].fluelLevel << endl;
        cout << "Hull Integrity(%) : " << ships[i].hullIntegrity << endl;
        cout << endl;

    }
    char answer;
    for(int i = 0; i < count ; i++){
        if(ships[i].fluelLevel < 30){
        cout << "\n=========== !NOTICE! ===========\n";
        cout << "The " << ships[i].nameShip << " has LOW fluel\n";
        cout << "Please Go To Workshop and Refuel\n";
        cout << "\n================================\n";
        } 
        if(ships[i].hullIntegrity < 50){
            cout << "\n=========== !NOTICE! ===========\n";
            cout << "The " << ships[i].nameShip << " need repair\n";
            cout << "Please Go To Workshop and Repair\n";
            cout << "\n================================\n";
        } 
    }
        cout << "\n================================\n";
        cout << "Ship check complete.\n";
        cout << "================================\n";
}

void workShop (shipProperties ships[], int &count, int size){
    int choice;
    do {
        cout << "\n------------ MENU --------------\n";
        cout << "1. Show All The Ships\n";
        cout << "2. Build A New Ships\n";
        cout << "3. Refuel Ships\n";
        cout << "4. Repair Ships\n";
        cout << "5. Back to Main Menu\n";
        cout << "Input : ";
        cin >> choice;

        int answer;
        switch (choice){
        case 1: {
            showShips(ships, count);
            break;
        }
        case 2: {
            newShips (ships, count, size);
            break;
        }
        case 3: {
            reFueld(ships, count);
            break;
        }
        case 4: {
            repair (ships, count);
        }
        }
    } while (choice != 5);

    update_Data(ships, count);
   
    //1. Build A New Ships, 2. Refuel Ships, 3. Repair Ships, 4. Backm 4, Back to Menu
}

void newShips (shipProperties ships[], int &count, int size){
    if (count >= size) { // Jika count (4) >= size (4) (contoh)
        cout << "\n--- Hangar is full! Cannot build more ships ---\n";
        return;
    }
    cout << "\n======== Build New Ship =========\n";
    cout << "Ship Name         : ";
    cin >> ships[count].nameShip;
    cout << "Type              : ";
    cin >> ships[count].type;
    cout << "Crew Capacity     : ";
    cin >> ships[count].crew;
    cout << "Fluel Level(%)    : ";
    cin >> ships[count].fluelLevel;
    cout << "Hull Integrity(%) : ";
    cin >> ships[count].hullIntegrity;
    count ++;

    cout << "\n --- Ship Build Successfully! ---\n";
    cout << "Total Ships : " << count << endl;
    cout << "\n=================================\n";
}

void reFueld (shipProperties ships[], int count){
    int refuel = 0;
    char answer;
    cout << "\n================================\n";
    cout << "--------Ships Fluel Status------\n";
    cout << endl;
    
    for(int i = 0; i < count; i++){
        cout << "The " << ships[i].nameShip << " : " << ships[i].fluelLevel << "%" << endl;
        if(ships[i].fluelLevel < 30){
            refuel++;
        }
    }
    cout << "\n================================\n";

    for(int i = 0; i < count; i++){
        if(ships[i].fluelLevel < 30 && refuel > 0){
            cout << "\nThere are " << refuel << " Ships Need to Refuel\n";
            cout << "Refuel All? (y/n) : ";
            cin >> answer;
            if(answer == 'y' || answer == 'Y'){
                ships[i].fluelLevel = 100;
                cout << "\n================================\n";
                cout << "---- Successfully Refueled ----\n";
                cout << "================================\n";
            } else if (answer == 'n' || answer == 'N'){
                cout << "\n=========== !NOTICE! ===========\n";
                cout << "The Ships need refuel\n";
                cout << "Automatically Refuel The Ship\n";
                ships[i].fluelLevel = 100;
                cout << "\n================================\n";
                cout << "---- Successfully Refueled ----\n";
                cout << "================================\n";
            }
        }else if (refuel == 0){
            cout << "================================\n";
            cout << "All ships have sufficient fuel\n";
            cout << "Ready to carry out the mission\n";
            cout << "================================\n";;
        }
    }
}

void repair (shipProperties ships[], int count){
    int repair = 0;
    char answer;

    cout << "\n=========================================\n";
    cout << "--------Ships Hull Integrity Status------\n";
    cout << endl;
    
    for(int i = 0; i < count; i++){
        cout << "The " << ships[i].nameShip << ": " << ships[i].hullIntegrity << "%" << endl;
        if(ships[i].hullIntegrity < 50){
            repair++;
        }
    }
    cout << "\n================================\n";

    for( int i = 0; i < count; i++) {
        if (ships[i].hullIntegrity < 50 && repair > 0) {
            cout << "\nThere are " << repair << " Ships Need to Repair\n";
            cout << "Refuel All? (y/n) : ";
            cin >> answer;
            if(answer == 'y' || answer == 'Y'){
                ships[i].hullIntegrity = 100;
                cout << "\n================================\n";
                cout << "---- Successfully Repaired ----\n";
                cout << "================================\n";
            } else if (answer == 'n' || answer == 'N'){
                cout << "\n=========== !NOTICE! ===========\n";
                cout << "\nThe Ships need repair\n";
                cout << "Automatically Repair The Ship\n";
                ships[i].hullIntegrity = 100;
                cout << "\n================================\n";
                cout << "---- Successfully Repair ----\n";
                cout << "================================\n";
            }
        } else if (repair == 0){
            cout << "================================\n";
            cout << "All ships have sufficient fuel\n";
            cout << "Ready to carry out the mission\n";
            cout << "================================\n";;
        }
    }
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void controlPanel (shipProperties ships[], int &count){
    int choice;
    do {
        setColor(7); // Reset warna ke putih
        cout << "\n===================================\n";
        cout << "---------- CONTROL PANEL ----------\n";
        cout << "\n1. Check Current Status\n";
        cout << "2. Show Missions Report\n";
        cout << "3. Back to Main Menu\n";
        cout << "Input : ";
        cin >> choice;

        switch (choice){
        case 1: {
            currentStatus(ships, count);
            break;
        }
        case 2: {
            setColor(11); // Biru muda
            cout << "\n===================================\n";
            cout << "--------- MISSIONS REPORT ---------\n";
            cout << "\nEarth Saving Missions    : " << g_earthSavingScore << endl;
            cout << "Space Samples Collected  : " << g_spaceSampleScore << endl;
            cout << "\n===================================\n";
            setColor(7); // Reset warna
            break;
            }
        }

    } while (choice != 3);
}

void currentStatus(shipProperties ships[], int &count) {
    bool dataChanged = false;
    if (count > 0) {
        cout << "\n===================================\n";
        cout << "Scanning sector... All ships consume resources...\n";
        cout << "===================================\n";
        for (int i = 0; i < count; i++) {
            // Kurangi fuel dan hull
            ships[i].fluelLevel -= 30;
            ships[i].hullIntegrity -= 22;

            // Pastikan tidak menjadi negatif (minimal 0)
            if (ships[i].fluelLevel < 0) ships[i].fluelLevel = 0;
            if (ships[i].hullIntegrity < 0) ships[i].hullIntegrity = 0;
        }
        dataChanged = true; // Tandai bahwa data berubah
    } else {
        cout << "\n===================================\n";
        cout << "Scanning sector... No active ships in the fleet.\n";
        cout << "===================================\n";
    }

    int status = rand() % 3;
    if (status == 0) {
            setColor(10); // Hijau cerah
            cout << "\n===================================\n";
            cout << "--------[STATUS: ON CONTROL]-------\n";
            cout << "\nAll systems normal. Sector is clear.\n";
            g_earthSavingScore++; // Tambah skor
            cout << "(+1 Earth Saving Mission)\n";
            cout << "=====================================\n";
    
    } else if (status == 1) {
            setColor(14); // Kuning
            cout << "\n===================================\n";
            cout << " [STATUS: UNKNOWN OBJECT DETECTED] \n";
            string objects[] = {"a dormant meteor", "a charged dust cloud", "a small comet fragment"};
            int objIdx = rand() % 3; // Acak objek
            cout << "\nScanning...\n";
            cout << "Object identified as " << objects[objIdx] << ".\n";
            g_spaceSampleScore++; // Tambah skor
            cout << "\n(+1 Space Sample Collected)\n";
            cout << "===================================\n";
    } else {
            setColor(12); // Merah cerah
            cout << "\n===================================\n";
            cout << "---- [STATUS: DANGER DETECTED!] ---\n";
            cout << "Hostile anomaly detected! Taking evasive maneuvers!\n";
    
            if (count == 0) {
                cout << "The fleet is empty! No ships to destroy.\n";
            }
            // Hancurkan 1 kapal secara acak
            int shipIndex = rand() % count; // Acak index dari 0 s/d (count-1)
            cout << "\nWARNING! Ship '" << ships[shipIndex].nameShip << "' has been destroyed!\n";
    
            // Hapus kapal dari array (geser array)
            for (int i = shipIndex; i < count - 1; i++) {
                ships[i] = ships[i + 1];
            }
            count--; // <-- PENTING: Kurangi jumlah kapal (by reference)
    
            // Identifikasi objek (tunggu 3 detik)
            cout << "Identifying threat...\n";
            this_thread::sleep_for(chrono::seconds(3)); // Jeda 3 detik
            
            string dangers[] = {"a Xylos Pirate Cruiser", "an unknown energy-based lifeform", "a sudden asteroid swarm"};
            int dangerIdx = rand() % 3; // Acak ancaman
            cout << "The unknown object was identified as: " << dangers[dangerIdx] << ".\n";
            
            // Simpan perubahan (karena kapal hancur)
            cout << "Updating fleet records...\n";
            cout << "Update Success\n";
            cout << "\n===================================\n";
            update_Data(ships, count);
    }
    setColor(7); // Reset warna
}

void update_Data(const shipProperties ships[], int count){
    ofstream outputFile("starship_data.txt"); //miripdengan function simpandata, function ini tidak pakai ios::app sehingga data akan terhapus lalu di tulis ulang
    if (outputFile.is_open()) {
        for(int i = 0; i < count; i++){ //pakai peprulangan karena untuk menulis kembali seluruh data 
            outputFile <<  ships[i].nameShip << " " << ships[i].type << " " << ships[i].crew << " " << ships[i].fluelLevel << " " << ships[i].hullIntegrity << endl;
        }
        outputFile.close();
    } else {
        cout << "Update data Failed." << endl;
    }
}
