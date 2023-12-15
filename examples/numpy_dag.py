from pathlib import Path

import numpy as np
import networkx as nx

from dag import isDAGAdjacencyMatrix as isDAGAdj
from dag import isDAGBitArray as isDAGBitArr
from dag import data_files

matrix_graphs = data_files("matrix_graphs")
bitarray_graphs = data_files("bitarray_graphs")
for graph in matrix_graphs:
    nx_graph = nx.from_numpy_array(np.load(graph), create_using=nx.DiGraph)
    print(graph, isDAGAdj(np.load(graph)), nx.is_directed_acyclic_graph(nx_graph))

for graph in bitarray_graphs:
    print(graph, isDAGBitArr(np.load(graph)))
