find_package(Threads REQUIRED)
#find_package(GMock REQUIRED)
find_package(GTest REQUIRED)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTEST REQUIRED gtest>=1.7.0)
#pkg_check_modules(GMOCK REQUIRED gmock>=1.7.0)

enable_testing()
include_directories(
    ${app_SOURCE_DIR}/lib/inc
    ${app_SOURCE_DIR}/lib
    ${GTEST_INCLUDE_DIRS}
#    ${GMOCK_INCLUDE_DIRS}
)

add_executable(unit_tests
    StringUtil_test.cpp
)

target_link_libraries(unit_tests
    cex
    ${target}
#    GMock::GMock
#    GMock::Main
    GTest::GTest
    GTest::Main
    ${CMAKE_THREAD_LIBS_INIT}
)

gtest_discover_tests(unit_tests)

add_custom_command (
  TARGET unit_tests POST_BUILD
  COMMAND unit_tests --gtest_output=xml:unit_tests.xml
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}
)
