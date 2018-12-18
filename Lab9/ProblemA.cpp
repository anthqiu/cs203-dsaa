#include <iostream>

int a[1010][2];

void read() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }
}

void work() {
    int Q;
    scanf("%d", &Q);
    int x, y, dx, dy;
    while (Q-- > 0) {
        scanf("%d%d", &x, &y);
        dx = a[x][0] > a[y][0] ? a[x][0] - a[y][0] : a[y][0] - a[x][0];
        dy = a[x][1] > a[y][1] ? a[x][1] - a[y][1] : a[y][1] - a[x][1];
        printf("%d\n", dx + dy);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        read();
        work();
    }
}