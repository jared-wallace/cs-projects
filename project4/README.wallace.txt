@author: Jared Wallace, A04111604
@date: 09-18-2012

General
============================================================================

This program is a basic ASCII art generator. It can produce the following
shapes:
  vertical line
  horizontal line
  widely spaced horizontal line
  solid square
  hollow square
  solid rectangle
  hollow rectangle
  US flag

I have split the program up into different files. Each class declaration and
implementation is in their respectively named files.


Compiling
============================================================================

The usual warnings apply, make sure you name the file properly (main.cpp)
and save the file before attempting to compile it. I have tested it only
with the gcc compiler.

To compile on the linux command line type
"g++ main.cpp rectangle.cpp triangle.cpp shape.cpp"
after navigating to the relevant folder.

Running
============================================================================

The program should catch any invalid input and handle it seamlessly. The
program is designed to only allow sizes between 1 and 35. This is to ensure
maximum compatibility with different size console windows. If you wish to 
try your luck, feel free to modify the values inside Shape's "inputValidate"
function.

Troubleshooting
============================================================================

If for any reason you get unexpected or incorrect output, email me at 
parrotbsd@gmail.com
