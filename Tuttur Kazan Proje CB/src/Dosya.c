#include "../include/Dosya.h"



dosya* new_dosya(char* adres)
{
    dosya* these;
    these=(dosya*)malloc(sizeof(struct DOSYA));
    these->adres=adres;
    FILE *file=fopen(adres,"r");

    if(file==NULL){
        printf("dosya acilamadi , hata \n");
        return;
    }

    else
    {
        int boyut_sayaci=0;
        while(!feof(file))
        {
            fgetc(file);
            boyut_sayaci++;
        }
        these->boyut=boyut_sayaci;
        these->strDosya=(char*)malloc(sizeof(char)*(boyut_sayaci+1));
        rewind(file);
        int i;
        for(i=0; !feof(file); i++)
        {
            (these->strDosya)[i]=fgetc(file);
        }
        (these->strDosya)[i]='\n';
        rewind(file);
        fclose(file);
    }
    return these;

};
char* getAdres(const dosya* these)
{
    return these->adres;
};
int getBoyut(const dosya* these)
{
    return these->boyut;
};
char* getStrDosya(const dosya* these)
{
    return these->strDosya;
};



