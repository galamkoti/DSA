#include<iostream>
using namespace std;
int main()
{
    int number;
    float sum=0,rate,total_rate;
    float arr[100];
    cout<<"enter number of bags";
    cin>>number;
    for (int i = 0; i < number; i++)
    {
        cout<<"enter"<<i+1<<"bag";
        cin>>arr[i];
    }
    for (int i = 0; i < number; i++)
    {
        if (arr[i]>=40)
        {
            arr[i]=arr[i]-1;
            sum=sum+arr[i];
        }
        else
        {
            arr[i]=arr[i]-0.5;
            sum=sum+arr[i];
        }
        
    }
    
    cout<<"enter the value of mirchi for one kg";
    cin>>rate;
    total_rate=rate*sum;
    cout<<"the total amount we get is"<<total_rate;
}