#include "mll.h"

int main()
{
    // INISIALISASI KERETA ANTAR KOTA TURANGGA
    kereta KeretaTurangga;
    KeretaTurangga = turangga();

//    // INISIALISASI KERETA ANTAR KOTA ARGO PARAHYANGAN
//    kereta KeretaTurangga;
//    KeretaTurangga = turangga();
//
//    // INISIALISASI KERETA LOKAL BANDUNG RAYA EKONOMI
//    kereta KeretaTurangga;
//    KeretaTurangga = turangga();

    
    //IDENTITAS
    cout << "========== TUGAS BESAR =========="<<endl;
    cout << "Kelompok : Gabi Tanpa Zal"<<endl;
    cout << "Tema : "<<endl;
    cout << "Anggota : "<<endl<<endl;
    

    // ALGORITMA MENU
    int inputUser;

    inputUser = menu();
    while (inputUser !=0){
        if (inputUser == 1){
            
            inputUser = menuLokal();
            while (inputUser!=0){
                if (inputUser == 1){
                    inputUser = menuKereta(KeretaTurangga);
                }else{
                    cout << "Maaf input tidak valid."<<endl;
                }
                inputUser = menuLokal();
            }
            cout<<endl;
            
        }else if (inputUser == 2){
            
            inputUser = menuAntarKota();
            while (inputUser!=0){
                if (inputUser == 1){
                    inputUser = menuKereta(KeretaTurangga);
                    while (inputUser!=0){
                        inputUser = menuKereta(KeretaTurangga);
                    }
                }else if (inputUser == 2){
                    //Menu Gerbong
                }else{
                    cout << "Maaf input tidak valid."<<endl;
                }
                inputUser = menuAntarKota();
            }
            cout<<endl;
            
        }else{
            
            cout << "Maaf input tidak valid."<<endl<<endl;
            
        }
        inputUser = menu();
    }

    cout<< "Program Selesai. Terima Kasih.";


    return 0;
}
