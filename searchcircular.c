#define N 3
int queue[N];
int front = -1;
int rear = -1;
#include <stdio.h>
#include <stdlib.h>

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front) {
        printf("Queue is full, cannot insert %d\n", x);
    }
    else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        printf("The deleted element is %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("The deleted element is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("The queue is: \n");
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        } while (i != (rear + 1) % N);
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("The peek element is: %d\n", queue[front]);
    }
}

void search(int x) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty, cannot search for %d\n", x);
    }
    else {
        int i = front;
        do {
            if (queue[i] == x) {
                printf("%d found in the queue.\n", x);
                return;
            }
            i = (i + 1) % N;
        } while (i != (rear + 1) % N);
        printf("%d not found in the queue.\n", x);
    }
}

void main() {
    int c, item;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Search\n6.Exit\nEnter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nEnter the data to search for: ");
                scanf("%d", &item);
                search(item);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
