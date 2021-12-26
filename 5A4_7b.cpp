 #include<iostream>
using namespace std;
#define SIZE 6
int cq[SIZE];
class cirqueue
{
int init=-1,finl=-1;
public:
void insert()
{
	int k;
	cout<<"enter the element to insert";
	 cin>>k;
	if((init==0 && finl==SIZE-1) || (finl==init-1))
	{
		cout<<"the cir queue is full";
		return;
	}
	else if(init==-1 && finl==-1)
	{
		init=finl=0;
		cq[finl]=k;
	}
	else if(init!=0 && finl==SIZE-1)
	{
		finl=0;
		cq[finl]=k;
	}
	else
	{
		finl=finl+1;
		cq[finl]=k;
	} 
}
void deleted()
{
	if(init==-1 && finl==-1)
	{
		cout<<"no more elements are left";
	} 
	else if(init==finl)
	{
			init=finl=-1;
	}
	else if(init==SIZE-1 && finl!=SIZE-1)
	{
		init=0;
	}
	else
	{
		init=init+1;
	}
}
void printing()
{
	if(init==-1 && finl==-1)
	{
		cout<<"cir queue is empty"; 
	}
	if(finl<init)
	{
		for(int i=init;i<SIZE;i++)
		{
			cout<<cq[i]<<" ";
		}
		for(int i=0;i<=finl;i++)
		{
			cout<<cq[i]<<" ";
		}
	}
	else
	{
		for(int i=init;i<=finl;i++)
		{
			cout<<cq[i]<<" ";
		}
	}
}
};
int main()
{
	cirqueue c1;
    int num;
    while(1)
    {
    cout<<"1.insert ";
    cout<<"2.delete ";
    cout<<"3.printing ";
    cout<<"4.quit ";
    cout<<"\nenter num :";
    cin>>num;
    switch(num)
    {
    case 1:c1.insert();
           break;
    case 2:c1.deleted();
           break;
    case 3:c1.printing();
            break;
    case 4:exit(0);
           break;
    }
    }
}