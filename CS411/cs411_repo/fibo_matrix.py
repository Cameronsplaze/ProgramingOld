#!/usr/bin/env python3
# fibo_matrix.py
# Glenn G. Chappell
# 16 Sep 2015
#
# For CS 411/611 Fall 2015
"""Computing Fibonacci Numbers
Uses Matrix Product
Requires Python 3.x."""


# Note: Lines beginning ">>>" are doctests. If a command-line interface
# is available, then these can be executed by doing the following:
#
#     python3 -m doctest fibomat.py
#
# When doing the above, only the results of failing tests are printed.
# Thus, no output is good. To get the results of all tests, add "-v"
# (for "verbose"):
#
#     python3 -m doctest fibomat.py -v


def fibomat(n):
    """nonneg int n -> [F(n-1), F(n), F(n), F(n+1)]; F(k) is kth Fibo #

    F(0) = 0. F(1) = 1. For k >= 2, F(k) = F(k-2) + F(k-1).
    Return value is a 2x2 matrix in row-major order.

    Recursive. Values computed using matrix products.

    >>> fibomat(0)
    [1, 0, 0, 1]
    >>> fibomat(5)
    [3, 5, 5, 8]
    >>> fibomat(100)  #doctest: +NORMALIZE_WHITESPACE
    [218922995834555169026, 354224848179261915075,
    354224848179261915075, 573147844013817084101]

    """
    assert isinstance(n, int)
    assert n >= 0
    # 2x2 matrices are represented in row-major order
    # We compute & return matrix (0, 1, 1, 1) raised to nth power

    # BASE CASE
    # For n = 0, return identity matrix
    if n == 0:
        return [1, 0, 0, 1]

    # RECURSIVE CASE
    # Find the matrix for floor(n/2)
    mat = fibomat(n // 2) # Integer division

    # Compute mat2 = mat * mat, the matrix for 2 * floor(n/2)
    mat2 = [mat[0]*mat[0]+mat[1]*mat[2],
            mat[0]*mat[1]+mat[1]*mat[3],
            mat[2]*mat[0]+mat[3]*mat[2],
            mat[2]*mat[1]+mat[3]*mat[3]]
    # If n is even, we are done
    if n % 2 == 0:
        return mat2

    # Otherwise n is odd; return matrix (0, 1, 1, 1) * mat2
    return [mat2[2], mat2[3], mat2[0]+mat2[2], mat2[1]+mat2[3]]


def fibo(n):
    """nonnegative int n -> F(n), the nth Fibonacci no.

    F(0) = 0. F(1) = 1. For k >= 2, F(k) = F(k-2) + F(k-1).

    Uses fibomat.

    >>> fibo(0)
    0
    >>> fibo(5)
    5
    >>> fibo(300)
    222232244629420445529739893461909967206666939096499764990979600

    """
    assert isinstance(n, int)
    assert n >= 0
    return fibomat(n)[1]


def print_results(n):
    """Compute Fibonacci number F(n); print in pretty form."""

    print("F({}) = {}".format(n, fibo(n)))


# If this module is executed as a program (instead of being imported):
#  input n, print F(n), repeat until blank line input
if __name__ == "__main__":
    while True:
        print()
        print("Given integer n, I will compute Fibonacci number F(n).")
        print()
        try:
            line = input("Type n [blank line to exit]: ")
            if line == "": break
            n = int(line)
            if n < 0: raise Exception()
        except:
            print()
            print("Please type a nonnegative integer")
        else:
            print()
            print_results(n)
        print()
        print("-" * 60)

