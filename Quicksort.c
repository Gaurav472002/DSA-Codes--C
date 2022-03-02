#include<stdio.h>  //Selection Sort function


void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;


    do
    {
        while(arr[i]<=pivot){
            i++;
        }

        while (arr[j]>pivot)
        {
            j--;
        }

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp ;
        }
        
    } while (i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;

    
}

void quicksort(int arr[],int low, int high){

    int index;

    if(low<high){
        index=partition(arr,low,high);
        quicksort(arr,low,index-1);
        quicksort(arr,index+1,high);

    }
}
int main(){
    int arr[10]={22,99,1,55,7,98,1,2,3,4};
    int n=10;

    printarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr,n);

return 0;
}
