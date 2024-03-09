#include <stdio.h>

void mergeSort(int arr[], int si, int ei);
void merge(int arr[], int si, int mid, int ei);

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, len-1);

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void mergeSort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = si + (ei-si)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
}


void merge(int arr[], int si, int mid, int ei){
    int temp[ei-si+1];
    int i = si;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ei){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    // remaining left part
    while(i<=mid){
        temp[k++] = arr[i++];
    }

    // remaining right part
    while(j<=ei){
        temp[k++] = arr[j++];
    }

    //copy temp array to original array
    for (k = 0, i = si; k < ei - si + 1; k++, i++) {
    arr[i] = temp[k];
    }
}



