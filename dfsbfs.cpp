#include<iostream>
using namespace std;
class stack
{
    public:
    int a[100];
    void push(int);
    int pop();
    int top=-1;
}s;
class queue
{
    public:
    int a[100];
    void insert(int);
    int remove();
    int front=-1,rear=-1;
}q;
class graph
{
    public:
    int n;
    int count;
    int v[100];
    int status[100];
    int adj[100][100];
    graph();
    void bfs(int);
    void dfs(int);
}g;
graph::graph()
{
    cout<<"enter the number of vertices";
    cin>>n;
    cout<<"enter the values to be inserted";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        status[i]=0;
    }
    cout<<"enter the adjacency matrix";
    for (int i = 0; i < n; i++)
    {
        for ( int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    } 
}
void graph:: bfs(int first)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i]==first)
        {
            status[i]=1;
            break;
        }
    }
    int k=q.remove();
    cout<<k<<" ";
    count++;
    for (int j=0;j<n;j++)
    {
        if(adj[i][j]=1)
        {
            if(status[j]!=1)
            {
                q.insert(v[j]);
                status[j]=1;
            }
        }
    }
    if (count<n)
    {
        first=q.a[q.front];
        bfs(first);
    }
}
void graph::dfs(int first)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(v[i]==first)
        {
            status[i]=1;
            break;
        }
    }
    int k=s.pop();
    cout<<k<<" ";
    count++;
    for (int j = 0; j < n; j++)
    {
        if(adj[i][j]=1)
        {
            if(status[j]!=1)
            {
                s.push(v[j]);
                status[j]=1;
            }
        }
    }
    if(count<n)
    {
        first=s.a[s.top];
        dfs(first);
    }
}
void stack::push(int s)
{
    a[++top]=s;
}
int stack::pop()
{
    return a[top--];
}
void queue::insert(int s)
{
    if(front==-1 && rear==-1)
    {
        front++;
    }
    rear++;
    a[rear]=s;
}
int queue::remove()
{
    return a[front++];
    
}
int main()
{
    int choice;
    int first_letter;
    while (1)
    {
        cout<<"enter one choice\n";
        cout<<"1.bfs 2.dfs 3.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"enter the starting element";
                    cin>>first_letter;
                    q.insert(first_letter);
                    g.count=0;
                    g.bfs(first_letter);
                    for (int k = 0; k < g.n; k++)
                    {
                        g.status[k]=0;
                    }
                    break;
            case 2:cout<<"enter the starting element";
                    cin>>first_letter;
                    s.push(first_letter);
                    g.count=0;
                    g.dfs(first_letter);
                    for (int k = 0; k < g.n; k++)
                    {
                        g.status[k]=0;
                    }
                    break;
            case 3:exit(0);
            default:cout<<"enter the correct choice";
        }
    }
}
