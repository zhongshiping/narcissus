project(DataStruct)

file(GLOB data_struct_header *.h)

add_library(DataStruct SHARED ${data_struct_header})
set_target_properties(DataStruct PROPERTIES LINKER_LANGUAGE CXX)