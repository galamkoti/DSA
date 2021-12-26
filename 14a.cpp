#include<iostream>
using namespace std;
int main()
{
    int n,i,ele,found=0;
    cout<<"enter the no: of elements to be stored in the array\n";
    cin>>n;
    int arr[n];
    cout<<"enter"<<n<<"elements\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the element to be searched\n";
    cin>>ele;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            cout<<"element found at index"<<i;
            found=1;
            break;
        }
        else
        {
            found=0;
        }
    }
    if(found)
    {
        cout<<"element found";
    }
    else
    {
        cout<<"element not found";
    }
}