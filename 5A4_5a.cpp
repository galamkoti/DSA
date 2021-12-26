#include<iostream> 
using namespace std;
#define SIZE 5
int stack[SIZE];
class stacks
{
    public:
    int top=-1;  
    public:
    void push();
    void pop();
    void traverse();
    void peek();
    int isfull();
    int isempty();
};
int main()
{
stacks s1;
int num,item;
while(1)
{
cout<<"1.push";
cout<<"2.pop";
cout<<"3.peek";
cout<<"4.traverse";
cout<<"5.quit";
cout<<"\nselect a number";
cin>>num;
switch(num)
{
case 1:s1.push();
       break;
case 2:s1.pop();
       break;
case 3:s1.peek();
       break;
case 4:s1.traverse();
       break;
case 5:exit(0);
       break;
default:cout<<"invalid input";
break;
}
}
}
void stacks::push()
{
int ele;
cout<<"enter no to be pushed";
cin>>ele;
if(isfull())
{
cout<<"stack is full";
}
else
{
stack[++top]=ele;
}
}
void stacks::pop()
{
int k;
if(isempty())
{
cout<<"stack is empty";
}
else
{
k=stack[top--];
cout<<"popped element is"<<k;
}
}
void stacks::peek()
{
if(isempty())
{
cout<<"stack is empty";
}
else
{
cout<<"peek element is "<<stack[top];
}
}
void stacks::traverse()
{
if(isempty())
{
cout<<"stack is empty";
}
else
{
int i;
cout<<"stack elements :";
for(i=0;i<=top;i++)
{
cout<<stack[i]<<" ";
}
}
}
int stacks::isfull()
{
if(top==SIZE-1)
{
return 1;
}
else
{
return 0;
}
}
int stacks::isempty()
{
if(top==-1)
{
return 1;
}
else
{
return 0;
}
}