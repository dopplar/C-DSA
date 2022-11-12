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
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main()
{
    // // Constructing the root node
    // struct node *p;
    // p = new node;
    // p->data;
    // p->left=NULL;
    // p->right=NULL;

    // // Constructing the second node
    // struct node *p1;
    // p1 = new node;
    // p1->data;
    // p1->left=NULL;
    // p1->right=NULL;

    // // Constructing the third node
    // struct node *p2;
    // p2 = new node;
    // p2->data;
    // p2->left=NULL;
    // p2->right=NULL;

    // p->left=p1;
    // p->right=p2;

    struct node *p= createNode(5);
    struct node *p1=createNode(11);
    struct node *p2=createNode(4);
    p->left=p1;
    p->right=p2;

}