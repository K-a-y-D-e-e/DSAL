#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;  // Point to the current head
    *head = newNode;        // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // If list is empty, new node becomes the head
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Link the last node to the new node
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;  // Update head to the next node
    free(temp);             // Free the old head
}

// Function to traverse the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;  // Initialize empty list

    // Inserting nodes at the beginning and end
    insertAtBeginning(&head, 10);  // List: 10
    insertAtBeginning(&head, 20);  // List: 20 -> 10
    insertAtEnd(&head, 30);        // List: 20 -> 10 -> 30
    insertAtEnd(&head, 40);        // List: 20 -> 10 -> 30 -> 40

    printf("Linked List after insertions:\n");
    printList(head);

    // Deleting node from the beginning
    deleteFromBeginning(&head);  // List: 10 -> 30 -> 40
    printf("\nLinked List after deleting from beginning:\n");
    printList(head);

    return 0;
}
