#include "MyString.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// ************************************************************************
// Testing Package:
//     Class Tester - For Tracking Tests
// ************************************************************************


// class Tester
// For extremely simple unit testing.
// Keeps track of number of tests and number of passes.
// Use test (with success/failure parameter) to do a test.
// Get results with numTests, numPassed, numFailed, allPassed.
// Restart testing with reset.
// Invariants:
//     countTests_ == number of tests (calls to test) since last reset.
//     countPasses_ == number of times function test called with true param
//      since last reset.
//     0 <= countPasses_ <= countTests_.
//     tolerance_ >= 0.
class Tester {

// ***** Tester: ctors, dctor, op= *****
public:

    // Default ctor
    // Sets countTests_, countPasses_ to zero, tolerance_ to given value
    // Pre: None.
    // Post:
    //     numTests == 0, countPasses == 0, tolerance_ == abs(theTolerance)
    // Does not throw (No-Throw Guarantee)
    Tester(double theTolerance = 0.0000001)
        :countTests_(0),
         countPasses_(0),
         tolerance_(theTolerance >= 0 ? theTolerance : -theTolerance)
    {}

    // Compiler-generated copy ctor, copy op=, dctor are used

// ***** Tester: general public functions *****
public:

    // test
    // Handles single test, param indicates pass/fail
    // Pre: None.
    // Post:
    //     countTests_ incremented
    //     countPasses_ incremented if (success)
    //     Message indicating test name (if given)
    //      and pass/fail printed to cout
    // Does not throw (No-Throw Guarantee)
    //  - Assuming exceptions have not been turned on for cout.
    void test(bool success,
              const std::string & testName = "")
    {
        ++countTests_;
        if (success) ++countPasses_;

        std::cout << "    ";
        if (testName != "")
        {
            std::cout << "Test: "
                      << testName
                      << " - ";
        }
        std::cout << (success ? "passed" : "********** FAILED **********")
                  << std::endl;
    }

    // ftest
    // Does single floating-point test.
    // Tests passes iff difference of first two values is <= tolerance.
    // Pre: None.
    // Post:
    //     countTests_ incremented
    //     countPasses_ incremented if (abs(val1-val2) <= tolerance_)
    //     Message indicating test name (if given)
    //      and pass/fail printed to cout
    // Does not throw (No-Throw Guarantee)
    void ftest(double val1,
               double val2,
               const std::string & testName = "")
    { test(val1-val2 <= tolerance_ && val2-val1 <= tolerance_, testName); }

    // reset
    // Resets *this to default constructed state
    // Pre: None.
    // Post:
    //     countTests_ == 0, countPasses_ == 0
    // Does not throw (No-Throw Guarantee)
    void reset()
    {
        countTests_ = 0;
        countPasses_ = 0;
    }

    // numTests
    // Returns the number of tests that have been done since last reset
    // Pre: None.
    // Post:
    //     return == countTests_
    // Does not throw (No-Throw Guarantee)
    int numTests() const
    { return countTests_; }

    // numPassed
    // Returns the number of tests that have passed since last reset
    // Pre: None.
    // Post:
    //     return == countPasses_
    // Does not throw (No-Throw Guarantee)
    int numPassed() const
    { return countPasses_; }

    // numFailed
    // Returns the number of tests that have not passed since last reset
    // Pre: None.
    // Post:
    //     return + countPasses_ == numTests_
    // Does not throw (No-Throw Guarantee)
    int numFailed() const
    { return countTests_ - countPasses_; }

    // allPassed
    // Returns true if all tests since last reset have passed
    // Pre: None.
    // Post:
    //     return == (countPasses_ == countTests_)
    // Does not throw (No-Throw Guarantee)
    bool allPassed() const
    { return countPasses_ == countTests_; }

    // setTolerance
    // Sets tolerance_ to given value
    // Pre: None.
    // Post:
    //     tolerance_ = abs(theTolerance)
    // Does not throw (No-Throw Guarantee)
    void setTolerance(double theTolerance)
    { tolerance_ = (theTolerance >= 0 ? theTolerance : -theTolerance); }

// ***** Tester: data members *****
private:

    int countTests_;    // Number of tests done since last reset
    int countPasses_;   // Number of tests passed since last reset
    double tolerance_;  // Tolerance for floating-point near-equality tests

};  // end class Tester

//tests the constructors
void TestConstructors(Tester & t)
{
  MyString ms1;

  //testing the constructor for size 0
  t.test(ms1.size()==0, "Testing default constructor");

//testing the constructor for size 10
  MyString ms2(10);
  t.test(ms2.size()==10, "Testing single parameter constructor");
  for(int i=0; i<ms2.size(); ++i)
  {
    ms2[i]=65+i;
  }


  //testing copy constructor
  MyString ms3(ms2);
  t.test(ms3.size()==10, "Testing copy constructor for size");

  bool equ=true;
  for(int i=0; i<ms2.size(); ++i)
  {
    if (ms2[i]!=ms3[i])
    {
      equ=false;
    }
  }
  t.test(equ,"Testing copy constructor for values");
}


void TestOperators(Tester & t)
{

  MyString ms1(10);
  for(int i=0; i<ms1.size(); ++i)
  {
    ms1[i]=65+i;
  }

  //testing operator <<
  ostringstream oss;
  oss << ms1;
  t.test(oss.str()=="ABCDEFGHIJ", "Testing insertion operator");

  //clear the osstring stream
  oss.str("");
  oss.clear();
  ms1[3]=88;
  oss << ms1;

  //testing bracket operator
  t.test(oss.str()=="ABCXEFGHIJ", "Testing bracket operator changing value");

  //clear oss
  oss.str("");
  oss.clear();

  //testing bracket operator
  oss << ms1[5];
  t.test(oss.str()=="F", "Testing bracket operator return");


  oss.str("");
  oss.clear();

  for(int i=0; i<ms1.size(); ++i)
  {
    ms1[i]=65+i;
  }


  MyString ms2(5);
  for(int i=0; i<ms2.size(); ++i)
  {
    ms2[i]=97+i;
  }

  //testing operator +
  oss << (ms1+ms2);
  t.test(oss.str()=="ABCDEFGHIJabcde", "Testing concatenation (+) operator");

  oss.str("");
  oss.clear();

  //testing operator=
  ms1=ms2;
  oss << ms1;
  t.test(oss.str()=="abcde", "Testing assignment operator unequal");

  oss.str("");
  oss.clear();

  ms1=ms1;
  oss << ms1;
  t.test(oss.str()=="abcde", "Testing assignment operator equal");


  oss.str("");
  oss.clear();

  //testing != and ==
  MyString ms3(2);
  t.test(ms2==ms1, "Testing equality when equal");
  t.test(!(ms2!=ms1), "Testing inequality when equal");
  t.test(!(ms3==ms1), "Testing equality when unequal");
  t.test(ms3!=ms1, "Testing inequality when unequal");

}
int main()
{
  Tester t;     //our tester

  cout << "Testing Constructors:" << endl;
  TestConstructors(t);

  cout << "Testing Operators" << endl;
  TestOperators(t);

  cout << endl;
  if (t.allPassed())
  {
    cout << "All tests successful"
    << endl;
  }
  else
  {
     cout << "Tests ********** UNSUCCESSFUL **********"
    << endl;
  }
  cout << endl;

  cout << "Press ENTER to quit ";
  while (cin.get() != '\n') ;

  return 0;
}
