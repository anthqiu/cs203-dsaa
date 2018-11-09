//
// Created by ayau on 10/29/18.
//
#include <iostream>

void OutputPreOrder(int a[][2], int node) {
    if (node == -1) return;
    std::cout << node + 1 << " ";
    OutputPreOrder(a, a[node][0]);
    OutputPreOrder(a, a[node][1]);
}

void OutputInOrder(int a[][2], int node) {
    if (node == -1) return;
    OutputInOrder(a, a[node][0]);
    std::cout << node + 1 << " ";
    OutputInOrder(a, a[node][1]);
}

void OutputPostOrder(int a[][2], int node) {
    if (node == -1) return;
    OutputPostOrder(a, a[node][0]);
    OutputPostOrder(a, a[node][1]);
    std::cout << node + 1 << " ";
}


int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        int a[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j] = -1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int p, s;
            scanf("%d%d", &p, &s);
            if (a[p - 1][0] == -1) a[p - 1][0] = s - 1;
            else a[p - 1][1] = s - 1;
        }
        OutputPreOrder(a, 0);
        std::cout << std::endl;
        OutputInOrder(a, 0);
        std::cout << std::endl;
        OutputPostOrder(a, 0);
        std::cout << std::endl;
    }
}