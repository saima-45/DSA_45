#include <stdio.h>

int main() {
    // a) Traverse an array.
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    printf("Array elements: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // b) Find the number of elements (Length) of an array.
    printf("Length of array: %d\n", size);

    // c) Search an element from the array.
    int search = 15;
    int found = 0;
    for(i = 0; i < size; i++) {
        if(arr[i] == search) {
            printf("Element %d found at index %d\n", search, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found\n", search);
    }

    // d) Find the largest element from the array.
    int max = arr[0];
    for(i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Largest element is %d\n", max);

    // e) Find the smallest element from the array.
    int min = arr[0];
    for(i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Smallest element is %d\n", min);

    // f) Insert an element at a given position in the array.
    int insert_pos = 2;
    int insert_value = 99;
    printf("Inserting %d at position %d:\n", insert_value, insert_pos);
    int arr2[10] = {1, 2, 3, 4, 5};
    int size2 = 5;
    for(i = size2; i > insert_pos; i--) {
        arr2[i] = arr2[i - 1];
    }
    arr2[insert_pos] = insert_value;
    size2++;
    for(i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // g) Delete an element from a given position in the array.
    int delete_pos = 2;
    int arr3[10] = {10, 20, 30, 40, 50};
    int size3 = 5;
    printf("Deleting element at position %d:\n", delete_pos);
    for(i = delete_pos; i < size3 - 1; i++) {
        arr3[i] = arr3[i + 1];
    }
    size3--;
    for(i = 0; i < size3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // h) Search for an element using linear search.
    int arr4[] = {7, 14, 21, 28, 35};
    int search_val = 28;
    found = 0;
    for(i = 0; i < size; i++) {
        if(arr4[i] == search_val) {
            printf("Element %d found at index %d\n", search_val, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found\n", search_val);
    }

    return 0;
}

