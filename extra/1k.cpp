//double linked list
#include<iostream>
#include<list>
using namespace std;
void insert_at_pos(list<int>& a,int element)
{
    int bpos=1,pos;
    cout<<"enter the position to add an element";
    cin>>pos;
    if(pos==1)
        a.push_front(element);
    else if(pos==a.size())
        a.push_back(element);
    else if(pos>a.size())
        {
        cout<<"position exceeds";
        }
    else
    {
        for (auto i =a.begin();i!=a.end(); i++)
        {
            if(bpos<pos)
                bpos++;
            else
                a.insert(i,element);
                break;
        }
    }
    
}
void printfwd(list<int>& dd)
{
    for (auto i =dd.begin();i!=dd.end(); i++)
    {
        cout<<*i<<"\t";
    }
}
int main()
{
    list<int> l1;
    int num,ele;
    while (1)
    {
        cout<<"select one option"<<"\n";
        cout<<"1.insert at begin 2.insert at end 3.insert at position 4. deleting at front ";
        cout<<"5.del at end 6. forward print 7.exit";
        cin>>num;
        switch (num)
        {
        case 1:cout<<"enter the element to insert at begin";
                cin>>ele;
                l1.push_front(ele);
                break;
        case 2:cout<<"enter the element to insert at end";
                cin>>ele;
                l1.push_back(ele);
                break;
        case 3:cout<<"enter the element to insert at a position";
                cin>>ele;
                insert_at_pos(l1,ele);
                break;
        case 4:l1.pop_front();
                break;
        case 5:l1.pop_back();
                break;
        case 6:printfwd(l1);
                break;
        case 7:exit(0);
        default:cout<<"enter correct choice";
                break;
        }
    }
}