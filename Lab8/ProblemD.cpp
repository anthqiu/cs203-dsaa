#include <iostream>
#include <cstring>

void work() {
    int n, m, s = 4;
    scanf("%d%d", &n, &m);
    bool a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            a[i][j] = false;
        }
    }
    int x, y;
    while (m-- > 0) {
        scanf("%d%d", &x, &y);
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        a[x][y] = true;
    }
    int count = 0;
    for (int i = 1; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            for (int k = j + 1; k <= n - 1; k++) {
                for (int p = k + 1; p <= n; p++) {
                    if (a[i][j] == true && a[i][k] == true &&
                        a[i][p] == true && a[j][k] == true &&
                        a[j][p] == true && a[k][p] == true)
                        count++;
                }
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) work();
}