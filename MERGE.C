#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, j, k, m, n, a[10], b[10], c[20];
    
    // Input size and elements of the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &m);
    printf("Enter the elements of the first array: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    
    // Input size and elements of the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &n);
    printf("Enter the elements of the second array: ");
    for(j = 0; j < n; j++) {
	scanf("%d", &b[j]);
    }

    // Merge the arrays
    i = 0;
    j = 0;
    k = 0;
    while(i < m && j < n) {
	if(a[i] < b[j]) {
	    c[k] = a[i];
	    i++;
	} else {
	    c[k] = b[j];
	    j++;
	}
	k++;
    }

    // If any elements are left in array a[]
    while(i < m) {
	c[k] = a[i];
	i++;
	k++;
    }

    // If any elements are left in array b[]
    while(j < n) {
	c[k] = b[j];
        j++;
        k++;
    }

    // Print the merged array
    printf("\nThe merged array is:\n");
    for(k = 0; k < m + n; k++) {
        printf("%d ", c[k]);
    }
    printf("\n");

    getch();

    return 0;
}
