#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

struct Edge {
    int next = -1;
    int to = -1;
};

void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    Edge graph[m];
    int head[n + 1];
    fill(head, head + n + 1, -1);
    int inDegree[n + 1];
    fill(inDegree, inDegree + n + 1, 0);
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        graph[i].to = w;
        graph[i].next = head[v];
        head[v] = i;
        inDegree[w]++;
    }
    priority_queue<int, vector<int>, greater<int>> output;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            output.push(i);
        }
    }
    int count = 0;
    int mem[n + 1];
    while (!output.empty()) {
        int t = output.top();
        output.pop();
        count++;
        mem[count] = t;
        int now = head[t];
        while (now >= 0) {
            int fuck = graph[now].to;
            inDegree[fuck]--;
            if (inDegree[fuck] == 0) output.push(fuck);
            now = graph[now].next;
        }
    }
    if (count == n)
        for (int i = 1; i <= n; i++) {
            printf("%d ", mem[i]);
        }
    else printf("impossible");
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        work();
    }
}