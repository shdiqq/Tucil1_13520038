#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "charmachine.c"
#include "wordmachine.c"
#include "matrix.c"
#include "listpos.c"
#include "queue.c"

int menu(){
    char inputMenu;

    printf("============ MENU ============\n");
    printf("1. Play World Search Puzzle\n");
    printf("2. Quit Game\n");
    printf("What do you want?\n");
    printf("Input example: 1\n>> ");
    scanf("%[^\n]%*c",&inputMenu);
    
    return(inputMenu);
}

int getCol(Matrix *m){
    int i = 1;
    ELMT(*m,0,i-1) = currentChar;
    adv();

    while ( currentChar != LF ){
        adv();
        i++;
        m->colEff++;
        ELMT(*m,0,i-1) = currentChar;
        adv();
    }
    return(i);
}

int getRow(int Col, Matrix *m){
    int j = 1;
    adv();
    while ( currentChar != LF ){
        for ( int i = 0 ; i < Col ; i++){
            ELMT(*m,j,i) = currentChar;
            adv();
            adv();
        }
        j++;
        m->rowEff++;
    }
    return(j);
}

Matrix makeMatrixPuzzle() {
    boolean isFileFound = false;
    char filePath[] = "../../test/";
    char inputFileName[100];
    int row, col;
    Matrix matPuzzle;
    FILE *f;
    
    // check file valid
    do {
        char filePath[] = "../../test/";
        printf("Enter the file name without typing the extension (make sure the file is in the test folder and has a .txt extension)\n");
        printf("Example : test1 \n>> ");
        scanf("%[^\n]%*c", inputFileName);
        strcat(filePath,inputFileName);
        strcat(filePath, ".txt");
        f = fopen(filePath, "r");
    } while ( f == NULL );    
    startWithFile(f);
    
    // make matrix
    CreateMatrix(1, 1, &matPuzzle);
    col = getCol(&matPuzzle);
    row = getRow(col, &matPuzzle);

    return ( matPuzzle );
}

Queue makeWord() {
    boolean isEndOfFile = false;
    char temp;
    ListPos oneWord;
    Queue q;
    
    CreateQueue(&q);

    while( !isEndOfFile ) {
        copyWordFromFile();

        CreateListPos(&oneWord);

        for ( int i = 0 ; i < currentWord.length ; i++ ){
            ELMT_LIST(oneWord, i) = currentWord.contents[i];
        }

        enqueue(&q, oneWord);

        temp = currentChar;
        adv();
        if ( temp == currentChar ) {
            isEndOfFile = true;
        }
    }
    
    return(q);
}

int checkNorth(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;

    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row - i,col) == ELMT_LIST(list,i) && isIdxEff(m,row - i,col) ){
            ELMT(showWord,row - i ,col) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}

int checkNorthEast(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row - i,col + i) == ELMT_LIST(list,i) && isIdxEff(m,row - i,col + i) ){
            ELMT(showWord,row - i,col + i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}

int checkEast(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 

    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row,col + i) == ELMT_LIST(list,i) && isIdxEff(m,row,col + i) ){
            ELMT(showWord,row,col + i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}
int checkSouthEast(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row + i,col + i) == ELMT_LIST(list,i) && isIdxEff(m,row + i,col + i) ){
            ELMT(showWord,row + i,col + i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}
int checkSouth(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row + i,col) == ELMT_LIST(list,i) && isIdxEff(m,row + i,col) ){
            ELMT(showWord,row + i,col) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}
int checkSouthWest(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row + i,col - i) == ELMT_LIST(list,i) && isIdxEff(m,row + i,col - i) ){
            ELMT(showWord,row + i,col - i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}
int checkWest(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row,col - i) == ELMT_LIST(list,i) && isIdxEff(m,row,col - i) ){
            ELMT(showWord,row,col - i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}
int checkNorthWest(int row, int col, Matrix m, ListPos list){
    int i = 1;
    int z = 0;
    boolean isWord = true;
    Matrix showWord;
    
    CreateMatrix( ROWS(m), COLS(m), &showWord) ;
    ELMT(showWord,row,col) = ELMT_LIST(list,0); 
    
    while ( i < lengthList(list) && isWord ){
        if ( ELMT(m,row - i,col - i) == ELMT_LIST(list,i) && isIdxEff(m,row - i,col - i) ){
            ELMT(showWord,row - i,col - i) = ELMT_LIST(list,i);
            z++;
            i++;
        } else {
            z++;
            isWord = false;
        }
    }
    if ( isWord ){
        printf("Found the word ");
        displayList(list);
        printf("\n");
        displayMatrix(showWord);
    }
    return(z);
}

int getAnswer(Matrix matPuzzle, ListPos list){
    int comparison, tempComparisonNorth, tempComparisonNorthEast, tempComparisonEast, tempComparisonSouthEast, tempComparisonSouth, tempComparisonSouthWwest, tempComparisonWest, tempComparisonNorthWest;
    char temp;

    comparison = 0;
    temp = ELMT_LIST(list, 0);
    for ( int i = 0 ; i <= getLastIdxRow(matPuzzle) ; i++ ){
        for ( int j = 0 ; j <= getLastIdxCol(matPuzzle) ; j++ ) {
            if ( ELMT(matPuzzle,i,j) == temp ){
                tempComparisonNorth = checkNorth(i,j,matPuzzle,list);
                tempComparisonNorthEast = checkNorthEast(i,j,matPuzzle,list);
                tempComparisonEast = checkEast(i,j,matPuzzle,list);
                tempComparisonSouthEast = checkSouthEast(i,j,matPuzzle,list);
                tempComparisonSouth = checkSouth(i,j,matPuzzle,list);
                tempComparisonSouthWwest = checkSouthWest(i,j,matPuzzle,list);
                tempComparisonWest = checkWest(i,j,matPuzzle,list);
                tempComparisonNorthWest = checkNorthWest(i,j,matPuzzle,list);
                comparison = comparison + tempComparisonNorth + tempComparisonNorthEast + tempComparisonEast + tempComparisonSouthEast + tempComparisonSouth + tempComparisonSouthWwest + tempComparisonWest + tempComparisonNorthWest;
            } else {
                comparison = comparison + 1;
            }
        }
    }
    printf("Comparison as much as %d to find the word above\n\n",comparison);
    return(comparison);
}

void proccessAnswer(Matrix matPuzzle, Queue q){
    int sumComparison;
    float tempComparison;
    ListPos tempWord;

    sumComparison = 0;

    clock_t begin = clock();
    while ( !isEmptyQueue(q) ){
        tempComparison = 0;
        dequeue(&q, &tempWord);
        tempComparison = getAnswer(matPuzzle, tempWord);
        sumComparison = sumComparison + tempComparison;
    }
    clock_t end = clock();
    float time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The program execution time is %.2f seconds\n",time_spent);
    printf("The number of comparisons of all letters made to find all the words in the puzzle is %d comparison\n",sumComparison);
}

int main() {

    char menuInput;
    boolean isQuit = false;
    boolean isFirstStart = true;
    Matrix matPuzzle;
    Queue listWord;

    while ( !isQuit ){
        // intro
        if ( isFirstStart ){
            printf("Welcome to World Search Puzzle\n");
            menuInput = menu();
            isFirstStart = false;
        } else {
            menuInput = menu();
        }

        if ( menuInput == '1' ) {
            // make matrix puzzle
            matPuzzle = makeMatrixPuzzle();

            // make list word that use to play the games
            adv();
            listWord = makeWord();

            // solve the problem
            printf("Here are all the words found in the puzzle.\n\n");
            proccessAnswer(matPuzzle, listWord);

        } else if ( menuInput == '2' ) {
            isQuit = true;
        } else {
            printf("Your input is wrong! Please re-enter.\n");
        }
    }

    return(0);
}