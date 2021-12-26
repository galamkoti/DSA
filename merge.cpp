#include<iostream>
using namespace std;
void merge(int a[],int low,int mid,int high)
{
    int p,q,r,s,t;
    p=low,q=mid,r=mid+1,s=high,t=low;
    int b[high+1];
    while(p<=q && r<=s)
    {
        if(a[p]<a[r])
        {
            b[t]=a[p];
            p++,t++;
        }
        else if(a[p]>a[r])
        {
            b[t]=a[r];
            r++,t++;
        }
        else if(a[p]==a[r])
        {
            b[t]=a[p];
            b[t+1]=a[r];
            p++;
            r++;
            t=t+2;
        }
    }
        while(p<=q)
        {
            b[t]=a[p];
            p++;
            t++;
        }
        while(r<=s)
        {
            b[t]=a[r];
            r++;
            t++;
        }  
    for (int i = low; i<=high; i++)
    {
        a[i]=b[i];
    }
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main()
{
    int n;
    cout<<"enter the n value";
    cin>>n;
    int a[n];
    cout<<"enter the array elements"<<"\n";
    for (int i=0;i<n;i++)
    {
        cout<<"enter element at"<<i+1<<"position"<<"\n";
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"elements after sorting";
    for (int i=0;i<n;i++)
        cout<<a[i]<<"  ";
}