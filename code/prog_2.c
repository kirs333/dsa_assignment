#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} CharStack;

typedef struct {
    int data[MAX];
    int top;
} IntStack;

void initChar(CharStack* s) {
    s->top = -1;
}

void initInt(IntStack* s) {
    s->top = -1;
}

int isEmptyChar(CharStack* s) {
    return s->top == -1;
}

int isEmptyInt(IntStack* s) {
    return s->top == -1;
}

void pushChar(CharStack* s, char ch) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = ch;
    }
}

void pushInt(IntStack* s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

char popChar(CharStack* s) {
    if (!isEmptyChar(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int popInt(IntStack* s) {
    if (!isEmptyInt(s)) {
        return s->data[(s->top)--];
    }
    return 0;
}

char peekChar(CharStack* s) {
    if (!isEmptyChar(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return op == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    CharStack s;
    initChar(&s);
    int j = 0;
    
    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        
        if (ch == ' ') continue;
        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
            }
            popChar(&s);
        }
        else if (isOperator(ch)) {
            while (!isEmptyChar(&s) && peekChar(&s) != '(' &&
                   (precedence(peekChar(&s)) > precedence(ch) ||
                    (precedence(peekChar(&s)) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }
    
    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
    }
    
    postfix[j] = '\0';
}

int applyOperation(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
        default: return 0;
    }
}

int evaluatePostfix(char* postfix) {
    IntStack s;
    initInt(&s);
    
    printf("Enter values for variables:\n");
    int values[26];
    
    for (int i = 0; i < strlen(postfix); i++) {
        if (isalpha(postfix[i])) {
            printf("%c = ", postfix[i]);
            scanf("%d", &values[postfix[i] - 'a']);
        }
    }
    
    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        
        if (isalpha(ch)) {
            pushInt(&s, values[ch - 'a']);
        }
        else if (isdigit(ch)) {
            pushInt(&s, ch - '0');
        }
        else if (isOperator(ch)) {
            int b = popInt(&s);
            int a = popInt(&s);
            int result = applyOperation(a, b, ch);
            pushInt(&s, result);
        }
    }
    
    return popInt(&s);
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;
    
    infixToPostfix(infix, postfix);
    
    printf("\nInfix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    
    printf("\nEvaluating postfix expression...\n");
    int result = evaluatePostfix(postfix);
    
    printf("\nResult: %d\n", result);
    
    return 0;
}
