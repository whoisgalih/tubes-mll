#include "mll.h"

// MARK: - Inisialisai kereta Turangga
kereta turangga(){
    /* {Fungsi melakukan inisialisasi awal sebuah kereta, dan mengembalikan kereta yang list penumpang dan list gerbong nya sudah terisi} */

    // Create Info
    infoKereta info = createInfoKereta("Turangga", "Stasiun Bandung (BD)", "Stasiun Yogyakarta (YK)", "Senin, 9 Januari 2023", "18:40", "00:55",0,true);

    // Create Kereta
    kereta kereta = createKereta(info);

    // Dummy Data Gerbong Turangga
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Eksekutif AA", 50, "2-2", 540000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif A", 50, "2-2", 510000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif H", 50, "2-2", 480000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif I", 50, "2-2", 460000));
    insertLastGerbong(kereta, q);

    // Dummy Data Penumpang Turangga
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Muhammad Abiya", 20, "Laki-laki",61606160));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Muhammad Abiya", NULL, "Eksekutif AA");

    p = createElmPenumpang(createInfoPenumpang("Galih Akbar", 18, "Laki-laki",49862647));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Galih Akbar", NULL, "Eksekutif A");

    p = createElmPenumpang(createInfoPenumpang("Gading Makruf", 17, "Laki-laki",72918655));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Gading Makruf", NULL, "Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Nada Raudah", 19, "Perempuan",62043766));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Nada Raudah", NULL, "Eksekutif I");

    p = createElmPenumpang(createInfoPenumpang("Dian Irdianingsih", 45, "Perempuan",48717291));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Dian Irdianingsih", NULL, "Eksekutif A");

    p = createElmPenumpang(createInfoPenumpang("Azumah Yasmin", 19, "Perempuang",48605082));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Azumah Yasmin", NULL, "Eksekutif AA");

    p = createElmPenumpang(createInfoPenumpang("Falah Asyraf", 19, "Laki-laki",26308655));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Falah Asyraf", NULL, "Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Fajar Dwi", 5, "Laki-laki",57533829));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Fajar Dwi", NULL, "Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Makruf Amal", 55, "Laki-laki",33413341));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Makruf Amal", NULL, "Eksekutif I");

    p = createElmPenumpang(createInfoPenumpang("Itoh Masitoh", 72, "Perempuan",56305630));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta,"Itoh Masitoh", NULL, "Eksekutif AA");

    // Return Kereta
    return kereta;
}
