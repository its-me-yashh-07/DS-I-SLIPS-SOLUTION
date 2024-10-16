/*Slip_07_Q2. Write a program that checks whether a string of characters is palindrome
 or not. The function should use a stack library (cststack.h) of stack of
 characters using a static implementation of the stack.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct stack {
    char stk[MAX];
    int top;
} STACK;

STACK s;

void init() {
    s.top = -1;
}

int isempty() {
    return s.top == -1;
}

int isfull() {
    return s.top == MAX - 1;
}

void push(char ch) {
    if (isfull()) {
        printf("\n Stack is full");
    } else {
        s.stk[++s.top] = ch;
    }
}

char pop() {
    if (isempty()) {
        printf("\n Stack is empty");
        return 0;
    } else {
        return s.stk[s.top--];
    }
}

int main() {
    char str[MAX], rev[MAX];
    int i;

    init();

    printf("\n Enter String : ");
    scanf("%s", str);  // No '&' needed before str

    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    for (i = 0; !isempty(); i++) {
        rev[i] = pop();
    }

    rev[i] = '\0';

    if (strcasecmp(str, rev) == 0) {  // Replacing strcmpi with strcasecmp for case-insensitive comparison
        printf("\n String is Palindrome");
    } else {
        printf("\n String is not Palindrome");
    }

    return 0;
}
