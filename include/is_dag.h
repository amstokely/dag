#include <utility>
#include "cnpy.h"

/*!
 * @namespace DAG
 * @brief Contains functions for checking if a graph is a DAG.
 */
namespace DAG {
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
 * @brief Checks for a cycle in a directed graph using Depth-First Search.
 *
 * @param startNode The starting node for DFS.
 *
 * @param adjacencyMatrix A 2D array representing the adjacency matrix of the graph.
 *
 * @param visited An array to keep track of visited nodes.
 *
 * @param numVertices The number of vertices in the graph.
 *
 * @return Returns 1 if a cycle is found, 0 otherwise.
 */
    int isCyclicAdjacencyMatrix(
            int startNode,
            const int **adjacencyMatrix,
            int *visited,
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
 * @breaf Checks for a cycle in a directed graph using Depth-First Search and a bit array for the adjacency matrix.
 *
 * @param startNode The starting node for DFS.
 * @param adjacencyMatrix A bit array representing the adjacency matrix of the graph.
 * @param visited An array to keep track of visited nodes.
 * @param numVertices The number of vertices in the graph.
 * @return Returns 1 if a cycle is found, 0 otherwise.
 */
    int isCyclicBitarray(
            int startNode,
            const uint32_t *adjacencyMatrix,
            int *visited,
            int numVertices
    );

/*!
 * @brief Loads a numpy int32 array from a numpy binary file.
 *
 * @param npyFileName Full path to the numpy binary file. Make sure that the array saved
 * in the numpy binary file is of type int32.
 *
 * @param a Stores the loaded numpy array. Since memory for the array is allocated in this function, and the
 * array may be either 1D or 2D, 'a' is required to be a triple pointer. The array is stored in row-major order.
 *
 * @param m Stores the number of rows in the numpy array. If the numpy array is 1D, then m is set to 1.
 *
 * @param n Stores the number of columns in the numpy array.
 */
    void loadNpy(
            std::string npyFileName,
            int ***a,
            int *m,
            int *n
    );
}