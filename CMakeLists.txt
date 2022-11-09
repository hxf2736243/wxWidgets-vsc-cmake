cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0048 NEW)
project(myapp VERSION 0.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

#比INSTALL(TARGETS myapp DESTINATION bin)管用
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# we default to Release build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()


find_package(wxWidgets REQUIRED COMPONENTS net core base)
MESSAGE( STATUS "find_package(wxWidgets) = ${wxWidgets_LIBRARIES}.")
include(${wxWidgets_USE_FILE})
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)
set(src 
src/button.cpp
src/Panels.cpp
src/Communicate.cpp
src/main.cpp
)
add_executable(${PROJECT_NAME} ${src})
target_link_libraries(myapp ${wxWidgets_LIBRARIES})

# INSTALL(TARGETS myapp DESTINATION ${PROJECT_SOURCE_DIR}/bin)



