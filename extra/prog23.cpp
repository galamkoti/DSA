#include<iostream>
using namespace std;

class DFS_BFS
{
    int n,start;
    int a[20],adj[4][4],vis[10];
    public:
    void input();
    void logic();
    void dfs(int k);
    void input1();
    void logic1(int a[20][20],int v,int n);
};

void DFS_BFS :: input()
{
    cout<<"enter no of nodes"<<endl;
    cin>>n;
    cout<<"enter"<<n<<" no of vertices"<<endl;
    for(int i=1;i<=n;i++)
       cin>>a[i];
    cout<<"enter the adjenecy matrix"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
}
void DFS_BFS :: input1(){
    int a[20][20],i,j,v;
int n;
cout<<"Enter no.of vertices"<<"\n";
cin>>n;
cout<<"Enter the adjacency matrix"<<"\n";
for(i = 1; i <= n;i++)
  for(j = 1;j <= n;j++)
      cin>>a[i][j];
cout<<"Source Vertex"<<"\n";
cin>>v;
logic1(a,v,n);
}
void DFS_BFS :: logic1(int a[20][20],int v,int n){
int front = -1,rare = -1,arr[20],visited[20] = {0},i;
arr[++rare] = v;
visited[v] = 1;
while(front <= rare){
v = arr[++front];
cout<<v;
for(i = 1;i <= n;i++){
if(a[v][i] && !(visited[i])) {
visited[i] = 1;
arr[++rare] = i;
}
}
}
}

void DFS_BFS :: logic()
{
   cout<<"enter the name of the starting vertex"<<endl;
   cin>>start;
   for(int i=1;i<=n;i++)
   {
       if(start==a[i])
       {
           vis[i]=1;
           cout<<a[i];
           dfs(i);
           break;
       }
   }
}
void DFS_BFS :: dfs(int k)
{
    for(int i=1;i<=n;i++){
        if((adj[k][i]==1)&&(vis[i]==0)){
            vis[i]=1;
            cout<<a[i];
            dfs(i);
        }
    }
    cout<<"\n";
}

int  main()
{
    DFS_BFS d;
    int a;
    while(1)
    {
        cout<<"enter 1.DFS 2.BFS 3.exit"<<endl;
        cin>>a;
        switch(a)
        {
            case 1: d.input();
                    d.logic();
                    break;
            case 2: d.input1();
                    break;
            case 3: exit(0);                
            default : cout<<"enter correct operator"<<endl;
                    break;        
        }
    }
    return 0;
}