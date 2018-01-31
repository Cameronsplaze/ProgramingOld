// use_hash.cpp
// Glenn G. Chappell
// 2 Nov 2015
//
// For CS 411/611 Fall 2015
// C++11 Hash Table Demo

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <utility>
using std::pair;
using std::make_pair;
#include <unordered_map>
using std::unordered_map;  // Hash table


// (1) Run the program. Note the order the traversal prints the keys.
// (2) Change ALL instances of unordered_map to map & recompile.
// (3) Note how this affects the traversal order.
// (4) Explain why the C++ Standardization Committee chose the name
//     "unordered_map".


// print_item
// Given an item from an unordered_map<string, int>, prints it in pretty
// form. No trailing newline.
void print_item(const pair<string, int> & p)
{
    // Each item in a table is a pair: key & value
    cout << "(key: \"" << p.first << "\", "
         << "value: " << p.second << ")";
}


// check_key
// Given a string -> int unordered_map, and a key (string):
// - Determine whether the key lies in the hash table and print a
//   message indicating the result.
// - If the key lies in the hash table, then print the key and
//   associated value.
void check_key(const unordered_map<string, int> & h,
               const string & key)
{
    // READ operation
    auto it = h.find(key);  // Could also use h.count(key) here
    cout << "Key \"" << key << "\" ";
    if (it == h.end())
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << "found ";
        print_item(*it);
        cout << endl;
    }
}


// Main program
// Create a hash table and look for various keys in it.
int main()
{
    // Introductory message

    cout << "Mucking about with a hash table" << endl;
    cout << endl;

    // Make hash table

    unordered_map<string, int> animalnum;  // Hash table

    // Insert ("dog", 42) into hash table (CREATE operation)
    animalnum.insert(make_pair("dog", 42));
    // More insertions - alternate method: bracket operator
    animalnum["cat"] = 9;
    animalnum["llama"] = 54321;
    animalnum["goat"] = 666;
    animalnum["lion"] = 1;
    animalnum["zebra"] = 1111111;
    cout << "Keys inserted: \"dog\", \"cat\", \"llama\", \"goat\", "
         << "\"lion\", \"zebra\"" << endl;
    cout << endl;

    // Change value associated with key "dog" (UPDATE operation)
    animalnum["dog"] = 1000000;

    // Can also read value associated with a key using bracket operator
    cout << "animalnum[\"dog\"]: " << animalnum["dog"] << endl;
    // BE CAREFUL! If the key is not in the dataset, then this inserts
    //  it, with the associated value set to a default-constructed
    //  value. So avoid doing this, if you intend to test whether a key
    //  is in the dataset.
    cout << endl;

    // Check whether various keys are in hash table

    check_key(animalnum, "dog");
    check_key(animalnum, "cat");
    check_key(animalnum, "hamster");
    cout << endl;

    // Eliminate a key

    cout << "Deleting key \"dog\"" << endl;
    animalnum.erase("dog");
    check_key(animalnum, "dog");
    cout << endl;

    // Traverse the table

    cout << "Traverse" << endl;
    for (const auto & p : animalnum)
    {
        cout << "Item ";
        print_item(p);
        cout << endl;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;

    return 0;
}

