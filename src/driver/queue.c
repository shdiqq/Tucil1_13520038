#include "..\header\queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyQueue(Queue q){
    return( IDX_TAIL(q) == IDX_UNDEF && IDX_HEAD(q) == IDX_UNDEF );
}

int lengthQueue(Queue q){
    if ( isEmptyQueue(q) ){
        return(0);
    } else {
        return ( IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

void enqueue(Queue *q, ElType_Queue val){
    if ( isEmptyQueue(*q) ){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    } else {
        if ( IDX_TAIL(*q) == CAPACITY_QUEUE - 1 ) {
            for ( int i = IDX_HEAD(*q) ; i <= IDX_TAIL(*q) ; i++ ){
                q->bufferQueue[i - IDX_HEAD(*q)] = q->bufferQueue[i];
            }
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = IDX_TAIL(*q) - IDX_HEAD(*q);
        }
        int i = IDX_TAIL(*q);
        q->bufferQueue[i+1] = val;
        IDX_TAIL(*q) = IDX_TAIL(*q) + 1; 
    }
}

void dequeue(Queue *q, ElType_Queue *val){
    *val =  HEAD(*q);
    if ( IDX_HEAD(*q) == IDX_TAIL(*q) ){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}