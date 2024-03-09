#include <stdio.h>

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<len; i++){
        int key = arr[i];
        int j = i-1;

        while(key<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    

    return 0;
}