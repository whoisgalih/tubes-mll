#include "mll.h"

int main()
{
    //  MARK: - Inisialisasi Kereta
    //  Inisialisasi Kereta Antar Kota: Turangga
    kereta KeretaTurangga;
    KeretaTurangga = turangga();

    // Inisialisasi Kereta Antar Kota: Argo Parahyangan
    kereta KeretaArgoParahyangan;
    KeretaArgoParahyangan = argoParahyangan();

    //Inisialisasi Kereta Lokal: Bandung Raya Ekonomi
    kereta KeretaBandungRayaEkonomi;
    KeretaBandungRayaEkonomi = bandungRayaEkonomi();


    // MARK: - Identitas
    clearScreen();
    cout <<
    "\n"
    "       ~~~~ ____   |~~~~~~~~~~~~~~~~~|   |~~~~~~~~~~~~~~~~~|\n"
    "      Y_,___|[]|   |                 |   | GABI TANPA ZAL! |\n"
    "     {|_|_|_|PU|_,_|_________________|_,_|_________________|\n"
    "     //oo---OO=OO     OOO     OOO           OOO     OOO\n"
    " ****************************************************************\n\n";

    cout << "========== TUGAS BESAR =========="<<endl;
    cout << "Kelompok \t: Gabi Tanpa Zal"<<endl;
    cout << "Tema \t\t: Multi Linked-List A"<<endl;
    cout << "Judul \t\t: Kereta"<<endl;
    cout << "Anggota \t: 1. Galih Akbar Nugraha   - 1301213060"<<endl;
    cout << "\t\t  2. Muhammad Abiya Makruf - 1301213157"<<endl<<endl;

    // MARK: - Menu
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
                    inputUser = menuKereta(KeretaBandungRayaEkonomi);
                    while (inputUser!="0"){
                        inputUser = menuKereta(KeretaBandungRayaEkonomi);
                    }
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
                    inputUser = menuKereta(KeretaArgoParahyangan);
                    while (inputUser!="0"){
                        inputUser = menuKereta(KeretaArgoParahyangan);
                    }
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
