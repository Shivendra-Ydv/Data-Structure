#include<stdio.h>
#include<stdlib.h>
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
        printf("\nPress 1 to Insert\nPress 2 to Delete\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            if(rear==n-1)
            printf("\nOverflow!");
            else
            {
                if(front==-1&&rear==-1)
                    front++;
                rear++;
                printf("\nEnter data:");
                scanf("%d",&a[rear]);
            }
            break;
        case 2:
            if(front==-1||rear<front)
            printf("\nUnderflow!");
            else
            {
                printf("\n%d is deleted from the queue!",a[front]);
                if(front==rear)
                rear=front=-1;
                else
                front++;
            }
            break;
        case 3:
            if(front==-1||rear<front)
            printf("\nUnderflow!");
            else
            {
                for(int i=front;i<=rear;i++)
                printf("%d\t",a[i]);
            }
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