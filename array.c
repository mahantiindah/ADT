/* MODUL TABEL INTEGER */
/* 	NIM/Nama 	: 13517085/Mahanti Indah Rahajeng
	Nama file 	: array.c
	Topik 		: ADT Array
	Tanggal		: 11 September 2018
	Deskripsi	: Program ini berisi body prototipe tipe Array */

#include <stdio.h>
#include "boolean.h"
#include "array.h"

void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	Neff(*T) = 0;
}
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return Neff(T);
}
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax-IdxMin+1;
}
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return Neff(T);
}
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return (i>=GetFirstIdx(T) && i<=IdxMax);
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{ 
	return (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (NbElmt(T)==0);
}
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{ 
	return (NbElmt(T)==MaxNbEl(T));
}
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	IdxType i;
	int N,x;
	scanf("%d",&N);
	while (N<0 || N>MaxNbEl(*T)){
		scanf("%d",&N);
	}
	for (i=GetFirstIdx(*T);i<=N;i++){
		scanf("%d",&x);
		Elmt(*T,i) = x;
	}
	Neff(*T) = N;
}		
void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
	IdxType i;
	int x;
	i = GetFirstIdx(*T);
	scanf("%d",&x);
	while (x!=-9999 && i<=MaxNbEl(*T)){
		Elmt(*T,i) = x;
		i++;
		scanf("%d",&x);
	}
	Neff(*T) = i-1;
}	
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
	IdxType i;
	if (NbElmt(T)==0){
		printf("Tabel kosong\n");
	} else {
		for (i=GetFirstIdx(T);i<=NbElmt(T);i++){
			printf("[%d]%d\n",i,Elmt(T,i));
		}
	}
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	IdxType i;
	printf("[");
	for (i=GetFirstIdx(T);i<=NbElmt(T);i++){
		if (i==NbElmt(T)){
			printf("%d",Elmt(T,i));
		} else {
			printf("%d,",Elmt(T,i));
		}
	}
	printf("]");
}
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
	TabInt T;
	IdxType i;
	Neff(T) = NbElmt(T1);
	for (i=GetFirstIdx(T);i<=NbElmt(T);i++){
		Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
	}
	return T;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	TabInt T;
	IdxType i;
	Neff(T) = NbElmt(T1);
	for (i=GetFirstIdx(T);i<=NbElmt(T);i++){
		Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
	}
	return T;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
	TabInt T;
	IdxType i;
	Neff(T) = NbElmt(T1);
	for (i=GetFirstIdx(T);i<=NbElmt(T);i++){
		Elmt(T,i) = Elmt(T1,i) * Elmt(T2,i);
	}
	return T;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
	TabInt T;
	IdxType i;
	Neff(T) = NbElmt(Tin);
	for(i=GetFirstIdx(T);i<=NbElmt(T);i++){
		Elmt(T,i) = c * Elmt(Tin,i);
	}
	return T;
}
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	IdxType i;
	int count;
	if (NbElmt(T1)!=NbElmt(T2)){
		return !(NbElmt(T1)!=NbElmt(T2));
	} else {
		count = 0;
		for (i=GetFirstIdx(T1);i<=NbElmt(T1);i++){
			if (Elmt(T1,i)==Elmt(T2,i)){
				count++;
			}
		}
		return (count==NbElmt(T1));
	}
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
	IdxType i,j;
	i = GetFirstIdx(T1);
	j = GetFirstIdx(T2);
	while (Elmt(T1,i)==Elmt(T2,j) && i<GetLastIdx(T1)){
		i++;
		j++;
	}
	return (Elmt(T1,i)<Elmt(T2,j) || (NbElmt(T1)<NbElmt(T2) && Elmt(T1,i)==Elmt(T2,j)));
}
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
	IdxType i;
	if (IsEmpty(T)){
		return IdxUndef;
	} else {
		i = GetFirstIdx(T);
		while (i<NbElmt(T) && X!=Elmt(T,i)){
			i++;
		}
		if (X==Elmt(T,i)){
			return i;
		} else {
			return IdxUndef;
		}
	}
}
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
	IdxType i;
	boolean Found;
	if (IsEmpty(T)){
		return IdxUndef;
	} else {
		Found = false;
		i = GetFirstIdx(T);
		while (i<=NbElmt(T) && !Found){
			if (Elmt(T,i) == X){
				Found = true;
			} else {
				i++;
			}
		}
		if (Found){
			return i;
		} else {
			return IdxUndef;
		}
	}

}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
	IdxType i;
	boolean Found;
	Found = false;
	i = GetFirstIdx(T);
	while (i<=NbElmt(T) && !Found){
		if (Elmt(T,i) == X){
			Found = true;
		} else {
			i++;
		}
	}
	return Found;
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
	IdxType i;
	Elmt(T,0) = X;
	i = NbElmt(T);
	while (i>0 && X!=Elmt(T,i)){
		i--;
	}
	return (i>0);
}
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
	IdxType i;
	ElType max;
	i = GetFirstIdx(T);
	max = Elmt(T,i);
	for (i=GetFirstIdx(T)+1;i<=NbElmt(T);i++){
		if (Elmt(T,i)>max){
			max = Elmt(T,i);
		}
	}
	return max;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
	IdxType i;
	ElType min;
	i = GetFirstIdx(T);
	min = Elmt(T,i);
	for (i=GetFirstIdx(T)+1;i<=NbElmt(T);i++){
		if (Elmt(T,i)<min){
			min = Elmt(T,i);
		}
	}
	return min;
}
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
	IdxType i,imax;
	imax = GetFirstIdx(T);
	for (i=GetFirstIdx(T)+1;i<=NbElmt(T);i++){
		if (Elmt(T,i)>Elmt(T,imax)){
			imax = i;
		}
	}
	return imax;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
	IdxType i,imin;
	imin = GetFirstIdx(T);
	for (i=GetFirstIdx(T)+1;i<=NbElmt(T);i++){
		if (Elmt(T,i)<Elmt(T,imin)){
			imin = i;
		}
	}
	return imin;
}
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
	IdxType i;
	Neff(*Tout) = NbElmt(Tin);
	for (i=GetFirstIdx(*Tout);i<=NbElmt(*Tout);i++){
		Elmt(*Tout,i) = Elmt(Tin,i);
	}
}	
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
	TabInt TI;
	IdxType i,j;
	Neff(TI) = NbElmt(T);
	i = GetFirstIdx(TI);
	j = NbElmt(T);
	while (i<=NbElmt(TI)){
		Elmt(TI,i)=Elmt(T,j);
		i++;
		j--;
	}
	return TI;
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
	IdxType i,j;
	int count;
	if (NbElmt(T)==0){
		return (NbElmt(T)==0);
	} else {
		count = 0;
		i = GetFirstIdx(T);
		j = NbElmt(T);
		while (i<=NbElmt(T)/2){
			if (Elmt(T,i)==Elmt(T,j)){
				count++;
			}
			i++;
			j--;
		}
		return (count==NbElmt(T)/2);
	}
}
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
	IdxType i,pass,imax;
	ElType temp;
	if (NbElmt(*T)>1){
		for (pass=GetFirstIdx(*T);pass<NbElmt(*T);pass++){
			imax = pass;
			for (i=pass+1;i<=NbElmt(*T);i++){
				if (Elmt(*T,i)>Elmt(*T,imax)){
					imax = i;
				}
			}
			temp = Elmt(*T,imax);
			Elmt(*T,imax)=Elmt(*T,pass);
			Elmt(*T,pass) = temp;
		}
	}
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
	IdxType i,pass;
	ElType temp;
	if (NbElmt(*T)>1){
		for (pass=GetFirstIdx(*T)+1;pass<=NbElmt(*T);pass++){
			temp = Elmt(*T,pass);
			i = pass-1;
			while (temp<Elmt(*T,i) && (i>1)){
				Elmt(*T,i+1) = Elmt(*T,i);
				i--;
			}
			if (temp>=Elmt(*T,i)) {
				Elmt(*T,i+1) = temp;
			} else {
				Elmt(*T,i+1) = Elmt(*T,i);
				Elmt(*T,i) = temp;
			}
		}
	}
}
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	Neff(*T)++;
	Elmt(*T,NbElmt(*T)) = X;
}	
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
	IdxType j;
	Neff(*T)++;
	for (j=NbElmt(*T);j>=i+1;j--){
		Elmt(*T,j) = Elmt(*T,j-1);
	}
	Elmt(*T,i) = X;
}
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	*X = Elmt(*T,NbElmt(*T));
	Neff(*T)--;
}
void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
	ElType j;
	*X = Elmt(*T,i);
	for (j=i;j<NbElmt(*T);j++){
		Elmt(*T,j) = Elmt(*T,j+1);
	}
	Neff(*T)--;
}
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
	if (SearchSentinel(*T,X)){
		printf("nilai sudah ada\n");
	} else {
		AddAsLastEl(T,X);
	}
}
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
	return Search1(T,X);
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
	return Elmt(T,NbElmt(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
	return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T` */
{
	*Max = MaxUrut(T);
	*Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
	IdxType i,idx;
	if (NbElmt(*T)!=MaxNbEl(*T)){
		i = GetFirstIdx(*T);
		while (i<=NbElmt(*T) && X>=Elmt(*T,i)){
			i++;
		}
		idx = i;
		AddEli(T,X,idx);
	}
}			
void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
	if (SearchUrut(*T,X)!=IdxUndef){
		DelEli(T,SearchUrut(*T,X),&X);
	}
}
