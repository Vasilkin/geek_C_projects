#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return  array;
}

void fill2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = rand() % 100;
        }
    }
}

void convertInt2dIntArray(int** array, const int row, const int col, int* arr) {
    int k = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = arr[k++];
        }
    }
}

void print2dIntArray(const int** array, const int row, const int col, const int offset) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%*d", offset, *((*(array + i)) + j));
        }
        printf("\n");
    }
}

int* initIntArray(int* array, const int len) {
    array = (int*) calloc(sizeof(int*), len);
    return  array;
}

void fillIntArray(int* arr, int len, int** array, const int row, const int col) {
    for (int n = 0; n < len; ++n) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                *(arr + n) = *((*(array + i)) + j);
                n++;
            }
        }
    }
}

void swapInt(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swapInt(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void taskOne() {
    const int ROW = 10;
    const int COL = 10;
    const SIZE = ROW * COL;
    int** array = init2dIntArray(array, ROW, COL);
    fill2dIntArray(array, ROW, COL);

    int* array1 = initIntArray(array1, SIZE);
    fillIntArray(array1, SIZE, array, ROW, COL);

    bubbleSort(array1, SIZE);

    convertInt2dIntArray(array, ROW, COL, array1);
    print2dIntArray(array, ROW, COL, 3);
    free(array1);
    free(array);
}

void taskOne2() {
    int arr[3][3] = {1, 9, 2, 5, 7, 6, 4, 3, 8};
    bubbleSort(arr, 9);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%*d", 3, arr[i][j]);
        }
        printf("\n");
    }
}

double f(double t) {
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

void tpkAlgorithm(double* arr, int len) {
    for (int i = 0; i < len; ++i) {
        scanf("%lf", &arr[i]);
    }
    for (int i = len - 1; i >= 0; --i) {
        double y = f(arr[i]);
        if (y > 400) printf("%d larger than %d - %.16f\n", i, 400, y);
        else printf("%d %.16f\n", i, y);
    }
}

void taskTwo() {

    const int SIZE = 11;
    double  array[SIZE];

    tpkAlgorithm(array, SIZE);
}



int main() {
    taskOne();
    taskOne2();
    taskTwo();

    return 0;
}
