#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;              // Data part
    struct node *next;      // Address part
} *header;

void createList(int n)    /* Function to create a list */
{
    struct node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    // Create the first node
    header = (struct node *)malloc(sizeof(struct node));

    // If unable to allocate memory for head node
    if (header == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    } 
    else {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        header->data = data; // Links the data field with the input data
        header->next = NULL; // Links the address field to NULL
        temp = header;       // Current node is now the first node

        // Create the rest of the nodes
        for (i = 2; i <= n; i++) {
            newNode = (struct node *)malloc(sizeof(struct node));

            // Check if memory allocation failed
            if (newNode == NULL) {
                printf("Unable to allocate memory.\n");
                break;
            }

            printf("Enter the data of node %d: ", i);
            scanf("%d", &data);

            newNode->data = data;  // Links the data field with the input data
            newNode->next = NULL;  // Links the address field to NULL

            temp->next = newNode;  // Links the previous node to the new node
            temp = newNode;        // Updates the temp to the current node
        }
    }
}

int main()
{
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n); // Call the function to create the list
    return 0;
}
