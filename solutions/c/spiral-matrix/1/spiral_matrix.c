#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int size) {
    spiral_matrix_t *mat = malloc(sizeof *mat);
    mat->size = size;
    if (size == 0) { return mat; }
    
    mat->matrix = malloc(sizeof(int *) * size);
    for(int i = 0; i < size; i++) {
        mat->matrix[i] = calloc(size, sizeof(int));
    }

    int x = 0, y = 0;
    int dx = 0, dy = 1;
    
    for (int i = 1; i <= size * size; i++) {
        mat->matrix[x][y] = i;
        int nx = x + dx;
        int ny = y + dy;
        if (!(nx >= 0 && nx < size && ny >= 0 && ny < size && mat->matrix[nx][ny] == 0)) {
            int t = -dx;
            dx = dy;
            dy = t;
        }
        x += dx;
        y += dy;
    }    
    return mat;
}

void spiral_matrix_destroy(spiral_matrix_t* mat) {
    for (int i = 0; i < mat->size; i++) {
        free(mat->matrix[i]);
        mat->matrix[i] = NULL;
    }
    free(mat->matrix);
    mat->matrix = NULL;
    free(mat);
    mat = NULL;  
}