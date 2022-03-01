#include<stdio.h>


void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertion_sort(int*arr ,int n){
    
    
    int key,j;
    
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}



int main(){
    int arr[10]={22,99,1,55,7,98};
    int n=6;

    printarray(arr,n);
    insertion_sort(arr,n);
    printarray(arr,n);

return 0;
}




