//
// Created by antsy on 2018/9/30.
//

#include<cstdio>

using namespace std;
int a[1000000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int l = 1;
        int r = 1;
        long long ans = 0;
        bool t = true;
        while (r < n) {
            r++;
            while (l < r && a[r] - a[l] > m) {
                l++;
            }
            ans += (r - 1 - l) * (r - l) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
