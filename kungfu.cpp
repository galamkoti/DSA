#include<iostream>
using namespace std;
void push(void);//insert
void pop(void);//delete
void print(void);//display
int stack[25],top,choice,i,n,x;
int main()
{
  
  top=-1;
  cout<<"enter the stack size less then 25: ";
  cin>>n;
  cout<<"\nstack operations using arrays";
  cout<<"\n1.push 2.pop 3.print 4.exit";
  
  while(choice<4)
  {
      cout<<"\nenter the choice: ";
       cin>>choice;
     switch(choice)
     {
      case 1:push();
             break;
      case 2:pop();
             break;
      case 3:print();
             break;
      case 4:cout<<"\n EXIT POINT";
             break;
     default:cout<<"\nenter the valid choice";
  }
  }
}
void push()
{
    if(top>=n-1)
    {
        cout<<"\nthe stack is overflow";
    }
    else
    {
        cout<<"\nenter the element to be inserted : ";
        cin>>x;
        top++;//as intially top is -1 so first increment then stored in stack 
        stack[top]=x;

    }
}
void pop()
{
    if(top<=-1)
    {
        cout<<"there are no elements to deleted";
    }
    else
    {
        cout<<"the popped elements are"<<stack[top];
        top--;
    }
    
}
void print()
{
    if(top<=-1)
    {
        cout<<"there are no elements to print";
    }
    if(top>=0)
    cout<<"the elements in the stack";
    for(i=top;i>=0;i--)
    {
        cout<<stack[i];
    }
    cout<<"\n enter next choice";

}