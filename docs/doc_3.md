# Program 3: Reverse Traversal in Linked List

## Data Structure

Node structure for singly linked list.

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

Each node has integer data and pointer to next node.

## Functions

**`Node* createNode(int data)`**
- Creates new node with given data
- Sets next pointer to NULL
- Returns pointer to new node

**`void insertAtEnd(Node** head, int data)`**
- Inserts new node at end of list
- If list empty, makes new node the head
- Otherwise traverse to end and add node

**`void displayForward(Node* head)`**
- Prints list from start to end
- Uses iterative approach with while loop

**`void reverseTraversal(Node* head)`**
- Prints list from end to start
- Uses recursion to traverse in reverse
- Base case: if head is NULL, return
- Recursive case: call function on next node first, then print current

## Main Function

1. Creates empty linked list
2. Asks user for number of elements
3. Takes input and inserts elements at end
4. Displays list in forward direction
5. Displays list in reverse direction using reverseTraversal()

## How Reverse Traversal Works

The function uses recursion. It goes to the end of list first, then prints while comming back.

Example: List is 10 -> 20 -> 30 -> NULL

```
reverseTraversal(10)
  reverseTraversal(20)
    reverseTraversal(30)
      reverseTraversal(NULL) - returns
      print 30
    print 20
  print 10
```

Output: 30 20 10

## Sample Output

```
Enter number of elements: 5
Enter 5 elements:
10
20
30
40
50

Forward traversal: 10 20 30 40 50 
Reverse traversal: 50 40 30 20 10 
```

Another example:

```
Enter number of elements: 3
Enter 3 elements:
100
200
300

Forward traversal: 100 200 300 
Reverse traversal: 300 200 100 
```
