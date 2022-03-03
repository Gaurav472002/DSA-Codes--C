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

struct Node* BST_search(struct Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val==root->data){
        return root;
    }
    else if(val<root->data){
        return BST_search(root->left,val);
    }
    else{
        return BST_search(root->right,val);
    }
}


//Iterative seacrh
struct Node * searchIter(struct Node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

void Inorder(struct Node*root){
    if(root!=NULL){
        
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}



int main(){

    struct Node *p=create_node(20);
    struct Node *p1=create_node(10);
    struct Node *p2=create_node(333); 
    struct Node *p3=create_node(9); 
    struct Node *p4=create_node(11); 
   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    struct Node* n=searchIter(p,20);
    if(n!=NULL){
        printf("element found  %d",n->data);
    }
    else{
        printf("Not found \n");
    }
  


    
return 0;
}