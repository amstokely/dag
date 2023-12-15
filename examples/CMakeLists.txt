
ADD_EXECUTABLE(
        dag
        ${CMAKE_CURRENT_SOURCE_DIR}/bitarray_dag.c
        )
ADD_DEPENDENCIES(dag libdag libgraph_utils)
SET_TARGET_PROPERTIES(
        dag
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
        LINK_LIBRARIES "${DAG_LINK_LIBRARIES}"
        )

ADD_EXECUTABLE(
        numpy_dag
        ${CMAKE_CURRENT_SOURCE_DIR}/numpy_dag.cpp
        )
ADD_DEPENDENCIES(numpy_dag libdag)
SET_TARGET_PROPERTIES(
        numpy_dag
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
        LINK_LIBRARIES "${NUMPY_DAG_LINK_LIBRARIES}"
        )