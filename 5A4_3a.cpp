#include<iostream>
using namespace std;
int main()
{
int no,p,q,temp,z[20];
cout<<"enter the n value";
cin>>no;
for(p=0;p<no;p++)
{
cout<<"enter the"<<p+1<<" element";
cin>>z[p];
}
for(p=0;p<no-1;p++)
{
for(q=0;q<no-p-1;q++)
{
if(z[q]>z[q+1])
{
temp=z[q]; 
z[q]=z[q+1];
z[q+1]=temp;
}
}
}
cout<<"the bubble sort is";
for(q=0;q<no;q++)
{
cout<<z[q]<<" ";
}
}