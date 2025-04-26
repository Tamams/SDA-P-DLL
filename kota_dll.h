// kota_dll.h
#ifndef KOTA_DLL_H
#define KOTA_DLL_H

#include "SpNRSLL.h"

typedef struct KotaNode {
    char kt[50];
    struct KotaNode* prev;
    struct KotaNode* next;
    List namaList;  // List dari SpNRSLL.h
} KotaNode;

extern KotaNode* headKota;

// Prototipe fungsi
KotaNode* createKotaNode(char* kota);
void tambahKota(char* kota);
KotaNode* cariKota(char* kota);
void tampilkanData();
void hapusKota(char* kota);
void hapusNama(char* kota, infotype nama);
void menu();

#endif

