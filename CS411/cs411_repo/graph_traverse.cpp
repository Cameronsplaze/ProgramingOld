// graph_traverse.cpp
// Glenn G. Chappell
// 25 Sep 2015
//
// For CS 411/611 Fall 2015
// Graph traversals: DFS & BFS

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <stack>
using std::stack;
#include <queue>
using std::queue;


// CONVENTIONS
//
// A GRAPH is represented by a 0,1-adjacency matrix. For an n-vertex
// graph, the matrix will be stored in a vector<int> with size n*n.
// Vertices are numbered 0 .. n-1. If vertices i, j are adjacent, then
// item [i*n+j] in the vector is 1; otherwise it is 0.

// A traversal of a graph is printed as a list of vertex indices (each
// 0 .. n-1) separated by blanks.


// dfs_helper
// Prints Depth-First Search ordering of unvisited vertices of graph
// reachable from given start vertex. Marks these vertices as visited.
// Graph is described by given adjacency matrix. Where possible, lower-
// numbered vertex indices are printed first. There is no terminating
// newline.
//
// Pre:
//     n >= 0.
//     adjmat is the adjacency matrix of an a n-vertex graph (as above).
//     start is a vertex index.
//     visited has size n, and each item is either 0 (unvisited) or 1
//      (visited).
void dfs_helper(const vector<int> & adjmat,
                int n,
                int start,
                vector<int> & visited)
{
    stack<int> s;  // Holds vertices to visit

    s.push(start);

    while (!s.empty())
    {
        // Get next vertex
        int curr = s.top();
        s.pop();

        // Make sure it is unvisited
        if (visited[curr])
            continue;

        // Visit it
        cout << curr << " ";
        visited[curr] = 1;

        // And push its unvisited neighbors
        //  (in reverse order, so we pop lower numbers first)
        for (int i = n-1; i >= 0; --i)
        {
            if (adjmat[curr*n + i] && !visited[i])
                s.push(i);
        }
    }
}


// dfs
// Print Depth-First Search ordering of vertices of given graph,
// terminated with newline.
//
// Pre:
//     n >= 0.
//     adjmat is the adjacency matrix of an a n-vertex graph (as above).
void dfs(const vector<int> & adjmat,
         int n)
{
    vector<int> visited(n, 0);
                   // visited[i] == 1 if vertex i has been visited;
                   //  0 otherwise
    for (int i = 0; i < n; ++i)
        dfs_helper(adjmat, n, i, visited);
    cout << endl;
}


// bfs_helper
// Prints Breadth-First Search ordering of unvisited vertices of graph
// reachable from given start vertex. Marks these vertices as visited.
// Graph is described by given adjacency matrix. Where possible, lower-
// numbered vertex indices are printed first. There is no terminating
// newline.
//
// Pre:
//     n >= 0.
//     adjmat is the adjacency matrix of an a n-vertex graph (as above).
//     start is a vertex index.
//     visited has size n, and each item is either 0 (unvisited) or 1
//      (visited).
void bfs_helper(const vector<int> & adjmat,
                int n,
                int start,
                vector<int> & visited)
{
    queue<int> s;  // Holds vertices to visit

    s.push(start);

    while (!s.empty())
    {
        // Get next vertex
        int curr = s.front();
        s.pop();

        // Make sure it is unvisited
        if (visited[curr])
            continue;

        // Visit it
        cout << curr << " ";
        visited[curr] = 1;

        // And push its unvisited neighbors
        for (int i = 0; i < n; ++i)
        {
            if (adjmat[curr*n + i] && !visited[i])
                s.push(i);
        }
    }
}


// bfs
// Print Breadth-First Search ordering of vertices of given graph,
// terminated with newline.
//
// Pre:
//     n >= 0.
//     adjmat is the adjacency matrix of an a n-vertex graph (as above).
void bfs(const vector<int> & adjmat,
         int n)
{
    vector<int> visited(n, 0);
                   // visited[i] == 1 if vertex i has been visited;
                   //  0 otherwise
    for (int i = 0; i < n; ++i)
        bfs_helper(adjmat, n, i, visited);
    cout << endl;
}


// addEdge
// Adds edge a - b to n-vertex graph described by adjmat (see above).
void addEdge(vector<int> & adjmat, int n,
             int a, int b)
{
    adjmat[a*n + b] = 1;
    adjmat[b*n + a] = 1;
}


// doTree
// Print DFS & BFS for small Binary Tree
// Pre: None.
void doTree()
{
    // Graph: Binary Tree
    // 7 vertices: 0 .. 6.
    // Adjacencies: 0 - 1, 0 - 2
    //              1 - 3, 1 - 4
    //              2 - 5, 2 - 6
    const int n = 7;
    vector<int> adjmat(n * n, 0);
    addEdge(adjmat, n, 0, 1);
    addEdge(adjmat, n, 0, 2);
    addEdge(adjmat, n, 1, 3);
    addEdge(adjmat, n, 1, 4);
    addEdge(adjmat, n, 2, 5);
    addEdge(adjmat, n, 2, 6);

    cout << "Tree" << endl;
    cout << "DFS: ";
    dfs(adjmat, n);
    cout << "BFS: ";
    bfs(adjmat, n);
    cout << endl;
}


// doCycle
// Print DFS & BFS for cycle
// Pre: None.
void doCycle()
{
    // Graph: 8-Cycle
    // 8 vertices: 0 .. 7.
    // Adjacencies: 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 0
    const int n = 8;
    vector<int> adjmat(n * n, 0);

    for (int i = 0; i < n; ++i)
        addEdge(adjmat, n, i, (i+1)%n);

    cout << "8-Cycle" << endl;
    cout << "DFS: ";
    dfs(adjmat, n);
    cout << "BFS: ";
    bfs(adjmat, n);
    cout << endl;
}


// doDoublePath
// Print DFS & BFS for two paths
// Pre: None.
void doDoublePath()
{
    // Graph: two 5-paths
    // 10 vertices: 0 .. 9.
    // Adjacencies: 3 - 5 - 0 - 1 - 8
    //              7 - 2 - 4 - 9 - 6
    const int n = 10;
    vector<int> adjmat(n * n, 0);
    addEdge(adjmat, n, 3, 5);
    addEdge(adjmat, n, 5, 0);
    addEdge(adjmat, n, 0, 1);
    addEdge(adjmat, n, 1, 8);
    addEdge(adjmat, n, 7, 2);
    addEdge(adjmat, n, 2, 4);
    addEdge(adjmat, n, 4, 9);
    addEdge(adjmat, n, 9, 6);

    cout << "Two 5-Paths" << endl;
    cout << "DFS: ";
    dfs(adjmat, n);
    cout << "BFS: ";
    bfs(adjmat, n);
    cout << endl;
}


// Main program
// Do DFS & BFS on various graphs
int main()
{
    // Print DFS & BFS for graphs:
    doTree();        // Binary Tree
    doCycle();       // 8-Cycle
    doDoublePath();  // Two paths

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

