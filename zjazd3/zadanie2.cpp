#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int main()
{
int i;
float s=0;
float s1=0;
float s2=0;
float s3=0;
float s4=0;
float s5=0;
float tab[25];
for(i=0; i<25; i++)
{
cin>> tab[i];
}
while (i>=0)
{
s=s+tab[i];
i--;
}
for(int j=0;j<5;j++){
s1=s1+tab[j];
s2=s2+tab[j+5];
s3=s3+tab[j+10];
s4=s4+tab[j+15];
s5=s5+tab[j+20];
}
s=s/25;
s1=s1/5;
s2=s2/5;
s3=s3/5;
s4=s4/5;
s5=s5/5;
cout<< endl<< s <<endl;
if(s1>s){
cout<<1<<endl;
}
if(s2>s){
cout<<2<<endl;
}
if(s3>s){
cout<<3<<endl;
}
if(s4>s){
cout<<4<<endl;
}
if(s5>s){
cout<<5<<endl;
}
return 0;
}
