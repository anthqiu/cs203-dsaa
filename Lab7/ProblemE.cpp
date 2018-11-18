#include <cstdio>

using namespace std;

struct MinHeap {
    int a[100001];

    int count;

    MinHeap() {
        count = 0;
    }

    void add(int item) {
        a[++count] = item;
        int k = count;
        while (k > 1 && a[k / 2] > a[k]) {
            swap(k / 2, k);
            k = k / 2;
        }
    };

    void swap(int i_pos, int j_pos) {
        int tmp = a[i_pos];
        a[i_pos] = a[j_pos];
        a[j_pos] = tmp;
    }

    int rem() {
        int rt = a[1];
        swap(1, count);
        count--;
        int k = 1;
        while (2 * k <= count) {
            int j = 2 * k;
            if (j < count && a[j] > a[j + 1]) j++;
            if (a[k] > a[j]) {
                swap(j, k);
                k = j;
            } else break;
        }
        return rt;
    };

    int query() {
        if (count != 0)return a[1];
    };
};

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, k;
        scanf("%d%d", &n, &k);
        MinHeap mheap;
        int a[n];
        for (int i = 0; i < k; i++) {
            int tmp;
            scanf("%d", &tmp);
            mheap.add(tmp);
        }
        for (int i = k; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (tmp < mheap.query()) {
                printf("%d ", tmp);
            } else {
                printf("%d ", mheap.rem());
                mheap.add(tmp);
            }
        }
        while (mheap.count > 1) {
            printf("%d ", mheap.rem());
        }
        printf("%d\n", mheap.rem());
    }
}
