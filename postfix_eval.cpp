#include<iostream>
using namespace std;
#define MAX 6
int array[20];
int top=-1;
class stack
{
    public:
    void push(int);
    int pop();
    void postfix_eval(char a[]);
};
int main()
{
    stack s1;
    char k[20];
    cout<<"enter the postfix expr";
    gets(k);
    puts(k);
    s1.postfix_eval(k);
    cout<<"the value of evaluation"<<s1.pop();
}
void stack::postfix_eval(char a[])
{
int p,q,r,i=0;
char ch;
while(a[i]!='\0')
{
    if(a[i]>='0'&&a[i]<='9')
    {
        int x;
        x=a[i]-48;
        push(x);
    }
    else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
    {
        switch(a[i])
        {
            case '+':p=pop();
                    q=pop();
                    r=p+q;
                    break;
            case '-':p=pop();
                    q=pop();
                    r=p-q;
                    break;
            case '*':p=pop();
                    q=pop();
                    r=p*q;
                    break; 
            case '/':p=pop();
                    q=pop();
                    r=p/q;
                    break; 
            default:cout<<"enter valid input";
        }
        push(r);
    }
    i++;
}
}
void stack::push(int item)
{
    if(top==MAX-1)
    {
        cout<<"stack is full";
        return;
    }
    else
    {
        array[++top]=item;
    }
}
int stack::pop()
{
    int t;
    if(top==-1)
    {
        cout<<"stack is empty";
        return 0;
    }
    else
    {
        t=array[top];
        top=top-1;
        return t;
    }
}