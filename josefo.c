
#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"
typedef struct node{
    int data;
    struct node *next;
}*tNode;
tNode inicializeNode(int data){
    tNode new = malloc(sizeof(struct node));
    new->data = data; new->next = NULL;
    
    return new;
}
void freeNode(tNode n){
    free(n);
}
struct josefo{
    int *sequence;
    tNode head, tail;
    int lenght, sequenceLenght;
};
int isEmptyJosefo(tJosefo a){
    return a->lenght == 0;
}
tJosefo inicializeJosefo(int N){
    tJosefo new = malloc(sizeof(struct josefo));
    new->sequence = malloc(sizeof(int)*(N-1));
    new->lenght = 0;
    new->sequenceLenght = 0;
    for(int i = 0; i < N; i++, new->lenght++){
        tNode n = inicializeNode(i+1);
        if(isEmptyJosefo(new)){
            new->head = new->tail = n;
        }
        else{
            n->next = new->head;
            new->tail->next = n;
            new->tail = n;
        }
    }
    return new;
}
void evaluateJosefo(tJosefo j, int M){
    if(j->lenght == 1 || j->lenght == 0){
        return;
    }
    else{
        tNode p = j->head, ant = j->tail;
        for(int i = 0; i < M-1; i++){
            ant = p;
            p = p->next;
        }
        ant->next = p->next;
        j->head = p->next;
        j->tail = ant;

        j->sequence[j->sequenceLenght++] = p->data;
        j->lenght --;

        freeNode(p);
        evaluateJosefo(j, M);
    }
}
void printSequence(tJosefo j){
    printf("Sequence:\n");
    for(int i = 0; i < j->sequenceLenght; i++){
        printf("%d ", j->sequence[i]);
    }
    printf("\n");
}
int lider(tJosefo j){
    if(j->lenght == 1)
        return j->head->data;
    else
        return -1;
}
void freeJosefo(tJosefo j){
    free(j->sequence);
    free(j->head);
    free(j);
}