#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    int hyt;
};
class ff
{
    public:
    node* inserting(node*,node*);
    node* deleting(node*,int);
    node* newnode(int);
    node* rightrotate(node*);
    node* leftrotate(node*);
    node* LL(node*);
    node* RR(node*);
    node* RL(node*);
    node* LR(node*);
    int heit(node*);
    int balfac(node*);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
};
node* temp=NULL;
int main()
{
    int num,search,element,item;
    node *root=NULL;
    
    ff fk;
    while (true)
    {
        cout<<"select one number";
        cout<<"\n1.insert 2.delete3.inorder 4.preorder 5.postorder 6.exit";
        cin>>num;
        switch (num)
        {
        case 1:cout<<"enter the element to insert";
                cin>>element;
                temp=fk.newnode(element);
                root=fk.inserting(root,temp);
                break;
        case 2:cout<<"enter the element to delete";
                cin>>item;
                fk.deleting(root,item);
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
        case 6:cout<<"enter correct choice";
                break;
        default:exit(0);
    }
}
}
int ff::heit(node* temp)
{
    int hl,hr;
    if(temp->left==NULL)
        hl=0;
    else
        hl=1+temp->left->hyt;
    if(temp->right==NULL)
        hr=0;
    else
        hr=1+temp->right->hyt;
    if(hl>hr)
        return hl;
    else
        return hr;
}
int ff::balfac(node* temp)
{
    int hl,hr;
    if(temp->left==NULL)
        hl=0;
    else
        hl=1+temp->left->hyt;
    if(temp->right==NULL)
        hr=0;
    else
        hr=1+temp->right->hyt;
    return hl-hr;
}
node* ff::newnode(int var)
{
    node* temp=new node;
    temp->data=var;
    temp->left=temp->right=NULL;
    return temp;
}
node* ff::inserting(node* root,node* temp)
{
        if (root==NULL)
        {
            root=temp;
        }
        else if (temp->data < root->data)
        {
            root->left=inserting(root->left,temp);
            if(balfac(root)==2)
            {
            if(root->left->data > temp->data)
            {
                root=LL(root);
            }
            else
            {
                root=LR(root);
            }
            }
        }
        else if (temp->data > root->data)
        {
            root->right=inserting(root->right,temp);
            if(balfac(root)==-2)
            {
            if(root->right->data < temp->data)
            {
                root=RR(root);
            }
            else
            {
                root=RL(root);
            }
            }
        }
    root->hyt=heit(root);
    return root;
}
node* ff::leftrotate(node* temp)
{
    node* k;
    k=temp->right;
    temp->right=k->left;
    k->left=temp;
    temp->hyt=heit(temp);
    k->hyt=heit(k);
    return k;
}
node* ff::rightrotate(node* temp)
{
    node* k;
    k=temp->left;
    temp->left=k->right;
    k->right=temp;
    temp->hyt=heit(temp);
    k->hyt=heit(k);
    return k;
}
node* ff::LL(node* temp)
{
    temp=rightrotate(temp);
    return temp;
}
node* ff::RR(node* temp)
{
    temp=leftrotate(temp);
    return temp;
}
node* ff::LR(node* temp)
{
    temp->left=leftrotate(temp->left);
    temp=rightrotate(temp);
    return temp;
}
node* ff::RL(node* temp)
{
    temp->right=rightrotate(temp->right);
    temp=leftrotate(temp);
    return temp;
}
node* ff::deleting(node* root,int i)
{
    node* q=NULL;
    if(root==NULL)
        return NULL;
    else if(i > root->data)
    {
        root->right=deleting(root->right,i);
        if (balfac(root)==2)
        {
            if(balfac(root->left)>=0)
                root=LL(root);
            else
            {
                root=LR(root);
            }
        }
    }
    else if (i < root->data)
    {
        root->left=deleting(root->left,i);
        if (balfac(root)==2)
        {
            if(balfac(root->right)>=0)
                root=LL(root);
            else
            {
                root=LR(root);
            }
        }
    }
    else
    {
        if (root->right!=NULL)
        {
            q=root->right;
            while(q->left!=NULL)
                q=q->left;
            root->data=q->data;
            root->right=deleting(root->right,q->data);
            if(balfac(root)==2)
            {
                if (balfac(root->left)>=0)
                {
                    root=LL(root);
                }
                else
                {
                    root=LR(root);
                }
            }
        }
        else
        {
            return root->left;
        }
    }
    root->hyt=heit(root);
    return root;
}
void ff::inorder(node* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void ff::preorder(node* root)
{
    if (root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void ff::postorder(node* root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}