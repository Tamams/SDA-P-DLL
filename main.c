#include <stdio.h>
#include <string.h>
#include "kota_dll.h"

void menu() {
    int pilihan;
    char kota[50];
    infotype nama;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Hapus Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // buang newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(kota, sizeof(kota), stdin);
                kota[strcspn(kota, "\n")] = 0;
                tambahKota(kota);
                break;
            case 2:
                printf("Masukkan nama kota: ");
                fgets(kota, sizeof(kota), stdin);
                kota[strcspn(kota, "\n")] = 0;
                printf("Masukkan nama: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                {
                    KotaNode* k = cariKota(kota);
                    if (k != NULL) {
                        InsVLast(&k->namaList, nama);
                    } else {
                        printf("Kota tidak ditemukan.\n");
                    }
                }
                break;
            case 3:
                printf("Masukkan nama kota: ");
                fgets(kota, sizeof(kota), stdin);
                kota[strcspn(kota, "\n")] = 0;
                hapusKota(kota);
                break;
            case 4:
                printf("Masukkan nama kota: ");
                fgets(kota, sizeof(kota), stdin);
                kota[strcspn(kota, "\n")] = 0;
                printf("Masukkan nama yang ingin dihapus: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                hapusNama(kota, nama);
                break;
            case 5:
                tampilkanData();
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}
