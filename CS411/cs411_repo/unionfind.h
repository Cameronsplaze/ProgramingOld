// unionfind.h
// VERSION 2
// Glenn G. Chappell
// 16 Nov 2015
//
// For CS 411/611 Fall 2015
// Header for class UnionFind
// Union-Find Structure
// There is no associated source file
//
// History:
// - v2: Added optimizations: path compression, union by rank.

#ifndef FILE_UNIONFIND_H_INCLUDED
#define FILE_UNIONFIND_H_INCLUDED

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <cassert>
// for assert


// class UnionFind
// Union-Find structure.
// "Quick union" (rooted tree) implementation, with union-by-rank and
// path-compression optimizations.
//
// Items are nonnegative int values.
// Member functions:
// - makeSet (Make-Set operation)
// - find    (Find operation)
// - unionx  (Union operation)
class UnionFind {

// ***** UnionFind: ctors, dctor, op= *****
public:

    // Compiler generated default ctor, copy ctor, copy =, dctor used

// ***** UnionFind: general public functions *****
public:

    // makeSet
    // Make-Set operation.
    // Pre:
    //     x >= 0.
    void makeSet(int x)
    {
        assert(x >= 0);

        if (size_t(x) >= _data.size())
        {
            _data.resize(x+1, Info(0, 0, false));
        }

        if (!_data[x]._inited)
        {
            _data[x] = Info(x, 0, true);
        }
    }

    // find
    // Find operation.
    // Pre:
    //     x >= 0.
    //     makeSet must have been previously called on x.
    int find(int x)
    {
        assert(x >= 0);
        assert(size_t(x) < _data.size());
        assert(_data[x]._inited);

        // Do path compression
        if (_data[x]._parent != x)
        {
            _data[x]._parent = find(_data[x]._parent);
        }
        return _data[x]._parent;
    }

    // unionx
    // Union operation ("union" is a reserved word in C++).
    // Pre:
    //    x >= 0.
    //    y >= 0.
    //    makeSet must have been previously called on each of x, y.
    void unionx(int x,
                int y)
    {
        assert(x >= 0);
        assert(size_t(x) < _data.size());
        assert(_data[x]._inited);
        assert(y >= 0);
        assert(size_t(y) < _data.size());
        assert(_data[y]._inited);
        
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot)
        {
            return;
        }

        // Do union-by-rank
        if (_data[xroot]._rank < _data[yroot]._rank)
        {
            _data[xroot]._parent = yroot;
        }
        else if (_data[yroot]._rank < _data[xroot]._rank)
        {
            _data[yroot]._parent = xroot;
        }
        else
        {
            _data[yroot]._parent = xroot;
            ++_data[xroot]._rank;
        }
    }

// ***** UnionFind: internal-use types *****
private:

    // struct Info
    // Info on single item in union-find structure
    struct Info {
        int  _parent;  // Parent of item
        int  _rank;    // Tree rank; only valid for root item
        bool _inited;  // Has Make-Set been called on this item?
                       //  _parent, _rank fields invalid if !_inited

        // Ctor from field values, for convenience
        Info(int theParent,
             int theRank,
             bool theInited)
           :_parent(theParent),
            _rank(theRank),
            _inited(theInited)
        {}
    };

// ***** UnionFind: data members *****
private:

    vector<Info> _data;  // Info for each item

};  // End class UnionFind

#endif //#ifndef FILE_UNIONFIND_H_INCLUDED

