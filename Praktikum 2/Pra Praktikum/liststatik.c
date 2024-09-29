#include "liststatik.h"
#include <stdio.h>

#ifndef BOOLEAN_H
#define BOOLEAN_H

#define boolean unsigned char
#define TRUE 1
#define FALSE 0

#endif

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    IdxType i;
    for (i=IDX_MIN;i<CAPACITY;i++) {
        ELMT(*l, i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    int len = 0;
    IdxType i;
    for (i=IDX_MIN;i<CAPACITY;i++) {
        if (ELMT(l, i) == MARK) break;
        len++;
    }
    return len;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    return IDX_MIN;
}
IdxType getLastIdx(ListStatik l) {
    return listLength(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
    return (i >= IDX_MIN && i < CAPACITY);
}
boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < listLength(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (ELMT(l, IDX_MIN)==MARK);
}
boolean isFull(ListStatik l) {
    return (listLength(l)==CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    int n;
    scanf("%d", &n);
    while (n < IDX_MIN || n > CAPACITY) {
        scanf("%d", &n);
    }
    CreateListStatik(l);
    if (n > 0) {
        IdxType i;
        for (i=IDX_MIN;i<n;i++) {
            ElType el;
            scanf("%d", &el);
            ELMT(*l, i) = el;
        }
    }
}

void printList(ListStatik l) {
    printf("[");
    if (!(isEmpty(l))) {
        IdxType i = IDX_MIN;
        boolean koma = FALSE;
        while (i < CAPACITY) {
            printf("%d", ELMT(l, i));
            i++;
            if (ELMT(l, i)==MARK || i == CAPACITY) {
                break;
            } else {
                printf(",");
            }
        };
        }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l3;
    IdxType i;
    CreateListStatik(&l3);
    ElType res;
    for (i=IDX_MIN;i<CAPACITY;i++) {
        if (ELMT(l1, i)==MARK) {
            break;
        } else {
        if (plus) res = ELMT(l1, i) + ELMT(l2, i); else res = ELMT(l1, i) - ELMT(l2, i);
        ELMT(l3, i) = res;
        }
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    int len1 = listLength(l1);
    if (len1!=listLength(l2)) {
        return FALSE;
    } else {
        IdxType i;
        for (i=IDX_MIN;i<len1;i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
    IdxType i = IDX_MIN;
    if (isEmpty(l)) {
        return IDX_UNDEF;
    }
    while (i < CAPACITY) {
        if (ELMT(l, i)==MARK) {
            return IDX_UNDEF;
        } else if (ELMT(l, i)==val) {
            return i;
        }
        i++;
        if (i == CAPACITY) {
            return IDX_UNDEF;
        }
    }

}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
    IdxType i;
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    for (i=IDX_MIN;i<CAPACITY;i++) {
        if (ELMT(l, i)==MARK) {
            break;
        } else if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        } else if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) {
    if (isEmpty(*l)) {
        ELMT(*l, IDX_MIN) = val;
    } else {
        IdxType i;
        for (i=CAPACITY-1;i>IDX_MIN;i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, IDX_MIN) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    IdxType i;
    for (i=CAPACITY-1;i>idx;i--) {
        ELMT(*l, i) = ELMT(*l, i-1);
    }
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val) {
    if (isEmpty(*l)) {
        ELMT(*l, IDX_MIN) = val;
    } else {
        IdxType i = IDX_MIN;
        while (i < CAPACITY) {
            if (ELMT(*l,i)==MARK) {
                ELMT(*l,i) = val;
                break;
            }
            i++;
        }
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val) {
    IdxType i = IDX_MIN;
    *val = ELMT(*l, IDX_MIN);
    while (i < CAPACITY) {
        if (ELMT(*l,i)==MARK) {
            ELMT(*l, i-1) = MARK;
            break;
        } else if (i == CAPACITY-1) {
            ELMT(*l, i) = MARK;
            break;
        } else {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        i++;
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    IdxType i = idx;
    *val = ELMT(*l, idx);
    while (i < CAPACITY) {
        if (ELMT(*l,i)==MARK) {
            ELMT(*l, i-1) = MARK;
            break;
        } else if (i == CAPACITY-1) {
            ELMT(*l, i) = MARK;
            break;
        } else {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        i++;
    }
}

void deleteLast(ListStatik *l, ElType *val) {
    IdxType i = IDX_MIN;
    while (i < CAPACITY) {
        if (ELMT(*l,i)==MARK) {
            *val = ELMT(*l, i-1);
            ELMT(*l, i-1) = MARK;
            break;
        } else if (i == CAPACITY-1) {
            *val = ELMT(*l, i);
            ELMT(*l, i) = MARK;
            break;
        }
        i++;
    }
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    IdxType i;
    IdxType j;
    boolean swap = FALSE;
    if (asc) {
        IdxType idmin;
        
        int len = listLength(*l);
        for (i=IDX_MIN;i<len;i++) {
            ElType min = ELMT(*l, i);
            for (j=i;j<len;j++) {
                
                if (ELMT(*l, j) < min) {
                    swap = TRUE;
                    idmin = j;
                    min = ELMT(*l, idmin);
                }
            }
            if (swap) {
                ElType temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, idmin);
                ELMT(*l, idmin) = temp;
                swap = FALSE; 
            }
        }
    } else {
        IdxType idmax;
        
        int len = listLength(*l);
        for (i=IDX_MIN;i<len;i++) {
            ElType max = ELMT(*l, i);
            for (j=i;j<len;j++) {
                if (ELMT(*l, j) > max) {
                    swap = TRUE;
                    idmax = j;
                    max = ELMT(*l, j);
                }
            }
            if (swap) {
                ElType temp = ELMT(*l, i);
                ELMT(*l, i) = ELMT(*l, idmax);
                ELMT(*l, idmax) = temp;
                swap = FALSE;
            } 
        }
    }
}