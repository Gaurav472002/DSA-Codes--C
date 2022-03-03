// Various traversals of a Binary Tree

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

struct Node* predecessor(struct Node* root){ // function to find the rightmost element of the left subtree
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;

}

struct Node* delete_node(struct Node* root,int val){
    struct Node* ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right ==NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->left=delete_node(root->left,val);
    }
    else if(val>root->data){
        root->right=delete_node(root->right,val);
    }
    else{
        ipre=predecessor(root);
        root->data=ipre->data; // setting predecessor as the new root
        root->left=delete_node(root->left,ipre->data); // deleting the predecessor
    }
    return root;
}




void Inorder(struct Node*root){
    if(root!=NULL){
        
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int main(){

    struct Node *p=create_node(5);
    struct Node *p1=create_node(3);
    struct Node *p2=create_node(6); 
    struct Node *p3=create_node(1); 
    struct Node *p4=create_node(4); 
  
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
 

    Inorder(p);

    delete_node(p,5);
    printf("\n");
    
    Inorder(p);


    
return 0;
}