#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int low, int mid, int high);
void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int arr[], int low, int mid, int high) {
    int n1 = (mid - low) + 1;
    int n2 = (high - mid);
    int Left[n1];
    int Right[n2];
    
    for (int i = 0; i < n1; i++) {
        Left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        Right[j] = arr[mid + 1 + j];
    }

    int left = 0;
    int right = 0;
    int k = low;
    while (left < n1 && right < n2) {
        if (Left[left] < Right[right]) {
            arr[k] = Left[left];
            left++;
        }
        else {
            arr[k] = Right[right];
            right++;
        }
        k++;
    }
    while (left < n1) {
        arr[k] = Left[left];
        left++;
        k++;
    }
    while (right < n2) {
        arr[k] = Right[right];
        right++;
        k++;
    }
}

int main() {
    int test_cases[10][10] = {
        {1},
        {1, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {6, 7, 8, 0, 0, 0, 0},
        {1, 1, 2, 2, 3, 3, 4, 4},
        {-1, 1, -2, 2, 5, -5},
        {1000, 500, 250, -250, -500, -1000},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {100, 200, 300, 400, 500, 600, 700},
    };
    int sizes[10] = {1, 2, 5, 5, 7, 8, 6, 6, 10, 7};
    
    for (int i = 0; i < 10; i++) {
        printf("Test case %d : ", i + 1);
        print_array(test_cases[i], sizes[i]);
        if (sizes[i] > 0) {
            merge_sort(test_cases[i], 0, sizes[i] - 1);
        }
        printf("Sorted : ");
        print_array(test_cases[i], sizes[i]);
        printf("\n");
    }
    return 0;
}
