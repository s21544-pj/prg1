#include <iostream>
#include <string>
using namespace std;

int main(){

  char tablica[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ',' '}};
  int kolej = 0;
  int x = 0;
  int i = 0;
  int j = 0;
  while(1){
  cin>>x;
  i=(x-1)/3;
  j=(x-1)%3;
    /*switch(x){
      case 1:
      i=0;
      j=0;
      break;
      case 2:
      i=0;
      j=1;
      break;
      case 3:
      i=0;
      j=2;
      break;
      case 4:
      i=1;
      j=0;
      break;
      case 5:
      i=1;
      j=1;
      break;
      case 6:
      i=1;
      j=2;
      break;
      case 7:
      i=2;
      j=0;
      break;
      case 8:
      i=2;
      j=1;
      break;
      case 9:
      i=2;
      j=2;
      break;
    }*/
      if(tablica[i][j]!='x' && tablica[i][j]!='o'){
	if(kolej%2==0){
	  tablica[i][j] = 'x';

	}
	else {
	  tablica[i][j] = 'o';
	}
      }
      else {
	cout<<0;
        return 0;
      }
  }


return 0;
}
