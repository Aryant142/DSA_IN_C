#include<stdio.h>
#include<conio.h>
void trans(int*,int);

void main(){
    int a[]={1,2,3,4,5};
   int n=sizeof(a)/sizeof(int);
    trans(a,n);
}

void trans(int*a,int n){
    for(int i=0;i<n;i++)
        printf("%d \n",a[i]);
    
}