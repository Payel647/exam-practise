//linked list creation traversal ,insertion and deletion
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the linked list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at any position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is greater than the length of the list.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to delete a node with a given key
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) return head;

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = NULL;
    ptr = head;
    ptr->data = 21;
    ptr->next = (struct Node*)malloc(sizeof(struct Node));
    ptr = ptr->next;
    ptr->data = 15;
    ptr->next = (struct Node*)malloc(sizeof(struct Node));
    ptr = ptr->next;
    ptr->next = NULL; // Add this line to terminate the list

    // Insert a node at position 1
    head = insertAtPosition(head, 10, 1);

    // Traverse and print the list
    printf("Linked List: ");
    traverse(head);

    // Delete a node
    head = deleteNode(head, 15);
    printf("After deletion: ");
    traverse(head);

    return 0;
}
