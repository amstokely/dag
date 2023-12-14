 FIND_PACKAGE(SWIG REQUIRED)
 INCLUDE(${SWIG_USE_FILE})

 FIND_PACKAGE(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
 SET(
         PYTHON_LIBDAG_INCLUDE_DIRS
         ${INCLUDE_DIRS}
         ${Python3_INCLUDE_DIRS}
         ${Python3_NumPy_INCLUDE_DIRS}
         )

 SET_SOURCE_FILES_PROPERTIES(
         ${CMAKE_CURRENT_SOURCE_DIR}/python_dag.i
         PROPERTIES
         CPLUSPLUS ON
         MODULE_NAME dag
         INCLUDE_DIRECTORIES "${PYTHON_LIBDAG_INCLUDE_DIRS}"
         )
 SWIG_ADD_LIBRARY(
         libpython_dag
         LANGUAGE python
         OUTPUT_DIR ${CMAKE_SOURCE_DIR}/python/dag
         OUTFILE_DIR ${CMAKE_SOURCE_DIR}/python/dag
         SOURCES ${CMAKE_SOURCE_DIR}/swig/python_dag.i
         )
 TARGET_INCLUDE_DIRECTORIES(libpython_dag PUBLIC
                            "${PYTHON_LIBDAG_INCLUDE_DIRS}"
                            )
 ADD_DEPENDENCIES(libpython_dag libdag)
 SET_TARGET_PROPERTIES(
         libpython_dag
         PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/dag
         LINK_LIBRARIES "${PYTHON_LIBDAG_LINK_LIBRARIES}"
         )
 SET(PIP_UNINSTALL_PIP_ARGS "uninstall" "dag" "-y")
 SET(PYTHON_PIP_INSTALL_ARGS "setup.py" "install")
 ADD_CUSTOM_TARGET(PythonInstall
                   COMMAND pip ${PIP_UNINSTALL_PIP_ARGS}
                   COMMAND ${Python3_EXECUTABLE} ${PYTHON_PIP_INSTALL_ARGS}
                   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/python
                   )

