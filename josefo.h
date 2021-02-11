#ifndef JOSEFO
#define JOSEFO

typedef struct josefo* tJosefo;

tJosefo inicializeJosefo(int N);
void evaluateJosefo(tJosefo, int M);
void printSequence(tJosefo);
int lider(tJosefo);
void freeJosefo();
#endif