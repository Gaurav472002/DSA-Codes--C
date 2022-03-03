// Various traversals of a Binary Tree

#include<stdio.h>  
#include<stdlib.h>


struct Node  // Creating the Node ADT
{
    int data;
    struct Node*left;
    struct Node* right;
};

struct Node* createNode(int data){   // Function to create a new node in the tree
    struct Node*n =(struct Node*)malloc(sizeof(struct Node));  
    n->data=data;
    n->left=NULL;
    n->right=NULL;
}

void insert(struct Node* root, int key){
    struct Node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Cannot insert the element in the tree\n");
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }

    struct Node * new=createNode(key);
    if(key<prev->data){
        prev->left=new;   // prev holds th e position of the root node at which the element will be inserted as root will  become NULL

    }
    else{
        prev->right=new;
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
     // Constructing the root node - Using Function (Recommended)
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p, 2);
    printf("%d", p->left->left->right->data);
    return 0;

  


    
return 0;
}