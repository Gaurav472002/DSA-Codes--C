#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
    //printf("popped the element %d \n", val);
    return val;
}

int parenthesis_checking(char * exp){

    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    
    for (int i=0; exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i]==')'){
            if(is_empty(sp)){
                return 0;
            }
            pop(sp);

        }
    }
    if (is_empty(sp)){
        return 1;
    }
    else{
        return 0;
    }


    
}



int main(){
    
    char * exp = "((8)(*--$$9))";
    // Check if stack is empty
    if(parenthesis_checking(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

return 0;
}