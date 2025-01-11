#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

void insert();
void delete();
void display();
void search();  // Declaration of search function

int front = -1, rear = -1;
int queue[maxsize];

void main(){
    int choice;
    clrscr();
    while(1) {
        printf("\n1. Insert an element\n2. Delete an element\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: search(); break;  // Add case for search
            case 5: exit(0); break;
            default: printf("Enter a valid choice!\n");
        }
    }
}

void insert() {
    int item;
    if(rear == maxsize - 1) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &item);
    if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("%d value inserted\n", item);
}

void delete() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Value deleted: %d\n", queue[front]);
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = front + 1;
    }
}

void display() {
    int i;
    if(rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void search() {
    int item, i, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &item);
    
    for(i = front; i <= rear; i++) {
        if(queue[i] == item) {
            printf("Element %d found at index %d\n", item, i);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Element %d not found in the queue\n", item);
    }
}
