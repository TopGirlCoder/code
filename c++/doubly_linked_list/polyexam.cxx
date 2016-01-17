// FILE: polyexam2.cxx
// Written by: Michael Main (main@colorado.edu), Sep 8, 2000
// Non-interactive test program for the polynomial class
// from http://www.cs.colorado.edu/~main/chapter5/poly2.cxx

#include <climits>   // Provides UINT_MAX
#include <cmath>     // Provides fabs
#include <cstdlib>   // Provides rand
#include <cstring>   // Provides memcpy
#include <iostream>  // Provides cout
#include "poly.h"
using namespace std;
using namespace main_savitch_5;
const unsigned int TESTSIZE = 200;

// Descriptions and points for each of the tests:
const size_t MANY_TESTS = 11;
const int POINTS[MANY_TESTS+1] = {
     75, // Total points for all tests.
     25, // Test 1 points
     5,  // Test 2 points
     5,  // Test 3 points
     5,  // Test 4 points
     5,  // Test 5 points
     5,  // Test 6 points
     5,  // Test 7 points
     5,  // Test 8 points
     5,  // Test 9 points
     5,  // Test 10 points
     5   // Test 11 points
};

const char DESCRIPTION[MANY_TESTS+1][256] = {
    "tests for polynomial class",
    "Testing basic functions",
    "Testing derivative function",
    "Testing eval and operator ( )",
    "Testing next_term and previous_term function",
    "Testing operator +",
    "Testing operator -",
    "Testing operator *",
    "Testing operator <<",
    "Testing find_root",
    "Testing copy constructor",
    "Testing assignment operator"
};


// **************************************************************************
// bool close(double a, double b)
//   Returns true if a is within EPSILON of b.
// **************************************************************************
bool close(double a, double b)
{
    const double EPSILON = 0.0001;

    return (fabs(a-b) < EPSILON) || (fabs(1-a/b) < EPSILON);
}

// **************************************************************************
// bool correct(const polynomial& test, unsigned int d, double c[ ])
//   This function determines if the polynomial (test) is "correct" according
//   to these requirements:
//   a. its degree is d 
//   b. For each i in the range 0...(degree), test.coefficient(i) is c[i].
// **************************************************************************
bool correct(const polynomial& test, unsigned int d, double count[])
{
    size_t i;
    bool answer = true;
    if (test.degree( ) != d)
    {
		cout << "Incorrect degree. " << endl;
			answer = false;
    }
    else
    {
        for (i = 0; i <= d; ++i)
		{
				if (!close(count[i], test.coefficient(i)))
			{  
				cout << "Incorrect coefficient(" << i << ")" << endl;
				answer = false;
			}
		}
		for (i = d+1; i <= TESTSIZE; ++i)
		{
			if (!close(test.coefficient(i), 0))
			{  
				cout << "Incorrect-coefficient(" << i << ")" << endl;
				answer = false;
			}
		}
		// Add a few random coefficients:
		if (!close(count[d/2], test.coefficient(d/2)))
		{
			cout << "Incorrect coefficient when examined a second time.";
			answer = false;
		}
		if (!close(count[d], test.coefficient(d)))
		{
			cout << "Incorrect coefficient when examined a second time.";
			answer = false;
		}
		if (!close(count[d/2], test.coefficient(d/2)))
		{
			cout << "Incorrect coefficient when examined a second time.";
			answer = false;
		}
		cout << (answer ? "Test passed.\n" : "Test failed.\n") << endl;
    }
    return answer;
}

double test1( )
{
    polynomial empty, x_squared(1.0, 2), p, also_empty(0.0, 3);;
    cout << "nonzero poly " << x_squared << endl;
    double c[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    double rand_c[TESTSIZE];
    size_t i;

    cout << "I will now test the default constructor. After initializing\n"
         << "with the default constructor, a the coefficient member\n"
	 << "function should always return zero (even beyond MAX_EX)."
	 << endl;
    if (!correct(empty, 0, c)) return 0;

    cout << "I will now test the constructor with arguments." << endl;
    c[2] = 1.0;
    if (!correct(x_squared, 2, c)) return 0;

    cout << "I will now test constructor like this: polynomial p(0.0, 3).\n"
         << "After initializing this way, a polynomial\n"
	 << "should have all zero coefficients (even beyond MAX_EX)."
	 << endl;
    if (!correct(also_empty, 0, c)) return 0;

    cout << "I will now test assign_coef." << endl;
    p.assign_coef(10.0, 5);
    c[5] = 10.0;
    p.assign_coef(1.0, 2);
    if (!correct(p, 5, c)) return 0;
    cout << "Checking that assign_coef correctly adjusts degree downward." << endl;
    p.assign_coef(0.0, 5);
    c[5] = 0.0;
    if (!correct(p, 2, c)) return 0;

    cout << "I will now test add_to_coef." << endl;
    //cout << "p before adding " << p << endl;
    p.add_to_coef(2.0, 2);
    c[2] += 2.0;
    if (!correct(p, 2, c)) return 0;

    cout << "Checking that add_to_coef correctly adjusts degree downward." << endl;
    //cout << "p before adding " << p << endl;
    p.assign_coef(1.0, 10);
    p.add_to_coef(-p.coefficient(10), 10);
      // cout << "p after adding " << p << endl;
    if (!correct(p, 2, c)) return 0;

    cout << "I will now test the clear function." << endl;
    p.clear( );
    c[2] = 0.0;
    if (!correct(p, 0, c)) return 0;

    cout << "Inserting " << TESTSIZE << " random coefficients\n";
    cout << "   and then checking the basic functions.";
    cout << endl;
    for (i = 0; i < TESTSIZE; i++)
    {
	rand_c[i] = ((rand( ) % 1000)/100.0)+1;
	p.assign_coef(rand_c[i], i);
    }
    rand_c[TESTSIZE/2] = ((rand( ) % 1000)/100.0)+ 1;
    p.assign_coef(rand_c[TESTSIZE/2], TESTSIZE/2);
    if (!correct(p, TESTSIZE-1, rand_c)) return 0;

    return POINTS[1];
}


// Test derivative function 
double test2( )
{
    polynomial p;
    double c[TESTSIZE];
    unsigned int i;

    cout << "Testing derivative." << endl;
    p.assign_coef(((rand( ) % 1000)/100.0), 0);
    for (i = 1; i <= TESTSIZE; ++i)
    {
	p.assign_coef(((rand( ) % 1000)/100.0), i);
	c[i-1] = i * p.coefficient(i);
    }
    p.assign_coef(0.0, TESTSIZE/2);
    c[(TESTSIZE/2)-1] = 0.0;
    if (!correct(p.derivative( ), TESTSIZE-1, c)) return 0;

    return POINTS[2];
}

// Testing eval
double test3( )
{
    polynomial p;
    double value = 0.0;
    double power_of_x = 1.0;
    unsigned int i;
    const double X = 3.0;
    double c;

    cout << "Testing eval and operator ( )." << endl;
    for (i = 0; i < TESTSIZE; ++i)
    {
	c = ((rand( ) % 1000)/100.0);
        if (i == TESTSIZE/2) c = 0.0;
	p.assign_coef(c, i);
	value += c * power_of_x;
	power_of_x *= X;
    }
    cout << p.eval(X) << " should be " << value << endl;
    if (!close(p.eval(X), value)) return 0;
    if (!close(p(X), value)) return 0;

    return POINTS[3];
}

// Test next_term function 
double test4( )
{
    polynomial p;
    unsigned int i;

    for (i = 0; i <= TESTSIZE; ++i)
    {
		p.assign_coef(((rand( ) % 1000)/100.0)+1, i);
    }
	p.assign_coef(0.0, TESTSIZE/2);

    cout << "Testing next_term function." << endl;
    for (i = 0; i < TESTSIZE; ++i)
    {
		if ((i != (TESTSIZE/2) - 1) && (p.next_term(i) != i+1))
		{
			cout << i << " should next to " << i + 1 << endl; 
			return 0;
		}
		if (p.next_term((TESTSIZE/2)-1) != (TESTSIZE/2)+1)
		{
			cout << (TESTSIZE/2)-1 << " should next to " << (TESTSIZE/2)+1 << endl; 
			return 0;
		}
		for (i = TESTSIZE; i < 2*TESTSIZE; ++i)
		{
			cout << "Testing next_term(" << i << ")" << endl;
			if (p.next_term(i) != 0)
			{
				cout << i << " should next to " << 0 << endl; 
				return 0;
			}
		}
		cout << "Testing next_term(UINT_MAX)." << endl;
		if (p.next_term(UINT_MAX) != 0)
		{
				cout << UINT_MAX << " should next to " << 0 << endl; 
				return 0;
		}
		cout << "Next Term Function is okay." << endl;

	}
    cout << "Testing previous_term function." << endl;
    for (i = 1; i <= TESTSIZE; ++i)
    {
		if ((i != (TESTSIZE/2) + 1) && (p.previous_term(i) != i-1))
			return 0;
    }
    if (p.previous_term((TESTSIZE/2)+1) != (TESTSIZE/2)-1)
		return 0;
    for (i = TESTSIZE+1; i < 2*TESTSIZE; ++i)
    {
		if (p.previous_term(i) != TESTSIZE)
			return 0;
    }
    cout << "Testing previous_term(0)." << endl;
    if (p.previous_term(0) != UINT_MAX)
        return 0;
    p.assign_coef(0,0);
    if (p.previous_term(1) != UINT_MAX)
	return 0;
	
    return POINTS[4];
}

// Test operator + function 
double test5( )
{
    polynomial p, q;
    double c[TESTSIZE + 1];
    unsigned int i;
    cout << "Testing operator +" << endl;
    for (i = 0; i < TESTSIZE; ++i)
    {
	p.assign_coef(((rand( ) % 1000)/100.0), i);
	q.assign_coef(((rand( ) % 1000)/100.0), i);
	c[i] = p.coefficient(i) + q.coefficient(i);
    }
    p.assign_coef(((rand( ) % 1000)/100.0)+1, TESTSIZE);
    c[TESTSIZE] = p.coefficient(TESTSIZE);
    
    if (!correct(p+q, TESTSIZE, c)) return 0;

    return POINTS[5];
}

// Test operator - function 
double test6( )
{
    polynomial p, q;
    double c[TESTSIZE + 1];
    unsigned int i;
    
    cout << "Testing operator -" << endl;
    for (i = 0; i < TESTSIZE; ++i)
    {
	p.assign_coef(((rand( ) % 1000)/100.0), i);
	q.assign_coef(((rand( ) % 1000)/100.0), i);
	c[i] = p.coefficient(i) - q.coefficient(i);
    }
    p.assign_coef(((rand( ) % 1000)/100.0)+1, TESTSIZE);
    c[TESTSIZE] = p.coefficient(TESTSIZE);
    
    if (!correct(p-q, TESTSIZE, c)) return 0;

    return POINTS[6];
}

// Test operator * function 
double test7( )
{
    polynomial p, q;
    
    double c[2*TESTSIZE + 1];
    unsigned int i,j;
    
    cout << "Testing operator *" << endl;
    for (i = 0; i < TESTSIZE; ++i)
    {
	p.assign_coef(((rand( ) % 1000)/100.0), i);
	q.assign_coef(((rand( ) % 1000)/100.0), i);
    }
    p.assign_coef(((rand( ) % 1000)/100.0)+1, TESTSIZE);
    q.assign_coef(((rand( ) % 1000)/100.0)+1, TESTSIZE);

    for (i = 0; i <= 2 * TESTSIZE; ++i)
	c[i] = 0.0;

    for (i = 0; i <= TESTSIZE; ++i)
	for (j = 0; j <= TESTSIZE; ++j)
	    c[i+j] += p.coefficient(i) * q.coefficient(j);
    
    if (!correct(p*q, 2*TESTSIZE, c)) return 0;

    return POINTS[7];
}

// Write a polynomial to cout for visual inspection
double test8( )
{
    polynomial p;

    p.assign_coef(-5.5, 5);
    p.assign_coef(+3.3, 3);
    p.assign_coef(-2.2, 2);
    p.assign_coef(1.1, 1);
    p.assign_coef(10.0, 0);

    cout << "Printing a polynomial for visual inspection by the TA: \n"
	 << p
	 << endl;

    return POINTS[8];
}

// Test find_root
double test9( )
{
    polynomial p;
    double answer = 0.0;
    bool success = true;
    unsigned int iterations = 1000;

    p.assign_coef(1.0, 2);
    p.assign_coef(-3.0, 0);
    
    cout << "Testing find_root for x^2 - 3 initial guess 0:" << endl;
    p.find_root(answer, success, iterations, 0, 100, 0.0001);
    if (success)
    {
	cout << "Incorrectly set success to true." << endl;
	return 0;
    }
    if (iterations > 0)
    {
	cout << "Incorrect number of iterations before failure." << endl;
	return 0;
    }
    if (answer != 0.0)
    {
	cout << "Incorrect answer (it should still be zero)." << endl;
	return 0;
    }

    cout << "Testing find_root for x^2 - 3 initial guess 0.5:" << endl;
    p.find_root(answer, success, iterations, 0.5, 100, 0.0001);
    if (!success)
    {
	cout << "Incorrectly set success to false." << endl;
	return 0;
    }
    if (!close(answer, sqrt(3.0)))
    {
	cout << "Incorrect answer (it should still be 1.73205)." << endl;
	return 0;
    }

    cout << "Testing find_root for x^2 + 3 initial guess 0.5:" << endl;
    p.assign_coef(3.0, 0);
    p.find_root(answer, success, iterations, 0.5, 7, 0.0001);
    if (success)
    {
	cout << "Incorrectly set success to true." << endl;
	return 0;
    }
    if (iterations != 7)
    {
	cout << "Incorrect number of iterations (should be maximum)." << endl;
	return 0;
    }

    return POINTS[9];
}

// Test copy constructor
double test10( )
{
    polynomial p;
    polynomial *ptr;
    double c[ ] = { 10.0, 1.1, -2.2, 3.3, 0.0, -5.5};
    
    p.assign_coef(-5.5, 5);
    p.assign_coef(+3.3, 3);
    p.assign_coef(-2.2, 2);
    p.assign_coef(1.1, 1);
    p.assign_coef(10.0, 0);

    cout << "Testing copy constructor:" << endl;
    ptr = new polynomial(p);
    p.assign_coef(1.0, 3);
    if (!correct(*ptr, 5, c)) return 0;
    
    return POINTS[10];
}

// Test assignment operator
double test11( )
{
    polynomial p;
    polynomial q;
    double c[ ] = { 10.0, 1.1, -2.2, 3.3, 0.0, -5.5};
    
    p.assign_coef(-5.5, 5);
    p.assign_coef(+3.3, 3);
    p.assign_coef(-2.2, 2);
    p.assign_coef(1.1, 1);
    p.assign_coef(10.0, 0);

    cout << "Testing assignment operator:" << endl;
    q = p;
    p.assign_coef(1.0, 3);
    if (!correct(q, 5, c)) return 0;
    
    return POINTS[11];
}


double run_a_test(int number, const char message[], double test_function( ), int max)
{
    double result;
    
    cout << endl << "START OF TEST " << number << ":" << endl;
    cout << message << " (" << max << " points)." << endl;
    result = test_function( );
    if (result > 0)
    {
        cout << "Test " << number << " got " << result << " points";
        cout << " out of a possible " << max << "." << endl;
    }
    else
        cout << "Test " << number << " failed." << endl;
    cout << "END OF TEST " << number << "." << endl << endl;
    
    return result;
}


// **************************************************************************
// int main( )
//   The main program calls all tests and prints the sum of all points
//   earned from the tests.
// **************************************************************************
int main( )
{
    double sum = 0;
    srand (time(NULL));
    
    cout << "Running " << DESCRIPTION[0] << endl;

    sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
    sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);
    sum += run_a_test(3, DESCRIPTION[3], test3, POINTS[3]);
    sum += run_a_test(4, DESCRIPTION[4], test4, POINTS[4]);
    sum += run_a_test(5, DESCRIPTION[5], test5, POINTS[5]);
    sum += run_a_test(6, DESCRIPTION[6], test6, POINTS[6]);
    sum += run_a_test(7, DESCRIPTION[7], test7, POINTS[7]);
    sum += run_a_test(8, DESCRIPTION[8], test8, POINTS[8]);
    sum += run_a_test(9, DESCRIPTION[9], test9, POINTS[9]);
    sum += run_a_test(10, DESCRIPTION[10], test10, POINTS[10]);
    sum += run_a_test(11, DESCRIPTION[11], test11, POINTS[11]);

    cout << "If you submit this to Dora now, you will have\n";
    cout << sum << " points out of the ";
    cout << POINTS[0];
    cout << " points from this test program.\n";
    
    return EXIT_SUCCESS;

}
