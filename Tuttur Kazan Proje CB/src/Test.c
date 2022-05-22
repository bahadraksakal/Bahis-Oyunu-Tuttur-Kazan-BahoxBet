#include "../include/Test.h"

int main()
{

    system("cls"); // linuxta hata verebilir.
    char path[]="./src/Kisiler.txt";
    Kisi* kislerList=KisilerJoin(path);

    char path2[]="./src/Sayilar.txt";
    int sayilar_size;
    int* sayilar= sayilarGet(path2,&sayilar_size);

    Oyuna_basla(kislerList,sayilar,sayilar_size);
    char DontStop[3];
    scanf("%c",DontStop);
    return 0;
}

Kisi* KisilerJoin(char* PathFileKisiler)
{

    dosya* fileKisiler = new_dosya(PathFileKisiler);
    char* strDosyaKisiler= fileKisiler->strDosya;
    int flag=0;
    int flag2=0;
    int position=0;
    char tempName[141];
    char *name;
    char tempBakiye[16];
    char* ptr_end;
    char tempOynananOran[14];
    char tempTahminSayi[3];
    Kisi* KisiNode=NULL;
    Kisi* KisiRoot=NULL;
    Kisi* KisiBagla=NULL;
    for(int i=0, strCtrl=0 ; strDosyaKisiler[i]!='\0' ; i++)
    {

        if(position==0)
        {

            if(strDosyaKisiler[i]=='#')
            {
                tempName[strCtrl]='\0';
                name=(char*)malloc(sizeof(char)*(strCtrl+1));
                name=strcpy(name,tempName);

                position=1;
                strCtrl=0;
                continue;
            }
            tempName[strCtrl]= strDosyaKisiler[i];
            strCtrl++;
        }
        else if(position==1)
        {
            if(strDosyaKisiler[i]=='#')
            {
                tempBakiye[strCtrl]='\0';
                position=2;
                strCtrl=0;
                continue;
            }
            tempBakiye[strCtrl]= strDosyaKisiler[i];
            strCtrl++;
        }
        else if(position==2)
        {

            if(strDosyaKisiler[i]=='#')
            {
                tempOynananOran[strCtrl]='\0';
                position=3;
                strCtrl=0;
                continue;
            }
            tempOynananOran[strCtrl]=strDosyaKisiler[i];
            strCtrl++;
        }
        else if(position==3)
        {
            if(strDosyaKisiler[i]=='#' || strDosyaKisiler[i]=='\n')
            {
                tempTahminSayi[strCtrl]='\0';
                position=4;
                strCtrl=0;
                i--;
                continue;
            }
            tempTahminSayi[strCtrl]= strDosyaKisiler[i];
            strCtrl++;
        }
        else
        {
            position=0;
            if(flag==1)
            {

                KisiNode=new_kisi(name,strtod(tempBakiye,&ptr_end),strtod(tempOynananOran,&ptr_end),atoi(tempTahminSayi));
                if(flag2==0)
                {
                    KisiBagla=KisiNode;
                    KisiRoot->next=KisiNode;
                    KisiNode->pre=KisiRoot;
                    flag2=1;
                }
                else
                {
                    KisiBagla->next=KisiNode;
                    KisiBagla->next->pre= KisiBagla;
                    KisiBagla=KisiNode;

                }


            }
            else
            {
                KisiRoot = new_kisi(name,strtod(tempBakiye,&ptr_end),strtod(tempOynananOran,&ptr_end),atoi(tempTahminSayi));
                KisiRoot->next=NULL;
                KisiRoot->pre=NULL;
                flag=1;
            }
        }


    }
    return KisiRoot;

    return KisiRoot;
}

int* sayilarGet(char* PathFileSayilar,int* sayilar_size)
{
    dosya* fileSayilar = new_dosya(PathFileSayilar);
    char* strDosyaKisiler= fileSayilar->strDosya;
    int satirSayisi=0;

    for(int i=0 ; strDosyaKisiler[i]!='\0' ; i++)
    {
        if(strDosyaKisiler[i]=='\n')
        {
            satirSayisi++;
        }
    }

    int* Sayilar=(int*)malloc(sizeof(int)*satirSayisi);
    *(sayilar_size) = satirSayisi;
    int flag=0,strCtrl=0;
    char StrSayilar[3];
    for(int i=0, strCtrl=0, j=0; strDosyaKisiler[i]!='\0' ; i++)
    {

        if(strDosyaKisiler[i]=='\n')
        {
            StrSayilar[strCtrl]='\0';
            Sayilar[j]=atoi(StrSayilar);
            j++;
            strCtrl=0;
            continue;
        }
        StrSayilar[strCtrl]= strDosyaKisiler[i];
        strCtrl++;
    }

    return Sayilar;
}


