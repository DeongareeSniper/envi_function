cmake_minimum_required(VERSION 3.28.1)
project(envi_function VERSION 0.1.0 LANGUAGES C CXX)

# include(CTest)
# enable_testing()

add_executable(envi_function ./src/main.cpp ./src/SpectralIndices_math.cpp ./src/SpectralIndices.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
