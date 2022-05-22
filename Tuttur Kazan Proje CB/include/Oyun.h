#ifndef OYUN_H
#define OYUN_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "windows.h"
#include "Kisi.h"
#include "Dosya.h"

typedef struct OYUN
{
    int tur;
    int sansliSayi;
    double masaBakiyesi;
    int* Sayilar;
    Kisi* KisiListRoot;
    Kisi* enZenginKisi;

}Oyun;

void Oyuna_basla(Kisi*,int*,int);
void gotoXY(int,int);

#endif
