//1) Create a Null Matrix of 3X3

#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS] = {0};  // Initializing all elements to 0

    printf("Null Matrix 3x3:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//2) Create an Identity Matrix of 4X4
#include <stdio.h>

#define SIZE 4

int main() {
    int matrix[SIZE][SIZE];

    // Initialize Identity Matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) 
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    // Print Identity Matrix
    printf("Identity Matrix 4x4:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//3) Check that a matrix is Square or Not
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];

    // Check if the matrix is square
    if (ROWS == COLS) {
        printf("The matrix is square.\n");
    } else {
        printf("The matrix is not square.\n");
    }
    return 0;
}

//4) Check that a matrix is Identity Matrix or Not.
#include <stdio.h>

#define SIZE 3

int isIdentityMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j && matrix[i][j] != 1) 
                return 0;  // Diagonal elements must be 1
            else if (i != j && matrix[i][j] != 0)
                return 0;  // Non-diagonal elements must be 0
        }
    }
    return 1;
}

int main() {
    int matrix[SIZE][SIZE] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    
    if (isIdentityMatrix(matrix)) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is not an Identity Matrix.\n");
    }
    return 0;
}

/*5) Write a program to implement a 2D Array by defining its elements and display the 
elements of the 2D Array*/
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Display the 2D Array
    printf("2D Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*6) Write a program to implement a 2D Array by taking inputs from user and display the 
elements of the 2D Array*/
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    
    // Taking user input for the 2D array
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the 2D Array
    printf("The entered 2D Array is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//Problem 1: Matrix Addition
#include <stdio.h>

#define MAX 10

int main() {
    int m, n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    // Prompting for rows and columns
    printf("Enter the number of rows for the matrices: ");
    scanf("%d", &m);  // Input for number of rows

    printf("Enter the number of columns for the matrices: ");
    scanf("%d", &n);  // Input for number of columns

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display the result
    printf("Sum of matrices A and B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//Problem 2: Matrix Multiplication
#include <stdio.h>
int main() {
    int m, p, n;
    printf("Enter rows of A, columns of A / rows of B, columns of B: ");
    scanf("%d %d %d", &m, &p, &n);

    int A[m][p], B[p][n], C[m][n];

    printf("Enter Matrix A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Initialize C to zero
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;

    // Multiply
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Product Matrix C = A × B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}


//Problem 3: Transpose of a Matrix
#include <stdio.h>

void transpose(int m, int n, int matrix[m][n]) {
    // Transpose the matrix
    int transposed[n][m];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Print the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Enter the dimensions of the matrix (m x n): ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    transpose(m, n, matrix);
    return 0;
}

//Problem 4: Determinant of a 2x2 Matrix
#include <stdio.h>

int determinant(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int main() {
    int matrix[2][2];
    printf("Enter the elements of the 2x2 matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int det = determinant(matrix);
    printf("Determinant of the matrix: %d\n", det);
    return 0;
}


//Problem 5: Saddle Point of a Matrix
#include <stdio.h>

void findSaddlePoints(int m, int n, int matrix[m][n]) {
    for (int i = 0; i < m; i++) {
        int min_row_value = matrix[i][0], min_row_index = 0;

        // Find the minimum element in the row
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < min_row_value) {
                min_row_value = matrix[i][j];
                min_row_index = j;
            }
        }

        // Check if the minimum element in the row is the largest in its column
        int is_saddle_point = 1;
        for (int k = 0; k < m; k++) {
            if (matrix[k][min_row_index] > min_row_value) {
                is_saddle_point = 0;
                break;
            }
        }

        if (is_saddle_point) {
            printf("Saddle Point: %d at position (%d, %d)\n", min_row_value, i + 1, min_row_index + 1);
        }
    }
}

int main() {
    int m, n;
    printf("Enter the dimensions of the matrix (m x n): ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findSaddlePoints(m, n, matrix);
    return 0;
}


//Problem 6: Traversal of a 3D Array
#include <stdio.h>

void display3DArray(int x, int y, int z, int array[x][y][z]) {
    // Display all elements of the 3D array
    printf("Elements of the 3D array:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
            }
        }
    }
}

void displayLayerByLayer(int x, int y, int z, int array[x][y][z]) {
    // Display elements layer by layer
    for (int i = 0; i < x; i++) {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
    }
}

int main() {
    int array[2][3][4] = {
        {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
        {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
    };

    display3DArray(2, 3, 4, array);
    displayLayerByLayer(2, 3, 4, array);
    
    return 0;
}

//Problem 7: Search in a 3D Array
#include <stdio.h>

void searchElement(int x, int y, int z, int array[x][y][z], int target) {
    int found = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                if (array[i][j][k] == target) {
                    printf("Element %d found at position (%d, %d, %d)\n", target, i + 1, j + 1, k + 1);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("Element %d not found.\n", target);
    }
}

int main() {
    int array[3][3][3];
    printf("Enter the elements of the 3x3x3 array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    searchElement(3, 3, 3, array, target);
    
    return 0;
}

//Problem 8: Sum of All Elements in a 3D Array
#include <stdio.h>

int sumOfElements(int x, int y, int z, int array[x][y][z]) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                sum += array[i][j][k];
            }
        }
    }
    return sum;
}

int main() {
    int array[2][2][2];
    printf("Enter the elements of the 2x2x2 array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    int total = sumOfElements(2, 2, 2, array);
    printf("Sum of all elements in the 3D array: %d\n", total);
    
    return 0;
}

