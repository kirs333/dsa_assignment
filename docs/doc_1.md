# Program 1: Balanced Parentheses Checker

## Data Structures

Stack structure stores characters with max size 100. Has data array and top index.

```c
typedef struct {
    char data[MAX];
    int top;
} Stack;
```

## Functions

**Stack Functions:**
- `init()` - sets top to -1
- `push()` - adds character to stack
- `pop()` - removes character from stack
- `isEmpty()` - checks if stack empty
- `isFull()` - checks if stack full
- `peek()` - returns top without removeing

**Helper Functions:**
- `isOpening()` - checks if (, [, or {
- `isClosing()` - checks if ), ], or }
- `matches()` - checks if brackets match

**Main Logic:**
- `isBalanced()` - scans expression and uses stack to check balanced parentheses

## Main Function

The main function tests three expressions:
1. `a + (b - c) * (d` - missing closing bracket
2. `m + [a - b * (c + d * {m)]` - wrong bracket types
3. `a + (b - c)` - balanced

For each expression it prints the result.

## How It Works

When we see opening bracket we push it to stack. When we see closing bracket we pop from stack and check if they match. At the end stack should be empty for balanced expression.

## Sample Output

```
Expression 1: a + (b - c) * (d
Result: Not Balanced

Expression 2: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression 3: a + (b - c)
Result: Balanced
```
