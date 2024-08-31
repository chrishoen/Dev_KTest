cmake_minimum_required (VERSION 3.10)
set (project "RisLib")
project(${project} CXX)
my_find_src_files (src_files ${project})
my_find_inc_files (inc_files)
add_library (${project} STATIC ${src_files})
my_add_pch (${project})

target_include_directories(${project} PUBLIC ${PROJECT_SOURCE_DIR})



