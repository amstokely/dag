
// Created by astokely on 12/12/23.
//

#include <algorithm>
#include "is_dag.h"
#include "is_dag_c.h"

int isCyclicAdjacencyMatrix(
        int startNode,
        const int **adjacencyMatrix,
        int *visited,
        int numVertices
) {
    auto inStack = new int[numVertices];
    std::fill_n(inStack, numVertices, 0);
    int dfsStackSize = 0;
    auto dfsStack = new int[numVertices];
    dfsStack[0] = startNode;
    dfsStackSize++;
    visited[startNode] = 1;
    inStack[startNode] = 1;

    while (dfsStackSize > 0) {
        int node = dfsStack[dfsStackSize - 1];
        int hasUnvisitedChild = 0;
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[node][i] != 0 && !visited[i]) {
                dfsStack[dfsStackSize] = i;
                dfsStackSize++;
                visited[i] = 1;
                inStack[i] = 1;
                hasUnvisitedChild = 1;
                break;
            } else if (adjacencyMatrix[node][i] != 0 && inStack[i]) {
                // Cycle found
                delete[] dfsStack;
                return 1;
            }
        }
        if (!hasUnvisitedChild) {
            inStack[node] = 0;
            dfsStackSize--;
        }
    }

    delete[] dfsStack;
    return 0;
}


int isDAGAdjacencyMatrix(
        const int **adjacencyMatrix,
        int numVertices
) {
    auto visited = new int[numVertices];
    std::fill_n(visited, numVertices, 0);

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && isCyclicAdjacencyMatrix(
                i,
                adjacencyMatrix,
                visited,
                numVertices
        ))
            return 0;
    }
    return 1;
}

int isCyclicBitarray(
        int startNode,
        const uint32_t *adjacencyMatrix,
        int *visited,
        int numVertices
) {
    auto inStack = new int[numVertices];
    std::fill_n(inStack, numVertices, 0);
    int dfsStackSize = 0;
    auto dfsStack = new int[numVertices];
    dfsStack[0] = startNode;
    dfsStackSize++;
    visited[startNode] = 1;
    inStack[startNode] = 1;

    while (dfsStackSize > 0) {
        int node = dfsStack[dfsStackSize - 1];
        int hasUnvisitedChild = 0;
        auto arr = new unsigned int[32];
        for (int i = 0; i < sizeof(int) * 8; i++) {
            unsigned int val = ((adjacencyMatrix[node]
                    >> i) & 1);
            arr[i] = val;
        }
        for (int i = 0; i < numVertices; ++i) {
            if (arr[i] != 0 && !visited[i]) {
                dfsStack[dfsStackSize] = i;
                dfsStackSize++;
                visited[i] = 1;
                inStack[i] = 1;
                hasUnvisitedChild = 1;
                break;
            } else if (arr[i] != 0 && inStack[i]) {
                // Cycle found
                delete[] arr;
                delete[] dfsStack;
                return 1;
            }
        }
        delete[] arr;

        if (!hasUnvisitedChild) {
            inStack[node] = 0;
            dfsStackSize--;
        }
    }

    delete[] dfsStack;
    return 0;
}


int isDAGBitArray(
        uint32_t *adjacencyMatrix,
        int numVertices
) {
    auto visited = new int[numVertices];
    std::fill_n(visited, numVertices, 0);

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && isCyclicBitarray(
                i,
                adjacencyMatrix,
                visited,
                numVertices
        ))
            return 0;
    }
    return 1;
}

int is_dag(
        uint32_t digraph[],
        int n_vertices
) {
    return isDAGBitArray(
            digraph,
            n_vertices
    );
}


