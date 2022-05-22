#include "../include/Oyun.h"
#define xKoordinati 35
#define xKoordinati2 81

void Oyuna_basla(Kisi* KisiListRoot,int* Sayilar, int size_sayilar)
{

    Oyun* theseOyun;
    theseOyun=(Oyun*)malloc(sizeof(Oyun));
    theseOyun->masaBakiyesi=0.0;
    theseOyun->sansliSayi=-1;
    theseOyun->Sayilar=Sayilar;
    theseOyun->tur=-1;
    theseOyun->enZenginKisi=KisiListRoot;
    theseOyun->KisiListRoot=KisiListRoot;
    Kisi* IteratorKisiler;

    for(int i=0; i<size_sayilar; i++)
    {
        theseOyun->tur=i+1;
        theseOyun->Sayilar=Sayilar;
        theseOyun->sansliSayi=Sayilar[i];
        IteratorKisiler=KisiListRoot;
        while(IteratorKisiler != NULL)
        {
            if(IteratorKisiler->oyunHakki <= 0)
            {
                IteratorKisiler=IteratorKisiler->next;
                continue;
            }
            if(IteratorKisiler->bakiye < 1000)
            {
                IteratorKisiler->oyunHakki--;
                IteratorKisiler=IteratorKisiler->next;
                continue;
            }

            double tempYatirilanMebla=IteratorKisiler->bakiye*IteratorKisiler->oynananOran;
            IteratorKisiler->bakiye-=tempYatirilanMebla;
            theseOyun->masaBakiyesi+=tempYatirilanMebla;
            if(IteratorKisiler->tahminSayi == theseOyun->sansliSayi)
            {
                IteratorKisiler->bakiye+= tempYatirilanMebla * 10;
                theseOyun->masaBakiyesi-=tempYatirilanMebla *10;
            }
            if(IteratorKisiler->bakiye > theseOyun->enZenginKisi->bakiye)
            {
                theseOyun->enZenginKisi=IteratorKisiler;
            }

            gotoXY(xKoordinati,6);
            printf("################################################");
            gotoXY(xKoordinati,7);
            printf("##              SANSLI SAYI: %d               ",theseOyun->sansliSayi);
            gotoXY(xKoordinati2,7);
            printf("##");
            gotoXY(xKoordinati,8);
            printf("################################################");
            gotoXY(xKoordinati,9);
            printf("################################################");
            gotoXY(xKoordinati,10);
            printf("##              TUR: %d                       ",theseOyun->tur);
            gotoXY(xKoordinati2,10);
            printf("##");
            gotoXY(xKoordinati,11);
            printf("##              MASA BAKIYE: %.2lf            ",theseOyun->masaBakiyesi);
            gotoXY(xKoordinati2,11);
            printf("##");
            gotoXY(xKoordinati,12);
            printf("##--------------------------------------------##");
            gotoXY(xKoordinati,13);
            printf("##              EN ZENGIN KISI                ##");
            gotoXY(xKoordinati,14);
            printf("##              %s                            ",theseOyun->enZenginKisi->isim);
            gotoXY(xKoordinati2,14);
            printf("##");
            gotoXY(xKoordinati,15);
            printf("##      BAKIYESI: %.2lf                       ",theseOyun->enZenginKisi->bakiye);
            gotoXY(xKoordinati2,15);
            printf("##");
            gotoXY(xKoordinati,16);
            printf("##                                            ##");
            gotoXY(xKoordinati,17);
            printf("################################################");
            IteratorKisiler=IteratorKisiler->next;
        }

    }

    gotoXY(0,25);
}
void gotoXY(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

