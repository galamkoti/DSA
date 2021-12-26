#include<iostream>
using namespace std;
class node
{
    int data;
    node *left;
    node *right;
};
class nodes
{
node *searching(nodes *root,int key);
node *inserting(nodes *root,int k);
};
node* nodes::searching(node *root,int key)
{
    if (key==root->data)
    {
        cout<<"element found";
        return;
    }
    else if(key<root->data)
        root->left=searching(root->left,key);
    else if(key>root->data)
        root->right=searching(root->right,key);
}
nodes *inserting(node *root,int k)
{
    if (root==NULL)
    {
        node *temp=new node;
        temp->data=k;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return root;
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
void inorder(node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(node *root)
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
    int num,element,search,choice,printopt,array[20];
    nodes  *root=NULL;
    while(true)
    {
        cout<<"enter the choice";
        cout<<"1.insert 2.search 3.print 4.quit";
        cin>>choice;
        switch (choice)
        {
        case 1:cout<<"enter the element u want";
                cin>>element;
                inserting(root,element);
                break;
        case 2:cout<<"enter the element to search";
                cin>>search;
                searching(root,search);
                break;
        case 3:cout<<"select the printing option";
               cout<<"1.inorder 2.preorder 3.postorder";
                cin>>printopt;
                switch(printopt)
                {
                    case 1:inorder(root);
                    break;
                    case 2:preorder(root);
                    break;
                    case 3:postorder(root);
                    break;
                    default:cout<<"enter valid option for printing";
                    break;
                }
        case 4:exit(0);
        default:cout<<"\nenter correct choice";
        }
    }
}