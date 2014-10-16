#include <iostream>
#include <string>
#include "stackobj.h"
#include "stack.h"

using namespace std;

int main(){

  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  int ch, row, col;


  Stack stack1;
  bool quit = false;
  string value = "";
  char base;
  int choice = 0;

  while (!quit){
    cout << "Choose an option" << endl;
    cout <<endl << "1) Add a value" << endl;
    cout << "2) Display stack" << endl;
    cout << "3) Change base" << endl;
    cout << "4) Quit" << endl;
    cin >> choice;
    switch (choice){
    case 1:
      cout << endl << "Enter a value ";
      cin >> value;
      stack1.push(value);
      break;
    case 2:
      cout << endl;
      stack1.display();
      break;
    case 3:
      cout << "Enter the base ";
      cin >> base;
      stack1.set_current_base(base);
      break;
    case 4:
      quit = true;
    }
  }
  return 0;
}
