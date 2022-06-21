#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int datecheck(struct data lahir, struct data today);
int totalhari(struct data waktu, int tukar, struct data waktu1);
int swapTanggal(struct data waktu, struct data waktu1);
void perhitungan(struct index *otonan, struct data lahir, struct data waktu1);
void current_time(struct data *today);

int main(){
    struct data lahir, today, waktu1;
    struct index otonan;
    int ulang, tukar;
    char wuku[31][15]={"Tolu", "Gumbreg", "Wariga", "Warigadian", "Julungwangi", "Sungsang", "Dunggulan", "Kuningan", "Langkir", "Medangsia", "Pujut", "Pahang", "Klurut", "Merakih", "Tambir", "Medangkungan", "Matal", "Uye", "Menail", "Prangbakat", "Bala", "Ugu", "Wayang", "Klau", "Dukut", "Watugunung", "Sinta", "Landep", "Ukir", "Kulantir", "Tolu"};
    char saptawara[8][10] = {"Redite", "Some", "Anggara", "Buda", "Wrespati", "Sukra", "Saniscara", "Redite"};
    char pancawara[6][10] = {"Kliwon", "Umanis", "Paing", "Pon", "Wage", "Kliwon"};
    char triwara[4][10] = {"Beteng", "Kajeng", "Pasah", "Beteng"};
    current_time(&today);
    do{
        waktu1.tanggal = 5;
        waktu1.bulan = 1;
        waktu1.tahun = 2020;
        system("cls");
        printf("               Program Menentukan Hari Otonan\n");
        printf("--------------------------------------------------------------\n");
        printf("                                                    %d-%d-%d\n", today.tanggal, today.bulan, today.tahun);
        printf("--------------------------------------------------------------\n");
        do{
            printf("Masukan Tanggal Lahir Anda : ");
            scanf("%d", &lahir.tanggal);
            printf("Masukan Bulan Lahir Anda   : ");
            scanf("%d", &lahir.bulan);
            printf("Masukan Tahun Lahir Anda   : ");
            scanf("%d", &lahir.tahun);
            if(datecheck(lahir,today)==0){
                printf("Tanggal lahir yang Anda masukan tidak valid.\nMohon masukan ulang tanggal lahir!\n");
            }
        }while(datecheck(lahir,today)==0);
        perhitungan(&otonan, lahir, waktu1);
        printf("--------------------------------------------------------------\n");
        printf("                     Hari Otonan Anda\n");
        printf("Wuku       : %s\n", wuku[otonan.wuku]);
        printf("Saptawara  : %s\n", saptawara[otonan.sapta]);
        printf("Pancawara  : %s\n", pancawara[otonan.panca]);
        printf("Triwara    : %s\n", triwara[otonan.tri]);
        tukar = swapTanggal(lahir, today);
        printf("Otonan Anda %d hari lagi\n", 210-totalhari(lahir,tukar,today)%210);
        printf("--------------------------------------------------------------\n");
        do{
            printf("[1] Ulangi Program\n");
            printf("[2] Akhiri Program\n");
            printf("Pilihan : ");
            scanf("%d", &ulang);
            if(ulang!=1&&ulang!=2){
                printf("Pihan Anda tidak tersedia!\n");
            }
        }while(ulang!=1&&ulang!=2);
    }while(ulang!=2);
    return 0;
}

void current_time(struct data *waktu){
    time_t now;
    now = time(NULL);
    struct tm *local;
    local = localtime(&now); 
    waktu->tanggal = local->tm_mday;
    waktu->bulan = local->tm_mon + 1;
    waktu->tahun = local->tm_year + 1900;
}

int swapTanggal(struct data waktu, struct data waktu1){
    int tukar = 0;
    if((waktu.bulan>=waktu1.bulan)&&(waktu.tahun>=waktu1.tahun) == 1){
        if(waktu.bulan==waktu1.bulan){
            if(waktu.tanggal>=waktu1.tanggal){
                tukar = 1;

            }
        }else{
                tukar = 1;
        }
    }
    return tukar;
}

int totalhari(struct data waktu, int tukar, struct data waktu1){
    int day = 0, tahun;
    struct data temp;
    if(tukar==1){
        temp = waktu1;
        waktu1 = waktu;
        waktu = temp;
    }
    int bulan[12][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    while(((waktu.tanggal==waktu1.tanggal)&&(waktu.bulan==waktu1.bulan)&&(waktu.tahun==waktu1.tahun)) == 0){
        if((waktu.tahun%400 == 0) || (waktu.tahun%4==0)&&(waktu.tahun%100!=0)){
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
    };
    return day;
}

int datecheck(struct data lahir, struct data today){
    int tahun = lahir.tahun;
    int bulan[12][2] = {{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    if (lahir.tahun%400==0||lahir.tahun%100!=0&&lahir.tahun%4==0){
        lahir.tahun = 1;
    }else{
        lahir.tahun = 0;
    }
    return ((lahir.tanggal <= bulan[lahir.bulan-1][lahir.tahun])&&(lahir.tanggal>0)&&(lahir.bulan>0&&lahir.bulan<=12)&&(tahun>0)/*&&(lahir.tahun<today.tahun)&&((lahir.tahun==today.tahun)&&(lahir.bulan<today.bulan))&&((lahir.tahun==today.tahun)&&(lahir.bulan==today.bulan)&&(lahir.tanggal<today.tanggal))*/); 
}

void perhitungan(struct index *otonan, struct data lahir, struct data waktu1){
    int tukar = swapTanggal(lahir, waktu1);
    int selisih = totalhari(lahir, tukar, waktu1);
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
