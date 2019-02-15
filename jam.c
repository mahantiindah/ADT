/* File: jam.c */
/* Tanggal: 4 September 2018 */
/* *** Body Prototype TYPE JAM *** */

#include <stdio.h>
#include "boolean.h"
#include "jam.h"

/* *** BODY PROTOTIPE *** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	return (H>=0 && H<=23 && M>=0 && M<=59 && S>=0 && S<=59);
}
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	JAM J;
	Hour(J) = HH;
	Minute(J) = MM;
	Second(J) = SS;
	return J;
}
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */ 
{
	int H,M,S;
	scanf("%d %d %d",&H,&M,&S);
	while (!IsJAMValid(H,M,S)){
		printf("Jam tidak valid\n");
		scanf("%d %d %d",&H,&M,&S);
	}
	*J = MakeJAM(H,M,S);
}
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
	printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
	long detik;
	detik = 3600*Hour(J) + 60*Minute(J) + Second(J);
	return detik;
}
JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
	long N1;
	JAM J;
	if (N >= 86400) {
		do {
			N1 = N % 86400;
		} while (N1 >= 86400);
	} else {
		N1 = N;
	}
	Hour(J) = N1 / 3600;
	Minute(J) = (N1 % 3600) / 60;
	Second(J) = (N1 % 3600) % 60;
	return J;
}
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
	return (Hour(J1)==Hour(J2) && Minute(J1)==Minute(J2) && Second(J1)==Second(J2));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
	return !(JEQ(J1,J2));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	boolean cek;
	cek = false;
	if (Hour(J1) < Hour(J2)){
		cek = true;
	} else if (Hour(J1) ==  Hour(J2)){ 
		if (Minute(J1) < Minute(J2)){
			cek = true;
		} else if (Minute(J1) == Minute(J2)){ 
			if (Second(J1) < Second(J2)){
				cek = true;
			} 
		}
	}
	return cek;
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
	boolean cek;
	cek = false;
	if (Hour(J1) > Hour(J2)){
		cek = true;
	} else if (Hour(J1) ==  Hour(J2)){ 
		if (Minute(J1) > Minute(J2)){
			cek = true;
		} else if (Minute(J1) == Minute(J2)){ 
			if (Second(J1) > Second(J2)){
				cek = true;
			} 
		}
	}
	return cek;
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
	long detik;
	detik = JAMToDetik(J);
	detik++;
	return DetikToJAM(detik);
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
	long detik;
	detik = JAMToDetik(J);
	detik+=N;
	return DetikToJAM(detik);
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
	long detik;
	detik = JAMToDetik(J);
	detik--;
	return DetikToJAM(detik);
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
	long detik;
	detik = JAMToDetik(J);
	detik-=N;
	return DetikToJAM(detik);
}
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	long detik;
	detik = (Hour(JAkh)-Hour(JAw))*3600 + (Minute(JAkh)-Minute(JAw))*60 + (Second(JAkh)-Second(JAw));
	if (JGT(JAw,JAkh)) {
		detik += 24*3600;
	}
	return detik;
}
