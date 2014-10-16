//This will attempt to convert any base 10 number into base 2
#include <iostream>
#include <cmath>
#include <bitset>
#include <string>

using namespace std;

int main()
{

  bitset<48> result;
  int initial, n(0);
  double numBits;
  string im, final;
  cout << "Enter a decimal number" << endl << endl;
  cin >> initial;
  //Microsoft blows for not including log2
  numBits = log10(double(initial))/ log10(double(2));
  numBits++;

  while (initial != 1)
  {
    if (initial%2)
    {
      result.set(n,1);
      n++;
      initial--;
      initial = (initial/2);
    }
    else
    {
      result.set(n,0);
      n++;
      initial = (initial/2);
    }
  }

  result.set(n,1); //to account for last bit
  im=result.to_string<char,char_traits<char>,allocator<char> >();//This line and the next adjust the ouput to the length of the binary number
  final = im.substr ((48-numBits), numBits);
  cout << "The answer you're looking for is" << endl << final << endl;
  cout << "Press enter to continue\n";
  cin.ignore();
  cin.get();
}
