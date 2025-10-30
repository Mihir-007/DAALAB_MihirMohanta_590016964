//for naive power calculation approach
#include <stdio.h>
#include <time.h>
double power_naive(double a, int n) {
    if (n == 0) {
        return 1.0;
    }
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= a;
    }
    return result;
}

//for greedy power calculation approach
double power_fast(double a, int n) {
    if (n == 0) return 1.0;
    double half = power_fast(a, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

int main() {
    double base = 3.0;
    int exponent = 10;
    clock_t start, end;
    double cpu_time_used;

    // Naïve method
    printf("By using Naive Power Calculation\n");
    start = clock();
    double result1 = power_naive(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result: %.2e\n", result1);
    printf("Time taken (Naive): %f seconds\n\n", cpu_time_used);

    // Fast method
    printf("By using Fast Exponentiation method\n");
    start = clock();
    double result2 = power_fast(base, exponent);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result: %.2e\n", result2);
    printf("Time taken (Fast): %f seconds\n", cpu_time_used);

    return 0;
}
