// topological_sort.cpp
// Glenn G. Chappell
// 2 Oct 2015
//
// For CS 412/611 Fall 2015
// Topological Sort
// Uses find-source algorithm

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <queue>
using std::queue;
#include <list>
using std::list;


// CONVENTIONS
//
// A DIGRAPH is represented by a 0,1-adjacency matrix. For an n-vertex
// digraph, the matrix will be stored in a vector<int> with size n*n.
// Vertices are numbered 0 .. n-1. If there is a directed edge from
// vertex i to vertex j, then item [i*n+j] in the vector is 1; otherwise
// it is 0.

// A traversal of a digraph is printed as a list of vertex indices (each
// 0 .. n-1) separated by blanks.


// topSort
// Print Topological Sort ordering of vertices of given digraph,
// terminated with newline, if such an ordering exists. Otherwise,
// print an error message.
// ordering).
//
// n is number of vertices in digraph. adjmat is nxn adjacency matrix
// for digraph.
//
// Pre:
//     n >= 0.
//     adjmat is the adjacency matrix of an a n-vertex digraph (as
//      above).
void topSort(const vector<int> & adjmat,
             int n)
{
    vector<int> indegrees(n, 0);    // indegrees[i] counts in-neighbors
                                    //  of vertex i that have NOT been
                                    //  processed yet
    queue<int, list<int>> sources;  // Vertices with no unprocessed
                                    //  in-neighbors
    // Initialize indegrees, sources
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (adjmat[j*n+i])
                ++indegrees[i];
        }
        if (indegrees[i] == 0)
            sources.push(i);
    }

    for (int count = 0; count < n; ++count)
    {
        // No sources? Not a DAG; no topological sort; exit
        if (sources.empty())
        {
            cout << "[ERROR]" << endl;
            cout << "*** Digraph is not a DAG; ";
            cout << "there is no topological sort" << endl;
            return;
        }

        // Get a source
        int s = sources.front();
        sources.pop();

        // Process this source as next vertex in topological sort
        cout << s << " ";

        // Update indegrees and sources
        for (int i = 0; i < n; ++i)
        {
            // edge from s to i?
            if (adjmat[s*n+i])
            {
                --indegrees[i];
                if (indegrees[i] == 0)
                    sources.push(i);
            }
        }
    }
    cout << endl;
}


// doWPDAG
// Print topological sort / error message for DAG from Wikipedia.
// From article on "Directed acyclic graph" retrieved 29 Sep 2014.
// Vertex indices in article:  2  3  5  7  8  9 10 11
// Vertex indices used here:   0  1  2  3  4  5  6  7
// Pre: None.
void doWPDAG()
{
    // Digraph: DAG from Wikipedia
    const int n = 8;
    std::vector<int> adjmat(n * n, 0);

    adjmat[1*n + 4] = 1;  // Edge 1 -> 4 (original  3 ->  8)
    adjmat[1*n + 7] = 1;  // Edge 1 -> 7 (original  3 -> 10)
    adjmat[2*n + 7] = 1;  // Edge 2 -> 7 (original  5 -> 11)
    adjmat[3*n + 7] = 1;  // Edge 3 -> 7 (original  7 ->  8)
    adjmat[3*n + 4] = 1;  // Edge 3 -> 4 (original  7 -> 11)
    adjmat[4*n + 5] = 1;  // Edge 4 -> 5 (original  8 ->  9)
    adjmat[7*n + 0] = 1;  // Edge 7 -> 0 (original 11 ->  2)
    adjmat[7*n + 5] = 1;  // Edge 7 -> 5 (original 11 ->  9)
    adjmat[7*n + 6] = 1;  // Edge 7 -> 6 (original 11 -> 10)

    cout << "DAG from Wikipedia" << endl;
    cout << "Topological Sort: ";
    topSort(adjmat, n);
    cout << endl;
}


// doCycle
// Print topological sort / error message for 8-cycle.
// Pre: None.
void doCycle()
{
    // Digraph: directed 8-Cycle
    // 8 vertices: 0 .. 7.
    // Adjacencies: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 0
    const int n = 8;
    vector<int> adjmat(n * n, 0);

    for (int i = 0; i < n; ++i)
        adjmat[i*n+(i+1)%n] = 1;

    cout << "Directed 8-Cycle" << endl;
    cout << "Topological Sort: ";
    topSort(adjmat, n);
    cout << endl;
}


// doTriWithTail
// Print topological sort / error message for triangle with tail.
// Pre: None.
void doTriWithTail()
{
    // Digraph: triangle with tail
    // 8 vertices: 0 .. 7.
    // Adjacencies: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 5
    const int n = 8;
    vector<int> adjmat(n * n, 0);

    for (int i = 0; i < n-1; ++i)
        adjmat[i*n+(i+1)] = 1;
    adjmat[7*n+5] = 1;

    cout << "Triangle with Tail" << endl;
    cout << "Topological Sort: ";
    topSort(adjmat, n);
    cout << endl;
}


// doMixPath
// Print topological sort / error message for mixed-up path.
// Pre: None.
void doMixPath()
{
    // Digraph: mixed-up path
    // 8 vertices: 0 .. 7.
    // Adjacencies: 7 -> 1 -> 3 -> 4 -> 2 -> 5 -> 0 -> 6
    const int n = 8;
    vector<int> adjmat(n * n, 0);

    adjmat[7*n+1] = 1;  // Edge 7 -> 1
    adjmat[1*n+3] = 1;  // Edge 1 -> 3
    adjmat[3*n+4] = 1;  // Edge 3 -> 4
    adjmat[4*n+2] = 1;  // Edge 4 -> 2
    adjmat[2*n+5] = 1;  // Edge 2 -> 5
    adjmat[5*n+0] = 1;  // Edge 5 -> 0
    adjmat[0*n+6] = 1;  // Edge 0 -> 6

    cout << "Mixed-Up Path" << endl;
    cout << "Topological Sort: ";
    topSort(adjmat, n);
    cout << endl;
}


// Main program
// Print topological sort for DAGs and/or error messages for non-DAGs
int main()
{
    // Print topological sort / error message for digraphs:
    doWPDAG();        // DAG from Wikipedia
    doCycle();        // Directed 8-Cycle
    doTriWithTail();  // "Triangle with Tail"
    doMixPath();      // Mixed-Up Path

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

