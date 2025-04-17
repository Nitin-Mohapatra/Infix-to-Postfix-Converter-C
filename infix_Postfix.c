#include <stdio.h>
#include <string.h>

char poped_ele = 0;

// Push function
int push(char *st, char ele, int top) {
    top += 1;
    st[top] = ele;
    return top;
}

// Pop function
int pop(char *st, int top) {
    poped_ele = st[top];
    top -= 1;
    return top;
}

void main() {
    char infix_exp[100];
    puts("Enter the infix exp");
    gets(infix_exp);
    char operator_stack[100];
    char postfix_stack[100];

    int len = strlen(infix_exp);
    int operator_top = -1;
    int postfix_top = -1;

    for (int i = 0; i < len; i++) {
        if ((infix_exp[i] >= 'a' && infix_exp[i] <= 'z') || (infix_exp[i] >= 'A' && infix_exp[i] <= 'Z')) {
            postfix_top = push(postfix_stack, infix_exp[i], postfix_top);
        } else {
            if (operator_top == -1) {
                operator_top = push(operator_stack, infix_exp[i], operator_top);
            } else if (operator_stack[operator_top] == infix_exp[i]) {
                operator_top = pop(operator_stack, operator_top);
                operator_top = push(operator_stack, infix_exp[i], operator_top);
                postfix_top = push(postfix_stack, poped_ele, postfix_top);
            } else if (
                (operator_stack[operator_top] == '*' || operator_stack[operator_top] == '%') &&
                (infix_exp[i] == '+' || infix_exp[i] == '-')) {
                operator_top = pop(operator_stack, operator_top);
                postfix_top = push(postfix_stack, poped_ele, postfix_top);
                operator_top = push(operator_stack, infix_exp[i], operator_top);
            } else if (
                ((operator_stack[operator_top] == '+' || operator_stack[operator_top] == '-') &&
                 (infix_exp[i] == '-' || infix_exp[i] == '+')) ||
                ((operator_stack[operator_top] == '*' || operator_stack[operator_top] == '%' || operator_stack[operator_top] == '/') &&
                 (infix_exp[i] == '*' || infix_exp[i] == '%' || infix_exp[i] == '/'))) {
                operator_top = pop(operator_stack, operator_top);
                postfix_top = push(postfix_stack, poped_ele, postfix_top);
                operator_top = push(operator_stack, infix_exp[i], operator_top);
            } else if (infix_exp[i] == ')') {
                while (operator_stack[operator_top] != '(') {
                    operator_top = pop(operator_stack, operator_top);
                    postfix_top = push(postfix_stack, poped_ele, postfix_top);
                }
                operator_top = pop(operator_stack, operator_top); // pop '('
            } else {
                operator_top = push(operator_stack, infix_exp[i], operator_top);
            }
        }
    }

    // Pop remaining operators
    while (operator_top != -1) {
        operator_top = pop(operator_stack, operator_top);
        postfix_top = push(postfix_stack, poped_ele, postfix_top);
    }

    printf("Postfix: ");
    for (int j = 0; j <= postfix_top; j++) {
        printf("%c", postfix_stack[j]);
    }
    printf("\n");
}
