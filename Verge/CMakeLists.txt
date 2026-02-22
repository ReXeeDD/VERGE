# CMakeList.txt : CMake project for Verge, include source and define
# project specific logic here.
#
project(Verge)

# 1. Collect all engine source files
file(GLOB_RECURSE ENGINE_SRCS "src/*.cpp" "src/*.h")



# 2. Create the DLL
add_library(Verge SHARED ${ENGINE_SRCS})
if (MSVC)
    target_compile_options(Verge PRIVATE /utf-8)
endif()

# 3. Include folders
target_include_directories(Verge PUBLIC src  ../vendor/spdlog/include)

# 4. Export Macro (Important for Windows)
# This defines VERGE_BUILD_DLL when compiling the engine
target_compile_definitions(Verge PRIVATE VERGE_BUILD_DLL)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Verge PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
