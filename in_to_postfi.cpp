#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;
};

int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {return 1;}
    else
    {return 0;}
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {return 1;}
    else
    {return 0;}
}

void push(struct stack *ptr, int val)
{
    if(isFull(ptr))
    {
        cout<<"Stack overflow"<<endl;
    }
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
        cout<<"Stack underflow";
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if(ch=='/' || ch=='*')
    return 3;
    else if(ch=='+' || ch=='-')
    return 2;
    else
    return 0;
}

int isoperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    return 1;
    else
    return 0;
}

char *InfixtoPostfix(char* infix)
{
   struct stack *sp= (struct stack*)malloc(sizeof(struct stack));
   sp->size=10;
   sp->top=-1;
   sp->arr=(char *)malloc(sp->size*sizeof(char));
   char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
   int i=0; //Track infix
   int j=0;  //Track Postfix
   while(infix[i]!='\0')
   {
       if(!isoperator(infix[i]))
       {
           postfix[j]=infix[i];
           j++;
           i++;
       }
       
       else{
           if(precedence(infix[i])>precedence(stacktop(sp)))
       {
           push(sp,infix[i]);
           i++;
       }
       else
       {
           postfix[j]=pop(sp);
           j++;
       }
       }
   }
   while(!isEmpty(sp))
   {
       postfix[j]=pop(sp);
       j++;
   }
   postfix[j]='\0';
   return postfix;

}

int main()
{
    char *infix = "x-y/z-k*d";
    cout<<"postfix is "<<InfixtoPostfix(infix);
    return 0;

}