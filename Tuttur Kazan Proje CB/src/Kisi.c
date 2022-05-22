#include "../include/Kisi.h"


Kisi* new_kisi(char* isim,double bakiye,double oynananOran,int tahminSayi){
    Kisi* thise;
    thise=(Kisi*)malloc(sizeof(Kisi));
    thise->oyunHakki=1;
    thise->next=NULL;
    thise->pre=NULL;
    thise->isim=isim;
    thise->bakiye=bakiye;
    thise->oynananOran=oynananOran;
    thise->tahminSayi=tahminSayi;
    thise->deleteKisi=&deleteKisi;

    return thise;
}

void deleteKisi(const Kisi* thise){
    if(thise==NULL) return;
    free(thise);
}
