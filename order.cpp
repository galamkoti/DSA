#include<iostream>
using namespace std;
class node_bst
{
    public:
    int data;
    node_bst *left;
    node_bst *right;
};
node_bst *inserting(node_bst *root,int k)
{
    if (root==NULL)
    {
        node_bst *temp=new node_bst;
        temp->data=k;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else
    {
        if (k<root->data)
        {
            root->left=inserting(root->left,k);
        }
        if (k>root->data)
        {
            root->right=inserting(root->right,k);
        }
    }
    return root;
}
void inorder(node_bst *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node_bst *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(node_bst *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    int num,array[20];
    node_bst *root=NULL;
    cout<<"enter no of elements";
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"enter the element"<<i+1;
        cin>>array[i];
        root=inserting(root,array[i]);
    }
}