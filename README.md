# Graph Algorithms Project

This project is an educational implementation of graph algorithms using custom data structures in C++. The project demonstrates how to build a graph using an adjacency list and implements several graph algorithms such as BFS, DFS, Dijkstra's, Prim's, and Kruskal's algorithms. Additionally, custom implementations of essential data structures are provided, including a dynamic array, queue, priority queue (min-heap), and union-find (DSU).

## Project Structure

```
.
├── include
│   ├── data_structures
│   │   ├── dynamic_array.hpp        # Template dynamic array.
│   │   ├── priority_queue.hpp       # Min-heap based priority queue.
│   │   ├── queue.hpp                # Simple FIFO queue.
│   │   ├── union_find.hpp           # Basic union-find (DSU) structure.
│   │   └── utils.hpp                # Helper functions (e.g., DFS utility).
│   └── graph
│       ├── graph.hpp                # Graph class declaration.
│       └── algorithms.hpp           # Declaration of graph algorithms.
├── src
│   ├── data_structures
│   │   └── utils.cpp                # Implementation of utility functions.
│   └── graph
│       ├── graph.cpp                # Graph class implementation.
│       └── algorithms.cpp           # Implementation of BFS, DFS, Dijkstra, Prim, and Kruskal.
├── test
│   ├── doctest                      # Contains the doctest header files.
│   ├── doctest_algorithms.cpp       # Doctest unit tests for graph algorithms.
│   └── doctest_data_structures.cpp  # Doctest unit tests for custom data structures.
└── Makefile                         # Makefile to build and test the project.
```

## Features

- **Graph Representation:**  
  - Implemented as an adjacency list using a custom dynamic array.
  - Supports undirected graphs with weighted edges.

- **Graph Algorithms:**  
  - **BFS:** Constructs a spanning tree from a given source vertex.
  - **DFS:** Constructs a spanning tree/forest from a given source vertex.
  - **Dijkstra:** Finds the shortest path tree from a start vertex on a weighted graph.
  - **Prim & Kruskal:** Compute a minimum spanning tree (MST) of the graph.

- **Custom Data Structures:**  
  - **Dynamic Array:** A simple, template-based array that automatically resizes.
  - **Queue:** A FIFO queue implemented using the dynamic array.
  - **Priority Queue:** A min-heap based priority queue for use in Dijkstra's and Prim's algorithms.
  - **Union-Find:** Basic disjoint set union implementation with path compression and union by rank for Kruskal's algorithm.

## Building the Project

This project uses a Makefile for building. The Makefile compiles the source files and builds the test executables using doctest. The option for checking for memory leaks using valgrind is also provided.

### On Linux

1. **Install Dependencies:**  
   Make sure you have a C++ compiler (clang++ or g++) and [Valgrind](https://valgrind.org/) (if you want to check for memory leaks).

2. **Build the Project and Tests:**

   ```bash
   make
   ```

   This will build two test executables:
   - `test/doctest_algorithms` for graph algorithm tests.
   - `test/doctest_data_structures` for data structures tests.

3. **Run Tests:**

   To run the algorithms tests:
   ```bash
   ./test/doctest_algorithms
   ```

   To run the data structures tests:
   ```bash
   ./test/doctest_data_structures
   ```

4. **Run Valgrind:**  
   For example, to check the algorithms test for memory leaks, run:
   ```bash
   make valgrind-algo
   ```

### On Windows (MSYS2)

1. **Install MSYS2:**  
   Download and install MSYS2 from [msys2.org](https://www.msys2.org/).

2. **Install Necessary Tools:**  
   Ensure you have a C++ compiler (clang++ or g++) and GNU Make installed via pacman.
   ```bash
   pacman -S mingw-w64-x86_64-clang mingw-w64-x86_64-make
   ```

3. **Update PATH:**  
   Make sure that the directory containing your compiler (e.g., `/c/msys64/mingw64/bin`) is in your PATH.

4. **Build and Run:**  
   In the MSYS2 shell, navigate to the project root and run:
   ```bash
   make
   ./test/doctest_algorithms.exe
   ./test/doctest_data_structures.exe
   ```

## License

This project is provided for educational purposes.
@Author: Aladdin Abu Hegly