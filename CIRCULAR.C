#include <stdio.h>
#include <conio.h>  // For Turbo C compatibility (for getch() and clrscr() if needed)

#define MAX 5 // Maximum size of the queue

int queue[MAX];  // Array to store the queue elements
int front = -1, rear = -1;  // Initialize front and rear

// Check if the queue is full
int isFull() {
    if (front == 0 && rear == MAX - 1) {
        return 1;  // Queue is full
    }
    if (rear == (front - 1) % (MAX - 1)) {
        return 1;  // Queue is full
    }
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1;  // Queue is empty
}

// Add an element to the queue (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        if (front == -1) {  // First element to be added
            front = 0;
            rear = 0;
        } else {
            // Move rear to the next position in a circular way
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("%d added to the queue.\n", value);
    }
}

// Remove an element from the queue (dequeue)
int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return error value
    } else {
        value = queue[front];
        if (front == rear) {  // Only one element in the queue
            front = rear = -1;  // Queue becomes empty
        } else {
            // Move front to the next position in a circular way
            front = (front + 1) % MAX;
        }
        return value;
    }
}

// Display all elements in the queue
void display() {
 int i = front;
    if (isEmpty()) {
        printf("Queue is empty! Nothing to display.\n");
    } else {
        printf("Queue elements: ");

        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  // Circular movement
        }
        printf("%d ", queue[rear]);  // Print the rear element
        printf("\n");
    }
}

// Search for an element in the queue
int search(int value) {
 int i = front;
    if (isEmpty()) {
        printf("Queue is empty! Nothing to search.\n");
        return -1;  // Return -1 if the queue is empty
    }


    while (i != rear) {
        if (queue[i] == value) {
            return i;  // Return the index if the element is found
        }
        i = (i + 1) % MAX;  // Circular movement
    }
    if (queue[rear] == value) {
        return rear;  // Check the rear element
    }
    
    return -1;  // Return -1 if the element is not found
}

void main() {
    int choice, value, index;
    clrscr(); // Clear the screen (specific to Turbo C)

    // Main loop for menu options
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("%d removed from the queue.\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                index = search(value);
                if (index != -1) {
                    printf("Element %d found at index %d.\n", value, index);
                } else {
                    printf("Element %d not found in the queue.\n", value);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);  // Exit if choice is 5

    getch();  // Wait for user input (specific to Turbo C)
}
