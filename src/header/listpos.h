/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTPOS_H
#define LISTPOS_H

#include "boolean.h"

/*  Kamus Umum */
#define CAPACITY_LIST 50
/* Kapasitas penyimpanan */
#define IDX_UNDEF_LIST -1
/* Indeks tak terdefinisi*/
#define CHAR_UNDEF_LIST '.'
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef char ElType_List;  /* type elemen List */
typedef struct {
   ElType_List contents[CAPACITY_LIST]; /* memori tempat penyimpan elemen (container) */
} ListPos;
/* Indeks yang digunakan [0..CAPACITY_LIST-1] */
/* Jika l adalah ListPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListPos */
/* Maka cara akses: 
   ELMT_LIST(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: ELMT_LIST(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT_LIST(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY_LIST */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthList(ListPos l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

void displayList(ListPos l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

#endif