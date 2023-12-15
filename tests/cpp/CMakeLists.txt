
  SET(DAG_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR})

  SET(DAG_TEST_LINK_LIBRARIES
          libdag
          gtest
          )

  ADD_EXECUTABLE(
          DAG_test
          ${DAG_TEST_DIR}/DAG_test.cpp
          )
  ADD_DEPENDENCIES(DAG_test libdag)
  SET_TARGET_PROPERTIES(
          DAG_test
          PROPERTIES
          LINK_LIBRARIES "${DAG_TEST_LINK_LIBRARIES}"
          )
  ADD_TEST(
          NAME DAG_MatrixGraphs
          COMMAND DAG_test --gtest_filter=*DAG_MatrixGraphs*
          WORKING_DIRECTORY ${DAG_TEST_DIR}
          )

  ADD_TEST(
          NAME DAG_BitArrayGraphs
          COMMAND DAG_test --gtest_filter=*DAG_BitArrayGraphs*
          WORKING_DIRECTORY ${DAG_TEST_DIR}
          )
