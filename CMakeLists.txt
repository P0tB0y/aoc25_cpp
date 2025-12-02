cmake_minimum_required(VERSION 4.0.0)

project( AoC_2025 
  VERSION 0.1
  LANGUAGES CXX
)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(WARNING_FLAGS -Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic -Wuninitialized -Wshadow -Werror -Wextra-semi 
    -Wimplicit-fallthrough -Wzero-as-null-pointer-constant -Wold-style-cast -Wno-unused-parameter -Wno-missing-braces
)
set(SANITIZER_FLAGS -fsanitize=address,undefined)

set(LIB_HARDENING_FLAGS -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC)
set(RELEASE_HARDENING_FLAGS -fhardened -Whardened)

set(DEBUG_FLAGS -O0 ${LIB_HARDENING_FLAGS} ${WARNING_FLAGS} ${SANITIZER_FLAGS})
set(RELEASE_FLAGS -O3 ${RELEASE_HARDENING_FLAGS} ${WARNING_FLAGS})

add_subdirectory(day_one)
add_subdirectory(day_two)
add_subdirectory(day_three)
add_subdirectory(day_four)
add_subdirectory(day_five)
add_subdirectory(day_six)
add_subdirectory(day_seven)
add_subdirectory(day_eight)
add_subdirectory(day_nine)
add_subdirectory(day_ten)
add_subdirectory(day_eleven)
add_subdirectory(day_twelve)
