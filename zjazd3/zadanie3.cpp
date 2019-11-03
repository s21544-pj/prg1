#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
int i=0;
string tab;
cin>>tab;
while( tab[i]!=0)
{
i++;
}
while(i>=0)
{
cout<< tab[i];
i--;
}
return 0;
}
