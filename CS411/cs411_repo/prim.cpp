// prim.cpp
// Glenn G. Chappell
// 11 Nov 2015
//
// For CS 411/611 Fall 2015
// Prim's Algorithm

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
#include <queue>
using std::priority_queue;
#include <cassert>  // for assert


const int INF = -1;  // Used to represent +infinity

// We represent a weighted graph by an adjacency-matrix-like structure.
//  For an N-vertex graph, the structure is a vector<int> of size N*N.
//  Entry [i*N+j] is INF if there is no edge from i to j, and
//  nonnegative otherwise. This nonnegative value is the weight on the
//  edge from i to j.

typedef pair<int, int> Edge;    // Type for edge of graph
                                //  Integers are indices of endpoints.


// prim
// Compute minimum spanning tree using Prim's Algorithm.
// Given weighted graph (represented as discussed above), order of
// graph, adjacency lists, and start vertex.
vector<Edge> prim(
    const vector<int> & wgraph,             // weights
    int N,                                  // number of vertices
    const vector<vector<int> > & adjlists,  // adjacency lists
    int start)                              // index of start vertex
{
    assert (N >= 1);
    assert (wgraph.size() == size_t(N*N));
    assert (0 <= start && start < N);
    assert (adjlists.size() == size_t(N));

    vector<int> reached(N, 0);  // item i is 1 if vert i reached, else 0
    vector<Edge> tree;          // Edges in tree

    // Make priority queue of edges; top edge is one of least weight

    // Comparison function for priority queue
    auto comp = [&](const Edge & a, const Edge & b)  // Comparison func
    {
        // Get weight of edge a, edge b
        auto wta = wgraph[a.first*N+a.second];
        auto wtb = wgraph[b.first*N+b.second];
        return wtb < wta;       // Compare reversed to get smallest
    };
    // The priority queue itself
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);

    // Handle start vertex
    reached[start] = 1;
    for (auto v : adjlists[start])
    {
        if (!reached[v])
            pq.push(Edge(start, v));
    }

    // Repeat until done with all edges
    while (!pq.empty())
    {
        // Get least-weight edge from reached to unreached vertex
        auto e = pq.top();
        pq.pop();
        auto u = e.second;
        if (reached[u])
            continue;

        // Handle new edge (e) & vertex (u)
        tree.push_back(e);
        if (tree.size() == size_t(N-1))
            break;  // An easy optimization
        reached[u] = 1;
        for (auto v : adjlists[u])
        {
            if (!reached[v])
                pq.push(Edge(u, v));
        }
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
// Example using function prim
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

    // Run Prim's Algorithm & print result
    cout << "Running Prim's Algorithm" << endl;
    vector<Edge> tree = prim(wgraph, N, adjlists, 0);
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

