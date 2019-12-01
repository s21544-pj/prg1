#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
  int i=0;
  int j=0;
  int k=0;
  int tab[9];
  int tab2[9];
  for(;i<9;i++){
    cin>>tab[i];
  }
  for(;k<9;k++){
    cin>>tab2[k];
  }
  while (j<9)
  {
  cout<<tab[j]+tab2[j]<<" "<<tab[j+1]+tab2[j+1]<<" "<<tab[j+2]+tab2[j+2]<<endl;
  j=j+3;
  }

return 0;
}
