#include <stdio.h>
#include <stdlib.h>

// STACK DATA STRUCTURE CREATION AND VARIOUS OPERATIONS

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (is_full(ptr))
    {
        printf("Stack overflow!!!\n");
    }
    ptr->top++;
    ptr->arr[ptr->top] = val; // inserting the new element at the top of the stack
}

int pop(struct stack *ptr)
{
    if (is_empty(ptr))
    {
        printf("Stack Underflow!!!\n");
    }
    int val = ptr->arr[ptr->top]; // storing the value to be deleted
    ptr->top--;
    printf("popped the element %d \n", val);
    return val;
}

int stack_top(struct stack *ptr)
{
    if (is_empty(ptr))
    {
        printf("Stack Underflow!!!\n");
    }
    return ptr->arr[ptr->top];
}

int stack_bottom(struct stack *ptr)
{
    if (is_empty(ptr))
    {
        printf("Stack Underflow!!!\n");
    }
    return ptr->arr[0];
}

int peek(struct stack *ptr, int i)
{
    int arr_ind = ptr->top - i;
    if (arr_ind < 0)
    {
        printf("Not a valid position!!!\n");
        return -1;
    }
    return ptr->arr[arr_ind];
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    // printf("stack created successfully");

    push(sp, 11);
    push(sp, 22);
    push(sp, 33);
    push(sp, 44);

    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);
    // pop(sp);

    // printf("%d\n",stack_top(sp));
    // printf("%d\n",stack_bottom(sp));
    // printf("%d\n",peek(sp,2));

    // Printing values from the stack
    for (int j = 0; j <= sp->top ; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

    return 0;
}