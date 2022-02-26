//Queue Using arrays all operations

#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int f;
    int r;
    int * arr;
    int size;
};

int is_empty(struct queue* q){
    if(q->r==q->f){
        return 1;
    }
    else return 0;
}

int is_full(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else return 0;
}

void enqueue(struct queue *q,int val){
    if(is_full(q)){
        printf("Queue Overflow!!\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqued element: %d\n", val);

    }
    
}

int dequeue(struct queue *q){
    int a=-1;
    if(is_empty(q)){
        printf("queue Underlow!!");

    }
    else{
        q->f++;
        a=q->arr[q->f];
        
    }
    return a;

}


int main(){
    struct queue q;
    q.size=5;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    
 
    if(is_empty(&q)){
        printf("Queue is empty\n");
    }
    if(is_full(&q)){
        printf("Queue is full\n");
    }
    
    



    

return 0;
}