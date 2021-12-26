#include<iostream>
using namespace std;
void gcd(int a,int b)
{
  if(a>b)
  {
  int rem;
  rem=a%b;
  if(rem==0)
  {
    cout<<"the gcd is"<<b;
  }
  else
  {
    gcd(b,rem);
  }
  }
  if(a<b)
  {
  int rem;
  rem=b%a;
  if(rem==0)
  {
    cout<<"the gcd is"<<a;
  }
  else
  {
    gcd(a,rem);
  }
  }
}
int main()
{
  int num1,num2;
  cout<<"enter the 2 numbrs";
  cin>>num1;
  cin>>num2;
  gcd(num1,num2);
}