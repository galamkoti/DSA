#include<iostream>
using namespace std;

class node{
    public:
    int key;
    node *left,*right;
    int ht;
};

class AVL{
    public:
    node* root=NULL;
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    node* insertnode(node *root,node *tmp);
    node* deletenode(node*,int);
    int height(node*);
    int bf(node*);
    node* LL(node*);
    node* LR(node*);
    node* RL(node*);
    node* RR(node*);
    node* rightrotate(node*);
    node* leftrotate(node*);
};

void AVL::inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void AVL::preorder(node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void AVL::postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

int AVL :: height(node *tmp){
    int hl,hr;
    if(tmp->left==NULL)
        hl=0;
    else
        hl=1+tmp->left->ht;
    if(tmp->right == NULL)
        hr=0;
    else
        hr=1+tmp->right->ht;
    if(hl>hr)
        return hl;
    else
        return hr;
}

int AVL:: bf(node *tmp){
    int hl,hr;
    if(tmp->left==NULL)
        hl=0;
    else
        hl=1+tmp->left->ht;
    if(tmp->right == NULL)
        hr=0;
    else
        hr=1+tmp->right->ht;
    return hl-hr;
}

node* AVL :: rightrotate(node *tmp){
    node *a;
    a=tmp->left;
    tmp->left = a->right;
    a->right = tmp;
    return a;
}

node* AVL :: leftrotate(node *tmp){
    node *a;
    a=tmp->right;
    tmp->right = a->left;
    a->left = tmp;
    return a;
}

node* AVL :: LL(node *tmp){
    tmp=rightrotate(tmp);
    return tmp;
}

node* AVL :: RR(node *tmp){
    tmp=leftrotate(tmp);
    return tmp;
}

node* AVL :: LR(node *tmp){
    tmp->left=leftrotate(tmp->left);
    tmp=rightrotate(tmp);
    return tmp;
}

node* AVL :: RL(node *tmp){
    tmp->right=rightrotate(tmp->right);
    tmp=leftrotate(tmp);
    return tmp;
}

node* AVL :: insertnode(node *root,node *tmp){
    if(root == NULL)
        root=tmp;
        
    else if(root->key > tmp->key){
        root->left=insertnode(root->left,tmp);
        if(bf(root)==2){
            if(root->left->key > tmp->key)
                root=LL(root);
            else
                root=LR(root);
        }
    }
    
    else if( root->key < tmp->key){
        root->right=insertnode(root->right,tmp);
        if(bf(root)==-2){
            if(root->right->key < tmp->key)
                root=RR(root);
            else
                root=RL(root);
        }
    }
    root->ht=height(root);
    return root;
}

node* AVL::deletenode(node* root,int v)
{
    node *tmp=NULL;
    if(root==NULL)
    {
        return NULL;
    }
    else if(v>root->key)
    {
        root->right=deletenode(root->right,v);
        if(bf(root)==-2)
        {
            if(bf(root->left)>0)
            {
                root=LL(root);
            }
            else
            {
              root=LR(root);
            }
        }
    }
    else if(v<root->key)
    {
        root->left=deletenode(root->left,v);
         if(bf(root)==2)
           {          
               if(bf(root->right)<0)
                 {
                     root=RR(root);
                 }
               else
                 {
                     root=RL(root);
                 }
           }
    }
    else
    {
        if(root->right!=NULL)
        {
             tmp=root->right;
             while(tmp->left!=NULL)
             {
                 tmp=tmp->left;
             }
                 root->key=tmp->key;
                 root->right=deletenode(root->right,tmp->key);
                  if(bf(root)==2)
                 {
                     if(bf(root->left)>=0)
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
    root->ht=height(root);
    return root;
}

int main(){
    int n,n1,n2;
    node *tmp=NULL;
    AVL b1;
    while(1){
        cout<<"select an option 1.insert 2.Delete 3.print 4.exit";
        cin>>n;
        switch(n){
            case 1: tmp=new node();
                    cout<<"Enter the value to insert\n";
                    cin>>tmp->key;
                    tmp->left = NULL;
                    tmp->right = NULL;
                    b1.root = b1.insertnode(b1.root,tmp);
                    break;
            case 2: cout<<"Enter the node value to delete";
                    cin>>n1;
                    b1.root = b1.deletenode(b1.root,n1);
                    break;
            case 3: cout<<"select an option 1.inorder 2.preorder 3.postorder";
                    cin>>n2;
                    switch(n2){
                        case 1: b1.inorder(b1.root);
                                break;
                        case 2: b1.preorder(b1.root);
                                break;
                        case 3: b1.postorder(b1.root);
                                break;
                        default: cout<<"Enter correct choice";
                    }
                    break;
            case 4: exit(0);
            
        }
    }
}