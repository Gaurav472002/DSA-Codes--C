#include<stdio.h>  //Selection Sort function
#include<limits.h> 
#include<stdlib.h> 


void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int maximumnum(int arr[],int n){
    int max= INT_MIN;

    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void countsort(int*arr,int n){

    int i,j;
    int max =maximumnum(arr,n);

    int*count =(int*)malloc((max+1)*sizeof(int));

    for( i=0;i<max+1;i++){
        
        count[i]=0;
    }

    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }

    i=0;
    j=0;

    while(i<=max){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;

        }
        else{
            i++;
        }
    }



}


int main(){
    int arr[10]={22,99,1,55,7,98};
    int n=6;

    printarray(arr,n);
    countsort(arr,n);
    printarray(arr,n);

return 0;
}
