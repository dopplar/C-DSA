#include<iostream>
#include<stdio.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *n;
    n=new node;
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    return n;
}

int inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }
    return 0;
}

int isBST(struct node *root)
{
    static struct node *prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {return 0;}
        if(prev!=NULL && root->data <= prev->data)
        return 0;
        prev=root;
        return isBST(root->right);
    }
    else
    return 1;
}

int main()
{
    struct node *p=createNode(5);
    struct node *p1=createNode(3);
    struct node *p2=createNode(6);
    struct node *p3=createNode(1);
    struct node *p4=createNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p); //prints the tree elemnts in ascending order
    cout<<endl;
    if(isBST(p))
    {
        cout<<"This is a BST";
    }
    else
    {
        cout<<"This is not a BST";
    }
    return 0;
}