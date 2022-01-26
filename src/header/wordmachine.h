/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H


#include "boolean.h"
#include "charmachine.h"

#define CAPACITY 50
#define BLANK ' '
#define CR '\r' //carriage return
#define LF '\n' //line feed

typedef struct {
   char contents[CAPACITY]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY-1] */
   int length;
} Word;

/* Word Engine State */
extern Word currentWord;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK */

void copyWordFromFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK atau currentChar = '\n' atau currentChar = '\r'
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika ternyata currentChar tetap berupa karakter terakhir yang diakuisi, pembacaan file telah berakhir.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

#endif