#include <iostream>
using namespace std;
void swap(int *x,int *y)
{
 int t=*x;
 *x=*y; 
 *y=t; 
}  
int divide(int bray[], int low, int high)
 { 
 int pivot = bray[high];
 int i=(low-1);
 for(int j=low;j<high;j++)
 {
 if(bray[j]<=pivot)
 { 
i++; 
swap(&bray[i],&bray[j]);
 }
 } 
swap(&bray[i+1],&bray[high]);
return (i+1);
 }
 void quicks(int bray[], int low, int high)
 {
 if (low<high) 
{  
int pi = divide(bray,low,high); 
quicks(bray,low,pi-1); 
quicks(bray,pi+1,high); 
} 
} 
int main() 
{ 
int num,f,data[20];
cout<<"enter the n value";
cin>>num;
for(f=0;f<num;f++)
{
cout<<"enter the  element"<<f+1;
cin>>data[f];
}
quicks(data,0,num-1);
cout<<"\nSorted array in ascending order:";
for(f=0;f<num;f++)
{
cout<<data[f]<<" ";
}
}