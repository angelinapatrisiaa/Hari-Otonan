#include <stdio.h>
#include <stdlib.h>

struct data{
    int tanggal;
    int bulan;
    int tahun;
};

struct index{
    int wuku;
    int sapta;
    int panca;
    int tri;
};

struct data waktu1 = {5, 1, 2020};

int datecheck(struct data lahir);
int totalhari(struct data waktu);
int swapTanggal(struct data *waktu);
void perhitungan(struct index *otonan, struct data *lahir);

int main(){
    struct data lahir;
    struct index otonan;
    int ulang;
    char wuku[31][15]={"Tolu", "Gumbreg", "Wariga", "Warigadian", "Julungwangi", "Sungsang", "Dunggulan", "Kuningan", "Langkir", "Medangsia", "Pujut", "Pahang", "Klurut", "Merakih", "Tambir", "Medangkungan", "Matal", "Uye", "Menail", "Prangbakat", "Bala", "Ugu", "Wayang", "Klau", "Dukut", "Watugunung", "Sinta", "Landep", "Ukir", "Kulantir", "Tolu"};
    char saptawara[8][10] = {"Redite", "Some", "Anggara", "Buda", "Wrespati", "Sukra", "Saniscara", "Redite"};
    char pancawara[6][10] = {"Kliwon", "Umanis", "Paing", "Pon", "Wage", "Kliwon"};
    char triwara[4][10] = {"Beteng", "Kajeng", "Pasah", "Beteng"};
    do{
        system("cls");
        printf("---------------Program Menentukan Hari Otonan-----------------\n");
        do{
            printf("Masukan Tanggal Lahir Anda : ");
            scanf("%d", &lahir.tanggal);
            printf("Masukan Bulan Lahir Anda   : ");
            scanf("%d", &lahir.bulan);
            printf("Masukan Tahun Lahir Anda   : ");
            scanf("%d", &lahir.tahun);
            if(datecheck(lahir)==0){
                printf("Tanggal lahir yang Anda masukan tidak valid.\nMohon masukan ulang tanggal lahir!\n");
            }
        }while(datecheck(lahir)==0);
        perhitungan(&otonan, &lahir);
        printf("--------------------------------------------------------------\n");
        printf("                     Hari Otonan Anda\n");
        printf("Wuku       : %s\n", wuku[otonan.wuku]);
        printf("Saptawara  : %s\n", saptawara[otonan.sapta]);
        printf("Pancawara  : %s\n", pancawara[otonan.panca]);
        printf("Triwara    : %s\n", triwara[otonan.tri]);
        printf("");
        printf("--------------------------------------------------------------\n");
        printf("[1] Ulangi Program\n");
        printf("[2] Keluar Program\n");
        printf("Pilihan : ");
        scanf("%d", &ulang);
    }while(ulang==1);
    return 0;
}

int swapTanggal(struct data *waktu){
    struct data temp;
    int tukar = 0;
    if((waktu->bulan>=waktu1.bulan)&&(waktu->tahun>=waktu1.tahun) == 1){
        if(waktu->bulan==waktu1.bulan){
            if(waktu->tanggal>=waktu1.tanggal){
                tukar = 1;
                temp = waktu1;
                waktu1 = *waktu;
                *waktu = temp;
            }
        }else{
                temp = waktu1;
                waktu1 = *waktu;
                *waktu = temp;
                tukar = 1;
        }

    }

    return tukar;
}

int totalhari(struct data waktu){
    int day = 0, tahun;
    //swapTanggal(&waktu);
    int bulan[12][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    while(((waktu.tanggal==waktu1.tanggal)&&(waktu.bulan==waktu1.bulan)&&(waktu.tahun==waktu1.tahun)) == 0){
        if((waktu.tahun%400 == 0) || (waktu.tahun%4==0&&waktu.tahun%100!=0)){
            tahun = 1;
        }else{
            tahun = 0;
        }
        day++;
        waktu.tanggal++;
        if(waktu.tanggal>bulan[waktu.bulan-1][tahun]){
            waktu.tanggal = 1;
            waktu.bulan++;
        }
        if(waktu.bulan>12){
                waktu.bulan = 1;
                waktu.tahun++;
        }
    }
    return day;
}

int datecheck(struct data lahir){
    int tahun = lahir.tahun;
    int bulan[12][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    if (lahir.tahun%400==0||lahir.tahun%100!=0&&lahir.tahun%4==0){
        lahir.tahun = 1;
    }else{
        lahir.tahun = 0;
    }
    return ((lahir.tanggal <= bulan[lahir.bulan-1][lahir.tahun])&&(lahir.tanggal>0)&&(lahir.bulan>0&&lahir.bulan<=12)&&tahun>0); 
}

void perhitungan(struct index *otonan, struct data *lahir){
    int tukar = swapTanggal(lahir);
    int selisih = totalhari(*lahir);
    if(tukar==0){
        otonan->wuku = 29 - (selisih/7)%30;
        otonan->sapta = 7 - selisih%7;
        otonan->panca = 5 - selisih%5;
        otonan->tri = 3 - selisih%3;
    }else{
        otonan->wuku = (selisih/7)%30;
        otonan->sapta = selisih%7;
        otonan->panca = selisih%5;
        otonan->tri = selisih%3;
    }
}