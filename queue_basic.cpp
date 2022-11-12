// array  implementaition of queue
#include<iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};

int isFull(struct queue *q)
{
    if(q->b==q->size-1)
    return 1;
    else
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    cout<<"Queue is full"<<endl;
    else{
        q->b++;
        q->arr[q->b]=val;
        cout<<"Enqued element: "<<val<<endl;
    }
}

int isEmpty(struct queue *q)
{
    if(q->f==q->b)
    return 1;
    else
    return 0;
}

int dequeue(struct queue *q)
{
    int a=-1;
    if(isEmpty(q))
    cout<<"Queue is Empty"<<endl;
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}


int main()
{
    struct queue q;
    q.f=q.b=0;
    q.size=4;
    q.arr=(int *)malloc(q.size*sizeof(int));

    enqueue(&q,20);             //Passing 'q' by reference because we have not declared a pointer for teh structure
    enqueue(&q,30);
    enqueue(&q,40);

    cout<<"Dequeuing element"<<dequeue(&q)<<endl;
    cout<<"Dequeuing element"<<dequeue(&q)<<endl;
    cout<<"Dequeuing element"<<dequeue(&q)<<endl;

    enqueue(&q,100);
    enqueue(&q,200);
    enqueue(&q,300);

    if(isEmpty(&q))
    {
        cout<<"Queue is empty"<<endl;
    }
    if(isFull(&q))
    {
        cout<<"Queue is full"<<endl;
    }
    return 0;
}

// Queue is full is being printed multiple time becuase q->b is not being reseted after dequeuing