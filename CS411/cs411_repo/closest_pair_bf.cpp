// closest_pair_bf.cpp
// VERSION 2
// Glenn G. Chappell
// 23 Sep 2015
// Updated: 18 Oct 2015
//
// For CS 411/611 Fall 2015
// Brute-Force Closest-Pair

#include "grand.h"
// For class GRand - easy pseuorandom number generation
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <cmath>
using std::sqrt;
#include <cstddef>
using std::size_t;
#include <cstdlib>
using std::exit;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <algorithm>
using std::swap;
#include <cassert>  // for assert


// getNum
// Prints prompt to cout and then inputs a number of type int on a line
// from cin. Repeats until valid number obtained; returns it to caller
// in reference argument. Return is false if number could not be
// obtained.
bool getNum(const string & prompt,
            int & num)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())
                return false;
            continue;
        }

        istringstream istr(line);
        istr >> num;
        if (!istr)
            continue;
        return true;
    }
}


// struct Pt2
// Holds a 2-D point in the obvious way
struct Pt2 {
    Pt2(double theX, double theY)
        :x(theX),
         y(theY)
    {}

    double x;
    double y;
};


// dist
// Given two Pt2 objects, returns the distance between them.
double dist(const Pt2 & p1,
            const Pt2 & p2)
{
    double xd = p1.x - p2.x;
    double yd = p1.y - p2.y;
    return sqrt(xd*xd + yd*yd);
}


// randPt2
// Returns a random Pt2 object, both coordinates in range [min, max],
//  uniformly distributed, based on given PRNG.
Pt2 randPt2(GRand & r,
            double min=0.,
            double max=1.)
{
    double x = r.d(max-min)+min;
    double y = r.d(max-min)+min;
    return Pt2(x, y);
}


// printPair
// Given a list of Pt2 objects and a pair of indices in this list,
// output the points with the given indices, in order of increasing
// index, along with the distance between the two points.
void printPair(const vector<Pt2> & pts,
               pair<size_t, size_t> p)
{
    size_t a = p.first;
    size_t b = p.second;
    if (b < a)
        swap(a, b);
    cout << a << ": (" << pts[a].x << ", " << pts[a].y << ")" << endl;
    cout << b << ": (" << pts[b].x << ", " << pts[b].y << ")" << endl;
    cout << "Distance: " << dist(pts[a], pts[b]) << endl;
}


// closestPair_bf
// Given vector of Pt2 objects, returns a std::pair holding the indices
//  of a closest pair of distinct points.
// Uses brute-force method.
// Pre:
//     pts.size() >= 2.
pair<size_t, size_t> closestPair_bf(const vector<Pt2> & pts)
{
    size_t n = pts.size();  // Number of pts in dataset
    assert (n >= 2);

    // Variables holding best pair so far & distances to compare
    // Best pair so far is initialized to first 2 pts given
    pair<size_t, size_t> closepair(0, 1);     // Indices of best pair
    double closedist = dist(pts[0], pts[1]);  // Distance of best pair
    double newdist;                           // Distance of new pair

    // Loop through all pairs of indices i,j with 0 <= i < j < n
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i+1; j < n; ++j)
        {
            // Find distance of current pair
            newdist = dist(pts[i], pts[j]);

            // Is this pair closer than best so far?
            if (newdist < closedist)
            {
                // Found closer pair; save it
                closepair.first = i;
                closepair.second = j;
                closedist = newdist;
            }
        }
    }

    // Return indices of closest pair
    return closepair;
}


// main
// Generate list of random 2-D pts, find closest pair, print results.
int main()
{
    GRand r;                           // Our PRNG; seeded unpredictably
    cout << fixed << setprecision(8);  // Floating-point output format

    // Get number of points
    int numpts;
    while (true)
    {
        bool success =
            getNum("Number of points (at least 2)? ", numpts);
        if (!success)
            exit(1);
        if (numpts >= 2)
            break;
        cout << endl;
        cout << "Number of points must be at least 2" << endl;
    }
    cout << endl;

    // Generate list of points
    vector<Pt2> pts;
    for (int i = 0; i < numpts; ++i)
    {
        pts.push_back(randPt2(r, -100., 100.));
    }

    // Print coordinates, if not many points; print how many points
    if (numpts <= 10)
    {
        cout << "Points:" << endl;
        for (int i = 0; i < numpts; ++i)
        {
            cout << i << ": (" << pts[i].x << ", " << pts[i].y << ")"
                 << endl;
        }
        cout << endl;
    }
    cout << numpts << " points generated" << endl;
    cout << endl;

    // Variables for results
    pair <size_t, size_t> closepair;  // Indices of closest pair

    // Print closest pair (Brute-Force method)
    cout << "Closest pair (Brute-Force method):" << endl;
    closepair = closestPair_bf(pts);
    printPair(pts, closepair);
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

