//
// Created by antsy on 2018/10/4.
//

#include <iostream>
#include <stack>

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        std::stack<int> min, max, seq;
        int n;
        scanf("%d", &n);
        int last;
        for (int i = 0; i < n; i++) {
            char op[4];
            scanf("%4s", op);
            if (op[1] == 'u') {
                int m;
                scanf("%d", &m);
                seq.push(m);
                if (min.empty() || min.top() >= m) min.push(m);
                if (max.empty() || max.top() <= m) max.push(m);
            } else if (op[1] == 'o') {
                if (seq.size() <= 1) {
                    printf("0\n");
                } else {
                    if (seq.top() == min.top()) min.pop();
                    if (seq.top() == max.top()) max.pop();
                    seq.pop();
                    printf("%d\n", max.top() - min.top());
                }
            }
        }
    }
}
