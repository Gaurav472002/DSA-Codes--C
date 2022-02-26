// Online C compiler to run C program online
#include <stdio.h>

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
        // printf("\n");
    }
    printf("\n");
}

int arr_insert(int arr[],int size,int capacity,int index,int ele){
    if(size>=capacity){
        return -1;
    }
    
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=ele;
    return 1;
}

void delete_arr(int arr[] ,int size, int index){
    for(int i=index;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    
}

int main() {
    int arr[20]={55,66,88,99,1000};
    display(arr,5);
    
    arr_insert(arr,5,20,2,77);
    display(arr,6);
    
    delete_arr(arr,6,5);
    display(arr,6);
    
    return 0;
}