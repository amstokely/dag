
// Created by astokely on 12/12/23.
//

#include <algorithm>
#include "is_dag.h"
#include "is_dag_c.h"

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
) {
    // Array to keep track of nodes in the current DFS stack.
    auto inStack = new int[numVertices];
    std::fill_n(
            inStack,
            numVertices,
            0
    ); // Initialize all elements to 0.

    int dfsStackSize = 0; // Current size of the DFS stack.
    auto dfsStack = new int[numVertices]; // Stack for DFS traversal.
    dfsStack[0] = startNode; // Start DFS from the startNode.
    dfsStackSize++;
    visited[startNode] = 1; // Mark startNode as visited.
    inStack[startNode] = 1; // Add startNode to the DFS stack.

    // Continue DFS until the stack is empty.
    while (dfsStackSize > 0) {
        int node = dfsStack[dfsStackSize -
                            1]; // Current node to process.
        int hasUnvisitedChild = 0; // Flag for unvisited child nodes.

        // Iterate over all vertices to find unvisited adjacent nodes.
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[node][i] != 0 && !visited[i]) {
                // Found an unvisited adjacent node. Push it to the stack.
                dfsStack[dfsStackSize] = i;
                dfsStackSize++;
                visited[i] = 1; // Mark as visited.
                inStack[i] = 1; // Add to DFS stack.
                hasUnvisitedChild = 1; // Set flag for unvisited child.
                break;
            } else if (adjacencyMatrix[node][i] != 0 && inStack[i]) {
                // Found a back edge indicating a cycle.
                delete[] dfsStack;
                return 1; // Cycle detected.
            }
        }

        // If no unvisited child, pop the current node from the stack.
        if (!hasUnvisitedChild) {
            inStack[node] = 0; // Remove from DFS stack.
            dfsStackSize--; // Decrease stack size.
        }
    }

    // Clean up and return 0 as no cycle was found.
    delete[] dfsStack;
    return 0;
}

/*!
 * @breaf Checks whether a directed graph is a Directed Acyclic Graph (DAG).
 * This function iterates through all vertices and uses Depth-First Search
 * to check for cycles. A graph is a DAG if there are no cycles.
 *
 * @param adjacencyMatrix A 2D array representing the adjacency matrix of the graph.
 * @param numVertices The number of vertices in the graph.
 * @return Returns 1 if the graph is a DAG (no cycles), 0 otherwise.
 */
int isDAGAdjacencyMatrix(
        const int **adjacencyMatrix,
        int numVertices
) {
    // Array to keep track of visited nodes.
    auto visited = new int[numVertices];
    std::fill_n(
            visited,
            numVertices,
            0
    ); // Initialize all elements to 0.

    // Iterate over each vertex in the graph.
    for (int i = 0; i < numVertices; i++) {
        // If the vertex is not visited, start a DFS from this vertex.
        if (!visited[i]) {
            // Check for a cycle starting from the current vertex.
            if (isCyclicAdjacencyMatrix(
                    i,
                    adjacencyMatrix,
                    visited,
                    numVertices
            )) {
                // If a cycle is found, the graph is not a DAG.
                return 0;
            }
        }
    }

    // If no cycles are found in any DFS, the graph is a DAG.
    return 1;
}


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
) {
    auto inStack = new int[numVertices]; // Array to keep track of nodes in the current DFS stack.
    std::fill_n(
            inStack,
            numVertices,
            0
    ); // Initialize all elements to 0.

    int dfsStackSize = 0; // Current size of the DFS stack.
    auto dfsStack = new int[numVertices]; // Stack for DFS traversal.
    dfsStack[0] = startNode; // Start DFS from the startNode.
    dfsStackSize++;
    visited[startNode] = 1; // Mark startNode as visited.
    inStack[startNode] = 1; // Add startNode to the DFS stack.

    while (dfsStackSize > 0) {
        int node = dfsStack[dfsStackSize -
                            1]; // Current node to process.
        int hasUnvisitedChild = 0; // Flag for unvisited child nodes.
        auto nodeEdges = new unsigned int[numVertices]; // Stores the bitarray for the current node,
        // which represents its edges.

        // Convert each bitarray value to an array of 32 bits. Each bit represents an edge, and each
        // value in the bitarray represents a row of the adjacency matrix.
        for (int i = 0; i < numVertices; i++) {
            unsigned int val = ((adjacencyMatrix[node]
                    >> i) & 1);
            nodeEdges[i] = val;
        }

        // Iterate over all vertices to find unvisited adjacent nodes.
        for (int i = 0; i < numVertices; ++i) {
            if (nodeEdges[i] != 0 && !visited[i]) {
                // Found an unvisited adjacent node. Push it to the stack.
                dfsStack[dfsStackSize] = i;
                dfsStackSize++;
                visited[i] = 1; // Mark as visited.
                inStack[i] = 1; // Add to DFS stack.
                hasUnvisitedChild = 1; // Set flag for unvisited child.
                break;
            } else if (nodeEdges[i] != 0 && inStack[i]) {
                // Found a back edge indicating a cycle.
                delete[] nodeEdges;
                delete[] dfsStack;
                return 1; // Cycle detected.
            }
        }
        delete[] nodeEdges; // Clean up the adjacency array.

        // If no unvisited child, pop the current node from the stack.
        if (!hasUnvisitedChild) {
            inStack[node] = 0; // Remove from DFS stack.
            dfsStackSize--; // Decrease stack size.
        }
    }

    // Clean up and return 0 as no cycle was found.
    delete[] dfsStack;
    return 0;
}


/**
 * Checks whether a directed graph is a Directed Acyclic Graph (DAG) using a bit array for the adjacency matrix.
 *
 * This function iterates through all vertices and uses Depth-First Search
 * to check for cycles. A graph is a DAG if there are no cycles.
 *
 * @param adjacencyMatrix A bit array representing the adjacency matrix of the graph.
 * @param numVertices The number of vertices in the graph.
 * @return Returns 1 if the graph is a DAG (no cycles), 0 otherwise.
 */
int isDAGBitArray(
        uint32_t *adjacencyMatrix,
        int numVertices
) {
    auto visited = new int[numVertices]; // Array to keep track of visited nodes.
    std::fill_n(visited, numVertices, 0); // Initialize all elements to 0.

    // Iterate over each vertex in the graph.
    for (int i = 0; i < numVertices; i++) {
        // If the vertex is not visited, start a DFS from this vertex.
        if (!visited[i]) {
            // Check for a cycle starting from the current vertex.
            if (isCyclicBitarray(
                    i,
                    adjacencyMatrix,
                    visited,
                    numVertices
            )) {
                // If a cycle is found, the graph is not a DAG.
                return 0;
            }
        }
    }

    // If no cycles are found in any DFS, the graph is a DAG.
    return 1;
}


/*!
 * @brief C wrapper for isDAGAdjacencyMatrix, which allows isDAGAdjacencyMatrix to be called from C.
 *
 * @param adjacencyMatrix A 2D array representing the adjacency matrix of the graph.
 * @param numVertices The number of vertices in the graph.
 * @return Returns 1 if the graph is a DAG (no cycles), 0 otherwise.
 */
int is_dag(
        uint32_t digraph[],
        int n_vertices
) {
    return isDAGBitArray(
            digraph,
            n_vertices
    );
}


