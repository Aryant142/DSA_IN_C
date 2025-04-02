#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()  {
    int a[11] = {1, 2, 3, 5, 6}; 
    int i, p = -1, k, n = 5; 
    
    for (i = 0; i < n; i++) {
        printf("The Array a[%d] is: %d\n", i, a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &k);

    // Search for the element
    for (i = 0; i < n; i++) {
        if (k == a[i]) {
            p = i;
            break;
        }
    }

    if (p != -1) {
        printf("Your searched element %d is at index %d.\n", k, p);
    } else {
        printf("Element not found.\n");
    }

    getch(); 
}
