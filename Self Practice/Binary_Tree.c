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
    n->data = 2; // Setting the Data
    n->left = NULL; // Setting the left child value as null
    n->right = NULL; // Setting the right child value as null
}

int main(){
    //Constructing root node - Using Functions
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    //Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;

}