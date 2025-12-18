# GTest include code for fetch content over the internet 
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
  GIT_SHALLOW    TRUE
  GIT_PROGRESS   TRUE
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

#Testing persons library
add_executable(persons-test persons-test.cc)
target_link_libraries(persons-test
 PRIVATE GTest::gtest_main persons)
gtest_discover_tests(persons-test)

#Testing catalog library
add_executable(catalog-test catalog-test.cc)
target_link_libraries(catalog-test
 PRIVATE GTest::gtest_main catalog)
gtest_discover_tests(catalog-test)

#Testing stage library
add_executable(stage-test stage-test.cc)
target_link_libraries(stage-test
 PRIVATE GTest::gtest_main stage)
gtest_discover_tests(stage-test)

#Testing gclist library
add_executable(gclist-test gclist-test.cc)
target_link_libraries(gclist-test
 PRIVATE GTest::gtest_main gclist catalog stage persons)
gtest_discover_tests(gclist-test)

#Testing counter library
add_executable(counter-test counter-test.cc)
target_link_libraries(counter-test
  PRIVATE GTest::gtest_main counter)
gtest_discover_tests(counter-test)

#Testing irole library
add_executable(irole-test irole-test.cc)
target_link_libraries(irole-test
  PRIVATE GTest::gtest_main persons)
gtest_discover_tests(irole-test)