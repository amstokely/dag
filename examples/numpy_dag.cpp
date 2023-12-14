//
// Created by astokely on 12/14/23.
//
#include "is_dag.h"
#include <filesystem>

int main() {
    int n, m;
    int **a;
    std::string path = "/home/astokely/CLionProjects/dag/numpy_test_graphs/bitarray_graphs";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::cout
                << entry.path()
                << " ";
        loadNpy(
                entry.path(),
                &a,
                &m,
                &n
        );
        // print a

        std::cout
                <<
                isDAGBitArray(
                        (uint32_t
                        *) a[0],
                        m
                )
                <<
                std::endl;
        if (n) {
            for (
                    int i = 0;
                    i < m;
                    i++) {
                delete[] a[i];
            }
            delete[]
                    a;
        } else {
            delete[]
                    a[0];
            delete[]
                    a;
        }
    }
    path = "/home/astokely/CLionProjects/dag/numpy_test_graphs/matrix_graphs";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::cout
                << entry.path()
                << " ";
        loadNpy(
                entry.path(),
                &a,
                &m,
                &n
        );

        std::cout
                <<
                isDAGAdjacencyMatrix(
                        (const int
                        **) a,
                        m

                )
                <<
                std::endl;
        if (n) {
            for (
                    int i = 0;
                    i < m;
                    i++) {
                delete[] a[i];
            }
            delete[]
                    a;
        } else {
            delete[]
                    a[0];
            delete[]
                    a;
        }
    }
    return 0;
}
