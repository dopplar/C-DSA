#include<iostream>
#include<stdlib.h>
using namespace std;

int trav(struct node *);

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
};


int main()
{
    struct node *n1,*n2,*n3,*n4;
    //creating nodes
    n1=(struct node *)malloc(sizeof(struct node));
    n2=(struct node *)malloc(sizeof(struct node));
    n3=(struct node *)malloc(sizeof(struct node));
    n4=(struct node *)malloc(sizeof(struct node));

    //Linking nodes

    n1->data=10;
    n1->next=n2;
    n1->prev=NULL;

    n2->data=20;
    n2->next=n3;
    n2->prev=n1;

    n3->data=30;
    n3->next=n4;
    n3->prev=n2;

    n4->data=40;
    n4->next=NULL;
    n4->prev=n3;

    trav(n1);
    return 0;

}

int trav(struct node * head)
{
    cout<<"Printing the original linked list: "<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    cout<<"Printing the linked list in reverse: "<<endl;
    struct node *ptr;
    while(ptr!=NULL)
    ptr=ptr->next;
    do{
        cout<<ptr->data;
        ptr=ptr->prev;
    }while(ptr!=NULL);
    return 0;
}
