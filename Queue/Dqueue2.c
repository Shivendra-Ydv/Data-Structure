//                                             Dqueue with shifting
#include<stdio.h>
#include<stdlib.h>
void insert_rear(int *a,int *rear,int *front,int n);
void insert_front(int *a,int *rear,int *front,int n);
void del_front(int *a,int *rear,int *front);
void del_rear(int *a,int *rear,int *front);
void traverse(int *a,int rear,int front);
int main()
{
    int ch,n,rear,front,*a;
    printf("Enter the size of queue:");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    rear=-1;
    front=-1;
    do
    {
        printf("\nPress 1 to Insert from rear\nPress 2 to Insert from front\nPress 3 to Delete from front\nPress 4 to Delete from rear\nPress 5 to Traverse\nPress 6 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert_rear(a,&rear,&front,n);
            break;
        case 2:
            insert_front(a,&rear,&front,n);
            break;
        case 3:
            del_front(a,&rear,&front);
            break;
        case 4:
            del_rear(a,&rear,&front);
            break;
        case 5:
            traverse(a,rear,front);
            break;
        case 6:
            break;
        default:
        printf("Please enter a valid input!\n");        
        }
    } while (ch!=6);
return 0;
}
void insert_rear(int *a,int *rear,int *front,int n)
{
    if((*rear==n-1&&*front==0))
            printf("\nOverflow!");
            else
            {
                if(*front==-1&&*rear==-1)
                   {
                        (*front)++;
                        (*rear)++;
                   }
                else if(*rear==n-1&&*front>0)
                {   (*front)--;
                    for (int i = *front; i < *rear; i++)
                        a[i]=a[i+1];                   
                }
                else
                (*rear)++;
                printf("\nEnter data:");
                scanf("%d",&a[*rear]);
            }
}
void del_front(int *a,int *rear,int *front)
{
    if(*front==-1||*rear<*front)
            printf("\nUnderflow!");
            else
            {
                printf("\n%d is deleted from the queue!",a[*front]);
                if(*front==*rear)
                *rear=*front=-1;
                else
                (*front)++;
            }
}
void traverse(int *a,int rear,int front)
{
    if(front==-1||rear<front)
            printf("\nUnderflow!");
            else
            {
                for(int i=front;i<=rear;i++)
                printf("%d\t",a[i]);
            }
}
void insert_front(int *a,int *rear,int *front,int n)
{
    if((*rear==n-1&&*front==0))
            printf("\nOverflow!");
            else
            {
                if(*front==-1&&*rear==-1)
                   {
                        (*front)++;
                        (*rear)++;
                   }
                else if(*rear<n-1&&*front==0)
                {   (*rear)++;
                    for (int i = *rear; i >*front; i--)
                        a[i]=a[i-1];                   
                }
                else
                (*front)--;
                printf("\nEnter data:");
                scanf("%d",&a[*front]);
            }
}
void del_rear(int *a,int *rear,int *front)
{
    if(*front==-1||*rear<*front)
            printf("\nUnderflow!");
            else
            {
                printf("\n%d is deleted from the queue!",a[*rear]);
                if(*front==*rear)
                *rear=*front=-1;
                else
                (*rear)--;
            }
}