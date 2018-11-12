//
// Created by antsy on 11/11/2018.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int black[n + 1];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &black[i]);
        }
        int tree[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int father, son;
            scanf("%d%d", &father, &son);
            tree[son] = father;
        }
        int level[n + 1];
        int maxlev = 1;
        for (int i = 1; i <= n; i++) {
            int tmp = tree[i], lev = 1;
            while (tmp != 0) {
                lev++;
                tmp = tree[tmp];
            }
            level[i] = lev;
            maxlev = maxlev < lev ? lev : maxlev;
        }
        bool fuck = false;
        for (int i = 1; i <= maxlev; i++) {
            int b = 0;
            for (int j = 1; j <= n; j++) {
                if (level[j] == i) b += black[j];
            }
            if (b % 2 == 1) {
                printf("YES\n");
                fuck = true;
                break;
            }
        }
        if (!fuck) printf("NO\n");
    }
}
