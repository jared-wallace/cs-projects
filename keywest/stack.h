#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include "stackobj.h"

using namespace std;

class Stack {
  private:
    vector<StackObject> stack;
    char current_base;
    bool VerifyInput(string);
  public:
    void pop();
    void push(string);
    void repeat();
    void display(int, int);
    void set_current_base(char);
    Stack();
};

#endif
