#include <iostream>
using namespace std;

// 1-ci tapşırıq: Mənfi elementləri silən funksiya
int* removeNegativeElements(int* arr, int size, int& newSize) {
    int count = 0;

    // Mənfi olmayan elementlərin sayını tap
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) count++;
    }

    // Yeni massiv üçün yer ayır
    int* newArr = new int[count];
    newSize = count;
    int j = 0;

    // Mənfi olmayan elementləri yeni massivə köçür
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0) newArr[j++] = arr[i];
    }

    return newArr;
}

// 3-cü tapşırıq: İki massivdən ortaq elementləri tapan funksiya
int* commonElements(int* A, int M, int* B, int N, int& newSize) {
    int* commonArr = new int[min(M, N)];
    newSize = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                bool exists = false;
                for (int k = 0; k < newSize; k++) {
                    if (commonArr[k] == A[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    commonArr[newSize++] = A[i];
                }
            }
        }
    }

    return commonArr;
}

// 4-cü tapşırıq: A massivində olub, B massivində olmayan elementləri tapan funksiya
int* uniqueInA(int* A, int M, int* B, int N, int& newSize) {
    int* uniqueArr = new int[M];
    newSize = 0;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueArr[newSize++] = A[i];
        }
    }

    return uniqueArr;
}

// 5-ci tapşırıq: A və B massivi arasında ortaq olmayan elementləri tapan funksiya
int* uniqueInBoth(int* A, int M, int* B, int N, int& newSize) {
    int* uniqueArr = new int[M + N];
    newSize = 0;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueArr[newSize++] = A[i];
        }
    }

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueArr[newSize++] = B[i];
        }
    }

    return uniqueArr;
}

int main() {
    cout << "\ntask1" << endl;
    int arr[] = { 1, -2, 3, 4, -5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int newSize;

    int* newArr = removeNegativeElements(arr, size, newSize);
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;
    delete[] newArr;

    cout << "\ntask3" << endl;
    int A[] = { 1, 2, 3, 4 };
    int B[] = { 3, 4, 5, 6 };
    int M = sizeof(A) / sizeof(A[0]);
    int N = sizeof(B) / sizeof(B[0]);

    int commonSize;
    int* commonArr = commonElements(A, M, B, N, commonSize);
    for (int i = 0; i < commonSize; i++) {
        cout << commonArr[i] << " ";
    }
    cout << endl;
    delete[] commonArr;

    cout << "\ntask4" << endl;
    int uniqueSize;
    int* uniqueArrInA = uniqueInA(A, M, B, N, uniqueSize);
    for (int i = 0; i < uniqueSize; i++) {
        cout << uniqueArrInA[i] << " ";
    }
    cout << endl;
    delete[] uniqueArrInA;

    cout << "\ntask5" << endl;
    int uniqueBothSize;
    int* uniqueArrInBoth = uniqueInBoth(A, M, B, N, uniqueBothSize);
    for (int i = 0; i < uniqueBothSize; i++) {
        cout << uniqueArrInBoth[i] << " ";
    }
    cout << endl;
    delete[] uniqueArrInBoth;

    return 0;
}