// closest_pair_dc.cpp
// Glenn G. Chappell
// 18 Oct 2015
//
// For CS 411/611 Fall 2015
// Closest-Pair Using Divide-and-Conquer

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
using std::sort;
#include <numeric>
using std::iota;
#include <chrono>
using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;
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


// closestPair_dc_recurse
// Given vector of Pt2 objects, and 2 ranges of indices into this list:
//  one x-sorted, one y-sorted, returns a std::pair holding the indices
//  of a closest pair of distinct points.
// Recursive helper function for closestPair_dc.
// Uses Divide-and-Conquer method.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter is Pt2.
// Pre:
//     pts.size() >= 2.
//     No two items in pts have the same x-coordinate.
//     [xsort_f, xsort_l) is a valid range.
//     xsort_l-xsort_f >= 2.
//     Values in [xsort_f, xsort_l) are pairwise distinct indices into
//      pts. These are sorted by the x-coordinate of the indexed Pt2,
//      ascending.
//     [ysort_f, ysort_l) is a valid range.
//     ysort_l-ysort_f >= 2.
//     Values in [ysort_f, ysort_l) are pairwise distinct indices into
//      pts. These are sorted by the y-coordinate of the indexed Pt2,
//      ascending.
//     Ranges [xsort_f, xsort_l), [ysort_f, ysort_l) contain the same
//      values, possibly in different orders.
// Post:
//     Return is std::pair holding indices, in pts, of a closest pair of
//      distinct points whose indices lie in [xsort_f, xsort_l).
template<typename RAIter>
pair<size_t, size_t> closestPair_dc_recurse(
    const vector<Pt2> & pts,
    RAIter xsort_f, RAIter xsort_l,
    RAIter ysort_f, RAIter ysort_l)
{
    size_t n = xsort_l - xsort_f;
    assert (n >= 2);
    assert (n == ysort_l - ysort_f);
    assert (n <= pts.size());

    // Variables holding best pair so far & distances to compare
    pair<size_t, size_t> closepair;  // Indices of best pair
    double closedist;                // Distance of best pair
    double newdist;                  // Distance of new pair

    // BASE CASE

    const size_t SMALL_SIZE = 50;  // Max base case size (must be >= 3)
    assert (SMALL_SIZE >= 3);
    if (n <= SMALL_SIZE)
    {
        closepair.first = xsort_f[0];
        closepair.second = xsort_f[1];
                                  // Indices of first 2 pts
        closedist = dist(pts[closepair.first], pts[closepair.second]);
                                  // Distance of first 2 pts

        // Loop through all pairs of indices i,j with 0 <= i < j < n
        for (size_t i = 0; i < n; ++i)
        {
            size_t a = xsort_f[i];
            for (size_t j = i+1; j < n; ++j)
            {
                size_t b = xsort_f[j];

                // Find distance of current pair
                newdist = dist(pts[a], pts[b]);

                // Is this pair closer than best so far?
                if (newdist < closedist)
                {
                    // Found closer pair; save it
                    closepair.first = a;
                    closepair.second = b;
                    closedist = newdist;
                }
            }
        }

        // Return indices of closest pair
        return closepair;
    }

    // RECURSIVE CASE

    // Find median of x-coords of pts: xsplit
    size_t halfn = n/2;
    assert (halfn >= 2);
    assert (n-halfn >= 2);
    double x1 = pts[xsort_f[halfn-1]].x;
    double x2 = pts[xsort_f[halfn]].x;
    assert (x1 != x2);
    double xsplit = (x1+x2)/2.;

    // Create y-sorted list of indices of pts on lo, hi side of x split
    vector<size_t> lo_x_ysort;
    lo_x_ysort.reserve(halfn);
    vector<size_t> hi_x_ysort;
    hi_x_ysort.reserve(n-halfn);
    for (size_t i = 0; i < n; ++i)
    {
        size_t b = ysort_f[i];
        if (pts[b].x < xsplit)
            lo_x_ysort.push_back(b);
        else
            hi_x_ysort.push_back(b);
    }
    assert (lo_x_ysort.size() == halfn);
    assert (hi_x_ysort.size() == n-halfn);

    // Do 1st recursive call
    closepair = closestPair_dc_recurse(
        pts,
        xsort_f, xsort_f+halfn,
        lo_x_ysort.begin(), lo_x_ysort.end());
    closedist = dist(pts[closepair.first], pts[closepair.second]);

    // Do 2nd recursive call
    auto newpair = closestPair_dc_recurse(
        pts,
        xsort_f+halfn, xsort_l,
        hi_x_ysort.begin(), hi_x_ysort.end());
    newdist = dist(pts[newpair.first], pts[newpair.second]);

    // Did 2nd recursive call give better result?
    if (newdist <= closedist)
    {
        closepair = newpair;
        closedist = newdist;
    }

    // Deal with center strip: pts whose x-coordinates are within the
    // current minimum distance (closedist) of the x-coordinate split
    // point (xsplit).
    
    // Create y-sorted list of indices of pts in center strip
    vector<size_t> strip_ysort;
    strip_ysort.reserve(n);
    for (size_t i = 0; i < n; ++i)
    {
        size_t b = ysort_f[i];
        if (xsplit-closedist < pts[b].x && pts[b].x < xsplit+closedist)
            strip_ysort.push_back(b);
    }

    // Iterate through center strip
    // For each point, we consider the pairs consisting of this point
    // and each of the next 5 points.
    for (size_t i = 0; i < strip_ysort.size(); ++i)
    {
        size_t a = strip_ysort[i];
        for (size_t j = i+1; j < i+5 && j < strip_ysort.size(); ++j)
        {
            size_t b = strip_ysort[j];

            // Find distance of current pair
            newdist = dist(pts[a], pts[b]);

            // Is this pair closer than best so far?
            if (newdist < closedist)
            {
                // Found closer pair; save it
                closepair.first = a;
                closepair.second = b;
                closedist = newdist;
            }
        }
    }

    // Return indices of closest pair
    return closepair;
}


// closestPair_dc
// Given vector of Pt2 objects, returns a std::pair holding the indices
//  of a closest pair of distinct points.
// Calls closestPair_dc_recurse to do most of the work.
// Uses Divide-and-Conquer method.
// Pre:
//     pts.size() >= 2.
//     No two items in pts have the same x-coordinate.
// Post:
//     Return is std::pair holding indices, in pts, of a closest pair of
//      distinct points.
pair<size_t, size_t> closestPair_dc(const vector<Pt2> & pts)
{
    size_t n = pts.size();  // No. of pts in dataset
    assert (n >= 2);

    // Make x-sorted & y-sorted list of indices into pts
    vector<size_t> xsort(n);
    iota(xsort.begin(), xsort.end(), 0);
    sort(xsort.begin(), xsort.end(),
      [&pts](size_t a, size_t b) { return pts[a].x < pts[b].x; }
    );
    vector<size_t> ysort(n);
    iota(ysort.begin(), ysort.end(), 0);
    sort(ysort.begin(), ysort.end(),
      [&pts](size_t a, size_t b) { return pts[a].y < pts[b].y; }
    );

   return closestPair_dc_recurse(
       pts,
       xsort.begin(), xsort.end(),
       ysort.begin(), ysort.end());
}


// timeSec
// Returns time in seconds since -- something. Nanosecond resolution, if
//  system supports it.
double timeSec()
{
    auto nanos = static_cast<nanoseconds>(
        high_resolution_clock::now().time_since_epoch());
    return static_cast<double>(nanos.count())/1.e9;
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
    double time1;                     // Start time (sec)
    double time2;                     // End time (sec)
    double elapsedtime;               // Time for computation (sec)

    // Print closest pair (Divide-and-Conquer) method)
    cout << "Closest pair (Divide-and-Conquer method):" << endl;
    time1 = timeSec();
    closepair = closestPair_dc(pts);
    time2 = timeSec();
    printPair(pts, closepair);
    elapsedtime = time2 - time1;
    cout << "Elapsed time: " << elapsedtime << endl;
    cout << endl;

    // Print closest pair (Brute-Force method)
    cout << "Closest pair (Brute-Force method):" << endl;
    time1 = timeSec();
    closepair = closestPair_bf(pts);
    time2 = timeSec();
    printPair(pts, closepair);
    elapsedtime = time2 - time1;
    cout << "Elapsed time: " << elapsedtime << endl;
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

