
SET_SOURCE_FILES_PROPERTIES(
        ${CMAKE_CURRENT_SOURCE_DIR}/python_dag.i
        PROPERTIES
        CPLUSPLUS ON
        MODULE_NAME dag
        )
SWIG_ADD_LIBRARY(
        libpython_dag
        LANGUAGE python
        OUTPUT_DIR ${CMAKE_SOURCE_DIR}/python/dag
        OUTFILE_DIR ${CMAKE_SOURCE_DIR}/python/dag
        SOURCES ${CMAKE_SOURCE_DIR}/swig/python_dag.i
        )
ADD_DEPENDENCIES(libpython_dag libdag)
SET_TARGET_PROPERTIES(
        libpython_dag
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/dag
        LINK_LIBRARIES "${PYTHON_LIBDAG_LINK_LIBRARIES}"
        )
