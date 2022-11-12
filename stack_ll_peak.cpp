#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;



int isEmpty(struct node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    {
        return 1;
    }
    else
    {return 0;}
}

struct node* push(struct node *top, int x)
{
    if(isFull(top))
    {
        cout<<"Stack overflow"<<endl;
    }
    else{
        struct node *n=(struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(struct node *top)
{
    if(isEmpty(top))
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        struct node *n=top;
        top=top->next;
        int x=n->data;
        free(n);
        return x;
    }

}

void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int peek(int pos)
{
    struct node *ptr=top;
    for (int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else
    return -1;
}

int main()
{
    top=push(top,20);
    top=push(top,45);
    top=push(top,100);
    top=push(top,70);
    for(int i=1;i<=4;i++)
    {
        cout<<"Element at position "<<i<<" is "<<peek(i)<<endl;
    }
    traversal(top);

    return 0;
}