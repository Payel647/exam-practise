// Stack implementation using linked list
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

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
struct Node* push(struct Node* top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    return top;
}

// Function to pop an element from the stack
struct Node* pop(struct Node* top, int* poppedData) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        return top;
    }
    struct Node* temp = top;
    *poppedData = top->data;
    top = top->next;
    free(temp);
    return top;
}

// Function to peek the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to traverse and print the stack
void traverse(struct Node* top) {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* top = NULL;
    int poppedData;

    // Push elements onto the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // Traverse and print the stack
    printf("Stack: ");
    traverse(top);

    // Peek the top element
    printf("Top element is %d\n", peek(top));

    // Pop elements from the stack
    top = pop(top, &poppedData);
    printf("Popped element is %d\n", poppedData);
    top = pop(top, &poppedData);
    printf("Popped element is %d\n", poppedData);

    // Traverse and print the stack after popping
    printf("Stack after popping: ");
    traverse(top);

    return 0;
}
