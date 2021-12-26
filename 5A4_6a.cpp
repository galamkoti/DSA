#include<iostream>
using namespace std;
#define MAX 5
int stak[100];
int high=-1;
class kg
{
    public:
    void push(int v)
    {
        if(high==MAX-1)
        {
            cout<<"OverFlow";
        }
        else
        {
            ++high;
            stak[high] = v;
        }
    }
    int top()
    {
        if(high==-1)
        {
            cout<<"UnderFlow";
            return -1;
        }
        else
        {
            return stak[high];
        }
    }
    void pop()
    {
        if(high==-1)
        {
            cout<<"UnderFlow";
        }
        else
        {
            high=high-1;
        }
    }
    int isempty()
    {
        if(high==-1)
            return 1;
        else
            return 0;
    }
};
int main() 
{
    kg k;
	int i, number;
	cout<<"Enter a number: ";
	cin>>number;
	k.push(1);
	for(i=2;i<=number;++i)
    {
		k.push(k.top()*i);
	}
	cout<<"Factorial of a number is:"<<k.top();
	return 0;
}