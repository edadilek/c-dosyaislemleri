#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Kullanici {
    long long int ogrno;
    char ad[20];
    char soyad[20];
    long long int telefon;
    char mail[20];
};

static int sayac;

void menu();
void kullaniciEkle(struct Kullanici*);
void kullaniciBul(struct Kullanici*);
void kullaniciSirala(struct Kullanici*);
void teleGore(struct Kullanici kullanici[]);
void ogrnoGore(struct Kullanici kullanici[]);
void mailGore(struct Kullanici kullanici[]);
int karsilastirma(char a[], char b[]);
void isimSirala(struct Kullanici kullanici[]);
void ogrnoSirala(struct Kullanici kullanici[]);
void dosyayaKaydet(struct Kullanici* kullanici, int adet);


int main() {
    struct Kullanici kullanici[99];
    menu(kullanici);
}

void menu(struct Kullanici* kullanici) {
    int secim;

    while (1) {
        printf("1->Kullanici ekle\n");
        printf("2->Kullanici bul\n");
        printf("3->Kullanici sirala\n");
        printf("4->Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            kullaniciEkle(kullanici);
            break;

        case 2:
            kullaniciBul(kullanici);
            break;

        case 3:
            kullaniciSirala(kullanici);
            break;

        case 4:
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Gecersiz secim!\n\n");
        }
    }

}

void kullaniciEkle(struct Kullanici* kullanici) {

    int i, giris;
    sayac = 0;
    for (i = 0; i < 99; i++) {

        printf("Kullanici ogrenci no giriniz:\n");
        scanf("%lld", &kullanici[i].ogrno);
        printf("Kullanici adini giriniz:\n");
        scanf("%s", kullanici[i].ad);
        printf("Kullanici soyadini giriniz:\n");
        scanf("%s", kullanici[i].soyad);
        printf("Kullanici telefon no giriniz:\n");
        scanf("%lld", &(kullanici[i].telefon));
        printf("Kullanici mailini giriniz:\n");
        scanf("%s", kullanici[i].mail);


        dosyayaKaydet(kullanici, sayac + 1);

        printf("Cikis icin -> 4\n");
        printf("Kullanici eklemeye devam etmek icin -> 1\n");
        scanf("%d", &giris);
        if (giris == 4) {
            break;
        }
        sayac++;

        
    }
}

void kullaniciBul(struct Kullanici* kullanici) {
    int secim;

    printf("1->Telefon numarasina gore bul\n");
    printf("2->Ogrenci numarasina gore bul\n");
    printf("3->Mail adresine gore bul\n");
    printf("4->Bir ust menuye don\n");
    printf("Seciminizi yapiniz: ");
    scanf("%d", &secim);

    
        switch (secim) {
        case 1:
            teleGore(kullanici);
            break;

        case 2:
            ogrnoGore(kullanici);
            break;

        case 3:
            mailGore(kullanici);
            break;

        case 4:
            return;

        default:
            printf("Gecersiz secim!\n\n");
        }
 
}

void kullaniciSirala(struct Kullanici* kullanici) {
    int secim;
    printf("1->Isme gore\n");
    printf("2->Ogrenci numarasina gore\n");
    printf("3->Bir ust menuye don\n");
    printf("Seciminizi yapiniz: ");
    scanf("%d", &secim);

    
        switch (secim) {
        case 1:
            isimSirala(kullanici);
            break;

        case 2:
            ogrnoSirala(kullanici);
            break;

        case 3:
            return;

        default:
            printf("Gecersiz secim!\n\n");

        }
    

}

void teleGore(struct Kullanici* kullanici) {
    int i;
    long long int tel;
    printf("Bulunacak kullanicinin telefonunu giriniz: ");
    scanf("%lld", &tel);
    for (i = 0; i < sayac+1; i++) {
        if (tel == kullanici[i].telefon) {
            printf("%20lld\t%20s\t%20s\t%20lld\t%20s\t\n", kullanici[i].ogrno, kullanici[i].ad, kullanici[i].soyad, kullanici[i].telefon, kullanici[i].mail);
            
        }
      
    }


}

void ogrnoGore(struct Kullanici* kullanici) {
    int i;
    long long int ogrencino;
    printf("Bulunacak kullanicinin ogrenci numarasini giriniz: ");
    scanf("%lld", &ogrencino);
    for (i = 0; i < sayac+1; i++) {
        if (ogrencino == kullanici[i].ogrno) {
            printf("%20lld\t%20s\t%20s\t%20lld\t%20s\t\n", kullanici[i].ogrno, kullanici[i].ad, kullanici[i].soyad, kullanici[i].telefon, kullanici[i].mail);
            return;
        }
      
    }

}

void mailGore(struct Kullanici* kullanici) {
    int i;
    char eposta[20];
    printf("Bulunacak kullanicinin mailini giriniz: ");
    scanf("%s", eposta);

    for (i = 0; i < sayac; i++) {
        if (karsilastirma(kullanici[i].mail, eposta) == 1)
        {
            printf("%20lld\t%20s\t%20s\t%20lld\t%20s\t\n", kullanici[i].ogrno, kullanici[i].ad, kullanici[i].soyad, kullanici[i].telefon, kullanici[i].mail);
            return;
        }
    }


}
int karsilastirma(char a[], char b[]) {
    int i, result = 1;
    for (i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            result = 0;
            break;
        }
    }
    return result;
}


void isimSirala(struct Kullanici* kullanici) {

      char gecici[99];
   int i, j, k;
   for (i = 1; i < sayac+1; i++) {
       for (j = 1; j < sayac+1; j++) {
           if (strcmp(kullanici[j - 1].ad, kullanici[j].ad) > 0) {
               strcpy(gecici, kullanici[j - 1].ad);
               strcpy(kullanici[j - 1].ad, kullanici[j].ad);
               strcpy(kullanici[j].ad, gecici);
           }
       }
   }

    for (k = 0; k < sayac + 1; k++) {
        printf("%20lld\t%20s\t%20s\t%20lld\t%20s\t\n", kullanici[k].ogrno, kullanici[k].ad, kullanici[k].soyad, kullanici[k].telefon, kullanici[k].mail);
    }

}


void ogrnoSirala(struct Kullanici* kullanici) {

    struct Kullanici temp;
    int i, j, k;
    
    for (i = 0; i < sayac; i++)
    {
        for (j = 0; j < (sayac - i); j++)
        {
            if (kullanici[j].ogrno < kullanici[j + 1].ogrno)
            {
                temp = kullanici[j];
                kullanici[j] = kullanici[j + 1];
                kullanici[j + 1] = temp;
            }
        }
    }



    for (k = 0; k < sayac + 1; k++) {
        printf("%20lld\t%20s\t%20s\t%20lld\t%20s\t\n", kullanici[k].ogrno,kullanici[k].ad, kullanici[k].soyad, kullanici[k].telefon, kullanici[k].mail); 
    }


}

void dosyayaKaydet(struct Kullanici* kullanici, int adet) {

    FILE* dosya;
    if ((dosya = fopen("dosya.txt", "w+")) == NULL)
        printf("Dosya bulunamadi\n");
    char a[11] = "Ogrenci No";
    char b[3] = "Ad";
    char c[6] = "Soyad";
    char d[8] = "Telefon";
    char e[5] = "Mail";
    fprintf(dosya, "%20s", a);
    fprintf(dosya, "%20s", b);
    fprintf(dosya, "%20s", c);
    fprintf(dosya, "%20s", d);
    fprintf(dosya, "%30s\n", e);

    int i;
    for (i = 0; i < adet; i++) {

        fprintf(dosya, "%20lld", kullanici[i].ogrno);
        fprintf(dosya, "%20s", kullanici[i].ad);
        fprintf(dosya, "%20s", kullanici[i].soyad);
        fprintf(dosya, "%20lld", kullanici[i].telefon);
        fprintf(dosya, "%30s\n", kullanici[i].mail);


    }

    fclose(dosya);
}
