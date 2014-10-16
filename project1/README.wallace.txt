Tip Computer, by Jared Wallace, A0411604

This program can be compiled on windows or linux.  Macintosh might be viable, but I have no way
to test whether or not it works.  You may use your compiler of choice, I have tested it on 
Eclipse (cygwin and gcc), Visual Studio 2012, NetBeans 7.2 and g++ on Linux Mint's command line.

For all cases, you obviously need a copy of the source code titled assg1.wallace.cpp

Windows

Using Visual Studio 2012:  Just make a new project, erase all the crap VS puts into your main.cpp,
    and copy/paste the source code into the main.cpp. Hit F7 to build it, and Ctrl+F5 to run it.

Using Eclipse: Make a new project like you normally do, don't forget to select cygwin when doing
    so, and create a new main.cpp file.  DO NOT forget to name the file main.cpp.  Also DO NOT
    forget to save the main.cpp after you have copy/pasted the source code.  Otherwise it
    will whine about some "undefined reference to _winmain @ 16". After doing that, it should
    build and run correctly. If it fails to, uninstall eclipse and get a real IDE ;P

Using NetBeans 7.2: Just create a new project (c++ Application). You can name the project 
    whatever you want, and accept all the other stuff as default. Open main.cpp and erase
    all the default crap NetBeans places in there.  Then copy/paste the source code. Press
    F11 to build it, and F6 to run it.

Linux

Check to see if gcc/g++ is installed (type "g++ --version" without the quotation marks into 
    the console.  If it says anything but an error message, you should be ok)  Now navigate
    to the directory of the source code and type "g++ assg1.wallace.cpp -o assg1.exe" without
    the quotation marks. Then type "./assg1.exe" without the quotation marks.

Notes on some potential landmines:
    This program has virtually (read none) error handling capability.  If you give it some
    input it does not expect (ie not a real number) than it will behave badly.  For example
    if you try to enter your restaurant bill by writing out the numbers like "two hundred"
    it will output all zeros and exit immediately instead of waiting patiently for you to press
    <enter>.  In addition, if you were to give it a completely unreasonable large number,
    say on the order of 666666666666666666666666666 than it will also behave badly, outputting
    garbage values and petulantly refusing to exit normally.

    Having said that, the program should function well for all normal restaurant bills.
