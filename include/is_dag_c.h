//
// Created by astokely on 12/12/23.
//

#ifndef DAG_DAG_H
#define DAG_DAG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    /*!
     * @brief C wrapper for isDAGBitArray, which allows isDAGBitArray to be called from C.
     *
     * @param 1D array of 32-bit unsigned integers representing the adjacency matrix. Each value's bit string
     * represents a row of the adjacency matrix. The bit string of the value at index i represents the
     * ith row of the adjacency matrix.
     *
     * @param nVertices The number of vertices in the graph
     *
     * @return 1 if the graph is a DAG, 0 otherwise
     */
int is_dag(
        uint32_t digraph[],
        int nVertices
);

#ifdef __cplusplus
}
#endif

#endif //DAG_DAG_H
