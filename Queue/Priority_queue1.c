                            // Priority Queue - Type 1(Deletion Acc. to priority)
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data,pri;
    struct node *next;
}Node;
Node *Create_node(){
    Node *p;
    p=(Node *)malloc(sizeof(Node));
    printf("\nEnter data:");
    scanf("%d",&p->data);
    printf("\nEnter priority:");
    scanf("%d",&p->pri);
    p->next=NULL;
    return p;
}
Node *Insert(Node **start,Node *q)
{   Node *p;
    p=Create_node();
    if(p==NULL)
    printf("Overflow Condition\n");
    else if(p->pri<0)
    {
    printf("\nPriority can not be Negative!");
    free(p);
    }
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
{   Node *q,*p=*start;
    int n; 
    if(*start==NULL)
    printf("Underflow Condition!\n");
    else
    {
        n=(*start)->pri;
        while (p->next!=NULL)
        {
            if(n>(p->next)->pri)
            {
                q=p;
                n=(p->next)->pri;
            }
            p=p->next;
        }
        if(n==(*start)->pri)
        {   p=*start;
            printf("%d is Deleted from the Queue!",(*start)->data);
            *start=(*start)->next;
            free(p);
        }
        else{
            p=q->next;
            q->next=p->next;
            printf("%d is Deleted from the Queue!",p->data);
            free(p);
        }
    }
}
void Traverse(Node *start)
{
    if(start==NULL)
    printf("Underflow Condition!\n");
    else{
    printf("\nPriority\tData");
    for (; start!=NULL; start=start->next)
    {
    printf("\n%d\t\t",start->pri);
    printf("%d",start->data);
    }
    }
}
int main()
{
    Node *q,*start=NULL;
    int ch;
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
            break;
        default:
        printf("Please enter a valid input!\n");        
        }
    } while (ch!=4);
return 0;
}