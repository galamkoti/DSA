#include<iostream>
using namespace std;
int q[20],top=-1,head=-1,rear=-1,array[20][20],visited[20],stacks[20]; 
int deleting();
void adding(int item);
void bfs(int s1,int n1);
void dfs(int s1,int n1);
void push(int item);
int pop();
int main()
{
int no,r,s,ch,p;
char c;
cout<<"enter the no of vertices u want";
cin>>no;
for(r=1;r<=no;r++)
{
for(p=1;p<=no;p++)
{
cout<<"enter value 1 if"<<r<<"had a node with"<<s<<"else 0";
cin>>array[r][p];
}
}
cout<<"The adjacency matrix is\n";
for(r=1;r<=no;r++)
{
for(p=1;p<=no;p++)
{
cout<<array[r][p];
}
cout<<"\n";
}

do
{
for(r=1;r<=no;r++)visited[r]=0;
cout<<"\n1.BFS";
cout<<"\n2.DFS";
cout<<"\nenter ur choice";
cin>>ch;
cout<<"enter the source vertex:";
cin>>s;

switch(ch)
{
case 1:bfs(s,no);
break;
case 2:
dfs(s,no);
break;
}
cout<<"do u want to continue(Y/N) ? ";
cin>>c;
}while((c=='y')||(c=='Y'));
}
void bfs(int s,int n)
{
int w,x;
adding(s);
visited[s]=1;
w=deleting();
if(w!=0)
cout<<w;
while(w!=0)
{
for(x=1;x<=n;x++)
if((array[w][x]!=0)&&(visited[x]==0))
{
adding(x);
visited[x]=1;
}
w=deleting();
if(w!=0)
cout<<w;
}
for(x=1;x<=n;x++)
if(visited[x]==0)
bfs(x,n);
}


void adding(int item)
{
if(rear==19)
cout<<"QUEUE FULL";
else
{
if(rear==-1)
{
q[++rear]=item;
head++;
}
else
q[++rear]=item;
}
}
int deleting()
{
int k;
if((head>rear)||(head==-1))
return(0);
else
{
k=q[head++];
return(k);
}
}

void dfs(int s1,int n1)
{
int i,k;
push(s1);
visited[s1]=1;
k=pop();
if(k!=0)
cout<<k;
while(k!=0)
{
for(i=1;i<=n1;i++)
if((array[k][i]!=0)&&(visited[i]==0))
{
push(i);
visited[i]=1;
}
k=pop();
if(k!=0)
cout<<k;
}
for(i=1;i<=n1;i++)
if(visited[i]==0)
dfs(i,n1);
}


void push(int item)
{
if(top==19)
cout<<"Stack overflow ";
else
stacks[++top]=item;
}


int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stacks[top--];
return(k);
}
}