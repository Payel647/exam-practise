#include<stdio.h>


void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;  // Swap if in wrong order
            }
        }
    }
}
int main(){
    int arr[]={-2, 45, 0, 11, -9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    bubble_sort(arr,n);
    printf("\nSorted array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

