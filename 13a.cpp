//modifying the index of an array elements
#include<iostream>
using namespace std;
#define N 7
int array[7];
void add_front(int *arr,int ele)
{
    int i,j,k,a,b,ar[10];
    cout<<"enter the two indexes";
    cin>>a>>b;
    if(a<b)
    {
    int l=0;
    for(i=a;i<=b;i++)
    {
    ar[l]=arr[i];
    cout<<ar[l];
    l++;
    }
    for(j=0;j<a;j++)
    {
    ar[l]=arr[j];
    cout<<ar[l];
    l++;
    }
    for(k=b+1;k<N;k++)
    {
    ar[l]=arr[k];
    cout<<ar[l];
    l++;
    }
    }
    else
    {
        cout<<"not possible in this method";
    }
}
void add_back(int *arr,int ele)
{
    int i,j,k,a,b,ar[10];
    cout<<"enter the two indexes";
    cin>>a>>b;
    if(a<b)
    {
    int l=0;
    for(i=0;i<a;i++)
    {
    ar[l]=arr[i];
    cout<<ar[l];
    l++;
    }
    for(j=b+1;j<N;j++)
    {
    ar[l]=arr[j];
    cout<<ar[l];
    l++;
    }
    for(k=a;k<=b;k++)
    {
    ar[l]=arr[k];
    cout<<ar[l];
    l++;
    }
    }
    else
    {
        cout<<"not possible in this method";
    }
}
int main()
{
    int key;
    for (int i = 0; i < N; i++)
    {
        cin>>array[i];
    }
    while(1)
    {
    cout<<"enter the type u want 1 or 2 ";
    cout<<"3.to exit";
    cin>>key;
    switch (key)
    {
    case 1:add_front(array,key);
        break;
    case 2:add_back(array,key);
        break;
    case 3:exit(0);
        break;
    default:cout<<"enter the correct key";
        break;
    }
    }
}