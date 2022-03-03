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


void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node*root){
    if(root!=NULL){
     
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


void Inorder(struct Node*root){
    if(root!=NULL){
        
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int main(){

    struct Node *p=create_node(22);
    struct Node *p1=create_node(23);
    struct Node *p2=create_node(24); 
    struct Node *p3=create_node(25); 
    struct Node *p4=create_node(77); 
    struct Node *p5=create_node(11); 
    struct Node *p6=create_node(45); 
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    Inorder(p);


    
return 0;
}