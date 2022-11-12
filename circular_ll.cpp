#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int trav(struct node *head)
{
    struct node *p=head;

    do{
        cout<<"Element is: "<<p->data<<endl;
        p=p->next;
    }while(p!=head);
    return 0;
}

struct node * insertAtFirst(struct node *head, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    head=ptr;     //Value inserted
    return head;
}

// struct node * insertAtindex(struct node *head, int data, int index)
// {
//     struct node *ptr=(struct node *)malloc(sizeof(struct node));
//     ptr->data=data;
//     struct node *p=head->next;
//     for(int i=0;i<index-1;i++)
//     {
//         p=p->next;
//         head=head->next;
//     }
//     p->next=ptr;
    

// }

int main()
{
    struct node *head,*second,*third,*fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=head;

    cout<<"Before insertion"<<endl;
    trav(head);
    cout<<"After insertion"<<endl;
    head=insertAtFirst(head,90);
    trav(head);
    return 0;
}