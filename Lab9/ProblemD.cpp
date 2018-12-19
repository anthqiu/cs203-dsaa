#include <stdio.h>
#include <queue>

using namespace std;



struct Edge {
    int v, w;
    int weight;
};

class UF {
private:
    vector<int> uf;
    vector<int> rank;
public:
    UF(int n) {
        for (int i = 0; i <= n; i++) {
            uf.push_back(i);
            rank.push_back(1);
        }
    }

//    int find(int x) {
//        if (uf[x] == x) return x;
//        else return find(uf[x]);
//    }
//  new find() by xiaoming
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
        return true;
    }
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

void work() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int gs = m + k;
    priority_queue<Edge> graph;
    Edge tmp;
    while (gs-- > 0) {
        scanf("%d%d%d", &tmp.v, &tmp.w, &tmp.weight);
        graph.push(tmp);
    }
    UF *uf = new UF(n);
    long long result = 0;
    int count = 0;
    while (count < n - 1) {
        if (graph.empty()) {
            printf("%d\n", -1);
            return;
        }
        tmp = graph.top();
        graph.pop();
        if (uf->connect(tmp.v, tmp.w)) {
            result += tmp.weight;
            count++;
        }
    }
    printf("%lld\n", result);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        work();
    }
}
