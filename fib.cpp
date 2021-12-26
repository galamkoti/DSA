#include<iostream>
using namespace std;
int main()
{
    int fib2=0,fib1=1,fibm,offset,index,search;
    int n,arr[20];
    fibm=fib1+fib2;
    cout<< "enter the n value";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter"<<i+1<<"element";
        cin>>n;
    }
    while(fibm<=n)
    {
        fib2 =fib1;
        fib1=fibm;
        fibm=fib1+fib2;
    }
    cout<<"enter a value for search";
    cin>>search;
    for(int i=fibm;i>0;i++)
    {
        if(offset+fib2<n-1)
        {
            index=offset+fib2;
        }
        else
        {
            index=n-1;
        }
        if(arr[index]<search)
        {
            fibm=fib1;
            fib1=fib2;
            fib2=fibm-fib1;
            offset=index;
        }
        else if(arr[index]>search )
        {
            fibm=fib2;
            fib2=fibm-fib1; 
            fib1=fib1-fib2;
        }
        else{
            break ;
        }
    }
    if(arr[index]==search)
    {
        cout<<"element found";
    }
    else{
    cout<<"element not found";
    }
    return 0;
}