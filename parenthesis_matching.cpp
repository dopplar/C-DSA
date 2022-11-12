#include<iostream>
#include<stdio.h>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    return 1;
    else
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    return 0;
}

int push(struct stack *ptr, char val)
{
    if(isFull(ptr))
    {cout<<"Stack Overflow"<<endl;
    return -1;}
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else
    {
        char val=ptr->arr[ptr->top];;
        ptr->top--;
        return val;
    }
}
char stacktop(struct stack *ptr)
{
    cout<<ptr->arr[ptr->top];
}

