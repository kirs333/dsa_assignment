#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    prevNode->next = newNode;
    
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        return;
    }
    
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    free(delNode);
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
    newNode->prev = temp;
}

void display(Node* head) {
    Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    int choice, value, afterValue;
    Node* node;
    
    while (1) {
        printf("\n1. Insert at end\n");
        printf("2. Insert after node\n");
        printf("3. Delete node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
                
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Insert after which value: ");
                scanf("%d", &afterValue);
                node = findNode(head, afterValue);
                if (node != NULL) {
                    insertAfter(node, value);
                } else {
                    printf("Node not found\n");
                }
                break;
                
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                node = findNode(head, value);
                if (node != NULL) {
                    deleteNode(&head, node);
                    printf("Node deleted\n");
                } else {
                    printf("Node not found\n");
                }
                break;
                
            case 4:
                display(head);
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
