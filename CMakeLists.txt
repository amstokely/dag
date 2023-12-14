CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

set(CMAKE_BUILD_TYPE Release)

PROJECT(dag LANGUAGES CXX C)

SET(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
SET(
        INCLUDE_DIRS
        ${Python3_INCLUDE_DIRS}
        ${Python3_NumPy_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/include
        )

INCLUDE_DIRECTORIES("${INCLUDE_DIRS}")

SET_SOURCE_FILES_PROPERTIES(
        ${CMAKE_SOURCE_DIR}/swig/python_dag.i
        PROPERTIES
        CPLUSPLUS ON
        )

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

ADD_LIBRARY(
        dag
        SHARED
        ${CMAKE_SOURCE_DIR}/src/is_dag.cpp
        )
SET_TARGET_PROPERTIES(
        dag
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
        )

LINK_LIBRARIES(dag)

ADD_LIBRARY(
        graph_utils
        SHARED
        ${CMAKE_SOURCE_DIR}/src/graph_utils.c
        )
SET_TARGET_PROPERTIES(
        graph_utils
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
        )

SWIG_ADD_LIBRARY(
        python_dag
        LANGUAGE python
        OUTPUT_DIR ${CMAKE_SOURCE_DIR}/python
        OUTFILE_DIR ${CMAKE_SOURCE_DIR}/python
        SOURCES ${CMAKE_SOURCE_DIR}/swig/python_dag.i
        )
SET_TARGET_PROPERTIES(
        python_dag
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python
        )

LINK_LIBRARIES(graph_utils)
ADD_EXECUTABLE(
        main
        ${CMAKE_SOURCE_DIR}/main.c
        )
SET_TARGET_PROPERTIES(
        main
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
        )