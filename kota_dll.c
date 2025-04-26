// kota_dll.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota_dll.h"

KotaNode* headKota = NULL;

KotaNode* createKotaNode(char* kota) {
    KotaNode* newNode = (KotaNode*) malloc(sizeof(KotaNode));
    strcpy(newNode->kt, kota);
    newNode->prev = NULL;
    newNode->next = NULL;
    CreateList(&newNode->namaList);
    return newNode;
}

void tambahKota(char* kota) {
    KotaNode* newKota = createKotaNode(kota);
    if (headKota == NULL) {
        headKota = newKota;
    } else {
        KotaNode* temp = headKota;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newKota;
        newKota->prev = temp;
    }
}

KotaNode* cariKota(char* kota) {
    KotaNode* temp = headKota;
    while (temp != NULL) {
        if (strcmp(temp->kt, kota) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void tampilkanData() {
    KotaNode* kota = headKota;
    while (kota != NULL) {
        printf("\nKota: %s\n", kota->kt);
        if (ListEmpty(kota->namaList)) {
            printf("  (tidak ada nama)\n");
        } else {
            PrintInfo(kota->namaList);
        }
        kota = kota->next;
    }
}

void hapusKota(char* kota) {
    KotaNode* target = cariKota(kota);
    if (target == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    DelAll(&target->namaList);

    if (target->prev != NULL)
        target->prev->next = target->next;
    else
        headKota = target->next;

    if (target->next != NULL)
        target->next->prev = target->prev;

    free(target);
    printf("Kota dan semua nama telah dihapus.\n");
}

void hapusNama(char* kota, infotype nama) {
    KotaNode* k = cariKota(kota);
    if (k == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }
    DelP(&k->namaList, nama);
}

