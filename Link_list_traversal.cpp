//linked list traversal

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int trav(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%\n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}

int main()
{
    struct node *head,*first,*second,*third;
    head=(struct node *)malloc(sizeof(struct node));
    first=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));

    head->data=7;
    head->next=first;

    first->data=10;
    first->next=second;

    second->data=12;
    second->next=third;

    third->data=25;
    third->next=NULL;

    trav(head);
    return 0;

}