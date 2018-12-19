#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct Edge {
    int v, w;
    int weight;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

class UF {
private:
    vector<int> uf;
    vector<int> rank;
    int count;
public:
    UF(int n) {
        for (int i = 0; i <= n; i++) {
            uf.push_back(i);
            rank.push_back(1);
        }
        count = n;
    }

    int find(int x) {
        int tmp;
        while (x != uf[x]) {
            tmp = x;
            x = uf[x];
            uf[tmp] = uf[x];
        }
        return x;
    }

    bool connect(int m, int n) {
        int fm = find(m), fn = find(n);
        if (fm == fn) return false;
        if (rank[m] < rank[n]) {
            rank[fn] += rank[fm];
            uf[fm] = fn;
        } else {
            rank[fm] += rank[fn];
            uf[fn] = fm;
        }
        count--;
        return true;
    }

    int getCount() {
        return count;
    }
};

int connected(int n, int m, priority_queue<Edge> graph) {
    int count = 0;
    while (!graph.empty() && graph.top().weight < m) graph.pop();
    UF *uf = new UF(n);
//    while (!graph.empty()&&uf->getCount() != 1) {
//        Edge tmp = graph.top();
//        graph.pop();
//        uf->connect(tmp.v, tmp.w);
//        count += tmp.weight;
//    }
    int result = 0;
    Edge tmp;
    while (count < n - 1) {
        if (graph.empty()) {
            return -1;
        }
        tmp = graph.top();
        graph.pop();
        if (uf->connect(tmp.v, tmp.w)) {
            result += tmp.weight;
            count++;
        }
    }
    return result;
}

void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue<Edge> graph;
    Edge tmp;
    int maxWeight = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &tmp.v, &tmp.w, &tmp.weight);
        graph.push(tmp);
        maxWeight = maxWeight < tmp.weight ? tmp.weight : maxWeight;
    }
    int begin = 0, end = maxWeight;
    int result = 0;
    while (end != begin) {
        int mid = begin + (end - begin) / 2 + 1;
        result = connected(n, mid, graph);
        if (result > 0) {
            begin = mid;
        } else {
            end = mid - 1;
        }
    }
    printf("%d\n", connected(n, begin, graph));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        work();
    }
}
