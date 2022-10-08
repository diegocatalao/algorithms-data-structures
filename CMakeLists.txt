cmake_minimum_required(VERSION 3.0.0)
project(grokking VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compile common libraries
add_library(csv SHARED src/commons/csv.c)

# Grooking - Compile executables
add_executable(knapsack src/grokking/knapsack.c)
add_executable(biggest_substring src/grokking/biggest_substring.c)
add_executable(binary_search src/grokking/binary_search.c)
add_executable(dc_sum src/grokking/dc_sum.c)
add_executable(dijkstra src/grokking/dijkstra.c)
add_executable(graphway src/grokking/graphway.c)
add_executable(greedy src/grokking/greedy.c)
add_executable(hash_table src/grokking/hash_table.c)

add_executable(knn src/grokking/knn.c)
target_link_libraries(knn PRIVATE csv)

add_executable(linked_list src/grokking/linked_list.c)
add_executable(merge_sort src/grokking/merge_sort.c)
add_executable(quicksort src/grokking/quicksort.c)
add_executable(selection_sort src/grokking/selection_sort.c)
add_executable(recursion src/grokking/recursion.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/three)

add_executable(avl src/grokking/three/avl.c)
add_executable(b src/grokking/three/b.c)
add_executable(heap src/grokking/three/heap.c)
add_executable(r src/grokking/three/r.c)
add_executable(red_black src/grokking/three/red_black.c)
add_executable(self_balancing src/grokking/three/self_balancing.c)
add_executable(splay src/grokking/three/splay.c)
add_executable(trie src/grokking/three/trie.c)

# Backtracking - Compile executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin/backtracking)

add_executable(n-queen src/backtracking/n-queen.c)
add_executable(maze src/backtracking/maze.c)