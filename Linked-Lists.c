// LINKED LISTS creation, traversal, insertion

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* ptr){
    printf("....Here is your Linked List....\n");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

// Function to insert a node at the first of a linked list
struct Node* insert_first(struct Node* head,int data){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    printf("Inserted the element successfully\n");
    return ptr;
    
}

// function to add node b/w two nodes in a linked list

struct Node* insert_between(struct Node* head,int data,int index){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;

    int i=0;
    while(i!= index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    printf("Inserted the element successfully\n");
    return head;
   
    
}

// Function to insert a node at the end of a linked list
struct Node* insert_end(struct Node* head,int data){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;  
    while(p->next!=NULL){
        p=p->next;
        
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    printf("Inserted the element successfully\n");
    return head;
    
    
}


struct Node * delete_first(struct Node*head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;


}

struct Node* delete_index(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    printf("Deleted the element at index %d  successfully\n",index );
    return head;

}

struct Node* delete_data(struct Node* head,int value){
    struct Node* p=head;
    struct Node* q=head->next;

    while(q->data!=value && q->next!= NULL  ){
        p=p->next;
        q=q->next;

    }
    if(q->data==value){
        p->next=q->next;
        free(q);

    }
    printf("Deleted the element  %d  successfully\n",value );
    return head;

}


struct Node* delete_last(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;

    while(q->next!= NULL  ){
        p=p->next;
        q=q->next;

    }
    p->next=NULL;
    free(q);
    printf("Deleted the last element successfully\n" );
    return head;

}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // pointer to the first node of the linked list
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    
    head->data=11;
    head->next=second;
    
    second->data=22;
    second->next=third;

    third->data=33;
    third->next=fourth;

    fourth->data=44;
    fourth->next= NULL;

    display(head); // calling the display function using the head pointer

    //INSERTION OPERATIONS

    //head =insert_first(head,77);
    //head=insert_between(head,999,2);
    //head=delete_index(head,1);
    // head=insert_end(head,55);

    //DELETION OPERATIONS
    
    // head= delete_first(head);
    // head=delete_index(head,2);
    //delete_data(head,22);
    head=delete_last(head);

    
    display(head);

return 0;
}