import networkx as nx
import numpy as np

import dag
import pytest


@pytest.fixture(scope="module")
def matrix_graph_files():
    return dag.data_files("matrix_graphs")


@pytest.fixture(scope="module")
def bitarray_graph_files():
    return [
        file for file in dag.data_files("bitarray_graphs")
    ]


def test_dag_adjacnet_matrix(matrix_graph_files):
    for file in matrix_graph_files:
        adjacency_matrix = np.load(file)
        G = nx.from_numpy_array(adjacency_matrix, create_using=nx.DiGraph)
        assert dag.isDAGAdjacencyMatrix(adjacency_matrix) == nx.is_directed_acyclic_graph(G)


def test_dag_bitarray(bitarray_graph_files):
    control = {
        "two_loop": 0,
        "big_cycle": 0,
        "K4_cycles": 0,
        "binary_tree": 1,
        "disconnected_cycle": 0,
        "binary_tree2": 1,
        "not_a_tree": 0,
        "simple_path": 1,
        "self_loop": 0,
        "no_edges": 1,
        "K4_nocycles": 1,
        "tricycle": 0,
    }
    for file in bitarray_graph_files:
        adjacency_matrix = np.load(file)
        assert dag.isDAGBitArray(adjacency_matrix) == control[file.stem]
