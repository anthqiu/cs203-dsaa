#include <iostream>

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = 0;
            }
        }
        int start, end;
        while (m-- > 0) {
            scanf("%d%d", &start, &end);
            a[start][end] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
}