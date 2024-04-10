#include <stdio.h>

void linearSearch(int arr[][10], int n, int target){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == target){
                printf("%d exists at index %d %d", target, i, j);
                return;
            }
            
        }
    }

    printf("%d does not exist", target);
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n][10];

    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int target;
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    linearSearch(arr, n, target);

    return 0;
}