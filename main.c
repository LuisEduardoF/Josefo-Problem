#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "josefo.h"

int main(int argc, char* argv[]){
    tJosefo p = inicializeJosefo(atoi(argv[1]));
    evaluateJosefo(p, atoi(argv[2]));
    printSequence(p);
    printf("Lider = %d\n", lider(p));
    freeJosefo(p);
}