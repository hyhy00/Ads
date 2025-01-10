#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL, *temp;


void insertend(int item, struct node** head) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    newnode->data = item;
    newnode->next = NULL;

    if (*head == NULL) {
	*head = newnode; 
    } else {
	temp = *head;
	while (temp->next != NULL) {
	    temp = temp->next;  
	}
	temp->next = newnode;  
    }
}


void display(struct node* head) {
    if (head == NULL) {
	printf("List Empty\n");
    } else {
	temp = head;
	while (temp != NULL) {
	    printf("%d ", temp->data); 
	    temp = temp->next;  
        }
        printf("\n");
    }
}


void concatenate(struct node** list1, struct node* list2) {
    if (*list1 == NULL) {
        *list1 = list2; 
    } else {
        temp = *list1;
        while (temp->next != NULL) {
            temp = temp->next; 
        }
        temp->next = list2; 
    }
}


void main() {
    int ch, x, c;

    while (1) {
        printf("\n1.Insert data in List 1\n2.Insert data in List 2\n3.Display List 1\n4.Display List 2\n5.Concatenate Lists\n6.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the data to be inserted into List 1: ");
                scanf("%d", &x);
                insertend(x, &head1);  
                break;
            
            case 2:
                printf("\nEnter the data to be inserted into List 2: ");
                scanf("%d", &x);
                insertend(x, &head2); 
                break;
            
            case 3:
                printf("\nDisplaying List 1:\n");
                display(head1);  
                break;

            case 4:
                printf("\nDisplaying List 2:\n");
                display(head2);  
                break;

            case 5:
                printf("\nConcatenating List 2 into List 1\n");
                concatenate(&head1, head2);  
                printf("List 2 has been concatenated into List 1\n");
                break;

            case 6:
                exit(0); 
                break;

            default:
                printf("\nInvalid option\n");
                break;
        }
    }
}
