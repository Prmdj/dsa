/*C code to implement stack using 2 queues
refer http://pagalscientistforyou.blogspot.com/2012/01/c-code-to-implement-stack-using-queue.html*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct queue
{
    struct node *rear;
    struct node *front;
};

void initial(struct queue *);
void qadd(struct queue *,int);
int qdel(struct queue *);
void dis(struct queue *);
void push(int);
void pop();

struct queue q1,q2;
int main()
{
    int c,value;
    initial(&q1);
    initial(&q2);
    while(1){
        printf("\n[1] Push\n[2] Pop\n[3] Display\n[0] Exit");
        printf("\nChoice: ");
        scanf(" %d", &c);
        switch(c){
            case 1: printf("\nEnter value to Push:");
                    scanf(" %d", &value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: printf("\nElements are:\n");
                    display(&q1);
                    break;
            case 0: exit(0);

    }
    }




    return 0;
}

void initial(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

void qadd(struct queue *q,int n)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));

    tmp->data=n;
    tmp->next=NULL;

    if(q->front==NULL)
    {
        q->rear=tmp;
        q->front=tmp;
        return;
    }

    q->rear->next=tmp;
    q->rear=tmp;
}

int qdel(struct queue *q)
{
    struct node *tmp;
    int itm;
    if(q->front==NULL)
    {
        printf("\nqueue is empty");
        return NULL;
    }

    //itm=q->front->data;
    tmp=q->front;
    itm=tmp->data;
    q->front=tmp->next;
    free(tmp);
    return itm;

}

void display(struct queue *q)
{
    struct node *tmp;
    tmp=q->front;
    while((tmp)!=NULL)
    {
        printf("\t%d",(tmp->data));
        tmp=tmp->next;
    }
    printf("\n");
}


void push(int val)
{
    struct queue tmp;
    int j;
    qadd(&q2,val);

    while(((&q1)->front)!=NULL)
    {
        j=qdel(&q1);
        qadd(&q2,j);
    }


    tmp=q1;  //swap q1 and q2
    q1=q2;
    q2=tmp;

}

void pop()
{
    printf("\nElement deleted is %d",qdel(&q1));
}
