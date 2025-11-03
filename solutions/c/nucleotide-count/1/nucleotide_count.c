#include "nucleotide_count.h"

char *count(const char *dna_strand){
    int nucl[4] = {0, 0, 0, 0};
    char *report = calloc(5 * 4, sizeof(char));
    
    if (!report) return NULL;
    
    if (dna_strand[0] == '\0') {
        sprintf(report, "A:0 C:0 G:0 T:0");
        return report;
    }
    
    for (size_t i = 0; *(dna_strand + i) != '\0'; i++){
        char c = *(dna_strand + i);
        switch(c) {
                case 'A': nucl[0]++; break;
                case 'C': nucl[1]++; break;
                case 'G': nucl[2]++; break;
                case 'T': nucl[3]++; break;
                default: return report;  // report = ""; (invalid)
        }
    }
    
    sprintf(report, "A:%d C:%d G:%d T:%d", nucl[0], nucl[1], nucl[2], nucl[3]);
    return report;
}