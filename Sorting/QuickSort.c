#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int arr[], int idx1, int idx2);

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, len-1);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);

        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

int partition(int arr[], int low, int high){
    int i=low;
    int j=high;
    int pivot = low;

    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high){
            i++;
        }

        while(arr[j]>arr[pivot] && j>=low){
            j--;
        }

        if(i<j){
            swap(arr, i, j);
        }
    }

    swap(arr, pivot, j);

    return j;
}

void swap(int arr[], int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}