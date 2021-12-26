//linear search
#include<iostream>
using namespace std;
int main()
{
    int b,position;
    int a[100],i,search;
    cout<<"enter the no of elements";
    cin>>b;
    for(i=0;i<b;i++)
    {
        cout<<"enter the element"<<i+1;
        cin>>a[i];
    }
    cout<<"enter the value for comparison";
    cin>>search;
    for(i=0;i<b;i++)
    {
        if(search==a[i])
        {
            position=i+1;
            break;
        }
        else
        {
            position=0;
        }
        
    }
    if (position!=0)
    {
        cout<<"element found at "<<position<<" position";
    }
    else
    {
        cout<<"element not found";
    }
    
    
}