#include "gtest/gtest.h"
#include "is_dag.h"
#include <map>

TEST(DAG_test,
     DAG_MatrixGraphs) {
    std::map<std::string, int> graphs = {
            {"data/graph_730_102.npy", 1},
            {"data/graph_726_718.npy", 0},
            {"data/graph_516_119.npy", 1},
            {"data/graph_203_770.npy", 0},
            {"data/graph_378_906.npy", 1},
            {"data/graph_276_484.npy", 0},
            {"data/graph_128_585.npy", 0},
            {"data/graph_861_525.npy", 0},
            {"data/graph_423_562.npy", 1},
            {"data/graph_606_315.npy", 1},
    };
    for (auto const &graph: graphs) {
        int **adjacencyMatrix;
        int numVertices;
        DAG::loadNpy(
                graph.first,
                &adjacencyMatrix,
                &numVertices,
                &numVertices
        );
        std::cout << graph.first << std::endl;
        EXPECT_EQ(
                DAG::isDAGAdjacencyMatrix(
                        (const int **) adjacencyMatrix,
                        numVertices
                ),
                graph.second
        );
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
}

TEST(DAG_test,
     DAG_BitArrayGraphs) {
    std::map<std::string, int> graphs = {
                    {"data/two_loop.npy", 0},
                    {"data/big_cycle.npy", 0},
                    {"data/K4_cycles.npy", 0},
                    {"data/binary_tree.npy", 1},
                    {"data/disconnected_cycle.npy", 0},
                    {"data/binary_tree2.npy", 1},
                    {"data/not_a_tree.npy", 0},
                    {"data/simple_path.npy", 1},
                    {"data/self_loop.npy", 0},
                    {"data/no_edges.npy", 1},
                    {"data/K4_nocycles.npy", 1},
                    {"data/tricycle.npy", 0},
    };
    for (auto const &graph: graphs) {
        int **adjacencyMatrix;
        int m, n;
        DAG::loadNpy(
                graph.first,
                &adjacencyMatrix,
                &m,
                &n
        );
        int numVertices = m;
        EXPECT_EQ(
                DAG::isDAGBitArray(
        ((uint32_t *)adjacencyMatrix[0]),
                        numVertices
                ),
                graph.second
        );
        delete[] adjacencyMatrix[0];
        delete[] adjacencyMatrix;
    }
}

int main(
        int argc,
        char **argv
) {
    ::testing::InitGoogleTest(
            &argc,
            argv
    );
    return RUN_ALL_TESTS();
}