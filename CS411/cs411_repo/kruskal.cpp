// kruskal.cpp
// Glenn G. Chappell
// 16 Nov 2015
//
// For CS 411/611 Fall 2015
// Kruskal's Algorithm

#include "unionfind.h"
// For class UnionFind
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <utility>
using std::pair;
#include <algorithm>
using std::sort;
#include <cassert>
// for assert


const int INF = -1;  // Used to represent +infinity

// We represent a weighted graph by an adjacency-matrix-like structure.
//  For an N-vertex graph, the structure is a vector<int> of size N*N.
//  Entry [i*N+j] is INF if there is no edge from i to j, and
//  nonnegative otherwise. This nonnegative value is the weight on the
//  edge from i to j.

typedef pair<int, int> Edge;    // Type for edge of graph
                                //  Integers are indices of endpoints.


// kruskal
// Compute minimum spanning tree using Kruskal's Algorithm.
// Given weighted graph (represented as discussed above), order of
// graph, and adjacency lists.
vector<Edge> kruskal(
    const vector<int> & wgraph,             // weights
    int N,                                  // number of vertices
    const vector<vector<int> > & adjlists)  // adjacency lists
{
    assert (N >= 1);
    assert (wgraph.size() == size_t(N*N));
    assert (adjlists.size() == size_t(N));

    // Make list of edges
    vector<Edge> edges;
    for (int i = 0; i < N; ++i)
    {
        for (auto v : adjlists[i])
        {
            if (v > i)
                edges.push_back(Edge(i, v));
        }
    }

    // List of edges -> sorted list of edges
    sort(edges.begin(), edges.end(),
        [&](const Edge & a, const Edge & b)
        { return wgraph[a.first*N+a.second]
               < wgraph[b.first*N+b.second]; });

    // Make union-find structure with one blob for each vertex
    UnionFind uf;
    for (int i = 0; i < N; ++i)
    {
        uf.makeSet(i);
    }

    // Make tree from cheapest N-1 edges that do not create cycle
    vector<Edge> tree;          // Edges in tree
    for (auto e : edges)
    {
        if (uf.find(e.first) == uf.find(e.second))
            continue;

        // Add new edge to tree & do union
        tree.push_back(e);
        if (tree.size() == size_t(N-1))
            break;  // An easy optimization
        uf.unionx(e.first, e.second);
    }

    // Done
    return tree;
}


// makeAdjLists
// Given weights for graph, with nonedges indicated by INF,
//  returns vector of adjacency lists.
vector<vector<int> > makeAdjLists(const vector<int> & wgraph,
                                  int N)  // number of vertices
{
    vector<vector<int> > adjlists;
    for (int i = 0; i < N; ++i)
    {
        adjlists.push_back(vector<int>());
        for (int j = 0; j < N; ++j)
        {
            if (wgraph[i*N + j] != INF)
                adjlists[i].push_back(j);
        }
    }
    return adjlists;
}


// printMatrix
// Given a matrix stored in a vector, with the (i,j) entry stored in
// matrix[i*numcols+j], print the matrix, entries separated by blanks,
// rows ending with newline.
void printMatrix(const vector<int> & matrix,
                 int numcols)
{
    for (int row = 0; size_t((row+1)*numcols) <= matrix.size(); ++row)
    {
        for (int col = 0; col < numcols; ++col)
        {
            int value = matrix[row*numcols+col];
            if (value == INF)
                cout << "  -";
            else
                cout << setw(3) <<value;
            cout << " ";
        }
        cout << endl;
    }
}

// setWeight
// Sets weight of a,b edge in N-vertex weighted graph described by
//  wgraph (see above).
void setWeight(vector<int> & wgraph, int N,
               int a, int b,
               int wt)
{
    wgraph[a*N + b] = wt;
    wgraph[b*N + a] = wt;
}


// main
// Example using function kruskal
int main()
{
    const int N = 5;  // Number of vertices of graph

    // Set up weight matrix for graph;
    vector<int> wgraph(N*N, INF);
    setWeight(wgraph, N, 0, 1, 7);
    setWeight(wgraph, N, 0, 3, 4);
    setWeight(wgraph, N, 0, 4, 3);
    setWeight(wgraph, N, 1, 2, 2);
    setWeight(wgraph, N, 1, 3, 8);
    setWeight(wgraph, N, 1, 4, 6);
    setWeight(wgraph, N, 2, 3, 9);
    setWeight(wgraph, N, 2, 4, 5);
    setWeight(wgraph, N, 3, 4, 1);

    // Print weights
    cout << "Weight matrix:" << endl;
    printMatrix(wgraph, N);
    cout << endl;

    // Compute & print adjacency lists
    vector<vector<int> > adjlists = makeAdjLists(wgraph, N);
    cout << "Adjacency lists:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << i << ": ";
        for (int j = 0; size_t(j) < adjlists[i].size(); ++j)
        {
            if (j != 0)
                cout << ", ";
            cout << adjlists[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Run Kruskal's Algorithm & print result
    cout << "Running Kruskal's Algorithm" << endl;
    vector<Edge> tree = kruskal(wgraph, N, adjlists);
    cout << "Edges in minimum spanning tree:" << endl;
    if (tree.size() == 0)
        cout << "[NONE]" << endl;
    for (int i = 0; size_t(i) < tree.size(); ++i)
    {
        cout << tree[i].first << ", " << tree[i].second << endl;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

