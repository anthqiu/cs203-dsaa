#include <iostream>

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int max = -1;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            max = a > max ? a : max;
        }
        printf("%d\n", max);
    }
}