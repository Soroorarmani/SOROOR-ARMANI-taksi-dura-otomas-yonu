#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

const int MAX_TAXI = 100;
const int MAX_MUSTERI = 100;

struct Taxi {
    char plaka[15];
    char model[80];
    char durum; 
};

struct Musteri {
    char ad[50];
    char soyad[50];
    char nereden[100];
    char nereye[100];
};

Taxi taxis[MAX_TAXI];
Musteri musteris[MAX_MUSTERI];
int taxiSayisi = 0;
int musteriSayisi = 0;

void TaxiEkle();
void TaxiListeleme();
void TaxiArama();
void TaxiSil();
void TaxiDuzenle();

void MusteriEkle();
void MusteriListeleme();
void MusteriArama();

int main() {
    char anamenu;
    do {
        system("cls");

        cout << "|-------Taksi Duragi Yonetimi------|" << endl;
        cout << "|       Secim Yapiniz              |" << endl;
        cout << "|       1- Taksi Islemleri         |" << endl;
        cout << "|       2- Musteri Islemleri       |" << endl;
        cout << "|       3- Cikis                   |" << endl;
        cout << "|----------------------------------|" << endl;
        char secim;
        cin >> secim;

        switch (secim) {
            case '1': {
                system("cls");
                cout << "|-------Taksi Islemleri------|" << endl;
                cout << "|       Secim Yapiniz        |" << endl;
                cout << "|       1- Taksi Ekleme      |" << endl;
                cout << "|       2- Taksi Listeleme   |" << endl;
                cout << "|       3- Taksi Arama       |" << endl;
                cout << "|       4- Taksi Sil         |" << endl;
                cout << "|       5- Taksi Duzenle     |" << endl;
                cout << "|----------------------------|" << endl;
                char taxiSecim;
                cin >> taxiSecim;

                switch (taxiSecim) {
                    case '1':
                        TaxiEkle();
                        break;
                    case '2':
                        TaxiListeleme();
                        break;
                    case '3':
                        TaxiArama();
                        break;
                    case '4':
                        TaxiSil();
                        break;
                    case '5':
                        TaxiDuzenle();
                        break;
                    default:
                        cout << "Gecersiz secim. Tekrar deneyin." << endl;
                }

                break;
            }
            case '2': {
                system("cls");
                cout << "|-------Musteri Islemleri------|" << endl;
                cout << "|       Secim Yapiniz          |" << endl;
                cout << "|       1- Musteri Ekleme      |" << endl;
                cout << "|       2- Musteri Listeleme   |" << endl;
                cout << "|       3- Musteri Arama       |" << endl;
                cout << "|------------------------------|" << endl;
                char musteriSecim;
                cin >> musteriSecim;

                switch (musteriSecim) {
                    case '1':
                        MusteriEkle();
                        break;
                    case '2':
                        MusteriListeleme();
                        break;
                    case '3':
                        MusteriArama();
                        break;
                    default:
                        cout << "Gecersiz secim. Tekrar deneyin." << endl;
                }

                break;
            }
            case '3':
                cout << "Programdan cikiliyor..." << endl;
                return 0;
            default:
                cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }

        cout << "Ana menuye donmek icin: a, cikmak icin: c" << endl;
        anamenu = getche();

    } while (anamenu == 'a');

    return 0;
}

void MusteriEkle() {
    Musteri musteri;
    char secim;

    do {
        cout << "Musteri Adi: ";
        cin >> musteri.ad;
        cout << "Musteri Soyadi: ";
        cin >> musteri.soyad;
        cout << "Nereden: ";
        cin >> musteri.nereden;
        cout << "Nereye: ";
        cin >> musteri.nereye;

        if (musteriSayisi < MAX_MUSTERI) {
            musteris[musteriSayisi++] = musteri;
            cout << "Baska musteri eklemek ister misiniz? (E/H)" << endl;
            secim = getche();
            cout << endl;
        } else {
            cout << "Musteri kapasitesi doldu. Islem yapilamaz." << endl;
            break;
        }

    } while (secim == 'e' || secim == 'E');

    cout << "Musteri bilgileri basariyla eklendi." << endl;
}

void MusteriListeleme() {
    cout << "Toplam Musteri Kayit Sayisi: " << musteriSayisi << endl;

    if (musteriSayisi > 0) {
        for (int i = 0; i < musteriSayisi; i++) {
            cout << i + 1 << ". Musteri Bilgileri" << endl;
            cout << "Ad: " << musteris[i].ad << endl;
            cout << "Soyad: " << musteris[i].soyad << endl;
            cout << "Nereden: " << musteris[i].nereden << endl;
            cout << "Nereye: " << musteris[i].nereye << endl;
        }
    } else {
        cout << "Kayit Bulunamadi..." << endl;
    }
}

void MusteriArama() {
    cout << "Aranan Musteri Adini Giriniz: ";
    char ad[50];
    cin >> ad;

    bool found = false;
    for (int i = 0; i < musteriSayisi; i++) {
        if (strcmp(musteris[i].ad, ad) == 0) {
            cout << "Bulunan Musteri Bilgileri" << endl;
            cout << "Ad: " << musteris[i].ad << endl;
            cout << "Soyad: " << musteris[i].soyad << endl;
            cout << "Nereden: " << musteris[i].nereden << endl;
            cout << "Nereye: " << musteris[i].nereye << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Kayit Bulunamadi..." << endl;
    }
}

void TaxiEkle() {
    Taxi taxi;
    char secim;
    int adet = 0;

    do {
        cout << "Taksi Plaka Giriniz" << endl;
        cin >> taxi.plaka;
        cout << "Taksi Model Giriniz" << endl;
        cin >> taxi.model;
        cout << "Taksi Durumu Giriniz (D/U)" << endl;
        taxi.durum = getche();
        cout << endl;

        if (taxiSayisi < MAX_TAXI) {
            taxis[taxiSayisi++] = taxi;
            adet++;
            cout << "Baska Taksi Eklemek Ister misiniz? (E/H)" << endl;
            secim = getche();
            cout << endl;
        } else {
            cout << "Taksi kapasitesi doldu. Islem yapilamaz." << endl;
            break;
        }

    } while (secim == 'e' || secim == 'E');

    cout << adet << " adet Taksi Ekledi.." << endl;
}

void TaxiListeleme() {
    cout << "Toplam Taksi Kayit Sayisi:" << taxiSayisi << endl;

    if (taxiSayisi > 0) {
        for (int i = 0; i < taxiSayisi; i++) {
            cout << i + 1 << ". Taksi Bilgileri" << endl;
            cout << "Taksi Plakasi: " << taxis[i].plaka << endl;
            cout << "Taksi Modeli: " << taxis[i].model << endl;
            cout << "Taksi Durumu: " << (taxis[i].durum == 'D' || 'd' ? "Uygun" : "Uygun Degil") << endl;
        }
    } else {
        cout << "Kayit Bulunamadi..." << endl;
    }
}

void TaxiArama() {
    cout << "Aranan Taksi Plakasini Giriniz" << endl;
    char plaka[15];
    cin >> plaka;

    bool found = false;
    for (int i = 0; i < taxiSayisi; i++) {
        if (strcmp(taxis[i].plaka, plaka) == 0) {
            cout << "Bulunan Taksinin Bilgileri" << endl;
            cout << "Taksi Plakasi: " << taxis[i].plaka << endl;
            cout << "Taksi Modeli: " << taxis[i].model << endl;
            cout << "Taksi Durumu: " << (taxis[i].durum == 'D' || 'd' ? "Uygun" : "Uygun Degil") << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Kayit Bulunamadi..." << endl;
    }
}

void TaxiSil() {
    char plaka[15];
    char secim = ' ';
    bool var = false;

    cout << "Silinecek Taksi Plakasini Giriniz: ";
    cin >> plaka;

    for (int i = 0; i < taxiSayisi; i++) {
        if (strcmp(taxis[i].plaka, plaka) == 0) {
            cout << "Silmek istediginiz Taksi Bilgileri" << endl;
            cout << "Taksi Plakasi: " << taxis[i].plaka << endl;
            cout << "Taksi Modeli: " << taxis[i].model << endl;
            cout << "Taksi Durumu: " << (taxis[i].durum == 'D' || 'd' ? "Uygun" : "Uygun Degil") << endl;

            cout << "\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
            secim = getche();
            if (secim == 'e' || secim == 'E') {
                var = true;
                for (int j = i; j < taxiSayisi - 1; j++) {
                    taxis[j] = taxis[j + 1];
                }
                taxiSayisi--;
            }
        }
    }

    if (var) {
        cout << "\n Taksi Silindi" << endl;
    } else {
        cout << "\n Taksi Bulunamadi" << endl;
    }
}

void TaxiDuzenle() {
    char plaka[15];
    char secim = ' ';
    bool var = false;

    cout << "Duzenlenecek Taksi Plakasini Giriniz : ";
    cin >> plaka;

    for (int i = 0; i < taxiSayisi; i++) {
        if (strcmp(taxis[i].plaka, plaka) == 0) {
            cout << "Duzeltmek istediginiz Taksi Bilgileri" << endl;
            cout << "Taksi Plakasi: " << taxis[i].plaka << endl;
            cout << "Taksi Modeli: " << taxis[i].model << endl;
            cout << "Taksi Durumu: " << (taxis[i].durum == 'D' || 'd' ? "Uygun" : "Uygun Degil") << endl;

            cout << "\nDuzeltmek Istediginiz Kayit Bu Mu? [E/H] : ";
            secim = getche();
            if (secim == 'E' || secim == 'e') {
                var = true;
                cout << "\nTaksi Plaka Giriniz" << endl;
                cin >> taxis[i].plaka;
                cout << "Taksi Model Giriniz" << endl;
                cin >> taxis[i].model;
                cout << "Taksi Durumu Giriniz (D/U)" << endl;
                taxis[i].durum = getche();
                cout << endl;
            }
        }
    }

    if (var) {
        cout << "\nTaksi Duzeltildi." << endl;
    } else {
        cout << "\nTaksi Bulunamadi" << endl;
    }
}

