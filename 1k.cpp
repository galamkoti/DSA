//bubble sort using single linked list
#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *link;
};
class sll
{
  public:
    int k;
    node *temp;
    node *temp1;
    node* temp2;
    node *front=NULL;
    node *rear=NULL;
  public:
    void insertatend();
    void printing();
    void bubblesort(); 
};
void sll::insertatend()
{
  cout<<"element to insert at end";
  cin>>k;
  temp=new node();
  temp->data=k;
  temp->link=NULL;
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
void sll::printing()
{
  temp=front;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->link;
  }
}
void sll::bubblesort()
{
    int p;
    temp2=front->link;
    while(temp2!=NULL)
    {
      temp=front;
      temp1=front->link;
    while (temp1!=NULL)
    {
        if (temp->data > temp1->data)
        {
            p=temp->data;
            temp->data=temp1->data;
            temp1->data=p;
        }
        temp1=temp1->link;
        temp=temp->link;
    }
    temp2=temp2->link;
    } 
}
int main()
{
    int n;
    sll l1;
    cout<<"enter no of nodes";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        l1.insertatend();   
    }
    cout<<"elements after entering";
    l1.printing();
    l1.bubblesort();
    cout<<"elements after sorting";
    l1.printing();
    cout<<"im done";
}