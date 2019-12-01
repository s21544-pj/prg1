#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main()
{
  int i=0;
  int j=0;
  int k=0;
  int tab[3][3];
  int tab2[3][3];
  int tab3[3][3];
  for(i=0;i<3;i++){
	for(j=0;j<3;j++){
    		cin>>tab[i][j];
	}
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
	cin>>tab2[i][j];
	}
  }

 for(i=0;i<3;i++){
	for(j=0;j<3;j++){
	tab3[i][j]=0;
	  for(k=0;k<3;k++){
	    tab3[i][j]+=tab[i][k]*tab2[k][j];

	  }
	}
 }
for(i=0;i<3;i++){
	for(j=0;j<3;j++){
	cout<<tab3[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}
