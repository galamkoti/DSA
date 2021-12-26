#include<iostream>
using namespace std;
int towers(int,char,char,char);
int main()
{ 
int z;
char s='S',d='D',i='I';
cout<<"enter the value of z";
cin>>z;
towers(z,s,d,i);
}
int towers(int k,char s,char d,char i)
{
    if(k==1)
    {
    cout<<"\nmove disc "<<k<<"from "<<s<< "to "<<d;
    }
    else
    {
    towers(k-1,s,i,d);
    cout<<"\nmove disc "<<k<<"from "<<s<< "to "<<d;
    towers(k-1,i,d,s);
    }
}