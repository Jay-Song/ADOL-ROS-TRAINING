cmake_minimum_required(VERSION 3.0.2) #-> for kinetic 2.8.3
project(ros_simple_topic_example)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find dependencies (other package or libraries)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## The catkin_package macro generates cmake config files for your package
catkin_package(
  #LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp std_msgs
)

## Set the include directories
include_directories(${catkin_INCLUDE_DIRS})

## Declare a C++ executable
add_executable(${PROJECT_NAME}_publisher src/ros_simple_topic_example_publisher.cpp)
add_executable(${PROJECT_NAME}_subscriber src/ros_simple_topic_example_subscriber.cpp)

## Add cmake target dependencies of the executable
add_dependencies(${PROJECT_NAME}_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(${PROJECT_NAME}_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_publisher ${catkin_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_subscriber ${catkin_LIBRARIES})