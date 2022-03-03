// Representation of trees using linked lists
#include<stdio.h>  
#include<stdlib.h>


struct Node  // Creating the Node ADT
{
    int data;
    struct Node*left;
    struct Node* right;
};

struct Node* create_node(int data){   // Function to create a new node in the tree
    struct Node*n =(struct Node*)malloc(sizeof(struct Node));  
    n->data=data;
    n->left=NULL;
    n->right=NULL;
}

int main(){

    struct Node *p=create_node(22); // Root node
    struct Node *p1=create_node(23); // left Node
    struct Node *p2=create_node(242); // RIght node
    p->left=p1;
    p->right=p2;

    printf("%d ",p->data);
    printf("%d ",p->left->data);
    printf("%d ",p->right->data);

return 0;
}