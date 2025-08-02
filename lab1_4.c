// a) Traverse an array.
#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}





// b) Find the number of elements (Length) of an array.
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Length of array: %d", length);
    return 0;
}




// c) Search an element from the array.
#include <stdio.h>
int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int search = 15;
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++) {
        if(arr[i] == search) {
            printf("Element found at index %d", i);
        }
    }
    return 0;
}





// d) Find the largest element from the array.
#include <stdio.h>
int main() {
    int arr[] = {11, 56, 23, 89, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Largest element is %d", max);
    return 0;
}




// e) Find the smallest element from the array.
#include <stdio.h>
int main() {
    int arr[] = {9, 21, 5, 33, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Smallest element is %d", min);
    return 0;
}





// f) Insert an element at a given position in the array.
#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    int pos = 2;
    int value = 99;
    for(int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}





// g) Delete an element from a given position in the array.
#include <stdio.h>
int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;
    int pos = 2;
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}





// h) Search for an element using linear search.
#include <stdio.h>
int main() {
    int arr[] = {7, 14, 21, 28, 35};
    int search = 28;
    int size = sizeof(arr) / sizeof(arr[0]);
    int found = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == search) {
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Element not found");
    }
    return 0;
}







