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
    node *temp2;
    node *front=NULL;
    node *rear=NULL;
  public:
    void insertatend();
    void insertatbegin();
    void insertatposition();
    void removeatend();
    void removeatbegin();
    void removeatposition();
    void printing();
};
int main()
{
  int n,insert,ins;
  sll ll;
  while(true)
  {
    cout<<"\nplease select an option";
    cout<<"\n1.insert 2.remove 3.print 4.exit";
    cin>>n;
    switch(n)
    {
      case 1:cout<<"\nselect an option";
      cout<<"\n1.insertatend 2.insertatbegin 3.insert at a position";
      cin>>insert;
      switch(insert)
      {
        case 1:ll.insertatend();
        break;
        case 2:ll.insertatbegin();
        break;
        case 3:ll.insertatposition();
        break;
      }
      break;
      case 2:cout<<"\nselect an option";
      cout<<"\n1.remove at end 2.remove at begin3.remove at position";
      cin>>ins;
      switch(ins)
      {
        case 1:ll.removeatend();
        break;
        case 2:ll.removeatbegin();
        break;
        case 3:ll.removeatposition();
        break;
      }
      break;
      case 3:ll.printing();
      break;
      case 4:exit(0);
      break;
    }
  }
}
void sll::insertatend()
{
  
  if(front==NULL && rear==NULL)
  {
    cout<<"element to insert at end";
  cin>>k;
  temp=new node();
  temp->data=k;
  temp->link=NULL;
    front=rear=temp;
  }
  else
  {
    cout<<"element to insert at end";
  cin>>k;
  temp=new node();
  temp->data=k;
  temp->link=NULL;
    rear->link=temp;
    rear=temp;
  }
}
void sll::insertatbegin()
{
  if(front==NULL && rear==NULL)
  {
    cout<<"element to insert at begin";
    cin>>k;
    temp=new node();
    temp->data=k;
    temp->link=NULL;
    front=rear=temp;
  }
  else
  {
  cout<<"element to insert at begin";
  cin>>k; 
  temp=new node();
  temp->data=k;
  temp->link=front;
  front=temp;
  }
}
void sll::insertatposition()
{
  int position,pos1;
  cout<<"enter position to add node";
  cin>>position;
  if(position==1)
  {
    insertatbegin();
  }
  else
  {
  temp=new node();
  cout<<"enter data to insert";
  cin>>k;
  temp->data=k;
  temp->link=NULL;
    temp1=front;
    pos1=1;
    while(pos1!=position-1)
    {
      temp1=temp1->link; 
      pos1++;
    }
    temp->link=temp1->link;
    temp1->link=temp;
  }
}
void sll::removeatbegin()
{
  if(front==NULL && rear==NULL)
  {
    cout<<"The linked list is empty";
  }
  else
  {
    temp=front->link;
    front->link=NULL;
    delete front;
    front=temp;
  }
}
void sll::removeatend()
{
  if(front==NULL && rear==NULL)
  {
    cout<<"The linked list is empty";
  }
  else
  {
    temp=front;
    while(temp->link!=rear)
    {
      temp=temp->link;
    }
    temp->link=NULL;
    delete rear;
    rear=temp;
  } 
}
void sll::removeatposition()
{
  int pos2, position2;
  cout<<"enter position to delete";
  cin>>position2;
  temp=front;
  pos2=1;
  while(pos2!=position2-1)
  {
    temp2=temp->link->link;
    pos2++;
  }
  delete temp->link;
  temp=temp2;
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