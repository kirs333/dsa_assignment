# Program 4: Doubly Linked List Implementation

## Data Structure

Doubly linked list node with prev and next pointers.

```c
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
```

Each node stores data and has two pointers - one to previous node and one to next node.

## Functions

**`Node* createNode(int data)`**
- Allocates memory for new node
- Initializes data and sets prev, next to NULL
- Returns pointer to new node

**`void insertAfter(Node* prevNode, int data)`**
- Inserts new node after given node
- Creates new node and adjusts pointers
- Updates prev and next links for adjacent nodes

**`void deleteNode(Node** head, Node* delNode)`**
- Deletes specified node from list
- Adjusts pointers of adjacent nodes
- Frees memory of deleted node
- Handles case when deleting head node

**`void insertAtEnd(Node** head, int data)`**
- Helper function to insert at end
- Used to build initial list

**`void display(Node* head)`**
- Prints entire list in format: NULL <-> data <-> data <-> NULL
- Shows doubly linked structure

**`Node* findNode(Node* head, int value)`**
- Searches for node with given value
- Returns pointer to node if found, NULL otherwise

## Main Function

Provides menu driven interface:
1. Insert at end - adds node at end of list
2. Insert after node - inserts after specific value
3. Delete node - removes node with specific value
4. Display - shows current list
5. Exit - terminates program

User can perform multiple operations in sequence to test the doubly linked list.

## How Insert After Works

To insert new node after given node:
1. Create new node
2. Set newNode.next = prevNode.next
3. Set newNode.prev = prevNode
4. Set prevNode.next = newNode
5. If newNode.next exists, set newNode.next.prev = newNode

## How Delete Works

To delete a node:
1. If node is head, update head pointer
2. If node has next, set next.prev = node.prev
3. If node has prev, set prev.next = node.next
4. Free the node memory

## Sample Output

```
1. Insert at end
2. Insert after node
3. Delete node
4. Display
5. Exit
Enter choice: 1
Enter value: 10

Enter choice: 1
Enter value: 20

Enter choice: 1
Enter value: 30

Enter choice: 4
NULL <-> 10 <-> 20 <-> 30 <-> NULL

Enter choice: 2
Enter value to insert: 15
Insert after which value: 10

Enter choice: 4
NULL <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

Enter choice: 3
Enter value to delete: 20
Node deleted

Enter choice: 4
NULL <-> 10 <-> 15 <-> 30 <-> NULL

Enter choice: 5
```
