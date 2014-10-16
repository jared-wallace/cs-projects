#include <iostream>
#include <string>
#include <ncurses.h>
#include "stackobj.h"
#include "stack.h"

using namespace std;

int main(){

  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  int ch, row, col;
  //get console size
  getmaxyx(stdscr, row, col);
  //instantiate stack1
  Stack stack1;
  //value will hold the input from the user
  string value = "";
  value.reserve(50);

  //start our input loop
  do{
    stack1.display(row, col);
    refresh();
    ch = getch();
    switch (ch){
      case 10://enter
        if (value == ""){
          stack1.repeat();
          break;
        }
        stack1.push(value);
        //reset value for next entry
        value = "";
        //"wipe" entry off screen
        move(row-1, 40);
        clrtoeol();
        break;
      case 92://backslash
        stack1.pop();
        break;
      case 111:
        stack1.set_current_base('o');
        break;
      case 98:
        stack1.set_current_base('b');
        break;
      case 100:
        stack1.set_current_base('d');
        break;
      case 104:
        stack1.set_current_base('h');
        break;
      default:
        value += ch;
        mvprintw(row-1, 80-(value.length()), "%s", value.c_str());
    }
    refresh();
  }while(ch != 113);
  endwin();
  return 0;
}
