cmake_minimum_required(VERSION 3.16)
project(OperatorLib LANGUAGES CXX)

add_library(operator_lib STATIC
    src/ops/matmul.cpp
    src/backends/reference/matmul.cpp
)
add_library(operator_lib::operator_lib ALIAS operator_lib)

target_compile_features(operator_lib PUBLIC cxx_std_17)
target_include_directories(operator_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

include(CTest)
if(BUILD_TESTING)
    add_executable(operator_lib_public_headers_test tests/public_headers_test.cpp)
    target_link_libraries(operator_lib_public_headers_test PRIVATE operator_lib::operator_lib)
    add_test(NAME operator_lib.public_headers COMMAND operator_lib_public_headers_test)
endif()
