#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct  node* root){
    static struct node *prev = NULL;    
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node * search(struct node *root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    else if(root->data<key)
    return search(root->right,key);
    else
    return search(root->left,key);
}

struct node * searchIter(struct node *root,int key)
{
    while(root!=NULL)
    {
        if(root->data==key)
        return root;
        else if(key<root->data)
        root=root->left;
        else
        root=root->right;
    }
    return NULL;
}

void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* n = createNode(key);
   if(key<prev->data){
       prev->left = n;
   }
   else{
       prev->right = n;
   }
}

struct node *inOrderPredecessor(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node *deleteNode(struct  node *root, int value)
{
    struct node *ipre;
    if(root!=NULL)
    {
        return NULL;
    }
    if(root->right==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(value<root->data)
    {
        root->left=deleteNode(root->left,value);
    }
    if(value>root->data)
    {
        root->right=deleteNode(root->right,value);
    }
    else{
        ipre=inOrderPredecessor(root);
        root->data=ipre->data;
        deleteNode(root->left,ipre->data);
    }
}
int min(struct node * root)
{
    struct node *current =root;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    deleteNode(p,3);
    inOrder(p);
    int a=min(p);
    cout<<endl;
    cout<<"Minimum of BST"<<a;
    return 0;

}