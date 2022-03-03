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

int Isbst(struct Node* root){
    static struct Node* prev=NULL;
    if(root!=NULL){
        if(!Isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<= prev->data){
            return 0;
        }
        prev=root;
        return Isbst(root->right);
    }

    else{
        return 1;
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

    struct Node *p=create_node(20);
    struct Node *p1=create_node(10);
    struct Node *p2=create_node(333); 
    struct Node *p3=create_node(9); 
    struct Node *p4=create_node(11); 
   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
  
    

  if(Isbst(p)){
      printf("This is a BST\n");
  }
  else{
      printf("This is not a BST");
  }



    
return 0;
}