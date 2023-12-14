
ADD_LIBRARY(
        libdag
        SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/is_dag.cpp
        )
ADD_DEPENDENCIES(libdag cnpy)
SET_TARGET_PROPERTIES(
        libdag
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
        LINK_LIBRARIES ${LIBDAG_LINK_LIBRARIES}
        )

TARGET_INCLUDE_DIRECTORIES(libdag PUBLIC "${INCLUDE_DIRS}")

ADD_LIBRARY(
        libgraph_utils
        SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/graph_utils.c
        )
TARGET_INCLUDE_DIRECTORIES(libgraph_utils PUBLIC "${INCLUDE_DIRS}")
SET_TARGET_PROPERTIES(
        libgraph_utils
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
        )