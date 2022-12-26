#include "mll.h"

// MARK: - Menu
int menu() {
    int inputUser;
    cout << "===== SELAMAT DATANG DI PROGRAM KERETA =====" << endl;
    cout << "1. Kereta Api Lokal" << endl;
    cout << "2. Kereta Api Antar Kota" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;
    
    return inputUser;
}

int menuLokal() {
    int inputUser;
    cout << "===== SILAHKAN PILIH KERETA =====" << endl;
    cout << "1. Bandung Raya Ekonomi" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;
    
    return inputUser;
}

int menuAntarKota()
{
    int inputUser;
    cout << "===== SILAHKAN PILIH KERETA =====" << endl;
    cout << "1. Turangga" << endl;
    cout << "2. Argo Parahyangan" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;
    
    return inputUser;
}

int menuKereta(kereta &k) {
    showKereta(k);
    
    int inputUser;
    cout << "===== SILAHKAN PILIH KERETA =====" << endl;
    cout << "1. Menampilkan informasi gerbong" << endl;
    cout << "2. Menampilkan jumlah penumpang" << endl;
    cout << "3. Mencari penumpang" << endl;
    cout << "4. Menambah gerbong" << endl;
    cout << "5. Menambah penumpang" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    
    switch (inputUser)
    {
        case 1:
            showGerbong(k);
            break;
        case 2:
            cout << "Jumlah penumpang kereta: " << countPenumpang(k);
            break;
        case 3: {
            string nama;
            cout << "Nama penumpang yang dicari: ";
            cin >> nama;
            
            adrPenumpang p = searchPenumpang(k, nama);
            
            if (p) {
                cout << "Terdapat penumpang bernama " << nama << endl;
                cout << "Jenis kelamin\t: " << info(p).jenisKelamin << endl;
                cout << "Umur\t\t\t: " << info(p).usia << endl;
                cout << "Gerbong\t\t: " << info(gerbong(p)).kelas << endl;
                cout << "Kereta\t\t: " << k.info.nama << endl;
            } else {
                cout << "Tidak terdapat penumpang bernama " << nama << endl;
            }
            
            break;
        }
        case 4: {
            infoGerbong info;
            
            cout << "Kelas\t\t\t: ";
            cin >> info.kelas;
            cout << "Maksimal Penumpang\t: ";
            cin >> info.maksPenumpang;
            cout << "Konfigurasi seat\t: ";
            cin >> info.konfigurasiSeat;
            cout << "Harga tiket\t\t: ";
            cin >> info.hargaTiket;
            
            insertLastGerbong(k, createElmGerbong(info));
            break;
        }
        case 5: {
            infoPenumpang info;
            
            cout << "Nama\t\t\t: ";
            cin >> info.nama;
            cout << "Usia\t\t\t: ";
            cin >> info.usia;
            cout << "Jenis Kelamin\t: ";
            cin >> info.jenisKelamin;
            
            insertLastPenumpang(k, createElmPenumpang(info));
            
            break;
        }
        case 0:
            break;
        default:
            menuKereta(k);
            break;
    }
    
    cout << endl;
    
    return inputUser;
}
