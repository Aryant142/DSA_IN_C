#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() {
    int a[11] = {1, 2, 3, 5, 6}; 
    int i, p, k, n = 5;

    
    for (i = 0; i < n; i++) {
        printf("THE ARRAY BEFORE INSERTING a[%d] IS :  %d\n", i,a[i]);
    }
    
    printf("Enter the number to be inserted: ");
    scanf("%d", &p);
    printf("Enter the index of the number to be inserted (0 to %d): ", n);
    scanf("%d", &k);

    // Check if the index is valid
    if (k < 0 || k > n) {
        printf("Invalid index!\n");
        return 1; // Exit the program with an error code
    }
   
    for (i = n; i > k; i--) {
        a[i] = a[i - 1];
    }

    a[k] = p;
    n++;

    for (i = 0; i < n; i++) {
        printf("THE ARRAY AFTER INSERTING a[%d] IS :  %d\n", i,a[i]);
    }

    return 0;
}
