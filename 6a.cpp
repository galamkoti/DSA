#include<iostream>
using namespace std;
#define SIZE 100
int stack[SIZE];
int top=-1;
class gk
{
    public:
    void push(int);
    int pop();
};
int main()
{
    gk g2;
    int number;
    cout<<"nter the number u want";
    cin>>number;
    g2.push(1);
    for (int i = 2; i <= number; i++)
    {
        g2.push(g2.pop()*i);
    }
    cout<<"factorial is "<<g2.pop();
}
void gk::push(int key)
{
    if (top==SIZE-1)
    {
        cout<<"stack is full";
    }
    else
    {
        stack[++top]=key;
    }
}
int gk::pop()
{
    if(top==-1)
    {
        cout<<"stack is empty";
    }
    else
    {
        return stack[top];
    }
}

