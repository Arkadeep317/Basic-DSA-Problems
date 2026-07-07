#include<stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    if (rear == N - 1) {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = number;
    }
    else {
        rear++;
        queue[rear] = number;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
    }
    else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
    	int i;
        printf("Queue elements: ");
        for ( i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    do {
        printf("\nEnter 1 for Enqueue\n2 for Dequeue\n3 for Display\n0 for exit");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0:
                printf("exit");
                break;
            
            default: printf("Invalid choice\n");
        }

    } while (ch > 0);

    return 0;
}

