#include <iostream>

using namespace std;
int main()
{
	int a,x;
	cin>>a;
	do
	{
	cin>>x;
	if(x>a)cout<<"za duzo";
	if(x<a)cout<<"za malo";
	}while(x!=a);
	cout<<"end";
	return 0;
	
}
