//
// Created by ayau on 10/29/18.
//
#include <iostream>

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int p, c;
            scanf("%d%d", &p, &c);
            a[c - 1]++;
            a[p - 1]++;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    }
}