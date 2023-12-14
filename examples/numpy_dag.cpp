//
// Created by astokely on 12/14/23.
//
#include "is_dag.h"
#include <filesystem>


/*!
 * @breaf Iterates through all NumPy adjacency matrix files in the numpy_test_graphs directory
 * and prints whether each graph is a DAG. The adjacency matrix files are loaded using the
 * cnpy library, which allows you to load NumPy .npy binary files into C++.
 *
 * @param argv[1] The path to the numpy_test_graphs directory.
 * @type char*
 */
int main(
        int argc,
        const char **argv
) {
    /* Check that the path to the numpy_test_graphs directory was provided */
    if (argc <= 1) {
        throw std::runtime_error("Please provide the path to the numpy_test_graphs directory.");
    }
    /*n and m will store the number or rows and columns of the adjacency matrix, respectively*/
    int n, m;
    /*a will store the adjacency matrix*/
    int **a;
    std::string path = std::string(argv[1]);
    /* Iterate through all files in the numpy_test_graphs directory */
    for (const auto &entry: std::filesystem::directory_iterator(path)) {
        std::cout
                << entry.path()
                << " ";
        /* The first argument is the adjacency matrix .npy file path, the second argument is a pointer to
         * the adjacency matrix variable, a, the third argument is a pointer to the number variable that
         * stores the number of rows, m, and the fourth argument is a pointer to the number variable that
         * stores the number of columns, n. */
        loadNpy(
                entry.path(),
                &a,
                &m,
                &n
        );
        /* Print whether the graph is a DAG */
        std::string isDAG = isDAGAdjacencyMatrix(
                (const int
                **) a,
                m
        ) ? "Graph is a DAG" : "Graph is not a DAG";
        std::cout
                << isDAG
                <<
                std::endl;
        /* Free the memory allocated for the adjacency matrix */
        for (
                int i = 0;
                i < m;
                i++) {
            delete[] a[i];
        }
        delete[] a;
        return 0;
    }
}