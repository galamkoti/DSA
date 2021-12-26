#include<iostream>
using namespace std;
int max_in_array(int a[],int n)
{
    int high=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>high)
        {
            high=a[i];
        }
    }
    return high;
}
int main()
{
    int n,arr[100];
    cout<<"enter n value";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"enter"<<i+1<<"element";
        cin>>arr[i];
    }
    cout<<"highest element is"<<max_in_array(arr,n);
}