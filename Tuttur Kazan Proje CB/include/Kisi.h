#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct KISI
{
    struct KISI* next;
    struct KISI* pre;
    int oyunHakki;
    char* isim;
    double bakiye;
    double oynananOran; //  bakiye* oran kadar para masaya konur.
    int tahminSayi;

    void* (*deleteKisi)(struct KISI*);

}Kisi;

Kisi* new_kisi(char*,double,double,int);
void deleteKisi(const Kisi*);

#endif
