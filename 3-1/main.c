#include <assert.h>
#include <stdio.h>
#include <time.h>

#define LENGTH 1000000
#define ITERATION_COUNT 1000000

int binsearch(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

int main(void) {
    int i;
    int array[LENGTH];
    clock_t begin_old, begin_new, end_old, end_new;
    double time_spent_old, time_spent_new;

    // fill the array
    for (i = 0; i < LENGTH; i++) {
        array[i] = i + 1;
    }

    // run old version search for million times and measure time
    begin_old = clock();
    for (i = 0; i < ITERATION_COUNT; i++) {
        binsearch(LENGTH / 2, array, LENGTH);
    }
    end_old = clock();

    // run new version search for million times and measure time
    begin_new = clock();
    for (i = 0; i < ITERATION_COUNT; i++) {
        binsearch_new(LENGTH / 2, array, LENGTH);
    }
    end_new = clock();


    time_spent_old = (double)(end_old - begin_old) / CLOCKS_PER_SEC;
    time_spent_new = (double)(end_new - begin_new) / CLOCKS_PER_SEC;

    printf("Time spent for old version: %f\n", time_spent_old);
    printf("Time spent for new version: %f\n", time_spent_new);


    return 0;
}

/** Binary search with checks inside loop */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

/** Binary search with checks outside loop */
int binsearch_new(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    return v[mid] == x ? mid : -1;
}
