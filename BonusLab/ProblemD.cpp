//
// Created by ayau on 10/25/18.
//

#include <iostream>

int _lis(int arr[], int n, int *min_ref) {
    if (n == 1)
        return 1;
    int res, min_ending_here = 1;
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, min_ref);
        if (arr[i - 1] > arr[n - 1] && res + 1 > min_ending_here)
            min_ending_here = res + 1;
    }
    if (*min_ref < min_ending_here)
        *min_ref = min_ending_here;
    return min_ending_here;
}

int lis(int arr[], int n) {
    int min = 1;
    _lis(arr, n, &min);
    return min;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%s\n", lis(a, n) > 2 ? "N" : "Y");
    }
}