#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *Insert(Node **start,Node *q);
void Del(Node **start);
void Traverse(Node *start);
int main()
{   Node *start=NULL,*q;
    int ch,top=-1;
    do
    {
        printf("\nPress 1 to Insert\nPress 2 to Del\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
           q=Insert(&start,q);
            break;
        case 2:
            Del(&start);
            break;
        case 3:
            Traverse(start);
            break;
        case 4:
            exit;
            break;
        default:
        printf("Please enter a valid input!\n");        
        }
    } while (ch!=4);
return 0;
}
Node *Insert(Node **start,Node *q)
{   Node *p;
    printf("Enter Data:");
    p=(Node*)malloc(sizeof(Node));
    scanf("%d",&p->data);
    p->next=NULL;
    if(p==NULL)
    printf("Overflow Condition\n");
    else
    {
        if(*start==NULL)
            *start=p;
        else
            q->next=p;
        q=p;
        return q;
    }
}
void Del(Node **start)
{   Node *p=*start;
    if(*start==NULL)
    printf("Underflow Condition!\n");
    else
    {
        printf("%d is Deleted from the Queue!",(*start)->data);
        *start=(*start)->next;
        free(p);
    }
}
void Traverse(Node *start)
{
    if(start==NULL)
    printf("Underflow Condition!\n");
    else{
    for (; start!=NULL; start=start->next)
    printf("%d\t",start->data);

    }
}