#include<iostream>
using namespace std;
int main()
{
    int c[50],k,p=1,q=0,res,key_value;
    int indx=0;
    int ofset=0;
    res=p+q;
    cout<<"enter the value of k";
    cin>>k;
    for(int i=0; i<k; i++)
    {
        cout<<"enter the %d element"<<i+1;
        cin>>c[i];
    }
   cout<<"enter the element to search";
    cin>>key_value;
    while(res<=k)
    {
        q=p;
        p=res;
        res= p+q;
    }
    for(int i=res;i>0;i--)
    {
        if(ofset+q<k-1)
        {
            indx = ofset+q;
        }
        else
        {
            indx =k-1;
        }
        if(c[indx]<key_value)
        {
            res=p;
            p=q;
             q=res-p;
            ofset =indx;
        }
        else if(c[indx]>key_value)
        {
            res=q;
            p=p-q;
            q=res-p;
        }
        else break;
    }
    if(c[indx]==key_value)
    {
        cout<<"element found at "<< indx+1<< "position";
    }
    else
    {
        cout<<"element not found";
    }
}
