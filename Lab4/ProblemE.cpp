//
// Created by antsy on 2018/9/30.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (; T > 0; T--) {
        int n;
        cin >> n;
        int seq[n], s_min[n], s_min_pos[n];
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
        }
        s_min[n - 1] = seq[n - 1];
        s_min_pos[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s_min[i + 1] < seq[i]) s_min[i] = s_min[i + 1], s_min_pos[i] = s_min_pos[i + 1];
            else s_min[i] = seq[i], s_min_pos[i] = i;
        }
        stack<int> res;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (res.empty() || res.top() > s_min[j])
                for (int k = s_min_pos[j]; j <= k; j++)
                    res.push(seq[j]);
            printf("%d%c", res.top(), i < n - 1 ? ' ' : '\n'),
                    res.pop();
        }
    }
}
