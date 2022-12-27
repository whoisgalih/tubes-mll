#include "mll.h"

// MARK: - Init kereta Bandung Raya Ekonomi
kereta bandungRayaEkonomi()
{
    /* {Fungsi melakukan inisialisasi awal sebuah kereta, dan mengembalikan kereta1 yang list penumpang dan list gerbong nya sudah terisi} */

    // CREATE INFO
    infoKereta info = createInfoKereta("Bandung Raya Ekonomi", "Stasiun Bandung (BD)", "Stasiun Cicalengka (CCL)", "Senin, 9 Januari 2023", "05:10", "06:00", 0, false);

    // CREATE KERETA
    kereta kereta1 = createKereta(info);

    // Dummy Gerbong Bandung Raya Ekonomi
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 1", 80, "3-2", 5000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 2", 80, "3-2", 5000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 3", 80, "3-2", 5000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-C 4", 80, "3-2", 5000));
    insertLastGerbong(kereta1, q);

    // Dummy Penumpang Bandung Raya Ekonomi
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Iman Ruslan", 18, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Iman Ruslan", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Maimunah Buana", 1, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Maiuman Buana", "Ekonomi-C 2");

    p = createElmPenumpang(createInfoPenumpang("Abdullah Harta", 22, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Abdullah Harta", "Ekonomi-C 3");

    p = createElmPenumpang(createInfoPenumpang("Setiawan Nurul", 3, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Setiawan Nurul", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Ratu Mansur", 51, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Ratu Mansur", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Bachtiar Vina", 5, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Bachtiar Vina", "Ekonomi-C 4");

    p = createElmPenumpang(createInfoPenumpang("Adi Kasih", 15, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Adi Kasih", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Hadijah Wati", 36, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Hadijah Wati", "Ekonomi-C 2");

    p = createElmPenumpang(createInfoPenumpang("Rahma Nurahmadi", 13, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Rahma Tirta", "Ekonomi-C 1");

    p = createElmPenumpang(createInfoPenumpang("Ismail Ali", 51, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1, "Ismail Ali", "Ekonomi-C 2");

    return kereta1;
}
