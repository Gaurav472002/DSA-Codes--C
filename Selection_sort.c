#include<stdio.h>  //Selection Sort function


void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void Selection_sort(int*arr,int n){

    int j, indexofmin,temp;  //index containing the minimum value---> indexofmin

    for(int i=0;i<n-1;i++){
        indexofmin=i;

        for (j=i+1;j<n;j++){

            if(arr[j]<arr[indexofmin]){
                indexofmin=j;
            }
        }
        // swapping the values

        temp=arr[i];
        arr[i]=arr[indexofmin];
        arr[indexofmin]=temp;

        
    }
}



int main(){
    int arr[10]={22,99,1,55,7,98};
    int n=6;

    printarray(arr,n);
    Selection_sort(arr,n);
    printarray(arr,n);

return 0;
}
