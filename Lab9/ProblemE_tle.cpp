#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

struct Node {
    vector<int> next;
    int inDegree = 0;
};

priority_queue<int, vector<int>, greater<int>> output;

Node graph[10000];

inline void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; i++) {
        int v, w;
        scanf("%d%d", &v, &w);
        graph[v].next.push_back(w);
        graph[w].inDegree++;
    }
    for (int i = 1; i <= n; i++) {
        if (graph[i].inDegree == 0) {
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
        for (int i:graph[t].next) {
            graph[i].inDegree--;
            if (graph[i].inDegree == 0) output.push(i);
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
