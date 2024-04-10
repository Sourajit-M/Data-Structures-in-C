#include <stdio.h>

int binarySearch(int arr[], int n, int target){
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = (start+end)/2;

        if(arr[mid] == target){
            return mid;
        }

        else if(arr[mid] < target){
            start = mid+1;
        }else{
            end = mid-1;
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

    int idx = binarySearch(arr, n, target);
    if(idx == -1){
        printf("Element does not exist");
    }else{
        printf("%d exists at index %i", target, idx);
    }

    return 0;
}