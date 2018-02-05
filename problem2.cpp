// https://projecteuler.net/problem=2
// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

#include <math.h>

const double sqrt_5 = sqrt(5);
const double phi = (1.0 + sqrt_5)/2.0;
const double psi = -1.0/phi;

// find the nth fibonacci number based on Binet's formula
// see here: https://en.wikipedia.org/wiki/Fibonacci_number#Closed-form_expression
unsigned long long fibonacci(unsigned n)
{
    return (unsigned long long)((pow(phi, n) - pow(psi, n))/sqrt_5);
}

const double log_sqrt_5 = log(sqrt_5);
const double log_phi = log(phi);

// find the largets fibonacci number smaller than n (based on approximation)
// see here: https://en.wikipedia.org/wiki/Fibonacci_number#Computation_by_rounding
unsigned long long find_nearest_fibonacci_index(unsigned n)
{
    return (unsigned long long)((log(n) + log_sqrt_5)/log_phi);
}

unsigned long long Problem2()
{
    const unsigned index_before_4M = find_nearest_fibonacci_index(4000000);
    // Sum of fibonacci series up to the nth element is:
    // S(n) = Fibonacci(n+2) -1
    // Sum of even values elements equals the sum of all elements divided by 2:
    return (fibonacci(index_before_4M+2) - 1 )/2;
}

