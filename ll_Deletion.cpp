#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    while(head!=NULL)
    {
        printf("Element is: %d\n", head->data);
        head=head->next;
    }
}

struct node * firstDeletion(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
}

struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node *LastDelete(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node *valueDelete(struct node *head, int value)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=NULL && q->data!=value)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head= (struct node *)malloc(sizeof(struct node));
    second= (struct node *)malloc(sizeof(struct node));
    third= (struct node *)malloc(sizeof(struct node));
    fourth= (struct node *)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    cout<<"Linked list before deletion";
    traversal(head);        //display
    // head=firstDeletion(head);   //Deleting the first element
    head=LastDelete(head);          //Delete the last element
    cout<<"After deleting last element"<<endl;
    traversal(head);
    // head=deleteAtIndex(head,2);       //Deleting by index
    // head=valueDelete(head,30);     //Delete by value

    return 0;
}