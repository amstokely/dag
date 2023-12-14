%{
#include <stdint.h>
%}

%inline %{
    int isDAGBitArray(
            int *IN_ARRAY1,
            int DIM1
    ) {
        auto diagraph = new uint32_t[DIM1];
        for (int i = 0; i < DIM1; ++i) {
            diagraph[i] = IN_ARRAY1[i];
        }
        int result = isDAGBitArray(
                diagraph,
                DIM1
        );
        delete[] diagraph;
        return result;
    }
%}


%inline %{
int isDAGAdjacencyMatrix(
        int *IN_ARRAY2,
        int DIM1,
        int DIM2
) {
    int **adjacencyMatrix = new int *[DIM1];
    for (int i = 0; i < DIM1; ++i) {
        adjacencyMatrix[i] = new int[DIM2];
        for (int j = 0; j < DIM2; ++j) {
            adjacencyMatrix[i][j] = IN_ARRAY2[i * DIM2 + j];
        }
    }
    int result = isDAGAdjacencyMatrix(
            (const int **) adjacencyMatrix,
            DIM1
    );
    for (int i = 0; i < DIM1; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
    return result;
}
%}
