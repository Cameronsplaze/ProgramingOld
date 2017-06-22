// cs372hw2.cpp
// Requires catch.hpp, cs372hw2.h, cs372hw2.cpp

// Includes for code to be tested
#include "cs372hw2.h"        // For Assignment 3 Functions & Templates
#include "cs372hw2.h"        // Double inclusion test

#define CATCH_CONFIG_MAIN  // We want Catch to write function main
#include "catch.hpp"       // For the "Catch" unit-testing framework

// Additional includes for this test program
#include <stdexcept>
using std::out_of_range;
using std::runtime_error;
#include <vector>
using std::vector;
#include <algorithm>
using std::equal;
#include <deque>
using std::deque;
#include <utility>
using std::pair;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;




// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE( "tdd-kata-1: string calculator to int" )
{
    SECTION( "Bace Cases: single numbers" )
    {
        REQUIRE( Add("") == 0 ); 
        REQUIRE( Add("0") == 0 );
        REQUIRE( Add("5") == 5 );

        REQUIRE( Add("10") == 10 );
        REQUIRE( Add("99") == 99 );
        REQUIRE( Add("222") == 222 );

        REQUIRE( Add("222999222") == 222999222 );
    }
    SECTION( "Two Numbers, non \\n seperation" )
    {
        REQUIRE( Add("0,0") == 0 ); 
        REQUIRE( Add("5,6") == 11 );
        REQUIRE( Add("9,9") == 18 );

        REQUIRE( Add("10,22") == 32 );
        REQUIRE( Add("2,78") == 80 );
        REQUIRE( Add("78,2") == 80 );
        
        REQUIRE( Add("100000,5") == 100005 );
    }
    SECTION( "Many Numbers, non \\n seperation" )
    {
        REQUIRE( Add("0,0,0,0,0,0") == 0 ); 
        REQUIRE( Add("5,6,9,10,1000,200") == 1230 );
        REQUIRE( Add("9,9,102") == 120 );
        REQUIRE( Add("10,22,8,20,5") == 65 );

        REQUIRE( Add("100000,5,3000,200") == 103205 );
    }
    SECTION( "Many Numbers, with \\n seperation" )
    {
        REQUIRE( Add("0\n0\n0\n0\n0\n0") == 0 ); 
        REQUIRE( Add("5\n6\n9\n10\n1000\n200") == 1230 );
        REQUIRE( Add("9\n9\n102") == 120 );
        REQUIRE( Add("10\n22\n8\n20\n5") == 65 );

        REQUIRE( Add("100000\n5\n3000\n200") == 103205 );
    }
    SECTION( "Many Numbers, mixed \\n seperation" )
    {
        REQUIRE( Add("0,0\n0,0,0\n0") == 0 ); 
        REQUIRE( Add("5,6,9\n10\n1000,200") == 1230 );
        REQUIRE( Add("9\n9,102") == 120 );
        REQUIRE( Add("10,22,8,20\n5") == 65 );

        REQUIRE( Add("100000,5\n3000,200") == 103205 );
    }
    // “//[delimiter]\n[numbers…]”
    SECTION( "Delimiter Tag of size 1" )
    {
        REQUIRE( Add("//t\n0,0t0t0,0\n0") == 0 ); 
        REQUIRE( Add("//@\n5,6,9@10\n1000@200") == 1230 );
        REQUIRE( Add("// \n9 9 102") == 120 );
        REQUIRE( Add("//*\n10,22*8,20*5") == 65 );

        REQUIRE( Add("//!\n100000!5\n3000!200") == 103205 );
    }
	//because i dont check what the delimiters, (Once i hit something thats not a number, 
	//skip it. next thing after it has to be number or '-') it doesn't matter what is between 
	//them, so to save time, i'm just using ',' from here on:
    SECTION( "Negative Numbers Mixed" )
    {
    	REQUIRE( Add("-0") == 0);
    	REQUIRE( Add("-5") == 0);
    	REQUIRE( Add("5,-6") == 5);
    	REQUIRE( Add("-7,6") == 6);
    	REQUIRE( Add("3,3,5,-7") == 11);
    	REQUIRE( Add("-4,-4,-4,2,-3") == 2);
    	REQUIRE( Add("-9000,-43634463,1000,100,10,9") == 1119);
    	REQUIRE( Add("50,50,-8989,7000,5,-98887") == 7105);
    	REQUIRE( Add("-9898,9000") == 9000);
    }
    //Same Delimiter tag for all because i dont save it in my program, so it wont matter what that
    //single char delimiter is. If i added multi-length delimiters, i would have to change these tests
    SECTION( "Negative Numbers Mixed With Delimiter Tag" )
    {
    	REQUIRE( Add("//t\n-0") == 0);
    	REQUIRE( Add("//t\n-5") == 0);
    	REQUIRE( Add("//t\n5,-6") == 5);
    	REQUIRE( Add("//t\n-7,6") == 6);
    	REQUIRE( Add("//t\n3,3,5,-7") == 11);
    	REQUIRE( Add("//t\n-4,-4,-4,2,-3") == 2);
    	REQUIRE( Add("//t\n-9000,-43634463,1000,100,10,9") == 1119);
    	REQUIRE( Add("//t\n50,50,-8989,7000,5,-98887") == 7105);
    	REQUIRE( Add("//t\n-9898,9000") == 9000);
    }

}


