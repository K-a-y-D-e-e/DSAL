#include<stdio.h>
#include<malloc.h>

struct node{  // Creating Node
    int data; 
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){  // Function for creating a node
    struct node *n; // Creating a node pointer
    n = (struct node*) malloc(sizeof(struct node)); // Allocating the memory in the heap
    n->data = data; // Setting the Data
    n->left = NULL; // Setting the left child value as null
    n->right = NULL; // Setting the right child value as null
    return n;
}

void InOrder(struct node* root){ // In Order traversal function
    if(root!=NULL){ // Termination condition
        InOrder(root->left); // First Left Subroot
        printf("%d ", root->data); // Then Main Root
        InOrder(root->right); // Lastly Right Subroot
    }
}

int main(){
    //Constructing root node - Using Functions
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    //Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    InOrder(p);
    return 0;

}

