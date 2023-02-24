                            // Priority Queue - Type 2(Insertion Acc. to priority)
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
void Insert(Node **start){
    Node *p,*q=*start,*r;
    p=Create_node();
    if(p==NULL)
    printf("\nOverflow Condition!");
    else if(p->pri<0)
    {
    printf("\nPriority can not be Negative!");
    free(p);
    }
    else if(*start==NULL||p->pri<=q->pri){
    p->next=*start;
    *start=p;
    }
    else
    {
        while (q!=NULL)
        {
            if(q->pri<p->pri)
            r=q;
            else 
            break;
            q=q->next;
        }
        r->next=p;
        p->next=q;
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
    Node *start=NULL;
    int ch;
    do
    {
        printf("\nPress 1 to Insert\nPress 2 to Del\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            Insert(&start);
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