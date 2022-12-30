#include "mll.h"

// MARK: - Inisialisasi Kereta Bandung Raya Ekonomi
kereta bandungRayaEkonomi()
{
    /* {Fungsi melakukan inisialisasi awal sebuah kereta,
        dan mengembalikan kereta yang list penumpang dan list gerbong nya sudah terisi} */

    // Create Info
    infoKereta info = createInfoKereta("Bandung Raya Ekonomi", "Stasiun Bandung (BD)", "Stasiun Cicalengka (CCL)", "Senin, 9 Januari 2023", "05:10", "06:00", 0, false);

    // Create Kereta
    kereta kereta = createKereta(info);

    // Dummy Data Gerbong Bandung Raya Ekonomi
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 1", 80, "3-2", 5000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 2", 80, "3-2", 5000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 3", 80, "3-2", 5000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 4", 80, "3-2", 5000));
    insertLastGerbong(kereta, q);

    // Dummy Data Penumpang Bandung Raya Ekonomi
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Iman Ruslan", 18, "Laki-laki",62042630));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Iman Ruslan", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Maimunah Buana", 1, "Perempuan",26308252));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Maiuman Buana", "Ekonomi-C 2");

    p = createElmPenumpang(createInfoPenumpang("Abdullah Harta", 22, "Laki-laki",82529497));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Abdullah Harta", "Ekonomi-C 3");

    p = createElmPenumpang(createInfoPenumpang("Setiawan Nurul", 3, "Laki-laki",94977146));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Setiawan Nurul", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Ratu Mansur", 51, "Perempuan",91167146));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Ratu Mansur", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Bachtiar Vina", 5, "Laki-laki",80684594));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Bachtiar Vina", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Adi Kasih", 15, "Laki-laki",38293829));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Adi Kasih", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Hadijah Wati", 36, "Perempuan",20455630));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Hadijah Wati", "Ekonomi-C 2");

    p = createElmPenumpang(createInfoPenumpang("Rahma Nurahmadi", 13, "Perempuan",80689352));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Rahma Tirta", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Ismail Ali", 51, "Laki-laki",93529352));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Ismail Ali", "Ekonomi-C 2");

    // Return Kereta
    return kereta;
}
