#include <utility>
#include "cnpy.h"

/*!
 * @brief Checks if the given adjacency matrix, which is stored as a 2D array,
 * represents a DAG.
 *
 * @param adjacencyMatrix A 2D array that represents the adjacency matrix of a graph.
 *
 * @param numVertices The number of vertices in the graph.
 */
int isDAGAdjacencyMatrix(
        const int **adjacencyMatrix,
        int numVertices
);

/*!
 * @brief Checks if the given adjacency matrix, which is stored as a 1D
 * int32 bit array, represents a DAG.
 *
 * @param adjacencyMatrix A 1D int32 bit array that represents the adjacency matrix of a graph. The bit string
 * of each value represents a row of the adjacency matrix. The bit string of the value at index i represents the
 * ith row of the adjacency matrix.
 *
 * @param numVertices The number of vertices in the graph.
 */
int isDAGBitArray(
        uint32_t *adjacencyMatrix,
        int numVertices
);

/*!
 * @brief Loads a numpy int32 array from a numpy binary file.
 * @param npyFileName Full path to the numpy binary file. Make sure that the array saved
 * in the numpy binary file is of type int32.
 * @param a Stores the loaded numpy array. Since memory for the array is allocated in this function, and the
 * array may be either 1D or 2D, 'a' is required to be a triple pointer. The array is stored in row-major order.
 * @param m Stores the number of rows in the numpy array. If the numpy array is 1D, then m is set to 1.
 * @param n Stores the number of columns in the numpy array.
 */
void loadNpy(
        std::string npyFileName,
        int ***a,
        int *m,
        int *n
) {
    /* Load the numpy array */
    cnpy::NpyArray arr = cnpy::npy_load(std::move(npyFileName));
    /* Set the number of rows and columns equal to m and n, respectively */
    *m = arr.shape[0];
    *n = arr.shape[1];
    /* If the numpy array is 1D, then set m to 1 and copy arr to 'a' in row-major order */
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