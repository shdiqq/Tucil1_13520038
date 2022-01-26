#include "..\header\matrix.h"

void CreateMatrix(int nRow, int nCol, Matrix *m){
    ROWS(*m) = nRow;
    COLS(*m) = nCol;

    for (int i = 0 ; i < ROWS(*m) ; i++){
        for ( int j = 0 ; j < COLS(*m) ; j++){
            ELMT(*m,i,j) = '-';
        }
    }
}

Index getLastIdxRow(Matrix m){
    return(ROWS(m)-1);
}

Index getLastIdxCol(Matrix m){
    return(COLS(m)-1);
}

boolean isIdxEff(Matrix m, Index i, Index j){
    return( (0 <= i && i <= getLastIdxRow(m)) && (0 <= j && j <= getLastIdxCol(m) ) );
}

void displayMatrix(Matrix m){
    for (int i = 0 ; i <= getLastIdxRow(m) ; i++){
        for (int j = 0 ; j <= getLastIdxCol(m) ; j++){
            printf("%c", ELMT(m,i,j));
            
            if (j == getLastIdxCol(m)){
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
}