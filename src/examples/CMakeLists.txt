# CMakeLists.txt

cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(TorchExample)

# set(CMAKE_PREFIX_PATH /usr/local/libtorch)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
find_package(Torch REQUIRED)

add_executable(example-app1 example-app1.cpp)
target_link_libraries(example-app1 "${TORCH_LIBRARIES}")
set_property(TARGET example-app1 PROPERTY CXX_STANDARD 17)

find_package(Armadillo REQUIRED)
add_executable(example-app2 example-app2.cpp)
target_link_libraries(example-app2 ${ARMADILLO_LIBRARIES} "${TORCH_LIBRARIES}")
set_property(TARGET example-app2 PROPERTY CXX_STANDARD 17)