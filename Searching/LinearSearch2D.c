#include <stdio.h>

int N;

int linearSearch2D(int arr[][N], int rows, int cols, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                printf("Element found at position (%d, %d)\n", i, j);
                return 1;
            }
        }
    }
    printf("Element not found in the array.\n");
    return 0;
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int array[N][N];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    linearSearch2D(array, N, N, target);

    return 0;
}
