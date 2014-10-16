#ifndef STACKOBJ_H
#define STACKOBJ_H

#include <string>

using namespace std;

class StackObject {

  private:
    int decimal_working_value;
    string decimal_value_;
    string binary_value_;
    string octal_value_;
    string hex_value_;
    //conversion function
    string ConvertToString(double, int);
    string ConvertFractionToString(double, int);
  public:
    string decimal_value() { return decimal_value_; }
    string binary_value() { return binary_value_; }
    string octal_value() { return octal_value_; }
    string hex_value() { return hex_value_; }
    StackObject(double);

};
#endif
