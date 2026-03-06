# CMakeList.txt : CMake project for Verge, include source and define
# project specific logic here.
#
include(FetchContent)

# 1. Declare SFML dependency
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)

# 2. Make it available
FetchContent_MakeAvailable(sfml)

project(Sandbox)

# 1. Collect sandbox source files (must have a main.cpp here)
file(GLOB_RECURSE SANDBOX_SRCS "src/*.cpp")

# 2. Create the Executable
add_executable(Sandbox ${SANDBOX_SRCS})
if (MSVC)
    target_compile_options(Sandbox PRIVATE /utf-8)
endif()
# 3. Link to the Engine
# This handles the .lib linking AND gives Sandbox access to Verge headers
target_link_libraries(Sandbox PRIVATE Verge sfml-graphics sfml-window sfml-system)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Verge PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

