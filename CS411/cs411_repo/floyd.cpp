// floyd.cpp
// Glenn G. Chappell
// 9 Nov 2015
//
// For CS 411/611 Fall 2015
// Floyd's Algorithm

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setw;
#include <vector>
using std::vector;
#include <cstdlib>
using std::size_t;


const int INF = -1;  // Used to represent +infinity (no path exists)

// We represent a weighted digraph by an adjacency-matrix-like
//  structure. For an N-vertex digraph, the structure is a vector<int>
//  of size N*N. Entry [i*N+j] is INF if there is no arc from i to j and
//  nonnegative otherwise. This nonnegative value is the weight on the
//  arc from i to j.


// minPlus
// Given a, b, c, returns min(a, b+c), where INF values are handled
//  correctly.
int minPlus(int a, int b, int c)
{
    if (b == INF || c == INF)
        return a;
    else if (a == INF || b+c < a)
        return b+c;
    return a;
}


// floyd
// Given a weighted digraph (represented as described above), solves
//  the All-Pairs Shortest-Path problem, using Floyd's Algorithm.
// Returns a weighted digraph (represented as described above). INF
//  means no path in the original digraph; otherwise, the weight is
//  the total weight of the shortest path in the original digraph.
//
// Input matrix is given in digraph, with its order in N.
// Output matrix is returned in the same format.
//
// Pre:
//     digraph has size at least N*N.
//     digraph[i*N + j] is either INF or nonnegative, for 0 <= i,j < N.
// Post:
//     Considering digraph[..] as a digraph [see above],
//      All-Pairs Shortest-Path solution lies in return value.
vector<int> floyd(const vector<int> & digraph,
                  size_t N)
{
    // d: temporary storage
    // Item i,j in adjacency matrix k is stored in d[k*n*n + i*n + j].
    // The item is the length of the shortest path in the original
    //  digraph from vertex i to vertex j, using only intermediate
    //  vertices numbered less than k, or INF if there is no such path.
    // NOTE: This numbering scheme is slightly different from that in
    //  the Levitin text.
    vector<int> d((N+1)*N*N);

    // Copy adjacency matrix to d
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            d[0*N*N + i*N + j] = digraph[i*N + j];

    // Run Floyd's Algorithm
    for (size_t k = 1; k <= N; ++k)
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < N; ++j)
                d[k*N*N + i*N + j] = minPlus(
                    d[(k-1)*N*N + i*N + j],
                    d[(k-1)*N*N + i*N + (k-1)],
                    d[(k-1)*N*N + (k-1)*N + j]);

    // Copy final matrix to storage for result and return it
    vector<int> result(N*N);
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            result[i*N + j] = d[N*N*N + i*N + j];
    return result;
}


// printMatrix
// Given a matrix stored in a vector, with the (i,j) entry stored in
// matrix[i*numcols+j], print the matrix, entries separated by blanks,
// rows ending with newline.
void printMatrix(const vector<int> & matrix,
                 size_t numcols)
{
    for (size_t row = 0; (row+1)*numcols-1 < matrix.size(); ++row)
    {
        for (size_t col = 0; col < numcols; ++col)
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


// Main program
// Demonstrate use of function floyd.
int main()
{
    const size_t N = 5;  // Number of vertices of digraph

    // Set up weighted adjacency matrix of digraph
    vector<int> weights(N*N, INF);
    weights[0*N + 1] = 1;
    weights[1*N + 0] = 3;
    weights[1*N + 4] = 2;
    weights[1*N + 3] = 7;
    weights[4*N + 2] = 2;
    weights[4*N + 3] = 3;

    // Print original adjacency matrix
    cout << "Original weighted digraph:" << endl;
    printMatrix(weights, N);
    cout << endl;

    // Compute All-Pairs Shortest-Paths solution
    vector<int> result = floyd(weights, N);

    // Print A-P S-P solution
    cout << "All-pairs shortest-paths solution:" << endl;
    printMatrix(result, N);
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

