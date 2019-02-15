/* 	NIM/Nama 	: 13517085/Mahanti Indah Rahajeng
	Nama file 	: listsirkuler.c
	Topik 		: ADT List Sirkuler
	Tanggal		: 27 Oktober 2018
	Deskripsi	: Program ini berisi body prototipe tipe List Sirkuler */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listsirkuler.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return First(L)==Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L)=Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (ElmtList *) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    if (IsEmpty(L)){
		return Nil;
	} else {
		P = First(L);
		while (Next(P)!=First(L) && Info(P)!=X){
			P = Next(P);
		}
		if (Info(P)==X){
			return P;
		} else {
			return Nil;
		}
	}
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;
    P = Alokasi(X);
    if (P!=Nil){
        InsertFirst(L,P);
    }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P = Alokasi(X);
    if (P!=Nil){
        InsertLast(L,P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	address last;
	if (IsEmpty(*L)){
		Next(P) = P;
	} else {
		last = First(*L);
		while (Next(last)!=First(*L)){
			last = Next(last);
		}
		Next(P) = First(*L);
		Next(last) = P;
	}
	First(*L) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	address last;
	if (IsEmpty(*L)){
		InsertFirst(L,P);
	} else {
		last = First(*L);
		while (Next(last)!=First(*L)){
			last = Next(last);
		}
		InsertAfter(L,P,last);
	}
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}
/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	address last;
	*P = First(*L);
	if (Next(First(*L))==First(*L)){
		First(*L) = Nil;
	} else {
		last = First(*L);
		while (Next(last)!=First(*L)){
			last = Next(last);
		}
		First(*L) = Next(First(*L));
		Next(last) = First(*L);
	}
	Next(*P) = Nil;
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address Last, PrecLast;
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last)!=First(*L)){
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if (PrecLast == Nil){
		First(*L) = Nil;
	} else {
		Next(PrecLast) = First(*L);
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P;
    address Prec;
    P = Search(*L,X);
    if (P!=Nil){
        if (P==First(*L)){
            DelFirst(L,&P);
        } else {
            Prec = First(*L);
            while (Next(Prec)!=P){
                Prec = Next(Prec);
            }
            DelAfter(L,&P,Prec);
        }
        Dealokasi(P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    if (IsEmpty(L)){
        printf("[]");
    } else {
        P = First(L);
        printf("[");
        while (Next(P)!=First(L)){
            printf("%d,",Info(P));
            P = Next(P);
        }
        printf("%d]",Info(P));
    }
}

// 13 WA DelVLast
// 16 WA DelLast
