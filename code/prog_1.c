#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char ch) {
    if (!isFull(s)) {
        s->data[++(s->top)] = ch;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

bool isOpening(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosing(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(char* expr) {
    Stack s;
    init(&s);
    
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        
        if (isOpening(ch)) {
            push(&s, ch);
        }
        else if (isClosing(ch)) {
            if (isEmpty(&s)) {
                return false;
            }
            char top = pop(&s);
            if (!matches(top, ch)) {
                return false;
            }
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char expr1[] = "a + (b - c) * (d";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    
    printf("Expression 1: %s\n", expr1);
    if (isBalanced(expr1)) {
        printf("Result: Balanced\n\n");
    } else {
        printf("Result: Not Balanced\n\n");
    }
    
    printf("Expression 2: %s\n", expr2);
    if (isBalanced(expr2)) {
        printf("Result: Balanced\n\n");
    } else {
        printf("Result: Not Balanced\n\n");
    }
    
    printf("Expression 3: %s\n", expr3);
    if (isBalanced(expr3)) {
        printf("Result: Balanced\n\n");
    } else {
        printf("Result: Not Balanced\n\n");
    }
    
    return 0;
}