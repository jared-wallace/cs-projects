#include <iostream>
#include <conio.h>
void main()
{
 clrscr();
 unsigned long int y,i=0,j=0,r,k[50];
 unsigned long a,x,b[50];
 cout << "\nEnter a decimal no. ";
 cin >> a;
 y=a;
 x=a-y;
 while(y>0)
 {
  r=y%2;
  k[i]=r;
  i++;
  y=y/2;
 }
 int m=0;
 while(m<10)
 {
  x=x*2;
  b[j]=int(x);
  j++;
  m++;
  if(x>1)
   x=x-1;
  else
   if(x==0)
    break;
 }
 cout << "\nDecimal no. "<<a<<" = ";
 if(a>1)
 {
  for(int e=i-1;e>=0;e--)
   cout << k[e];
  cout << ".";
  for(int g=0;g<m;g++)
   cout << b[g];
 }
 else
 {
  cout << "0.";
  for(int f=0;f<m;f++)
   cout << b[f];
 }
 cout << " in binary number system";
 getch();
}