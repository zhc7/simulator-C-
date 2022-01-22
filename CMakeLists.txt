cmake_minimum_required(VERSION 3.20)
project(simulator)


set(CMAKE_CXX_STANDARD 20)

# add_subdirectory(./backward-cpp-1.6)

#set(INC_DIR C:/Program Files (x86)/NumCpp/include)
#include_directories(${INC_DIR})


add_executable(simulator main.cpp Entity.h Shape.cpp Shape.h Vector.h Entity.cpp Vector.cpp World.cpp World.h shapes/Circle.cpp shapes/Circle.h shapes/InnerCircle.cpp shapes/InnerCircle.h demo.cpp)

# This will add libraries, definitions and include directories needed by backward
# by setting each property on the target.
# add_backward(simulator)

find_package(NumCpp 2.6.2 REQUIRED)
target_link_libraries(${PROJECT_NAME}
    NumCpp::NumCpp
)