#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    if (top == N - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        int item = stack[top];
        top--;
        printf("Popped item: %d\n", item);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d \n", stack[i]);
        }
      
    }
}

int main() {
    int ch;
    do {
        printf("\nEnter choice: 1=Push  2=Pop  3=Display  0=Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 0);
    
    return 0;
}

