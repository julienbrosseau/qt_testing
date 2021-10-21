# ==================================================================================================
# Typical execution based on this template
#
# $ cmake ..
# ==================================================================================================

# ==================================================================================================
# Global settings of CMakeLists
# ==================================================================================================
# Choose the minimun version required of cmake to run this CMakeLists
cmake_minimum_required(VERSION 3.10)

# Set details of the project
project(qt_testing
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "CMakeLists template for QT projects"
)

# ==================================================================================================
# Specific settings of CMakeLists
# ==================================================================================================
# Set the directory which will host the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

# Set standards for the compilation
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to run moc, rcc an uic when necessary
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set packages to find
find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)

# ==================================================================================================
# Directories settings of CMakeLists
# ==================================================================================================
# Add include directories (for build part) if necessary
include_directories(
    inc
)

# ==================================================================================================
# Executable settings of CMakeLists
# ==================================================================================================
# Add the executable with a "GLOB" of main files
file(GLOB PROJECT_EXECS
    "src/*.cpp"
)

# Add executable with the previous "GLOB"
add_executable(PROJECT_main ${PROJECT_EXECS})

# Link librairies (local ad external) to the executable
target_link_libraries(PROJECT_main Qt5::Gui Qt5::Core Qt5::Widgets)