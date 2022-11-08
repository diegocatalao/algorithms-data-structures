# Algorithms and Data Structures

Algorithms and Data Structures in C

![](./assets/docs/turing-machine.jpg)

## Installing dependencies

```
$ sudo apt-get install gcc build-essential libssl-dev cmake
```

## Compiling and running

```
$ cmake .
$ make
$ ./bin/<some listed program>
```

## Project content

### Simple Structures

| Problem                                       | Source                                                       | Description                                                                                                                                                                           |
| --------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Selection sort                                | [selection_sort.c](./src/simple-structures/selection_sort.c) | Sort a array with selection sort algorithm. It has an O(n2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort. |
| Hash table                                    | [hash_table.c](./src/simple-structures/hash_table.c)         | Implements an associative array with a simple structure with name field for hash table. The hash function is a Euclidean Extended Algorithm avoiding collisions.                      |
| Linked list                                   | [linked_list.c](./src/simple-structures/linked_list.c)       | A generic linked list implementation. Works like a array of ints.                                                                                                                     |
| Merge sort                                    | [merge_sort.c](./src/simple-structures/merge_sort.c)         | Sort a array with merge sort algorithm. It has an O(nlog2n) time complexity. Most efficient sort algorithm for general-purpose cases.                                                 |
| Fibonacci, Memonacci and Factorial Recursivly | [recursion.c](./src/simple-structures/recursion.c)           | Recursive algorithms comparation. The best case is Recursive Memonacci (recursive fibonacci implementation with memory).                                                              |

### Threes

| Problem        | Source                                            | Description                                                                                                                                                                                                                                                                                                                     |
| -------------- | ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| R              | [r.c](./src/threes/r.c)                           | Data structure used for storing spatial data indexes in an efficient manner. R-trees are highly useful for spatial data queries and storage. Some of the real-life applications are mentioned below: Indexing multi-dimensional information. Handling geospatial coordinates.                                                   |
| B              | [b.c](./src/threes/b.c)                           | Self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.                                                                                                                                                                            |
| Red black      | [red_black.c](./src/threes/red_black.c)           | Kind of self-balancing binary search tree. Each node stores an extra bit representing "color" ("red" or "black"), used to ensure that the tree remains balanced during insertions and deletions                                                                                                                                 |
| Self balancing | [self_balancing.c](./src/threes/self_balancing.c) | Self-balancing binary search tree (BST) is any node-based binary search tree that automatically keeps its height (maximal number of levels below the root) small in the face of arbitrary item insertions and deletions                                                                                                         |
| Avl            | [avl.c](./src/threes/avl.c)                       | Self-balancing binary search tree (BST). It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property                                                |
| Splay          | [splay.c](./src/threes/splay.c)                   | Binary search tree with the additional property that recently accessed elements are quick to access again. Like self-balancing binary search trees, a splay tree performs basic operations such as insertion, look-up and removal in O(log n) amortized time                                                                    |
| Heap           | [heap.c](./src/threes/heap.c)                     | specialized tree-based data structure which is essentially an almost complete tree that satisfies the heap property: in a max heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C. In a min heap, the key of P is less than or equal to the key of C |
| Trie           | [trie.c](./src/threes/trie.c)                     | A type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters                                                                                                   |

### Divide And Conquer

| Problem           | Source                                                              | Description                                                                                                                                                                                                                     |
| ----------------- | ------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Biggest substring | [biggest_substring.c](./src/divide-and-conquer/biggest_substring.c) | Longest common substring problem is to find a longest string that is a substring of two or more strings                                                                                                                         |
| Knapsack          | [knapsack.c](./src/divide-and-conquer/knapsack.c)                   | Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. |
| Binary search     | [binary_search.c](./src/divide-and-conquer/binary_search.c)         | Search algorithm that finds the position of a target value within a sorted array.                                                                                                                                               |
| Sum               | [sum.c](./src/divide-and-conquer/sum.c)                             | Sum an array of integers with divide and conquer. It's just an example case.                                                                                                                                                    |
| Quicksort         | [quicksort.c](./src/divide-and-conquer/quicksort.c)                 | Sort a array with quick sort algorithm. It has an O(n^2) time complexity. It can be somewhat faster than merge sort and about two or three times faster than heapsort                                                           |

### Greedy

| Problem  | Source                                | Description                                                                                                                                                                                             |
| -------- | ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Graphway | [graphway.c](./src/greedy/graphway.c) | Simple graph implementation.                                                                                                                                                                            |
| Greedy   | [greedy.c](./src/greedy/greedy.c)     | Very simple greegy algorithm implementation using graph.                                                                                                                                                |
| Dijkstra | [dijkstra.c](./src/greedy/dijkstra.c) | Finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later |

### Backtracking

| Problem      | Source                                              | Description                                                                                                                                                                                                                                                                                                                       |
| ------------ | --------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| N-queen      | [n-queen.c](./src/backtracking/n-queen.c)           | Finding how many different ways queens can be placed on a chessboard so that none attack each other                                                                                                                                                                                                                               |
| Knights-tour | [knights-tour.c](./src/backtracking/knights-tour.c) | A sequence of moves of a knight on a chessboard such that the knight visits every square exactly once. If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), the tour is closed (or re-entrant); otherwise, it is open |
| Maze         | [maze.c](./src/backtracking/maze.c)                 | Solve a ascii maze from assets file with backtracking.                                                                                                                                                                                                                                                                            |