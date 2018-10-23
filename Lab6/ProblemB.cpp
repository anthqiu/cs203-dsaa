

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int count = 1;
        while (count > m) {
            int b[n];
            int mid = a[m];
            int min = 0;
            int max = n - 1;
            for (int i = 0; i < n; i++) {
                if (a[i] < mid) {
                    b[min++] = a[i];
                    count++;
                } else if (a[i] > mid) {

                }
            }
        }
        printf("%d\n", a[m]);
    }
}
