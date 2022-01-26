#include "..\header\listpos.h"

void CreateListPos(ListPos *l){
    for (int i = 0 ; i < CAPACITY_LIST ; i++){
        ELMT_LIST(*l,i) = CHAR_UNDEF_LIST;
    }
}

int lengthList(ListPos l){
    int i = 0;
    while ( i < CAPACITY_LIST && ELMT_LIST(l,i) != CHAR_UNDEF_LIST ){
        i++;
    }
    return(i);
}

void displayList(ListPos l){
    for (int i = 0 ; i < lengthList(l) ; i++){
        printf("%c", ELMT_LIST(l,i));
    }
}