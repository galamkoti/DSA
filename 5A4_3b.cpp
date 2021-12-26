#include<iostream>
using namespace std;
int main()
{
int num,x,y,z,temp,p[100];
cout<<"enter the n value";
cin>>num;
for(x=0;x<num;x++)
{
cout<<"enter the  element"<<x+1;
cin>>p[x];
}
for(y=1;y<num;y++)
{
for(z=0;z<y;z++)
{
if(p[y]<p[z])
{
temp=p[z];
p[z]=p[y];
p[y]=temp;
}
}
}
cout<<"the insertion sort is";
for(x=0;x<num;x++)
{
cout<<p[x]<<" ";
}
return 0;
}