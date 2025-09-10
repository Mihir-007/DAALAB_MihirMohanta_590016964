#include<stdio.h>
#include <time.h>

void binarysearch(int arr[], int size, int k) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            //printf("Element %d found at index %d\n", k, mid);  {commenting this out so it doesn't mess up the outputs}
            return;
        }
        else if (arr[mid] > k) {
            high = mid -1;
        }
        else {
            low = mid+1;
        }
    }
    //printf("Element %d not found in the array\n", k);  {commenting this out so it doesn't mess up the outputs}
}

void run_cases(FILE *fp, int size, int k, char *test_case_type) {
    int arr[size];
    for(int i=0; i < size; i++) {
        arr[i] = i+1;
    }
    clock_t start = clock();
    binarysearch(arr, size, k);
    clock_t end = clock();
    double time_used = ((double)(end-start)/CLOCKS_PER_SEC*1e6);
    printf("%s size: %d, time: %f us\n", test_case_type, size, time_used);
    fprintf(fp, "%s,%d,%.6f\n", test_case_type, size, time_used); //adding data to csv file
}

int main() {
    int sizes[]= {1, 5, 10, 100, 1000};
    int i;
    FILE *fp = fopen("binary_search_data.csv", "w");
    if (fp == NULL) {
        printf("error opening the file!");
        return 1;
    }
    fprintf(fp, "test_case_type,size,time_used\n");

    for (i = 0; i<5; i++) {
        run_cases(fp, sizes[i], sizes[i]/2, "best");
    }
    for (i = 0; i<5; i++) {
        run_cases(fp, sizes[i], sizes[i]/4, "average");
    }
    for (i = 0; i<5; i++) {
        run_cases(fp, sizes[i], sizes[i]+20, "worst");
    }
    fclose(fp);
    printf("data entered in file binary_search_data.csv\n");
    return 0;
}