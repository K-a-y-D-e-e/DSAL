#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_beginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insert_end(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    
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

void insert_any(struct Node** head, int position, int newData) {
    if (position < 1) {
        printf("Invalid Position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid Position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete(struct Node** head, int position){
    if (*head == NULL){
        printf("The List is empty.");
    }
    struct Node* temp = *head;
    
    if(position == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    
    for (int i = 1; i < position-1 && temp != NULL; i++ ){
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL){
        printf("Invalid Position");
        return;
    }
    struct Node* todelete = temp->next;
    temp->next = temp->next->next;
    
    free(todelete);
}

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

int main() {
    struct Node* head = NULL;  // Initialize empty list

    // Inserting nodes at the beginning, end, and any position
    insert_beginning(&head, 10);  // List: 10
    insert_beginning(&head, 20);  // List: 20 -> 10
    insert_end(&head, 30);       // List: 20 -> 10 -> 30
    insert_any(&head, 1, 40);    // List: 40 -> 20 -> 10 -> 30
    insert_any(&head, 4, 50);    // List: 40 -> 20 -> 10 -> 30 -> 50
    delete(&head, 3);
    
    printf("Linked List after insertions:\n");
    printList(head);
    
    return 0;
}
