//deleting duplicate values in sorted list using ll
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* link;
};
class ll
{
    public:
    int k;
    node* front=NULL;
    node* rear=NULL;
    node* temp;
    node* temp1;
    public:
    void insertatend();
    void removeatend();
    void check_duplicate();
    void printll();
};
int main()
{
    ll l1;
    int n;
    cout<<"enter the no of elements u want";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the"<<i+1<<"element";
        l1.insertatend();
    }
    l1.check_duplicate();
    l1.printll();
    cout<<"finish";
    
}
void ll::insertatend()
{
    cout<<"enter the element to insert";
    cin>>k;
    if (front==NULL && rear==NULL)
    {
        temp=new node();
        temp->data=k;
        temp->link=NULL;
        front=rear=temp;
    }
    else
    {
        temp=new node();
        temp->data=k;
        temp->link=NULL;
        rear->link=temp;
        rear=temp;
    }    
}
void ll::check_duplicate()
{

}
void ll::removeatend()
{

}
void ll::printll()
{
    temp=front;
    while (temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->link;
    }
}