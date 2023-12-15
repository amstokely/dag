#include <utility>
#include "cnpy.h"

/*!
 * @namespace DAG
 * @brief Contains functions for checking if a graph is a DAG.
 * Directed Graph Cycle Detection Using Depth-First Search (DFS) Algorithm
 *
 * This algorithm is designed to detect cycles in a directed graph using DFS and is also capable of determining if
 * the graph is a Directed Acyclic Graph (DAG).
 * It involves two main functions: isCyclic and isDAG.
 *
 * Summary of the Algorithm:
 * 1. Initialization:
 *    - A 'visited' array marks nodes as visited or unvisited.
 *    - An 'inStack' array tracks nodes in the current DFS path for cycle detection.
 *
 * 2. Depth-First Search (DFS):
 *    - The DFS begins at a starting node and uses a stack to track the traversal path.
 *
 * 3. Traversal and Cycle Detection:
 *    - Visited nodes are marked and added to 'inStack'.
 *    - The DFS explores adjacent nodes per the adjacency matrix.
 *    - If an unvisited node is found, DFS goes deeper with that node.
 *
 * 4. Checking for Cycles:
 *    - If a node in 'inStack' is revisited, a cycle is detected, indicating the graph is not acyclic.
 *
 * 5. Backtracking:
 *    - On reaching a dead-end, backtrack by removing the node from 'inStack' and DFS path.
 *    - Continue until all nodes are visited or a cycle is found.
 *
 * 6. Determining Acyclicity (isDAG):
 *    - To check if the graph is a DAG, run cycle detection from each unvisited vertex.
 *    - If any run detects a cycle, the graph is not a DAG.
 *    - If no cycles are found, the graph is a DAG.
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