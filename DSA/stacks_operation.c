#include <stdio.h>
#define MAX 100
typedef struct StackItems
{
    int list[MAX];
    int top;
} Stack;
void push(Stack *a, int c);
int pop(Stack *a);
void print_stack(Stack *a);
int main()
{
    Stack stack1, temp;
    stack1.top = -1;
    temp.top = -1;
    int n, t1, t2, t3, t4, i, n1, j = 1;
    printf("\nHow many initial elements do you want in the stack\n");
    scanf("%d", &n);
    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t1);
        push(&stack1, t1);
    }
    int ch;
    while (j == 1)
    {
        printf("\nWhat would you like to do\n1.Check topmost 3rd element\n2.Pop out n elements\n3.Check bottommost n elements\n4.Display Stack\n5.Create a new Stack\n");
        scanf("%d", &ch);
        switch (ch)
        {
        //FInding the topmost third variable
        case 1:
            n = stack1.top + 1;
            for (i = 0; i <2; i++)
                push(&temp, pop(&stack1));
            t1 = pop(&stack1);
            push(&stack1, t1);
            for (int i = 0; i <2; i++)
                push(&stack1, pop(&temp));
            printf("\nThe third element from the top is %d\n", t1);
            printf("\nThe original stack is\n");
            print_stack(&stack1);
            break;
        //Popping n elments//
        case 2:
            printf("\nHow many elements do you want to remove\n");
            scanf("%d", &n1);
            while (n1 > stack1.top)
            {
                printf("\nThe value of n is too much please try again\n");
                scanf("%d", &n1);
            }
            for (i = 0; i <n1; i++)
                push(&temp, pop(&stack1));
            printf("\nThe remaining stack is\n");
            print_stack(&stack1);
            printf("\nThe popped elements are\n");
            print_stack(&temp);
            for (i = 0; i < n1; i++)
            {
                push(&stack1, pop(&temp));
            }
            printf("\nThe original stack is\n");
            print_stack(&stack1);
            break;
        //FInding the bottommost third variable
        case 3:
            n = stack1.top + 1;
            for (i = 0; i <n-3; i++)
                push(&temp, pop(&stack1));
            t2 = pop(&stack1);
            push(&stack1, t2);
            for (int i = 0; i < n-3; i++)
                push(&stack1, pop(&temp));
            printf("\nThe third element from the bottom is %d\n", t2);
            printf("\nThe original stack is\n");
            print_stack(&stack1);
            break;
            // Printing Stacks
        case 4:
            printf("\nThe stack is\n");
            print_stack(&stack1);
            break;
            // Rentering Stacks
        case 5:
            stack1.top=-1;
            printf("\nHow many initial elements do you want in the stack\n");
            scanf("%d", &n);
            printf("\nEnter the elements\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &t1);
                push(&stack1, t1);
            }
            break;
        default:
            printf("\nThe input is invalid\n");
            break;
        }
        printf("Press 1 to continue\n");
        scanf("%d", &j);
    }

    //End
}
void push(Stack *a, int c)
{
    if (a->top == MAX - 1)
    {
        printf("\nOVERFLOW CONDITION\n");
    }
    else
    {
        a->top++;
        a->list[a->top] = c;
    }
}
int pop(Stack *a)
{
    if (a->top == -1)
    {
        printf("\nUNDERFLOW CONDITION\n");
    }
    else
    {
        int temp_var;
        temp_var = a->list[a->top];
        a->top--;
        return temp_var;
    }
}
void print_stack(Stack *a)
{
    if (a->top == -1)
    {
        printf(" Empty\n");
    }
    for (int i = 0; i < a->top + 1; i++)
        printf(" %d ", a->list[i]);
    printf("\n");
}
