#include "..\header\wordmachine.h"

/* Word Engine State */
Word currentWord;

void ignoreBlank(){
    while ( (currentChar == BLANK ) ){
        adv();
    }
}

void copyWordFromFile(){
    int i = 0;
	boolean endOfWord;
	char tempCC,tempCC1,tempCC2,tempCC3,tempCC4,tempCC5;

	endOfWord = false;
    while ( (currentChar != LF) && (!endOfWord) ) {
        currentWord.contents[i] = currentChar;
        tempCC = currentChar; // S udah disimpen
		adv(); // S belom disimpen

		if (tempCC == currentChar) {
			tempCC1 = currentChar;
			adv();
			if (tempCC == currentChar){ // W
				tempCC2 = currentChar;
				adv();
				if (tempCC == currentChar){
					tempCC3 = currentChar;
					adv();
					if (tempCC == currentChar){
						tempCC4 = currentChar;
						adv();
						if (tempCC == currentChar){
							tempCC5 = currentChar;
							adv();
							if ( tempCC == currentChar ){
								endOfWord = true;
							} else {
								i = i + 5;
								currentWord.contents[i-4] = tempCC1;
								currentWord.contents[i-3] = tempCC2;
								currentWord.contents[i-2] = tempCC3;
								currentWord.contents[i-1] = tempCC4;
								currentWord.contents[i] = tempCC5;
							}
						} else {
							i = i + 4;
							currentWord.contents[i-3] = tempCC1;
							currentWord.contents[i-2] = tempCC2;
							currentWord.contents[i-1] = tempCC3;
							currentWord.contents[i] = tempCC4;
						}
					} else {
						i = i + 3;
						currentWord.contents[i-2] = tempCC1;
						currentWord.contents[i-1] = tempCC2;
						currentWord.contents[i] = tempCC3;
					}
				} else {
					i = i + 2;
					currentWord.contents[i-1] = tempCC1;
					currentWord.contents[i] = tempCC2;
				}
			} else {
				i = i + 1;
				currentWord.contents[i] = tempCC1;
			}
		}
		i++;
    }
    currentWord.length = i;
}