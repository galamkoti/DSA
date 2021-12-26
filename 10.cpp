#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
};
class fff
{
    public:
    node* inserting(node*,int);
    bool searching(node*,int);
    node* deleting(node*,int);
    node* minnodevalue(node*);
    node* newnode(int);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
};
int main()
{
    int num,search,element,item;
    node *root=NULL;
    fff fk;
    while (true)
    {
        cout<<"select one number";
        cout<<"\n1.insert 2.search 3.inorder 4.preorder 5.postorder 6.delete";
        cin>>num;
        switch (num)
        {
        case 1:cout<<"enter the element to insert";
                cin>>element;
                fk.inserting(root,element);
                break;
        case 2:cout<<"enter the number u want to search";
                cin>>search;
                if(fk.searching(root,search)==true)
                {
                    cout<<"element found";
                }
                else
                {
                    cout<<"element not found";
                }
                
                break;
        case 3:cout<<"the inorder is";
                fk.inorder(root);
                break;
        case 4:cout<<"the preorder is";
                fk.preorder(root);
                break;
        case 5:cout<<"the postorder is";
                fk.postorder(root);
                break;
        case 6:cout<<"enter the value to be deleted";
                cin>>item;
                fk.deleting(root,item);
        case 7:fk.minnodevalue(root);
                break;
        default:cout<<"enter correct value";
        }
    }
}
node* fff::inserting(node* root,int k)
{
        if (root==NULL)
        {
            root=newnode(k);
            
        }
        else if (k<root->data)
        {
            root->left=inserting(root->left,k);
        }
        else if (k>root->data)
        {
            root->right=inserting(root->right,k);
        }
    return root;
}

bool fff::searching(node* root,int key)
{
    if (root==NULL)
        return false;
    else if(root->data==key)
       return true;
    else if(key>root->data)
        return searching(root->right,key);
    else
        return searching(root->left,key);
}
void fff::inorder(node* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void fff::preorder(node* root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void fff::postorder(node* root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
node* fff::deleting(node* root,int l)
{
    if(root==NULL)
    {
        return root;
    }
    else if (l<root->data)
        {
            root->left=deleting(root->left,l);
        }
    else if (l>root->data)
        {
             root->right=deleting(root->right,l);
        }
    else
    {
        //case1:leaf node
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
            return root;
        }
        //case2:node having single node
        else if(root->left==NULL)
        {
            node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        else
        {
            //case3:node having two children
            node* temp=minnodevalue(root->right);
            root->data=temp->data;
            root->right=deleting(root->right,temp->data);
            return root;
        }
    }
}
node* fff::minnodevalue(node* root)
{
    node* current=root;
    while (current->left!=NULL)
    {
        current=current->left;
    }
    return current;   
}
node* fff::newnode(int var)
{
    node* temp=new node;
    temp->data=var;
    temp->left=temp->right=NULL;
    return temp;
}