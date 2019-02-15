/* 	NIM/Nama 	: 13517085/Mahanti Indah Rahajeng
	Nama file 	: matriks.c
	Topik 		: ADT Matriks
	Tanggal		: 15 September 2018
	Deskripsi	: Program ini berisi body prototipe tipe Matriks */

#include <stdio.h>
#include "boolean.h"
#include "matriks.h"
#include <math.h>

void MakeMATRIKS (int NB, int NK, MATRIKS * M) 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<= KolMax);
}
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return NBrsEff(M);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return NKolEff(M);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return(i>=GetFirstIdxBrs(M)&&i<=GetLastIdxBrs(M)&&j>=GetFirstIdxKol(M)&&j<=GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return Elmt(M,i,i);
}
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	indeks i,j;
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	for(i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
		for(j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
			Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
		}
	}
}
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	indeks i,j;
	MakeMATRIKS(NB,NK,M);
	for(i=GetFirstIdxBrs(*M);i<=NB;i++){
		for(j=GetFirstIdxKol(*M);j<=NK;j++){
			if (j==NK){
				if (i!=NB){
					scanf("%d\n",&Elmt(*M,i,j));
				} else {
					scanf("%d",&Elmt(*M,i,j));
				}
			} else {
				scanf("%d ",&Elmt(*M,i,j));
			}
		}
	}
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	indeks i,j;
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			printf("%d",Elmt(M,i,j));
			if (j!=GetLastIdxKol(M)){
				printf(" ");
			}
		}
		if (i!=GetLastIdxBrs(M)){
			printf("\n");
		}
	}
}                             
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
	MATRIKS MHsl;
	indeks i,j;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
		for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
		}
	}
	return MHsl;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	MATRIKS MHsl;
	indeks i,j;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	for (i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
		for (j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
		}
	}
	return MHsl;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	MATRIKS MHsl;
	indeks i,j,k;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MHsl);
	for (i=GetFirstIdxBrs(MHsl);i<=GetLastIdxBrs(MHsl);i++){
		for (j=GetFirstIdxKol(MHsl);j<=GetLastIdxKol(MHsl);j++){
			Elmt(MHsl,i,j) = 0;
			for (k=GetFirstIdxKol(M1);k<=GetLastIdxKol(M1);k++){
				Elmt(MHsl,i,j) += Elmt(M1,i,k) * Elmt(M2,k,j);
			} 
		}
	}
	return MHsl;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	MATRIKS MHsl;
	indeks i,j;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHsl);
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			Elmt(MHsl,i,j) = Elmt(M,i,j) * X;
		}
	}
	return MHsl;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	indeks i,j;
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j) = Elmt(*M,i,j) * K;
		}
	}
}
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	indeks i,j;
	int count;
	if (NBElmt(M1)!=NBElmt(M2)){
		return false;
	} else {
		count=0;
		for(i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
			for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M2);j++){
				if(Elmt(M1,i,j)==Elmt(M2,i,j)){
					count++;
				}
			}
		}
		return(count==NBElmt(M1));
	}
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return !EQ(M1,M2);
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2));
}
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return NBrsEff(M)*NKolEff(M);
}
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return(NBrsEff(M)==NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	indeks i,j;
	int count;
	if (!IsBujurSangkar(M)){
		return false;
	} else {
		count = 0;
		for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
				if(Elmt(M,i,j)==Elmt(M,j,i)){
					count++;
				}
			}
		}
		return (count==NBElmt(M));
	}
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	indeks i,j;
	int countd,count;
	if (!IsBujurSangkar(M)){
		return false;
	} else {
		countd = 0;
		for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
			if(GetElmtDiagonal(M,i)==1){
				countd++;
			}
		}
		count = 0;
		for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
				if(i!=j && Elmt(M,i,j)==0){
					count++;
				}
			}
		}
		return (countd==NBrsEff(M) && count==NBElmt(M)-NBrsEff(M));
	}
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	indeks i,j;
	int count;
	count = 0;
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
			for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
				if(Elmt(M,i,j)!=0){
					count++;
				}
			}
	} 
	return((float)count/(float)NBElmt(M)*100<=5);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	MATRIKS MHsl;
	indeks i,j;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHsl);
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			Elmt(MHsl,i,j) = Elmt(M,i,j) * (-1);
		}
	}
	return MHsl;
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
    int i,j,k;
    float det,temp;
    det=1;
    float m[NBrsEff(M)+1][NKolEff(M)+1];
    //deklarasi matriks berelemen float
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            m[i][j]=(float) Elmt(M,i,j);
        }
    }
    //mengisi matriks m dengan nilai float dari elemen matriks M
    for ( i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            for (k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
                if (i!=k){
					m[i][j]+=m[k][j];
				}
            }
        }
    }
    for (i=GetFirstIdxBrs(M);i<GetLastIdxBrs(M);i++){
        for (j=i;j<=GetLastIdxBrs(M);j++){
            if ( m[j][i]==0){
				return 0;
			}
            temp=m[j][i];
            det=det*temp;
            for(k=i;k<=GetLastIdxKol(M);k++){
                m[j][k]=m[j][k]/temp;
            }
        }
        for (j=i+1;j<=GetLastIdxBrs(M);j++){
            for(k=i;k<=GetLastIdxKol(M);k++){
                m[j][k]=m[j][k]-m[i][k];
            }
        }
    }
    det=det*m[i][i];
    return round(det);
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	indeks i,j;
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j) = Elmt(*M,i,j) * (-1);
		}
	}
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	MATRIKS MT;
	indeks i,j;
	CopyMATRIKS(*M,&MT);
	for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
		for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j) = Elmt(MT,j,i);
		}
	}
}
