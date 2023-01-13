cmake_minimum_required(VERSION 3.24)
project(data_structure_learn C)

set(CMAKE_C_STANDARD 90)

add_executable(data_structure_learn main.c)

add_subdirectory(List)
add_subdirectory(LinkedList)
add_subdirectory(DoubleLinkedList)
add_subdirectory(CircularLinkedList)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(BinaryTree)
add_subdirectory(ThreadBinaryTree)
