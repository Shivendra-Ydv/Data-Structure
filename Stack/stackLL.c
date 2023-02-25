//                                              IMPLEMTING STACK THROUGH LINKED LIST
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
void Push(Node **start);
void Pop(Node **start);
void Traverse(Node *start);
int main()
{   Node *start=NULL;
    int ch,top=-1;
    do
    {
        printf("\nPress 1 to Push\nPress 2 to Pop\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            Push(&start);
            break;
        case 2:
            Pop(&start);
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
void Push(Node **start)
{   Node *p;
    p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
    printf("Overflow Condition\n");
    else
    {
        printf("Enter Data:");
        p=(Node*)malloc(sizeof(Node));
        scanf("%d",&p->data);
            p->next=*start;
            *start=p;
    }
}
void Pop(Node **start)
{   Node *p=*start;
    if(*start==NULL)
    printf("Underflow Condition!\n");
    else
    {
        printf("%d is Deleted from the stack!",(*start)->data);
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