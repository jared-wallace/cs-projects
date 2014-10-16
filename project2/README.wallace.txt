@author: Jared Wallace, A04111604
@date: 09-18-2012

General
============================================================================

This program is a basic Polish notation calculator. By Polish Notation, I 
mean you enter the operator first, then the operands.
The available functions at this time include:
    addition
    subtraction
    multiplication
    division
    exponential
    factorial
    reciprocal
    and modulus(remainder)

Compiling
============================================================================

The usual warnings apply, make sure you name the file properly (main.cpp)
and save the file before attempting to compile it. As always, I have
tested it on VS 2012, g++,and  Netbeans 7.2. I still have no Macintosh,
so the program has not been tested on that platform, nor has it been
tested with Eclipse, as my current installation of Eclipse is not working.

Running
============================================================================

This program should catch most unexpected inputs with an error message
and the option to try again or to quit the program immediately.
For the division function, since we are using integers the answer will
be in the form 'quotient' with a 'remainder'. This should
help alleviate any potential issues with integer division.
The factorial function is only guaranteed to work for integers of 12 and
below. I elected to use 'long int' so that hopefully the factorial function
will be able to handle a few more numbers. On my two 64 bit machines, that
holds true. If you enter a number greater than 12 for the factorial function,
the program will warn about the potential for an incorrect answer.

Troubleshooting
============================================================================

If you happen to enter something other than an integer, like for example
a real number such as '.5' the program will behave unexpectedly. If this
happens, just 'ctrl + c' to halt the program. This is especially relevant
for the factorial operation.
