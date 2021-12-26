#include <iostream>
using namespace std;
class node
{
  public:
    int data;
    node *right;
    node *left;
};
class dll
{
    int k;
    node *temp;
    node *temp1;
    node *temp2;
    node *temp3;
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
    void reverseprint();
};
int main()
{
  int n,insert,ins,option;
  dll ll;
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
      case 3:cout<<"select an option";
      cout<<"1.print from begin 2.print from end";
      cin>>option;
      switch(option)
      {
        case 1:ll.printing();
        break;
        case 2:ll.reverseprint();
        break;
      }
      break;
      case 4:exit(0);
      break;
      default:cout<<"invalid input";
      break;
    }
  }
    
    
}
void dll::insertatend()
{
  cout<<"element to insert at end";
  cin>>k;
  temp=new node();
  temp->data=k;
  temp->right=NULL;
  temp->left=NULL;
  if(front==NULL && rear==NULL)
  {
    front=rear=temp;
  }
  else
  {
    rear->right=temp;
    temp->left=rear;
    rear=temp;
  }
}
void dll::insertatbegin()
{
  cout<<"enter element begin";
  cin>>k;
  temp=new node();
  temp->data=k;
  temp->right=NULL;
  temp->left=NULL;
  if(front==NULL && rear==NULL)
  {
    front=rear=temp;
  }
  else
  {
  temp->right=front;
  front->left=temp;
  front=temp;
  }
}
void dll::insertatposition()
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
    cout<<"enter data to insert";
    cin>>k;
    temp=new node();
    temp->data=k;
    temp->right=NULL;
    temp->left=NULL;
    temp2=front;
    pos1=1;
    while(pos1!=position-1)
    {
      temp2=temp2->right;
      pos1++;
    }
    temp3=temp2->right;

    temp2->right=temp;
    temp->left=temp2;
    temp->right=temp3;
    temp3->left=temp;
  }
}
void dll::removeatbegin()
{
  if(front==NULL && rear==NULL)
  {
    cout<<"The linked list is empty";
  }
  else
  {
    temp1=front->right;
    temp1->left=NULL;
    front->right=NULL;
    delete front;          
    front=temp1;            
  }
}
void dll::removeatend()
{
  if(front==NULL && rear==NULL)
  {
    cout<<"The linked list is empty";
  }
  else
  {
    /*temp=rear->left;
    temp->right=NULL;
    rear->left=NULL;
    delete rear;
    rear=temp;
    */
    
    temp=front;
    while(temp->right!=rear)
    {
    temp=temp->right;
     }
     temp->right=NULL;
     rear->left=NULL;
     delete rear;
     rear=temp;
  }
}
void dll::removeatposition()
{
  int pos2, position2;
  cout<<"enter position to delete";
  cin>>position2;
  if (position2==1)
  {
    removeatbegin();
  }
  else
  {
  temp=front;
  pos2=1;
  while(pos2!=position2-1)
  {
    temp=temp->right;
    pos2++;
  }
  temp1=temp->right;
  temp2=temp1->right;
  temp->right=temp2;
  temp2->left=temp;
  temp1->right=NULL;
  temp1->left=NULL;
  delete temp1;
}
}
void dll::printing()
{
  temp=front;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->right;
  }
}
void dll::reverseprint()
{
  temp=rear;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->left;
  }
} 