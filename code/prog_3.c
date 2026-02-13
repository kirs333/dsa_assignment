#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraversal(Node* head) {
    if (head == NULL) {
        return;
    }
    
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

int main() {
    Node* head = NULL;
    int n, value;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    
    printf("\nForward traversal: ");
    displayForward(head);
    
    printf("Reverse traversal: ");
    reverseTraversal(head);
    printf("\n");
    
    return 0;
}
