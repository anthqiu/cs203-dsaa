#include <iostream>

long long count = 0;
int fuck[100010];

void CountWhileSort(int *a, int min, int med, int max) {
    int i = min, j = med + 1, k = 0;
    int size = max - min + 1;
    while (i <= med && j <= max) {
        if (a[i] <= a[j]) {
            fuck[k++] = a[i++];
        } else {
            fuck[k++] = a[j++];
            count += med - i + 1;
        }
    }
    while (i <= med) fuck[k++] = a[i++];
    while (j <= max) fuck[k++] = a[j++];
    for (int k = 0; k < size; k++) {
        a[min + k] = fuck[k];
    }
}

void findCount(int *a, int min, int max) {
    if (min == max) return;
    int med = (min + max) / 2;
    findCount(a, min, med);
    findCount(a, med + 1, max);
    CountWhileSort(a, min, med, max);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        count
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        findCount(a, 0, n - 1);
        printf("%lld\n", count);
    }
}
