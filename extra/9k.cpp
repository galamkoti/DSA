//stack using linked list
#include<iostream>
using namespace std;
int count=0;
class node
{
    public:
    int data;
    node* link;
};
class stack
{
    public:
    node* front=NULL;
    node* rear=NULL;
    public:
    void push();
    void pop();
    void printing();
    void top();
};
int main()
{
    stack s;
    int num;
    while(1)
    {
        cout<<"1.push 2.pop 3.print 4.top 5.exit\n";
        cout<<"enter num value\n";
        cin>>num;
        switch(num)
        {
            case 1:s.push();
                break;
            case 2:s.pop();
            break;
            case 3:s.printing();
            break;
            case 4:s.top();
            break;
            case 5:exit(0);
            break;
        }
    }
}
void stack:: push()
{
    int key;
    cout<<"enter key to be pushed\n";
    cin>>key;
    node* temp=new node();
    temp->data=key;
    temp->link=NULL;
    count+=1;
    if(front==NULL && rear==NULL)
    {
    front=rear=temp;
    }
    else
    {
    rear->link=temp;
    rear=temp;
    }
    
}
void stack::pop()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"stack is empty";
    }
    else
    {
        node* temp1=new node();
        temp1=front;
        while(temp1->link!=rear)
        {
            temp1=temp1->link;
        }
        temp1->link=NULL;
        delete(rear);
        rear=temp1;
        if(count=0)
        {
            front=rear=NULL;
        }
        count-=1;
    }
}
void stack::printing()
{
    node* temp2=new node(); 
    if (front==NULL && rear==NULL)
    {
        cout<<"stack is empty";
    }
    else
    {
        temp2=front;
        while(temp2->link!=NULL)
        {
            cout<<temp2->data<<" ";
            temp2=temp2->link; 
        }
        cout<<temp2->data;
    }   
}
void stack::top()
{
    node* temp3=new node();
    temp3=front;
    while(temp3->link!=NULL)
    {
        temp3=temp3->link;
    }
    cout<<"top element is "<<temp3->data;
}