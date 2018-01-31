// coinrow.cpp
// Glenn G. Chappell
// 4 Nov 2015
//
// For CS 411/611 Fall 2015
// Simple Bottom-Up Dynamic-Programming Example

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <cstdlib>
using std::size_t;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;
#include <cassert>
// for assert


// getYN
// Prompt user with given string, repeatedly input until user types a
// string beginning with 'y', 'Y', 'n', or 'N'. Return yes/no to caller
// as bool (true means yes). Exit on EOF.
bool getYN(const string & prompt)
{
    while (true)
    {
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        if (line.size() > 0 && (line[0] == 'y' || line[0] == 'Y'))
            return true;
        if (line.size() > 0 && (line[0] == 'n' || line[0] == 'N'))
            return false;

        cout << endl;
        cout << "Please type \"y\" or \"n\"" << endl;
    }
}


// coinRow_bf_recurse
// Returns maximum sum of subset of values[0] .. values[n-1], on the
// condition that no two consecutive values lie in the subset. Assumes
// that all items in values are nonnegative.
// Brute-force method.
// Recursive helper for function coinRow_bf.
int coinRow_bf_recurse(const vector<int> & values,
                       size_t n)
{
    assert(n <= values.size());

    // BASE CASE
    if (n <= 1)
    {
        if (n == 0)
            return 0;
        return values[0];
    }

    // RECURSIVE CASE
    int max_without_last = coinRow_bf_recurse(values, n-1);
    int max_with_last = values[n-1] + coinRow_bf_recurse(values, n-2);
    int max_over_all = max(max_without_last, max_with_last);
    return max_over_all;
}


// coinRow_bf
// Returns maximum sum of subset of given values, on the condition that
// no two consecutive values lie in the subset. Assumes values are all
// nonnegative.
// Brute-force method.
// Uses recursive helper function coinRow_bf_recurse.
int coinRow_bf(const vector<int> & values)
{
    return coinRow_bf_recurse(values, values.size());
}


// coinRow_dp
// Returns maximum sum of subset of given values, on the condition that
// no two consecutive values lie in the subset. Assumes values are all
// nonnegative.
// Uses dynamic programming.
int coinRow_dp(const vector<int> & values)
{
    size_t n = values.size();

    vector<int> saved(n+1, 0);  // saved[i] is max for 1st i coins
    if (n >= 1) saved[1] = values[0];

    for (size_t i = 2; i <= n; ++i)
    {
        int max_without_last = saved[i-1];
        int max_with_last = values[i-1] + saved[i-2];
        int max_over_all = max(max_without_last, max_with_last);
        saved[i] = max_over_all;
    }
    return saved[n];
}


// try_coinRow
// Calls functions on a list of the given size; prints results.
void try_coinRow(size_t n,
                 bool dobf)  // True if we do brute-force method
{
    // Values to push
    vector<int> valuepattern { 1, 10, 1, 10, 10, 1, 10, 1 };

    // Make dataset
    vector<int> values;
    for (size_t i = 0; i != n; ++i)
        values.push_back(valuepattern[i%valuepattern.size()]);

    // Call coin-row function(s)
    cout << "Number of values: " << n << endl;
    cout << "Result (dynamic-programming version): " << endl;
    cout << "    " << coinRow_dp(values) << endl;
    if (dobf)
    {
        cout << "Result (brute-force version): " << endl;
        cout << "    " << coinRow_bf(values) << endl;
    }
    cout << endl;
}


// Main program
// Try functions for increasing input sizes.
int main()
{
    // Ask user whether to do brute-force computation
    cout << "Coin Row Problem, Dynamic Programming Method" << endl;
    cout << endl;
    string prompt =
        "Also use brute-force method (for comparison)? [y/n] ";
    bool do_brute_force = getYN(prompt);
    cout << endl;

    // Loop through problem sizes
    for (size_t i = 0; i < 100000000; ++i)
        try_coinRow(i, do_brute_force);

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

