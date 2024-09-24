#include "complex.h"
#include <stdio.h>
#include <math.h>

#ifndef BOOLEAN_H
#define BOOLEAN_H

#define boolean unsigned char
#define TRUE 1
#define FALSE 0

#endif

boolean IsCOMPLEXValid(float Re, float Im) {
    return TRUE;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
    float r, i;
    scanf("%f %f", &r, &i);
    CreateComplex(C, r, i);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) < 0) {
        printf("%.2f%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CF;
    CreateComplex(&CF, Real(C1) + Real(C2), Imag(C1) + Imag(C2)); 
    return CF;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CF;
    CreateComplex(&CF, Real(C1) - Real(C2), Imag(C1) - Imag(C2)); 
    return CF;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CF;
    CreateComplex(&CF, (Real(C1)*Real(C2))-(Imag(C1)*Imag(C2)), (Real(C1)*Imag(C2))+(Real(C2)*Imag(C1)));
    return CF;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX CF;
    float denom = ((Real(C2)*Real(C2)) + (Imag(C2)*Imag(C2)));
    if (denom) {
        COMPLEX CP = MultiplyCOMPLEX(C1, ConjugateCOMPLEX(C2));
        float CP_R = Real(CP) / denom;
        float CP_I = Imag(CP) / denom;
        CreateComplex(&CF, CP_R, CP_I);
    } else {
        CreateComplex(&CF, 0, 0);
    }
    return CF;
}

float AbsCOMPLEX(COMPLEX C) {
    return sqrt((Real(C)*Real(C))+(Imag(C)*Imag(C)));
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX CF;
    CreateComplex(&CF, Real(C), (-1) * Imag(C));
    return CF;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) != Real(C2)) || (Imag(C1) != Imag(C2));
}
