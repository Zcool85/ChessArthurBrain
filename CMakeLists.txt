cmake_minimum_required(VERSION 3.1...3.5)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(ChessArthurBrain_cmake
            VERSION 0.1
            LANGUAGES CXX
        )

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()


#########################################################
# External packages
#########################################################

find_package(Boost COMPONENTS system REQUIRED)

#########################################################
# Compiler default options
#########################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


#########################################################
# Targets
#########################################################

add_subdirectory(engine)
