#include <stdio.h>
#include <stdbool.h>

#define N 4

int knowsMatrix[N][N] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 1, 1, 0}
};

bool knows(int a, int b) {
    return knowsMatrix[a][b] == 1;
}
int findCelebrity(int total) {
    int current_celeb = 0;
    for (int i = 1; i < total; i++) {
        if (knows(current_celeb, i)) {
            current_celeb = i;
        }
    }
    for (int i = 0; i < total; i++) {
        if (i == current_celeb) {
            continue;
        }
        if (knows(current_celeb, i) || !knows(i, current_celeb)) {
            return -1;
        }
    }
    return current_celeb;
}
int main() {
    int result = findCelebrity(N);
    if (result == -1) {
        printf("No celebrity found.\n");
    } else {
        printf("Celebrity is person %d\n", result);
    }
    return 0;
}