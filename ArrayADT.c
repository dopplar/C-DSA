#include<stdio.h>
#include<stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarray *a,int t_size, int u_size)
{
    // (*a).total_size=t_size;
    // (*a).used_size=u_size;
    // (*a).ptr=(int *) malloc (t_size*sizeof(int));
    //The above commented lines do the exact same thing and the ones that are below this comment.
    a->total_size=t_size;
    a->used_size=u_size;
    a->ptr=(int *) malloc (t_size*sizeof(int));
}

void setval(struct myarray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the value of element %d",i);
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
    
}

void show(struct myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
    
}

int main()
{
    struct myarray marks;
    createarray(&marks,10,2);
    setval(&marks);
    show(&marks);
    return 0;
}