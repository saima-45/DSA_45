#include <stdio.h>
#include <stdlib.h>  // For malloc, free

void findLeaders(int arr[], int n) {
    // The last element is always a leader
    int max_from_right = arr[n - 1];

    // Print the last element first
    printf("%d ", max_from_right);

    // Traverse the array from second last element to the first element
    int i;  // Declare 'i' outside the loop for compatibility with older standards
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            printf("%d ", arr[i]);
            max_from_right = arr[i];  // Update the max_from_right
        }
    }
    printf("\n");
}

int main() {
    // Input the size of the array
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the array elements
    printf("Enter array elements: ");
    int i;  // Declare 'i' outside the loop for compatibility
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the leader elements
    printf("Leader elements are: ");
    findLeaders(arr, size);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
