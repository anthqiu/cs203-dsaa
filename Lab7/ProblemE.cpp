#include <cstdio>

using namespace std;

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;

    explicit Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

void *buildTree(int n, Node *a[]) {
    int t = n / 2;
    for (int i = 1; i < t; i++) {
        a[i]->left = a[2 * i];
        a[i]->right = a[2 * i + 1];
        a[2 * i]->parent = a[i];
        a[2 * i + 1]->parent = a[i];
    }
    if (n % 2 == 0) {
        a[t]->left = a[n];
        a[n]->parent = a[t];
    } else {
        a[t]->left = a[n - 1];
        a[t]->right = a[n];
        a[n - 1]->parent = a[t];
        a[n]->parent = a[t];
    }
}

void inOrder(Node *a) {
    Node *node = &a[1];
    if (node == nullptr) return;
    inOrder(node->left);
    scanf("%d", &node->key);
    inOrder(node->right);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        Node *a[n + 1];
        buildTree(n, a);

    }
}