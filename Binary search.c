#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main(){
    int a[11] = {1, 2, 3, 5, 6,7,8,9}; 
    int i, p = -1, k, n = 8,f=0,l=n-1,mid; 
    
    for (i = 0; i < n; i++) {
        printf("The Array a[%d] is: %d\n", i, a[i]);
    }
    mid=(f+l)/2;
    printf("enter the element to be searched :");
    scanf("%d",&k);   
    while (f <= l) {
        mid = (f + l) / 2;  // Recalculate mid on each iteration
        if (a[mid] == k) {
            p = mid;  // Element found
            break;    // Exit the loop as the element is found
        } else if (a[mid] < k) {
            f = mid + 1;  // Search in the right half
        } else {
            l = mid - 1;  // Search in the left half
        }
    }                     
printf("the  element is found at position %d\n", p);
 }       