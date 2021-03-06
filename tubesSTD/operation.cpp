#include "listBase.h"

void hitungIndex(connect &R) {
    float rata = (R -> info.kuis * (0.2) + R -> info.uts * (0.4) + R -> info.uas * (0.4));
    if (rata >= 80) {
        R -> info.Index = "A";
    } else if (rata < 80 && rata >= 70) {
        R -> info.Index = "AB";
    } else if (rata < 70 && rata >= 65) {
        R -> info.Index = "B";
    } else if (rata < 65 && rata >= 60) {
        R -> info.Index = "BC";
    } else if (rata < 60 && rata >= 50) {
        R -> info.Index = "C";
    } else if (rata < 50 && rata >= 40) {
        R -> info.Index = "D";
    } else {
        R -> info.Index = "E";
    }
    R -> info.rerata = rata;
}

float nilaiMedianMatkul(ListBase L, string st) {
    float arr[100] = {0};
    int i = 0;
    connect P = L.first;
    while (P != NULL) {
        if (P -> matkul -> info.matkul == st) {
            arr[i] = (P -> info.kuis * (0.2) + P -> info.uts * (0.4) + P -> info.uas * (0.4));
            i++;
        }
        P = P -> next;
    }
    if (i % 2 == 1) {
        return arr[i/2];
    } else {
        return (arr[i/2] + arr[i/2 - 1]) / 2;
    }
}

float nilaiRerata(ListBase L, string st) {
    connect P = L.first;
    float sum = 0;
    int nData = 0;
    while (P != NULL) {
        if (P -> matkul -> info.matkul == st) {
            sum += (P -> info.kuis * (0.2) + P -> info.uts * (0.4) + P -> info.uas * (0.4));
            nData++;
        }
        P = P -> next;
    }
    if (nData != 0) {
        return sum / nData;
    } else {
        return 0;
    }
}

void printReverse(List1 L) {
    address1 P = L.first;
    int i = 1;
    do {
        P = P -> prev;
        cout << i << ".\nNama\t: " << P -> info.nama << "\nNIM\t: " << P -> info.ID << endl;
        i++;
    } while (P != L.first);
}

void cleared() {
    system("cls");
}