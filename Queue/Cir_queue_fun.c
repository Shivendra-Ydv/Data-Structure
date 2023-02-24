#include<stdio.h>
#include<stdlib.h>
void insert(int *a,int *rear,int *front,int n);
void del(int *a,int *rear,int *front,int n);
void traverse(int *a,int rear,int front,int n);
int main()
{   int i;
    int ch,n,rear,front,*a;
    printf("Enter the size of queue:");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    rear=-1;
    front=-1;
    do
    {
        printf("\nPress 1 to Insert\nPress 2 to Delete\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
           insert(a,&rear,&front,n);
            break;
        case 2:
            del(a,&rear,&front,n);
            break;
        case 3:
            traverse(a,rear,front,n);    
            break;
        case 4:
            break;
        default:
        printf("Please enter a valid input!\n");        
        }
    } while (ch!=4);
return 0;
}
void insert(int *a,int *rear,int *front,int n)
{
    if((*rear+1)%n==*front)
            printf("\nOverflow!");
            else
            {
                if(*front==-1&&*rear==-1)
                    (*front)++;
                *rear=(*rear+1)%n;
                printf("\nEnter data:");
                scanf("%d",&a[*rear]);
            }
}
void del(int *a,int *rear,int *front,int n)
{
    if(*front==-1||*rear==-1)
            printf("\nUnderflow!");
            else
            {
                printf("\n%d is deleted from the queue!",a[*front]);
                if(*front==*rear)
                *rear=*front=-1;
                else
                *front=(*front+1)%n;
            }
}
void traverse(int *a,int rear,int front,int n)
{
    if(front==-1||rear==-1)
            printf("\nUnderflow!");
            else
            { 
                do
                {
                printf("%d\t",a[front]);
                front=(front+1)%n;
                }while (front!=(rear+1)%n);
            }
}