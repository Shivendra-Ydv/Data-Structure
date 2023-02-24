#include<stdio.h>
#include<stdlib.h>
int main()
{
    int front ,rear, n , *a , ch ;
    printf("Size of an array to be created");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    do
    {
       printf("press 1 for insertion\n  press 2 for delt\n  press 3 for traverse");
       scanf("%d",&ch);
       switch (ch)
       {
case 1:
       if ((rear + 1)% n ==front)
        printf("Under flow");
        else
        if(rear==-1 && front==-1)
        {
        front++;
        rear++;
        }
        else{
        rear = (rear + 1)%n;
        printf("Enter the item in the queue");
        scanf("%d", &a[rear]);}
         break;
 case 2:
         if(front==-1)
         printf("UNDERFLOW");
         else
         printf("deleted item is %d",a[rear]);
         if (rear==front)
          rear=front=-1;
        else
        front = (front+1)%n;
        break;
 case 3:
         if(front==-1 && rear==-1)
         printf("UNDERFLOW");
         for (int  i = front; i < rear; i++)
         {
            printf("%d",a[i]);
         }
         break;
      default:
         printf("Please enter a valid input!\n");        
        
       } 
    } while (ch!=4);
    
    return 0;
}