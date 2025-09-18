#include "rna_transcription.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna){
    char *rna = malloc(sizeof(char) * strlen(dna));
    if(rna == NULL){
        fprintf(stderr, "Unable to allocate storage\n");
    }
    for(size_t i = 0; i < strlen(dna); i++){
        switch(dna[i]){
            case 'C' : rna[i] = 'G';
                        break;
            case 'G' : rna[i] = 'C';
                        break;
            case 'T' : rna[i] = 'A';
                        break;
            case 'A' : rna[i] = 'U';
        }
    }
    return rna;
}