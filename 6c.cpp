#include<iostream>
using namespace std;
#define SIZE 50
int arr[100];
class stack
{
    public:
    int top=-1;
    public:
    void dec_to_bin(int);
    void push(int);
    void print();
};
void stack::dec_to_bin(int k)
{
    int rem;
    while (k>0)
    {
        rem=k%2;
        k=k/2;
        push(rem);
    }
    
}
void stack::push(int a)
{
    if(top==SIZE-1)
        cout<<"stack is full";
    else
    {
        arr[++top]=a;
    }    
}
void stack::print()
{
    if(top==-1)
        cout<<"stack is empty";
    else{
        for (int i = top; i>=0; i--)
        {
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
    stack s1;
    int ele;
    cout<<"enter the no to covert into binary";
    cin>>ele;
    s1.dec_to_bin(ele);
    s1.print();
}
