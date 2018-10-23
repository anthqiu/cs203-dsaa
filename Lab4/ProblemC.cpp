//
// Created by antsy on 2018/9/29.
//

#include <iostream>
#include <queue>

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::queue<int> A;
        int operate = 1;
        long long result = 0;
        bool has = false;
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            A.push(tmp);
            while (tmp - A.front() > m && A.size() > 0)
                A.pop();
            result += (A.size() - 1) * (A.size() - 2) / 2;
        }
        printf("%lld\n", result);
    }
}
