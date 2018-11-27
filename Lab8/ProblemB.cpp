#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int key;
    vector<Node *> next;

    Node(int k) {
        key = k;
    }
};

bool isConnected(Node *start, Node *end, int n) {
    int status[n + 1];
    for (int i = 1; i <= n; i++) {
        status[i] = 0;
    }
    queue<Node *> operation;
    operation.push(start);
    status[start->key] = 1;
    while (!operation.empty()) {
        Node *op = operation.front();
        for (Node *a:op->next) {
            if (a->key == end->key) return true;
            if (status[a->key] == 0) {
                operation.push(a);
                status[a->key] = 1;
            }
        }
        status[op->key] = 2;
        operation.pop();
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        Node *a[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = new Node(i);
        }
        int start, end;
        while (m-- > 0) {
            scanf("%d%d", &start, &end);
            a[start]->next.push_back(a[end]);
        }
        int Q;
        scanf("%d", &Q);
        while (Q-- > 0) {
            scanf("%d%d", &start, &end);
            bool is = isConnected(a[start], a[end], n);
            printf("%s", is ? "YES\n" : "NO\n");
        }
    }
}
