//binary search
#include<iostream>
using namespace std;
int main()
{
int x[20];
int i,number,high,low,mid,k,j,temp[1];
cout<<"enter number value";
cin>>number;
high=number-1;
low=0;
for(i=0;i<number;i++)
{
cout<<"enter the"<< i+1 <<"element"<<endl;
cin>>x[i];
}
for(i=0;i<number;i++)
{
for(j=i+1;j<number;j++)
{
if(x[i]>x[j])
{
temp[1]=x[i];
x[i]=x[j];
x[j]=temp[1];
}
}
}
cout<<"\nthe sorted order is";
for(i=0;i<number;i++)
{
cout<<x[i];
}
cout<<"\nentere key value";
cin>>k;
for(mid=0;mid<=number;mid++)
{
mid=(low+high)/2;
if(x[mid]==k)
{
cout<<"\nthe element found at "<<mid+1;
break;
}
else
{
if(x[mid]>k)
{
high=mid-1;
}
else
{
low=mid+1;
}
}
}
}