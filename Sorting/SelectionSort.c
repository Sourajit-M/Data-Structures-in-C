#include <stdio.h>

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<len; i++){
        int minIdx = i;
        for(int j=i+1; j<len; j++){
            if(arr[minIdx] > arr[j]){
                minIdx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}