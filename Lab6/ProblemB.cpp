

int find(const int a[], int s, int e, int k) {
    int size = e - s + 1;
    int mid = (e - s) / 2;
    int ak = a[mid];
    int b[size];
    int big = size - 1, small = 0;
    for (int i = s; i <= e; i++) {
        if (a[i] > ak) b[big--] = a[i];
        else if (a[i] < ak) b[small++] = a[i];
    }
    int i = small;
    while (i <= big) {
        b[i++] = ak;
    }
    if (small <= k - 1 && big >= k - 1) {
        return ak;
    }
    if (small > k - 1) {
        return find(b, 0, small, k);
    }
    if (big < k - 1) {
        big = big >= 0 ? big : 0;
        return find(b, big, size - 1, k - big);
    }
}

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
        int res = find(a, 0, n - 1, m);
        printf("%d\n", res);
    }
}
