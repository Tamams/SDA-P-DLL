/* BodyNRSL.c - Versi diperbarui untuk mendukung string sebagai infotype */

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "spnrsll.h"

boolean ListEmpty (List L) {
     return (First(L) == Nil);
}

void CreateList (List * L) {
     First(*L) = Nil;
}

address Alokasi (infotype X) {
     address P = (address) malloc(sizeof(ElmtList));
     if (P != Nil) {
          strcpy(Info(P), X);
          Next(P) = Nil;
     }
     return P;
}

void DeAlokasi (address P) {
     if (P != Nil) free(P);
}

address Search (List L, infotype X) {
     address P = First(L);
     while (P != Nil) {
          if (strcmp(Info(P), X) == 0)
               return P;
          P = Next(P);
     }
     return Nil;
}

boolean FSearch (List L, address P) {
     address PSearch = First(L);
     while (PSearch != Nil) {
          if (PSearch == P)
               return true;
          PSearch = Next(PSearch);
     }
     return false;
}

address SearchPrec (List L, infotype X) {
     address Prec = Nil;
     address P = First(L);
     while (P != Nil && strcmp(Info(P), X) != 0) {
          Prec = P;
          P = Next(P);
     }
     if (P != Nil)
          return Prec;
     else
          return Nil;
}

void InsVFirst (List * L, infotype X) {
     address P = Alokasi(X);
     if (P != Nil) InsertFirst(L, P);
}

void InsVLast (List * L, infotype X) {
     address P = Alokasi(X);
     if (P != Nil) InsertLast(L, P);
}

void DelVFirst (List * L, infotype * X) {
     address P;
     DelFirst(L, &P);
     strcpy(*X, Info(P));
     DeAlokasi(P);
}

void DelVLast (List * L, infotype * X) {
     address P;
     DelLast(L, &P);
     if (P != Nil) {
          strcpy(*X, Info(P));
          DeAlokasi(P);
     }
}

void InsertFirst (List * L, address P) {
     Next(P) = First(*L);
     First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec) {
     Next(P) = Next(Prec);
     Next(Prec) = P;
}

void InsertLast (List * L, address P) {
     if (ListEmpty(*L)) {
          InsertFirst(L, P);
     } else {
          address Last = First(*L);
          while (Next(Last) != Nil)
               Last = Next(Last);
          InsertAfter(L, P, Last);
     }
}

void DelFirst (List * L, address * P) {
     *P = First(*L);
     First(*L) = Next(First(*L));
     Next(*P) = Nil;
}

void DelP (List * L, infotype X) {
     address P = First(*L), Prec = Nil;
     while (P != Nil && strcmp(Info(P), X) != 0) {
          Prec = P;
          P = Next(P);
     }
     if (P != Nil) {
          if (Prec == Nil) {
               DelFirst(L, &P);
          } else {
               DelAfter(L, &P, Prec);
          }
          DeAlokasi(P);
     }
}

void DelLast (List * L, address * P) {
     address Prec = Nil;
     *P = First(*L);
     while (Next(*P) != Nil) {
          Prec = *P;
          *P = Next(*P);
     }
     if (Prec == Nil)
          First(*L) = Nil;
     else
          Next(Prec) = Nil;
}

void DelAfter (List * L, address * Pdel, address Prec) {
     *Pdel = Next(Prec);
     Next(Prec) = Next(*Pdel);
     Next(*Pdel) = Nil;
}

void PrintInfo (List L) {
     if (ListEmpty(L)) {
          printf("List Kosong\n");
     } else {
          address P = First(L);
          while (P != Nil) {
               printf("%s ", Info(P));
               P = Next(P);
          }
          printf("\n");
     }
}

void DelAll (List * L) {
     address PDel;
     while (!ListEmpty(*L)) {
          DelFirst(L, &PDel);
          DeAlokasi(PDel);
     }
}

