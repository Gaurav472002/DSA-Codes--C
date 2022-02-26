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

void enqueueR(struct queue *q,int val){
    if(is_full(q)){
        printf("Queue Overflow!!\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqued element: %d\n", val);

    }
    
}

void enqueueF(struct queue *q,int val){
    if(q->f==-1){
        printf("Queue Overflow!!\n");
    }
    else{
        
        q->arr[q->f]=val;
        q->f--;
        printf("Enqued element: %d\n", val);

    }
    
}

int dequeueF(struct queue *q){
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



int dequeueR(struct queue *q){
    int a=-1;
    if(is_empty(q)){
        printf("queue Underlow!!");

    }
    else{
       
        a=q->arr[q->r];
        q->r--;
        printf("deleted element from last %d\n",a);
        
    }
    return a;

}

int main(){
    struct queue q;
    q.size=5;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // dequeueR(&q);
    
    enqueueR(&q,99);
    enqueueR(&q,98);
    enqueueR(&q,92);
    enqueueR(&q,91);
    printf("%d %d \n",q.f,q.r);
    dequeueR(&q);
    
    printf("%d %d \n",q.f,q.r);
    dequeueF(&q);
    printf("%d %d \n",q.f,q.r);
    enqueueF(&q,922);
    printf("%d %d \n",q.f,q.r);
    
    enqueueF(&q,925);
    printf("%d %d \n",q.f,q.r);

    enqueueF(&q,925); //this should give error
    
   
    
  
    
    



    

return 0;
}