#include "..\header\charmachine.h"

char currentChar;
boolean eot;

static FILE * tape;
static int retval;

void startWithFile(FILE* f) {
	tape = f;
	adv();
}

void adv() {
	retval = fscanf(tape,"%c",&currentChar);
	eot = (currentChar == MARK);
	if (eot) {
      fclose(tape);
   }
}