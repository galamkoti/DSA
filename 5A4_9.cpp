#include<iostream>
#include<math.h>
using namespace std;
int array[20];
void inorder(int k)
{
    if (array[2*k]!=-1)
        inorder(2*k);
    cout<<array[k]<<" ";
    if(array[2*k+1]!=-1)
        inorder(2*k+1); 
}
void preorder(int k)
{
    cout<<array[k]<<" ";
    if (array[2*k]!=-1)
        preorder(2*k);
    if(array[2*k+1]!=-1)
        preorder(2*k+1); 
}
void postorder(int k)
{
    if (array[2*k]!=-1)
        inorder(2*k);
    if(array[2*k+1]!=-1)
        inorder(2*k+1);
    cout<<array[k]<<" ";
}
int main()
{
    int n11,n12,n;
    cout<<"enter the number of levels\n";
    cin>>n;
    n11=pow(2,n)-1;
    n12=pow(2,n+1)-1;
    cout<<"enter the"<<n11<<"nodes u want\n";
    for (int i = 1; i <=n11; i++)
    {
        cout<<"enter the element at"<<i<<"position\n";
        cin>>array[i];
    }
    for (int i = n11+1; i <=n12; i++)
    {
        array[i]=-1;
    }
    for (int i = 1; i <=n12; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<"\ninorder is";
    inorder(1);
    cout<<"\npreorder is";
    preorder(1);
    cout<<"\npostorder is";
    postorder(1);
}
