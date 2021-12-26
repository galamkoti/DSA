#include<iostream>
using namespace std;
int factorial(int t)
{
if(t==0)
{
return 1;
}
return t*factorial(t-1);
}
int main()
{
int t;
cout<<"enter the n value";
cin>>t;
cout<<"the factorial is"<<factorial(t);
}