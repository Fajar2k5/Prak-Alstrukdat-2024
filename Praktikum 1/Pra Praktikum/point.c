#include <stdio.h>
#include "point.h"
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void CreatePoint (POINT* P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
};

void BacaPOINT(POINT *P){
    float x,y;
    scanf("%f", &x);
    scanf("%f", &y);
    CreatePoint(P,x,y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    return (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2) {
    return (Absis(P1)!=Absis(P2)) || (Ordinat(P1)!=Ordinat(P2));
}

boolean IsOrigin (POINT P) {
    return (Absis(P) == 0) && (Ordinat(P) ==0);
}

boolean IsOnSbX(POINT P) {
    return !(Ordinat(P));
}

boolean IsOnSbY(POINT P) {
    return !(Absis(P));
}

int Kuadran (POINT P) {
    if (!(IsOrigin(P) || IsOnSbX(P) || IsOnSbY(P))) {
        if ((Absis(P) > 0) && Ordinat(P) > 0) {
            return 1;
        } else if ((Absis(P) < 0) && Ordinat(P) > 0) {
            return 2;
        } else if ((Absis(P) < 0) && Ordinat(P) < 0) {
            return 3;
        } else if ((Absis(P) > 0) && Ordinat(P) < 0) {
            return 4;
        }
    } 
}

POINT NextX (POINT P) {
    POINT PN;
    CreatePoint(&PN, Absis(P)+1, Ordinat(P));
    return PN;
}             
POINT NextY (POINT P) {
    POINT PN;
    CreatePoint(&PN, Absis(P), Ordinat(P)+1);
    return PN;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    POINT pt;
    CreatePoint(&pt, Absis(P)+deltaX, Ordinat(P)+deltaY);
    return pt;
}
POINT MirrorOf (POINT P, boolean SbX) {
    POINT PN;
    if (SbX) {
        CreatePoint(&PN, Absis(P), (-1)*(Ordinat(P)));
    } else {
        CreatePoint(&PN, (-1)*Absis(P), Ordinat(P));
    }
    return PN;
}

float Jarak0 (POINT P) {
    return sqrt((Absis(P)*Absis(P))+(Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2) {
    float p = Absis(P2) - Absis(P1);
    float l = Ordinat(P2) - Ordinat(P1);
    return sqrt(powf(p,2)+powf(l,2));
}

void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P)
    {Ordinat(*P) = 0;}
void GeserKeSbY (POINT *P) {
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) *= -1;
    } else {
        Absis(*P) *= -1;
    }
}

void Putar (POINT *P, float Sudut) {
    float SudRad = (-1) * Sudut * M_PI / 180;
    float tempA = Absis(*P);
    Absis(*P) = Absis(*P) * cos(SudRad) - Ordinat(*P) * sin(SudRad);
    Ordinat(*P) = tempA * sin(SudRad) + Ordinat(*P) * cos(SudRad);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2) {
    int a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2)-Absis(P1));
    // int b = (((-1)*(Absis(P1)*Ordinat(P2))+Absis(P1)*Ordinat(P1))) + Ordinat(P1);
    int b = (Ordinat(P1)) - (a*Absis(P1));
    // y = ((y2-y1)/(x2-x1) + ((-x1*y2 +x1*y1)/(x2-x1)) + y1)
    printf("(%d,%d)", a, b);
}