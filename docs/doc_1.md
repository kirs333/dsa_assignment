# Program 1: Balanced Parentheses Checker

## Data Structures

### Stack Structure
```c
typedef struct {
    char data[MAX];
    int top;
} Stack;
```
- `data[]`: Array to store characters (parentheses)
- `top`: Index of top element (-1 when empty)
- `MAX`: Maximum stack capacity (100)

## Functions Implemented

### Stack Operations

**`void init(Stack* s)`**
- Initializes stack by setting top to -1
- Prepares stack for use

**`bool isEmpty(Stack* s)`**
- Returns true if stack is empty (top == -1)
- Used to check if stack has elements

**`bool isFull(Stack* s)`**
- Returns true if stack is full (top == MAX-1)
- Prevents overflow

**`void push(Stack* s, char ch)`**
- Adds character to top of stack
- Increments top pointer

**`char pop(Stack* s)`**
- Removes and returns top character
- Decrements top pointer
- Returns '\0' if empty

**`char peek(Stack* s)`**
- Returns top character without removing
- Returns '\0' if empty

### Helper Functions

**`bool isOpening(char ch)`**
- Checks if character is opening bracket: (, [, {
- Returns true if opening bracket

**`bool isClosing(char ch)`**
- Checks if character is closing bracket: ), ], }
- Returns true if closing bracket

**`bool matches(char open, char close)`**
- Checks if opening and closing brackets match
- Returns true for matching pairs: () [] {}

### Main Logic

**`bool isBalanced(char* expr)`**
- Checks if expression has balanced parentheses
- Algorithm:
  1. Initialize empty stack
  2. Scan expression left to right
  3. If opening bracket found: push to stack
  4. If closing bracket found:
     - If stack empty: return false (unbalanced)
     - Pop from stack and check if it matches
     - If not matching: return false
  5. After scanning, stack should be empty for balanced expression
- Returns true if balanced, false otherwise

## Main Function Organization

1. **Define Test Expressions**
   - Expression 1: `a + (b - c) * (d` (unbalanced - missing closing parenthesis)
   - Expression 2: `m + [a - b * (c + d * {m)]` (unbalanced - mismatched brackets)
   - Expression 3: `a + (b - c)` (balanced)

2. **Test Each Expression**
   - Print expression
   - Call `isBalanced()` function
   - Display result (Balanced or Not Balanced)

3. **Return**
   - Program exits successfully

## Sample Output

```
Expression 1: a + (b - c) * (d
Result: Not Balanced

Expression 2: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression 3: a + (b - c)
Result: Balanced
```

## How It Works

### Example Trace: Expression 3 `a + (b - c)`

| Character | Action | Stack State |
|-----------|--------|-------------|
| a | Skip (not bracket) | [] |
| + | Skip | [] |
| ( | Push | [(] |
| b | Skip | [(] |
| - | Skip | [(] |
| c | Skip | [(] |
| ) | Pop and match with ( | [] |

Final stack is empty → **Balanced**

### Example Trace: Expression 1 `a + (b - c) * (d`

| Character | Action | Stack State |
|-----------|--------|-------------|
| a | Skip | [] |
| + | Skip | [] |
| ( | Push | [(] |
| b | Skip | [(] |
| - | Skip | [(] |
| c | Skip | [(] |
| ) | Pop and match | [] |
| * | Skip | [] |
| ( | Push | [(] |
| d | Skip | [(] |

Final stack is NOT empty → **Not Balanced**

### Example Trace: Expression 2 `m + [a - b * (c + d * {m)]`

| Character | Action | Stack State |
|-----------|--------|-------------|
| m | Skip | [] |
| + | Skip | [] |
| [ | Push | [[] |
| a | Skip | [[] |
| - | Skip | [[] |
| b | Skip | [[] |
| * | Skip | [[] |
| ( | Push | [[, (] |
| c | Skip | [[, (] |
| + | Skip | [[, (] |
| d | Skip | [[, (] |
| * | Skip | [[, (] |
| { | Push | [[, (, {] |
| m | Skip | [[, (, {] |
| ) | Pop {, doesn't match ) | **Not Balanced** |

Mismatch detected → **Not Balanced**

## Compilation and Execution

```bash
gcc prog_1.c -o prog_1
./prog_1
```
