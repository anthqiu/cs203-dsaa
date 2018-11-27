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

void printMinLength(Node *start, int n) {
    int status[n + 1];
    int length[n + 1];
    for (int i = 1; i <= n; i++) {
        status[i] = 0;
        length[i] = -1;
    }
    queue<Node *> operation;
    operation.push(start);
    status[start->key] = 1;
    length[start->key] = 0;
    while (!operation.empty()) {
        Node *op = operation.front();
        for (Node *a:op->next) {
            if (status[a->key] == 0) {
                operation.push(a);
                length[a->key] = length[op->key] + 1;
                status[a->key] = 1;
            }
        }
        status[op->key] = 2;
        operation.pop();
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%s", length[i], i == n ? "\n" : " ");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m, ii;
        scanf("%d%d%d", &n, &m, &ii);
        Node *a[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = new Node(i);
        }
        int start, end;
        while (m-- > 0) {
            scanf("%d%d", &start, &end);
            a[start]->next.push_back(a[end]);
            a[end]->next.push_back(a[start]);
        }
        printMinLength(a[ii], n);
        for (int i = 0; i <= n; i++) {
            free(a[i]);
        }
    }
}
