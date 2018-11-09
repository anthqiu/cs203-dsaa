//
// Created by antsy on 11/9/2018.
//

#include <iostream>

int a[100001];

struct Set {
    int count;

    Set() {
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

    void rem() {
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
    };

    int query() {
        if (count != 0)return a[1];
    };
};

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        Set set;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            set.add(tmp);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            switch (tmp) {
                case 1:
                    int item;
                    scanf("%d", &item);
                    set.add(item);
                    break;
                case 2:
                    set.rem();
                    break;
                case 3:
                    printf("%d\n", set.query());
                    break;
            }
        }
    }
}