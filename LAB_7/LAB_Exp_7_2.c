#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
    int index;
} Activity;

int compare(const void *a, const void *b) {
    Activity *act1 = (Activity *)a;
    Activity *act2 = (Activity *)b;
    return act1->finish - act2->finish;
}

void activitySelection(int n, Activity activities[]) {
    int i, j;
    i = 0;
    printf("Selected activities:\n");
    printf("Activity %d: Start = %d, Finish = %d\n", activities[i].index, activities[i].start, activities[i].finish);
    for (j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: Start = %d, Finish = %d\n", activities[j].index, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    Activity activities[n];
    printf("Enter start times of activities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
        activities[i].index = i + 1;
    }

    printf("Enter finish times of activities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].finish);
    }

    qsort(activities, n, sizeof(Activity), compare);

    activitySelection(n, activities);
    return 0;
}
