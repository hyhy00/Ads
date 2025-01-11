#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void display(int arr[], int size);
void union_(int abit[], int bbit[], int result[], int size);
void intersect(int abit[], int bbit[], int result[], int size);
void differ(int abit[], int bbit[], int result[], int size);

int main() {
    int uset[MAX], aset[MAX], bset[MAX], abit[MAX] = {0}, bbit[MAX] = {0}, result[MAX];
    int usize, asize, bsize, i, j, ch;

    printf("Enter the size of the universal set: ");
    scanf("%d", &usize);
    printf("Enter elements of the universal set:\n");
    for (i = 0; i < usize; i++) {
        scanf("%d", &uset[i]);
    }

    printf("Enter the size of set 1: ");
    scanf("%d", &asize);
    printf("Enter elements of set 1:\n");
    for (i = 0; i < asize; i++) {
        scanf("%d", &aset[i]);
    }

    printf("Enter the size of set 2: ");
    scanf("%d", &bsize);
    printf("Enter elements of set 2:\n");
    for (i = 0; i < bsize; i++) {
        scanf("%d", &bset[i]);
    }

    // Creating bit vectors for set 1 and set 2
    for (i = 0; i < usize; i++) {
        for (j = 0; j < asize; j++) {
            if (uset[i] == aset[j]) {
                abit[i] = 1;
                break;
            }
        }
        for (j = 0; j < bsize; j++) {
            if (uset[i] == bset[j]) {
                bbit[i] = 1;
                break;
            }
        }
    }

    while (1) {
        printf("\n1. Display sets\n2. Bit vectors\n3. Union\n4. Intersection\n5. Difference\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Universal set: ");
                display(uset, usize);
                printf("\nSet 1: ");
                display(aset, asize);
                printf("\nSet 2: ");
                display(bset, bsize);
                break;
            case 2:
                printf("Bit vector for Set 1: ");
                display(abit, usize);
                printf("\nBit vector for Set 2: ");
                display(bbit, usize);
                break;
            case 3:
                union_(abit, bbit, result, usize);
                printf("Union: ");
                display(result, usize);
                break;
            case 4:
                intersect(abit, bbit, result, usize);
                printf("Intersection: ");
                display(result, usize);
                break;
            case 5:
                differ(abit, bbit, result, usize);
                printf("Difference: ");
                display(result, usize);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}

void display(int arr[], int size) {
int i;
    printf("{ ");
    for ( i = 0; i < size; i++) {
	printf("%d ", arr[i]);
    }
    printf("}\n");
}

void union_(int abit[], int bbit[], int result[], int size) {
int i;
    for (i = 0; i < size; i++) {
	result[i] = abit[i] | bbit[i];  // Bitwise OR
    }
}

void intersect(int abit[], int bbit[], int result[], int size) {
int i;
    for (i = 0; i < size; i++) {
	result[i] = abit[i] & bbit[i];  // Bitwise AND
    }
}

void differ(int abit[], int bbit[], int result[], int size) {
int i;
    for ( i = 0; i < size; i++) {
	result[i] = abit[i] & ~bbit[i];  // Bitwise AND NOT
    }
}
