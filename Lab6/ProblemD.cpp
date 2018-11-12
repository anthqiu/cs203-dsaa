//
// Created by ayau on 10/29/18.
//
#include <iostream>
#include <vector>

using namespace std;

int findDistance(const int *a, int node1, int node2) {
    if (node1 == node2)
        return 0;
    vector<int> n1, n2;
    int i = node1, m = 0, n = 0;
    n1.push_back(node1);
    while (a[i] != -1) {
        i = a[i];
        m++;
        n1.push_back(i);
    }
    i = node2;
    n2.push_back(node2);
    while (a[i] != -1) {
        i = a[i];
        n++;
        n2.push_back(i);
    }
    for (i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (n1[i] == n2[j])
                return i + j;
        }
    }
    return -1;
}

void findLeaves(const int *a, int a_size, vector<int> *leaves) {
    for (int i = 1; i <= a_size; i++) {
        if (a[i] == -1) leaves->push_back(i);
    }
}

int findMaxDisLeave(const int *a, const vector<int> *leaves, int leaves_size, int leave, bool returnValue) {
    int max = 0, le = leaves->at(0);
    for (int i = 0; i < leaves_size; i++) {
        int tmp = leaves->at(i);
        int fuck = findDistance(a, leave, tmp);
        if (max < fuck) {
            max = fuck;
            le = tmp;
        }
    }
    if (returnValue) return max;
    return le;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int a[n + 1], b[n + 1];
        for (int i = 0; i < n + 1; i++) {
            a[i] = -1;
            b[i] = -1;
        }
        for (int i = 1; i < n; i++) {
            int father, son;
            scanf("%d%d", &father, &son);
            a[son] = father;
            b[father] = 0;
        }
        vector<int> leaves;
        findLeaves(b, n, &leaves);
        int size = (int) leaves.size();
        int node1 = findMaxDisLeave(a, &leaves, size, leaves[0], false);
        int fuck = findMaxDisLeave(a, &leaves, size, node1, true);
        printf("%d\n", fuck);
    }
}
