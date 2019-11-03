#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
int i=0;
string tab;
cin>>tab;
while (tab[i]!=0)
{
i++;
}
while(i>0){
if((char)(tab[i-1])>=65&&(char)(tab[i-1])<=90){
tab[i-1]=(char)(tab[i-1]+32);
}
i--;
}
cout<< endl<< tab <<endl;
return 0;
}
