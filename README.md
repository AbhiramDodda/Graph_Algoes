### GitHub README Description for Your Graph Algorithms Project

---

# Graph Algorithms CLI Application

This project is a **Command Line Interface (CLI)** tool for performing various graph operations and algorithms. It allows users to input graphs and execute multiple operations, such as finding the Minimum Cost Spanning Tree (MCST), checking if the graph is planar or complete, calculating shortest paths, solving the graph coloring problem, and more.

## Algorithms Used

1. **Kruskal's Algorithm** for finding the Minimum Cost Spanning Tree (MCST):
   - This algorithm sorts all edges by weight and greedily adds them to the spanning tree, ensuring no cycles are formed. It utilizes the **Union-Find** data structure to manage connected components.

2. **Floyd-Warshall Algorithm** for All-Pairs Shortest Paths:
   - A dynamic programming algorithm that computes the shortest paths between all pairs of nodes in a weighted graph. It iteratively updates the shortest paths by checking intermediate nodes.

3. **Graph Coloring Problem**:
   - A heuristic algorithm is used to assign colors to each node of the graph such that no two adjacent nodes share the same color. The minimum number of colors needed is calculated.

4. **Planar Graph Check** (Placeholder):
   - A simple check based on the number of edges and nodes. (You can extend this with more advanced techniques such as Kuratowski's theorem for real-world applications.)

5. **Complete Graph Check**:
   - Checks if every node is connected to every other node in the graph. A complete graph should have `n(n-1)/2` edges.

6. **Minimum Cut / Maximum Cut** (Placeholder):
   - For now, random values are used for min/max cuts, but you can extend this with algorithms like **Stoer-Wagner** for the minimum cut problem.

7. **Shortest Path Between Two Nodes**:
   - Using pre-computed shortest path results from the Floyd-Warshall algorithm, this feature allows you to find the shortest path between any two nodes in constant time.

## How to Run the Program

### Requirements
- A C++ compiler (e.g., g++, clang++) installed on your system.

### Steps to Compile and Run:
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/graph-algorithms-cli.git
   cd graph-algorithms-cli
   ```

2. **Compile the Code**:
   If you're using g++, run the following command to compile the program:
   ```bash
   g++ -o graph_app main.cpp
   ```

3. **Run the Program**:
   After compiling, run the program as follows:
   ```bash
   ./graph_app
   ```

### Input Format
1. **Nodes**: First, you will be asked to input the number of nodes.
2. **Edges**: Then, you'll be prompted to enter edges in the format `u v w`, where `u` and `v` are node numbers and `w` is the weight of the edge.

### Available Operations

Once you provide the graph input, you can choose from the following operations:

1. **Print All MCSTs**: Shows the minimum cost spanning tree and its total cost.
   ```
   Choose option: 1
   ```
   
2. **Check if Graph is Planar**: Determines whether the graph is planar (this is a basic placeholder check).
   ```
   Choose option: 2
   ```

3. **Check if Graph is Complete**: Checks if the graph is a complete graph.
   ```
   Choose option: 3
   ```

4. **All-Pairs Shortest Paths**: Computes and prints the shortest paths between all pairs of nodes using the Floyd-Warshall algorithm.
   ```
   Choose option: 4
   ```

5. **Graph Coloring**: Solves the graph coloring problem and prints the minimum number of colors required.
   ```
   Choose option: 5
   ```

6. **Shortest Distance Between Two Nodes**: Takes two node inputs and prints the shortest path between them.
   ```
   Choose option: 6
   ```

7. **Minimum and Maximum Cut**: Displays the minimum and maximum cut in the graph (current implementation is a placeholder).
   ```
   Choose option: 7
   ```

8. **Exit**: Type `-1` to exit the program.
   ```
   Choose option: -1
   ```

### Example Input and Output:

```bash
Enter the number of nodes: 4
Enter the number of edges: 5
Enter edges (u v w) format:
1 2 4
1 3 2
2 3 1
2 4 5
3 4 3

Choose an option:
1. Print all possible MCSTs
2. Check if graph is planar
3. Check if graph is complete
4. Print all pair shortest paths
5. Graph coloring
6. Print shortest distance between two nodes
7. Print min cut and max cut
-1. Exit
```

## Future Enhancements

- **Improved Planarity Check** using Kuratowski’s theorem.
- **Actual Minimum/Maximum Cut Algorithms** (e.g., Stoer-Wagner for min cut).
- **Support for Larger Graphs** with optimized algorithms.
