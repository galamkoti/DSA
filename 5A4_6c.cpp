#include<iostream>
using namespace std;
#define SIZE 100
int array[20];
class stacks
{
    int top=-1;
    public:
    void dectobin(int k)
    {
        int remainder;
        while (k>0)
        {
                remainder=k%2;
                push(remainder);
                k=k/2;
        }
        while (top!=-1)
        {
            cout<<pop()<<" ";
        }        
    }
    void push(int element)
    {
        if (top==SIZE-1)
        {
            cout<<"the stack is full";
        }
        else
        {
            array[++top]=element;
        }
    }
    int pop()
    {
        int key;
        if (top==-1)
        {
            cout<<"the stack is empty";
        }
        else
        {
            key=array[top];
            top=top-1;
            return(key);
        }
    }
};
int main()
{
    stacks s1;
    int number;
    cout<<"enter the number to convert to binary";
    cin>>number;
    s1.dectobin(number);
}