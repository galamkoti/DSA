#include<iostream>
using namespace std;
#define VALUE 5
int arr[VALUE];
class queue
{
    public:
    int front =-1;
    int rear =-1;
    public:
    void insert(int);
    void dequeue();
    void print();
    int isfull();
    int isempty();
};
int main()
{
    queue q;
    int num,item;
    while(1) {
        cout<<"1.Insert";
        cout<<"2.remove";
        cout<<"3.print queue";
        cout<<"4.exit";
        cout<<"\nenter num";
        cin>>num;
        switch(num)
        {
        case 1:
            cout<<"enter the element to insert";
            cin>>item;
            q.insert(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.print();
            break;
        case 4:
            exit(0);
        default:
            cout<<"invalid input";
            break;
        }
    }
}
void queue::insert(int k)
{
    if(isfull())
    {
        cout<<"the queue is full";
    }
    else
    {
        if(front==-1)
        {
        front=0;
        }
        arr[++rear]=k;
    }
}
int queue::isfull()
{
    if(rear==VALUE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int queue::isempty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void queue::dequeue()
{
    int i;
    if(isempty())
    {
        cout<<"the queue is empty";
    }
    else
    {
    cout<<"front element"<<arr[front];
        for(i=front; i<=rear; i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
        if(rear==-1)
        {
        front =-1;
        }
    }
    
}
void queue::print()
{
    int i;
    if(isempty())
    {
        cout<<"queue is empty";
    }
    else
    {
        for(i=front; i<=rear; i++)
        {
            cout<<arr[i]<<"\n";
        }
    }
}