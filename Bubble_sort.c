#include<stdio.h>

void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr,int n){ // bubble sort function
    for(int i=0;i<n-1;i++){
        int issorted=1;  /* using this variable to make the function more stable 
                                      only 1 passs will be executed if the array is already sorted */
        int temp;
        for(int j=0;j<n-1-i;j++){   //n-1 number of passes
            if(arr[j]>arr[j+1]){    //n-1-i number of comparisons in each pass
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                issorted=0;
            }
        }
        if(issorted){
            return;
        }
    }
    

}
int main(){

    int arr[10]={22,99,1,55,7,98};
    int n=6;

    printarray(arr,n);
    bubble_sort(arr,n);
    printarray(arr,n);

return 0;
}