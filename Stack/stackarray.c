#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is overflow");
        
    }
    else
    {
        printf(" Enter a value:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is underflow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}

int main()
{
    top=-1;
    printf("\n Enter the size of STACK (MAX=100):");
    scanf("%d",&n);
    
    do
    {
        printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t Byee... ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice");
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
