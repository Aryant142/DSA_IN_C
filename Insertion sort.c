#include <stdio.h>


void sort(int a[], int size);

int main(){
  int a[]={4,5,10,1,6,2};
  int n =sizeof(a)/sizeof(a[0]);
  sort(a,n);
  printf("the sorted array is : ");
  for(int i=0;i<n;i++){
    printf(" %d",a[i]);
  }
  return 0;
}

void sort(int a[],int size){
    int i,j,temp;
    for(i=1;i<size;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
} 