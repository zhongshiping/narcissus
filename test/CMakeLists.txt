file(GLOB test_file *.cc)

add_executable(Narcissus ${test_file})
target_link_libraries(Narcissus)
