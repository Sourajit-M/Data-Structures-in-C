#include <stdio.h>

int main(){
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int len = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<len; i++){
        for(int j=0; j<len-1-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}