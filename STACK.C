#include<stdio.h>
#include<conio.h>

int stack[100], choice = 0, n, top = -1;

void push();
void pop();
void show();
void search();  // Declaration of search function

void main() {
    clrscr();
    printf("Enter the number of elements in a stack:\n");
    scanf("%d", &n);
    printf("Stack operations using array\n");
    
    while (choice != 4) {  // Loop continues until the user selects option 4 (Exit)
        printf("Choose one from below options\n");
	printf("1. Push\n 2. Pop\n 3. Show\n 4. Exit\n5.search\n");
	printf("Enter your choice:\n");
	scanf("%d", &choice);

	switch(choice) {
	    case 1:
		push();
		break;
	    case 2:
		pop();
		break;
	    case 3:
		show();
		break;
	    case 4:
		printf("Exit\n");
		break;
	    case 5:
	       search();
	    default:
		printf("Please enter a valid choice\n");
	}
    }
}

void push() {
    int value;
    if (top == n - 1)
	printf("Overflow\n");
    else {
	printf("Enter the value: ");
	scanf("%d", &value);
	top = top + 1;
	stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
	printf("Underflow\n");
    } else {
	printf("Popped element: %d\n", stack[top]);
	top = top - 1;
    }
}

void show() {
    int i;
    if (top == -1) {
	printf("Stack is empty\n");
    } else {
	printf("Stack elements are:\n");
	for (i = top; i >= 0; i--) {
	    printf("%d\n", stack[i]);
	}
    }
}

void search() {
    int value, found = 0,i;
    printf("Enter the value to search: ");
    scanf("%d", &value);

    for ( i = top; i >= 0; i--) {
	if (stack[i] == value) {
	    printf("Element %d found at position %d (from the top)\n", value, top - i + 1);
	    found = 1;
	    break;
	}
    }

    if (!found) {
	printf("Element %d not found in the stack\n", value);
    }
}
