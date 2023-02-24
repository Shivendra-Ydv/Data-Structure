#include<stdio.h>
#include<stdlib.h>
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
            if((rear+1)%n==front)
            printf("\nOverflow!");
            else
            {
                if(front==-1&&rear==-1)
                    front++;
                rear=(rear+1)%n;
                printf("\nEnter data:");
                scanf("%d",&a[rear]);
            }
            break;
        case 2:
            if(front==-1||rear==-1)
            printf("\nUnderflow!");
            else
            {
                printf("\n%d is deleted from the queue!",a[front]);
                if(front==rear)
                rear=front=-1;
                else
                front=(front+1)%n;
            }
            break;
        case 3:
        
            if(front==-1||rear==-1)
            printf("\nUnderflow!");
            else
            {   i=front;
                do
                {
                printf("%d\t",a[i]);
                i=(i+1)%n;
                }while (i!=(rear+1)%n);
            }
            break;
        case 4:
            break;
        default:
        printf("Please enter a valid input!\n");        
        }
    } while (ch!=4);
return 0;
}