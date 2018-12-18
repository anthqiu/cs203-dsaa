#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
    int key;
    vector<int> len;
    int visit = 0;
    int father = 0;
    vector<Node> son;
};

int Max[100001];

void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    Node matrix[n + 1];
    int Max[n + 1];
    memset(Max, 0, sizeof(Max));
    for (int i = 1; i <= n; i++) {
        matrix[i].key = i;
    }
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        matrix[x].son.push_back(matrix[y]);
        matrix[y].father++;
        matrix[x].len.push_back(w);
    }
    queue<Node> q;
    for (int i = 1; i <= n; i++) {
        if (matrix[i].father == 0) q.push(matrix[i]);
    }
    while (!q.empty()) {
        Node tmp = q.front();
        q.pop();
        for (Node ttmp:tmp.son) {
            ttmp.father--;
        }
        int l = (int) tmp.son.size();
        for (int i = 0; i < l; i++) {
            Node ttmp = tmp.son[i];
            if (ttmp.father == 0) {
                q.push(tmp.son[i]);
            }
            int len = tmp.len[i];
            if (Max[ttmp.key] <= len + Max[tmp.key]) {
                Max[ttmp.key] = len + Max[tmp.key];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = ans > Max[i] ? ans : Max[i];
    }
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) work();
}
