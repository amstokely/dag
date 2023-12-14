#include <stdio.h>
#include <stdlib.h>
#include "graph_utils.h"
#include "is_dag_c.h"



int main(
        int argc,
        const char **argv
) {
    int i;

    if (argc <= 1) {
        fprintf(
                stderr,
                "\nUsage: is_dag <digraph file>+\n\n"
        );
        return 1;
    }

    for (i = 1; i < argc; i++) {
        uint32_t *digraph;
        int n_vertices;

        if (read_graph(
                argv[i],
                &digraph,
                &n_vertices
        )) {
            fprintf(
                    stderr,
                    "Error reading digraph from file %s\n",
                    argv[i]
            );
            return 1;
        }
        //is_dag(digraph, n_vertices) ? printf("1\n") : printf("0\n");
        for (int j = 0; j < n_vertices; ++j) {
            printf("%u ", digraph[j]);
        }
        printf("\n");
        free(digraph);
    }

    return 0;
}

