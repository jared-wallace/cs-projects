#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ncurses.h>
#include "stack.h"
#include "stackobj.h"

using namespace std;

Stack::Stack(){
  current_base = 'd';
}

void Stack::pop(){
  if (!stack.empty())
    stack.pop_back();
}

void Stack::push(string input){
  double base = 0.0;
  string buf = "";
  double value = 0.0;

  switch (current_base){
    case 'd':
      base = 10.0;
      break;
    case 'b':
      base = 2.0;
      break;
    case 'o':
      base = 8.0;
      break;
    case 'h':
      base = 16.0;
      break;
    default:
      cerr << "Error is base selection switch";
  }

  string fractional = "", integer = "";
  //separate into fractional and integer
  int i = 0;
  while (input[i] != '.' && i < input.length()){
    integer += input[i];
    i++;
  }
  i++;    //advance past decimal
  while (i < input.length()){
    fractional += input[i];
    i++;
  }
  // reverse the integer part so we can convert
  reverse (integer.begin(), integer.end());
  //do our conversion
  for (int i = 0; i < integer.length(); i++){
    switch (integer[i]){
      case 'A':
        value += 10.0 * pow(base, i);
        break;
      case 'B':
        value += 11.0 * pow(base, i);
        break;
      case 'C':
        value += 12.0 * pow(base, i);
        break;
      case 'D':
        value += 13.0 * pow(base, i);
        break;
      case 'E':
        value += 14.0 * pow(base, i);
        break;
      case 'F':
        value += 15.0 * pow(base, i);
        break;
      default:
        value += ((integer[i] - '0') * pow(base, i));
    }
  }

    //now we convert the fractional part
    for (int i = 0; i < fractional.length(); i++){
      switch (fractional[i]){
        case 'A':
          value += (10.0 * (1/(pow(base, i+1))));
          break;
        case 'B':
          value += (11.0 * (1/(pow(base, i+1))));
          break;
        case 'C':
          value += (12.0 * (1/(pow(base, i+1))));
          break;
        case 'D':
          value += (13.0 * (1/(pow(base, i+1))));
          break;
        case 'E':
          value += (14.0 * (1/(pow(base, i+1))));
          break;
        case 'F':
          value += (15.0 * (1/(pow(base, i+1))));
          break;
        default:
          value += ((fractional[i] - '0') * (1/(pow(base, i+1))));
      }
    }

  StackObject new_stack_object(value);
  stack.push_back(new_stack_object);
}

void Stack::repeat(){
  int last_object = stack.size()-1;
  StackObject new_stack_object(stack.at(last_object));
  stack.push_back(new_stack_object);
}
void Stack::display(int row, int col){
  //draw vertical line
  mvvline(1, 39, 124, row-3);
  //draw stack numbers
  int count = 1;
  for (int i = row-3; i>0; i--){
    mvprintw(i, 40, "%d:", count);
    count++;
  }
  //clear old values
  for (int i = 3; i < row; i++){
    move(row-i, 43);
    clrtoeol();
  }
  //draw stack values
  for (int i = 0; i < stack.size(); i++){
    switch (current_base){
      case 'd':{
        int string_length = stack.at(stack.size()-i-1).decimal_value().length();
        mvprintw(row-i-3, 80-string_length, "%s", stack.at(stack.size()-i-1).decimal_value().c_str());
        break;}
      case 'b':{
        int string_length = stack.at(stack.size()-i-1).binary_value().length();
        mvprintw(row-i-3, 80-string_length, "%s", stack.at(stack.size()-i-1).binary_value().c_str());
        break;}
      case 'o':{
        int string_length = stack.at(stack.size()-i-1).octal_value().length();
        mvprintw(row-i-3, 80-string_length, "%s", stack.at(stack.size()-i-1).octal_value().c_str());
        break;}
      case 'h':{
        int string_length = stack.at(stack.size()-i-1).hex_value().length();
        mvprintw(row-i-3, 80-string_length, "%s", stack.at(stack.size()-i-1).hex_value().c_str());
        break;}
    }
  }
  //draw horizontal line
  mvhline(row-2, 1, 95, 80);
  move(row-1, 81);
}

void Stack::set_current_base(char ch){
  current_base = ch;
}
