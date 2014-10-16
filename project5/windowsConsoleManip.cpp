#include <windows.h>
#include "windowsConcoleManip.h"

using namespace std;

/* This function is copied in entirity from */
/* www.cplusplus.com/articles/4z18T05o/     */
/* It was written by Duoas on April 2009    */
void WindowsConsoleManip::clearScreen()
{
    HANDLE                      hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO  csbi;
    DWORD                       count;
    DWORD                       cellCount;
    COORD                       homeCoords = { 0, 0 };

    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /*Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
      hStdOut,
      (TCHAR) ' ',
      cellCount,
      homeCoords;
      &count
      )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
      hStdOut,
      csbi.wAttributes,
      cellCount,
      homeCoords,
      &count
      )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

void WindowsConsoleManip::sleepy(int time)
{
    Sleep(timeValue);
}

