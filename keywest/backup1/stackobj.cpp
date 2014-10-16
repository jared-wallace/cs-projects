#include <string>
#include <cmath>
#include <algorithm>
#include "stackobj.h"

using namespace std;

StackObject::StackObject(double initial_value){
  decimal_value_ = ConvertToString(initial_value, 10);
  binary_value_ = ConvertToString(initial_value, 2);
  octal_value_ = ConvertToString(initial_value, 8);
  hex_value_ = ConvertToString(initial_value, 16);
}

/*
  This function converts a decimal number to any base 16 or less.
*/
string StackObject::ConvertToString(double value, int base) {

  string buf;
  buf.reserve(50);

  int quotient = value;
  double fraction = abs(value)-abs(quotient);
  value = quotient; //want to work with the whole number portion
  do
  {
    buf += "0123456789ABCDEF"[abs(quotient%base)];
    quotient /= base;
  } while (quotient);
  if ( value < 0)
    buf += '-';
  reverse( buf.begin(), buf.end() );
  buf += ConvertFractionToString(fraction, base);
  return buf;
}

string StackObject::ConvertFractionToString(double value, int base) {

  string buf;
  buf.reserve(50);
  //For whole numbers, we don't need to do anything
  if (!value)
    return buf;

  buf += ".";

  int whole, count = 0;
  do
  {
    //multiply the first digit by the base
    whole = value*base;
    //based on prev calculation, select appropriate digit
    //and place after decimal point
    if (whole)
      buf += "0123456789ABCDEF"[whole];
    //adjust our fractional portion
    value = (value*base)-whole;
    //trying to truncate
    count++;

  } while (value && count < 10);
  return buf;
}
