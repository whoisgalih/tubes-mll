#include "mll.h"

int main()
{
    // INISIALISASI KERETA ANTAR KOTA TURANGGA
    kereta KeretaTurangga;
    KeretaTurangga = turangga();
    showPenumpang(KeretaTurangga);
    showGerbong(KeretaTurangga);
    showPenumpangByGerbong(KeretaTurangga, "Eksekutif AA");
    showKereta(KeretaTurangga);

//    // INISIALISASI KERETA ANTAR KOTA ARGO PARAHYANGAN
//    kereta KeretaTurangga;
//    KeretaTurangga = turangga();
//
//    // INISIALISASI KERETA LOKAL BANDUNG RAYA EKONOMI
//    kereta KeretaTurangga;
//    KeretaTurangga = turangga();


    // ALGORITMA MENU



    return 0;
}
