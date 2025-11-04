#include "protein_translation.h"

#include <stdio.h>

void helper_fill(protein_t* protein_ptr, amino_acid_t aa){
    if (protein_ptr->count < MAX_AMINO_ACIDS){
        protein_ptr->amino_acids[protein_ptr->count] = aa;
        protein_ptr->count++;
    }
}

protein_t protein(const char *const rna){
    protein_t result;
    result.valid = false;
    result.count = 0;

    bool stop_seen = false;
    bool invalid_string = false;

    const size_t len = strlen(rna);
    
    if (len == 0){
        result.valid = true;
        return result;
    }

    char snippet[4] = {'\0'};
    
    for (size_t i = 0; i < len; i++){
        snippet[i % 3] = rna[i];
        if ((i + 1) % 3 == 0){
            if (!strcmp(snippet, "AUG")){
                helper_fill(&result, Methionine);
            } else if (!strcmp(snippet, "UUU") || !strcmp(snippet, "UUC")){
                helper_fill(&result, Phenylalanine);
            } else if (!strcmp(snippet, "UUA") || !strcmp(snippet, "UUG")){
                helper_fill(&result, Leucine);
            } else if (!strcmp(snippet, "UCU") || !strcmp(snippet, "UCC") || !strcmp(snippet, "UCA") || !strcmp(snippet, "UCG")){
                helper_fill(&result, Serine);
            } else if (!strcmp(snippet, "UAU") || !strcmp(snippet, "UAC")){
                helper_fill(&result, Tyrosine);
            } else if (!strcmp(snippet, "UGU") || !strcmp(snippet, "UGC")){
                helper_fill(&result, Cysteine);
            } else if (!strcmp(snippet, "UGG")){
                helper_fill(&result, Tryptophan);
            } else if (!strcmp(snippet, "UAA") || !strcmp(snippet, "UAG") || !strcmp(snippet, "UGA")){
                stop_seen = true;
                break;
            } else {
                invalid_string = true;
                break;
            }
        }
    }
    
    result.valid = !invalid_string && ((len % 3 == 0) || stop_seen); 
    
    return result;
}