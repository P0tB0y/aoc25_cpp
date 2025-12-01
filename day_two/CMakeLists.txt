cmake_minimum_required(VERSION 4.0.0)
set(PART part_one)

add_executable(${PART} ${PART}.cpp)
target_compile_features(${PART} PRIVATE
  cxx_std_26 
)

target_compile_options (${PART} PRIVATE
  "$<$<CONFIG:Debug>:${DEBUG_FLAGS}>"
  "$<$<CONFIG:Release>:${RELEASE_FLAGS}>"
)

target_link_options(${PART} PRIVATE
  "$<$<CONFIG:Debug>:${SANITIZER_FLAGS}>"
)

add_custom_command(
    TARGET ${PART} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${CMAKE_CURRENT_SOURCE_DIR}/input.txt"
    "$<TARGET_FILE_DIR:${PART}>/input.txt"
)

set(PART part_two)
add_executable(${PART} ${PART}.cpp)
target_compile_features(${PART} PRIVATE
  cxx_std_26 
)

target_compile_options (${PART} PRIVATE
  "$<$<CONFIG:Debug>:${DEBUG_FLAGS}>"
  "$<$<CONFIG:Release>:${RELEASE_FLAGS}>"
)

target_link_options(${PART} PRIVATE
  "$<$<CONFIG:Debug>:${SANITIZER_FLAGS}>"
)
