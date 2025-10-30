#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int weight;
    double ratio;
} Item;

int compareItems(const void *a, const void *b) {
    const Item *itemA = (const Item *)a;
    const Item *itemB = (const Item *)b;
    if (itemA->ratio < itemB->ratio) return 1;
    if (itemA->ratio > itemB->ratio) return -1;
    return 0;
}
double solveKnapsack(int capacity, Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    qsort(items, n, sizeof(Item), compareItems);

    double totalProfit = 0.0;
    int remaining = capacity;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remaining) {
            totalProfit += items[i].profit;
            remaining -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * remaining;
            remaining = 0;
            break;
        }
        if (remaining == 0) {
            break;
        }
    }
    return totalProfit;
}
int main() {
    Item items[] = {
        {20, 4, 0.0},
        {9, 6, 0.0},
        {28, 10, 0.0},
        {14, 14, 0.0},
        {12, 8, 0.0}
    };
    int capacity = 25;
    int n = sizeof(items) / sizeof(items[0]);
    double maxProfit = solveKnapsack(capacity, items, n);
    printf("Maximum profit for Knapsack capacity %d: %.2f\n", capacity, maxProfit);
    return 0;
}
