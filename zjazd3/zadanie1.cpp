#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main()
{
int i;
float s=0;
float tab[5];
for(i=0; i<5; i++)
{
cin>> tab[i];
}
while (i>=0)
{
s=s+tab[i];
i--;
}
cout<< endl<< s/5 <<endl;
return 0;
}
