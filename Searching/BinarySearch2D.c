#include <stdio.h>

void binarySearch(int arr[][10], int n, int target){
    int row = 0;
    int col = n-1;

    while(row<n && col>=0){
        if(arr[row][col] == target){
            printf("%d exists at index %d %d", target, row, col);
                return;
        }else if(arr[row][col] < target){
            row++;
        }else{
            col--;
        }
    }
    printf("%d does not exist", target);
}

void binarySearch2D_01(int arr[][10], int n, int target){
    int row = n-1;
    int col = 0;

    while(row>=0 && col<n){
        if(arr[row][col] == target){
            printf("%d exists at index %d %d", target, row, col);
            return;
        }else if(arr[row][col] < target){
            col++;
        }else{
            row--;
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
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    }

    int target;
    printf("Enter the element to be searched: ");
    scanf("%d", &target);

    binarySearch(arr, n, target);
    printf("\n");
    binarySearch2D_01(arr, n, target);

    return 0;
}