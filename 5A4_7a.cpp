#include<iostream>
using namespace std;
class Queue
{
    int array[2][100]; 
    int head=-1, rear=-1;
    public:
    int size;
    void insert(int number, int pro);
    void remove();
    void display();
};
void Queue::insert(int number, int pro)
{
    if(head==-1)
    {
        head++; 
        rear++;
        array[0][head] = pro;
        array[1][head] = number;
        cout<<"Inserted";
        return;
    }
    rear++;
    int y=rear;
    if(rear==size)
    {
        rear--;
        cout<<"Size exceeds";
        return;
    }
    else
    {
        for(int x=0;x<=rear;x++)
        {
            if(x==rear)
            {
                array[0][rear] = pro;
                array[1][rear] = number;
                cout<<"Inserted";
                return;
            }
            if(array[0][x]<pro)
            {
                for(y;y>x;y--)
                {
                    array[0][y] = array[0][y-1];
                    array[1][y] = array[1][y-1];
                }   
                array[0][x] = pro;
                array[1][x] = number;
                cout<<"Inserted";
                return;
            }
        }
    }
}

void Queue::display()
{
    if(head==-1)
    {
        cout<<"No element found";
    }
    else
    {
        for(int x=0;x<=rear;x++)
        {
            cout<<array[0][x]<<" ";
        }
        cout<<"\n";
        for(int x=0;x<=rear;x++)
        {
            cout<<array[1][x]<<" ";
        }
    }
}

void Queue::remove()
{
    if(rear==-1)
    {
        cout<<"No elements to delete.";
    }
    else
    {
        if(rear==0)
        {
            rear--; 
            head--;
            cout<<"Deleted.";
            return;
        }
        for(int x=0;x<rear;x++)
        {
            array[0][x] = array[0][x+1];
            array[1][x] = array[1][x+1];
        }
        rear--;
        cout<<"Deleted.";
    }
}

int main()
{
    Queue q;
    int option;
    cout<<"Enter no. of elements: ";
    cin>>q.size;
    cout<<"Select an option:\n";
    cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\nChoose a option: ";
    cin>>option; 
    while(1)
    {
        switch (option)
        {
        case 1:
            int value, priority;
            cout<<"Enter a value: ";
            cin>>value;
            cout<<"Enter the priority: ";
            cin>>priority;
            q.insert(value, priority);
            break;
        case 2:
            q.remove();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout<<"Exiting";
            break;
        default:
            cout<<"Choose a valid option.";
            break;
        }
    }
}