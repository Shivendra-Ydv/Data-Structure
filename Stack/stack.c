#include<stdio.h>
#include<stdlib.h>
void Push(int n,int *a,int *top);
void Pop(int *a,int *top);
void Traverse(int *a,int top);
int main()
{   
    int n,*a;
    printf("Enter the size of Stack:");
    scanf("%d",&n);
    a=(int *)calloc(sizeof(int),n);
    int ch,top=-1;
    do
    {
        printf("\nPress 1 to Push\nPress 2 to Pop\nPress 3 to Traverse\nPress 4 to exit\n\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            Push(n,a,&top);
            break;
        case 2:
            Pop(a,&top);
            break;
        case 3:
            Traverse(a,top);
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
void Push(int n,int *a,int *top)
{
    if(*top==n-1)
    printf("Overflow Condition\n");
    else
    {
        (*top)++;
        printf("Enter Data:");
        scanf("%d",&a[*top]);
    }
}
void Pop(int *a,int *top)
{
    if(*top==-1)
    printf("Underflow Condition!\n");
    else
    {
        printf("%d is Deleted from the stack!",a[*top]);
        (*top)--;
    }
}
void Traverse(int *a,int top)
{
    if(top==-1)
    printf("Underflow Condition!\n");
    else{
    for (int i=0; i <= top; i++)
    printf("%d\t",a[i]);
    }
}