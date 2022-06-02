cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

project(Glasterpy)

add_library("GlasterpyScrypt" SHARED "src/GlasterpyScrypt.cpp")
target_include_directories("GlasterpyScrypt" PRIVATE "include/")

add_library("GlasterpyLexer" SHARED "src/GlasterpyLexer.cpp")
target_include_directories("GlasterpyLexer" PRIVATE "include/")
target_link_directories("GlasterpyLexer" PRIVATE "external-libs/")
target_link_libraries("GlasterpyLexer" PRIVATE "utf8proc")

add_executable("Glasterpy.bin" "main.cpp")
target_include_directories("Glasterpy.bin" PRIVATE "include/")
target_link_libraries("Glasterpy.bin" PRIVATE "GlasterpyScrypt" "GlasterpyLexer")

