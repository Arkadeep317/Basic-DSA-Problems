#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    stack[++top] = ch;
}
char pop() {
    return stack[top--];
}
int prec(char ch) {
    switch (ch) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char ch;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    while ((ch = infix[i++]) != '\0') {
        switch (ch) {
            case '(': 
                push(ch);
                break;

            case ')':
                while (top != -1 && stack[top] != '(') {
                    postfix[j++] = pop();
                }
                if (top != -1) pop();
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                while (top != -1 && prec(stack[top]) >= prec(ch)) {
                    postfix[j++] = pop();
                }
                push(ch);
                break;
            default:
                postfix[j++] = ch;
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("%s", postfix);
    return 0;
}
