//dequeue double ended queue
#include<iostream>
#include<deque>
using namespace std;
void printfwd(deque<int>& dd)
{
    for (auto i =dd.begin();i!=dd.end(); i++)
    {
        cout<<*i<<"\t";
    }
}
void printbwd(deque<int>& dd)
{
    for (auto i =dd.rbegin();i!=dd.rend(); i++)
    {
        cout<<*i<<"\t";
    }
}
int main()
{
    int num,ele;
    deque<int> d;
    while (1)
    {
        cout<<"select an option";
        cout<<"1.insert at begin 2.insert at end 3. deleting at front ";
        cout<<"4.del at end 5. forward print 6.backward print";
        cin>>num;
        switch (num)
        {
        case 1:cout<<"enter the element to insert at begin";
                cin>>ele;
                d.push_front(ele);
            break;
         case 2:cout<<"enter the element to insert at end"<<"\n";
                cin>>ele;
                d.push_back(ele);
            break;
        case 3:cout<<"deleting at begin"<<"\n";
                d.pop_front();
                break;
        case 4:cout<<"deleting at end"<<"\n";
                d.pop_back();
                break;
        case 5:cout<<"printing"<<"\n";
                printfwd(d);
                break;
        case 6:cout<<"printing"<<"\n";
                printbwd(d);
                break;
        
        default:exit(0);
        }
    }
    
}
