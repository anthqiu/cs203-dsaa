#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

struct Edge {
    int v, w;
    int weight;

    Edge(int v, int w, int weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }

    Edge() {
        v = w = weight = -1;
    }
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

class EdgeWeightedGraph {
private:
    priority_queue<Edge> *g;
    int n;
    int minWeight, minV, minW;
public:
    EdgeWeightedGraph(int n) {
        this->n = n;
        this->g = new priority_queue<Edge>[n + 1];
        minV = minW = -1;
        minWeight = 1000000;
    }

    void AddEdge(int v, int w, int weight) {
        Edge tmp;
        tmp.w = w;
        tmp.v = v;
        tmp.weight = weight;
        g[v].push(tmp);
        g[w].push(tmp);
        if (weight < minWeight) {
            minWeight = weight;
            minW = w, minV = v;
        }
    }

    priority_queue<Edge> getEdges(int i) {
        return g[i];
    }

    Edge *getMin() {
        return new Edge(minV, minW, minWeight);
    }
};

void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    auto *graph = new EdgeWeightedGraph(n);
    while (m-- > 0) {
        int v, w, weight;
        scanf("%d%d%d", &v, &w, &weight);
        graph->AddEdge(v, w, weight);
    }
    Edge *min = graph->getMin();
    int count = 2;
    bool fucked[n + 1];
    memset(fucked, 0, sizeof(fucked));
    fucked[min->v] = fucked[min->w] = true;
    int result = min->weight;
    Edge best[n + 1];
    memset(best, 0, sizeof(best));
    Edge Tmp;
    Tmp.v = Tmp.w = -1, Tmp.weight = 100000;
    best[0] = Tmp;
    for (int i = 1; i <= n; i++) {
        if (fucked[i]) {
            best[i] = Tmp;
            continue;
        };
        priority_queue<Edge> tmp = graph->getEdges(i);
        bool marked = false;
        while (!tmp.empty()) {
            if (fucked[tmp.top().v] || fucked[tmp.top().w]) {
                best[i] = tmp.top();
                marked = true;
                break;
            }
            tmp.pop();
        }
        if (!marked) {
            best[i] = Tmp;
        }
    }
    while (count < n) {
        priority_queue<Edge> Min;
        for (Edge fuck : best) {
            if (fuck.weight < 100000) Min.push(fuck);
        }
        Edge mmin = Min.top();
        count++;
        result += mmin.weight;
        int i = fucked[mmin.v] ? mmin.w : mmin.v;
        priority_queue<Edge> tmp = graph->getEdges(i);
        fucked[i] = true;
        best[i].weight = 100000;
        while (!tmp.empty()) {
            if (!(fucked[tmp.top().v] && fucked[tmp.top().w])) {
                int j = fucked[tmp.top().v] ? tmp.top().w : tmp.top().v;
                if (tmp.top().weight < best[j].weight) best[j] = tmp.top();
            }
            tmp.pop();
        }
    }
    printf("%d\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        work();
    }
}

/*
 1
 7 8
 1 3 2
 1 6 2
 3 6 2
 2 3 4
 2 7 3
 4 7 1
 2 4 5
 3 5 2
 */