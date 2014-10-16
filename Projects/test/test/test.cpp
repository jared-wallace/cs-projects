#include <string>
#include <fstream>
#using <mscorlib.dll>

using namespace System;
using namespace System::IO;
using std::string;
using std::ifstream;
int main() 
{
StreamReader^ contents1 = gcnew StreamReader("testtxt1.txt");
StreamReader^ contents2 = gcnew StreamReader("testtxt2.txt");
StreamReader^ contents3 = gcnew StreamReader("testtxt3.txt");
String^ line;
while(true){
// Read and display lines from the file until the end of 
// the file is reached.
while (line = contents1->ReadLine()){
Console::WriteLine(line);
while (line = contents2->ReadLine())
Console::WriteLine(line);
while (line = contents3->ReadLine())
Console::WriteLine(line);
}
}

}