#include <stdio.h>

void findLeaders(int arr[], int n) {
    // The last element is always a leader
    int max_from_right = arr[n - 1];

    // Print the last element first
    printf("%d ", max_from_right);

    // Traverse the array from second last element to the first element
    for (int i = n - 2; i >= 0; i--) {
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

    // Input the array elements
    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the leader elements
    printf("Leader elements are: ");
    findLeaders(arr, size);

    return 0;
}
