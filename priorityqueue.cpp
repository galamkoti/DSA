#include<iostream>
using namespace std;
#define max 50
class pqueue
{
    public:
    int a[100],b[100];
    int front=-1,rear=-1;
    public:
    void insert(int,int);
    void remove();
    void print();
};
void pqueue::insert(int k,int p)
{
    if (front==-1)
    {
        front++,rear++;
        a[rear]=k;
        b[rear]=p;
    }
    else if(rear==max-1)
    {
        cout<<"queue is full";

    }
    else
    {
        a[rear++]=k;
        b[rear]=p;
        cout<<"inserted";
    }
    for (int i = front; i < rear; i++)
    {
        for (int j = i; j > front; j++)
        {
            if (b[j+1]>b[j])
            {
                int temp=b[j+1];
                b[j+1]=b[j];
                b[j]=temp;

                int temp1=a[j+1];
                a[j+1]=a[j];
                a[j]=temp1;

            }   
        }   
    }    
}
void pqueue::remove()
{
    if (front==-1 && rear==-1 || front>rear)
    {
        cout<<"queue is empty";
    }
    else
    {
        front++;
        cout<<"deleted";
    }
}
void pqueue::print()
{
    if (front==-1 && rear==-1 || front > rear)
    {
        cout<<"queue is empty";
    }
    else
    {
        for (int i = front; i <=rear; i++)
        {
            cout<<a[i]<<" ";
        }
    }
    
}
int main()
{
    int num,priority,n;
    pqueue p;
    while (1)
    {
        cout<<"enter n value";
        cin>>n;
        switch (n)
        {
        case 1:cout<<"enter num, priority";
        cin>>num>>priority;
        p.insert(num,priority);
            break;
            case 2:p.remove();
            break;
        case 3:p.print();
        break;
        default:exit(0);
            break;
        }
    }
    
}