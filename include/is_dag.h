#include <stdint.h>

#include <utility>
#include "cnpy.h"

int isDAGAdjacencyMatrix(
        const int **adjacencyMatrix,
        int numVertices
);

int isDAGBitArray(
        uint32_t *adjacencyMatrix,
        int numVertices
);

void loadNpy(
        std::string npyFileName,
        int ***a,
        int *m,
        int *n
) {
    cnpy::NpyArray arr = cnpy::npy_load(std::move(npyFileName));
    *m = arr.shape[0];
    *n = arr.shape[1];
    if (!*n) {
        *a = new int *[1];
        *a[0] = new int[*m];
        for (int i = 0; i < *m; ++i) {
            (*(a))[0][i] = arr.data<int>()[i];
        }
    } else {
        *a = new int *[*m];
        for (int i = 0; i < *m; ++i) {
            (*(a))[i] = new int[*n];
            for (int j = 0; j < *n; ++j) {
                (*(a))[i][j] = arr.data<int>()[i * *n + j];
            }
        }
    }
}