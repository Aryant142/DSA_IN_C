#include <stdio.h>

int main() {
    int a[11] = {1, 2, 3, 5, 6}; 
    int i, p, k, n = 5;

    
    for (i = 0; i < n; i++) {
        printf("THE Array a[%d] before deletion is :  %d\n", i,a[i]);
    }

   printf("enter the element's index number to be deleted ");
   scanf("%d",&p);

   for (i=p;i<n;i++){
    a[i]=a[i+1];
   }

   n-=1;
    for (i = 0; i < n; i++) {
        printf("THE Array  a[%d] after deletion  is :  %d\n", i,a[i]);
    }
return 0;
}