#include <stdio.h>

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }

    return -1;
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    int idx = linearSearch(arr, n, target);
    if(idx == -1){
        printf("Element does not exist");
    }else{
        printf("%d exists at index %d", target, idx);
    }


    printf("\n");

    int idx1 = binarySearch(arr, n, target);
    if(idx1 == -1){
        printf("Element does not exist");
    }else{
        printf("%d exists at index %i", target, idx1);
    }

    return 0;
}