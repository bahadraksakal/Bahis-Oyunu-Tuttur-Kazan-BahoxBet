#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct DOSYA{
    char* adres;
    int boyut;
    char* strDosya;
    char* (*getAdres)(struct DOSYA*);
    int (*getBoyut)(struct DOSYA*);
    char* (*getStrDosya)(struct DOSYA*);

}dosya;


dosya* new_dosya(char*);
char* getAdres(const dosya* these);
int getBoyut(const dosya* these);
char* getStrDosya(const dosya* these);// sahllow copy



#endif



