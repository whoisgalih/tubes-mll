#include "mll.h"

int main()
{
    //  MARK: - Inisialisasi Kereta
    //  Inisialisasi Kereta Antar Kota: Turangga
    kereta KeretaTurangga;
    KeretaTurangga = turangga();
    
    //    // Inisialisasi Kereta Antar Kota: Argo Parahyangan
    //    kereta KeretaTurangga;
    //    KeretaTurangga = turangga();
    //
    //    // Inisialisasi Kereta Lokal: Bandung Raya Ekonomi
    //    kereta KeretaTurangga;
    //    KeretaTurangga = turangga();
    
    
    // MARK: - Identitas
    clearScreen();
    cout <<
    "  ~~~~ ____   |~~~~~~~~~~~~~~~~~|\n"
    " Y_,___|[]|   | GABI TANPA ZAL! |\n"
    "{|_|_|_|PU|_,_|_________________|\n"
    "//oo---OO=OO     OOO     OOO\n\n";
    
    cout << "========== TUGAS BESAR =========="<<endl;
    cout << "Kelompok \t: Gabi Tanpa Zal"<<endl;
    cout << "Tema \t\t: "<<endl;
    cout << "Anggota \t: 1. Galih Akbar Nugraha - 1301213060"<<endl;
    cout << "\t\t  2. Muhammad Abiya Makruf - 1301213157"<<endl<<endl;
    
    // ALGORITMA MENU
    string inputUser;
    
    // Menu without clear screen
    cout << "===== SELAMAT DATANG DI PROGRAM KERETA =====" << endl;
    cout << "1. Kereta Api Lokal" << endl;
    cout << "2. Kereta Api Antar Kota" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;
    
    while (inputUser !="0"){
        if (inputUser == "1"){
            
            inputUser = menuLokal();
            while (inputUser!="0"){
                if (inputUser == "1"){
                    inputUser = menuKereta(KeretaTurangga);
                }else{
                    invalidInput();
                }
                inputUser = menuLokal();
            }
            cout<<endl;
            
        }else if (inputUser == "2"){
            
            inputUser = menuAntarKota();
            while (inputUser!="0"){
                if (inputUser == "1"){
                    inputUser = menuKereta(KeretaTurangga);
                    while (inputUser!="0"){
                        inputUser = menuKereta(KeretaTurangga);
                    }
                }else if (inputUser == "2"){
                    //Menu Gerbong
                }else{
                    invalidInput();
                }
                inputUser = menuAntarKota();
            }
            cout<<endl;
            
        }else{
            
            invalidInput();
            
        }
        inputUser = menu();
    }
    
    cout<< "Program Selesai. Terima Kasih."<<endl;
    
    
    return 0;
}
