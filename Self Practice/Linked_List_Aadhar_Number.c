#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
struct Node {
    char aadhar[13];  // Store Aadhar as a string 
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* aadhar) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->aadhar, aadhar);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, char* aadhar) {
    struct Node* newNode = createNode(aadhar);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node in the middle
void insertInMiddle(struct Node** head, char* aadhar, int pos) {
    struct Node* newNode = createNode(aadhar);
    struct Node* temp = *head;
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->aadhar);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    // Insert Aadhar numbers of 4 employees
    insertAtEnd(&head, "123456789012");
    insertAtEnd(&head, "234567890123");
    insertAtEnd(&head, "345678901234");
    insertAtEnd(&head, "456789012345");

    printf("Original list:\n");
    displayList(head);
    
    // Insert the 5th employee's Aadhar number in the middle (at position 3)
    insertInMiddle(&head, "555555555555", 3);

    printf("\nList after inserting the 5th employee in the middle:\n");
    displayList(head);

    return 0;
}
