# Program 2: Infix to Postfix Conversion and Evaluation

## Data Structures

Two stack structures are used - one for characters and one for integers.

```c
typedef struct {
    char data[MAX];
    int top;
} CharStack;

typedef struct {
    int data[MAX];
    int top;
} IntStack;
```

CharStack is used for conversion and IntStack is used for evalution.

## Functions

**Stack Operations:**
- `initChar()` / `initInt()` - initialize stacks
- `pushChar()` / `pushInt()` - push to stack
- `popChar()` / `popInt()` - pop from stack
- `peekChar()` - view top without removing
- `isEmptyChar()` / `isEmptyInt()` - check if empty

**Helper Functions:**
- `isOperator()` - checks if character is +, -, *, /, ^
- `precedence()` - returns operator precedence (^ = 3, */ = 2, +- = 1)
- `isRightAssociative()` - checks if operator is right associative (only ^)
- `applyOperation()` - performs arithmetic operation

**Main Functions:**
- `infixToPostfix()` - converts infix expression to postfix
- `evaluatePostfix()` - evaluates postfix expression and returns result

## Main Function

1. Takes infix expression as input from user
2. Converts it to postfix using `infixToPostfix()`
3. Displays both infix and postfix expressions
4. Evaluates the postfix expression by asking for variable values
5. Shows final result

## How Conversion Works

The algorithm uses a stack to convert infix to postfix:
- Operands go directly to output
- Left parenthesis goes to stack
- Right parenthesis pops stack until left parenthesis
- Operators pop higher precedence operators from stack before pushing

## How Evaluation Works

Scans postfix expression left to right:
- If operand, push to stack
- If operator, pop two operands, apply operation, push result
- Final value in stack is the answer

## Sample Output

```
Enter infix expression: a+b*c

Infix: a+b*c
Postfix: abc*+

Evaluating postfix expression...
Enter values for variables:
a = 5
b = 3
c = 2

Result: 11
```

Another example:

```
Enter infix expression: (a+b)*(c-d)

Infix: (a+b)*(c-d)
Postfix: ab+cd-*

Evaluating postfix expression...
Enter values for variables:
a = 10
b = 5
c = 20
d = 8

Result: 180
```
