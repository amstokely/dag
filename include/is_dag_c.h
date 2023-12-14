//
// Created by astokely on 12/12/23.
//

#ifndef DAG_DAG_H
#define DAG_DAG_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


int is_dag(
        uint32_t digraph[],
        int nVertices
);

#ifdef __cplusplus
}
#endif

#endif //DAG_DAG_H
