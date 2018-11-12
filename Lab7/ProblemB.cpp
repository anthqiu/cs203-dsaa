#include <iostream>
#include <queue>

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

Node *nodes[1000000];
vector<int> inOrderKeySet;

void inOrder(Node *node) {
    if (node == nullptr) return;
    inOrder(node->left);
    inOrderKeySet.push_back(node->key);
    inOrder(node->right);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            nodes[i] = new Node(tmp);
        }
        bool isInvalidBinarySearchTree = false;
        for (int i = 0; i < n - 1; i++) {
            int parent, son;
            scanf("%d%d", &parent, &son);
            int parentKey = nodes[parent]->key;
            int sonKey = nodes[son]->key;
            if (sonKey < parentKey && nodes[parent]->left == nullptr)
                nodes[parent]->left = nodes[son];
            else if (sonKey > parentKey && nodes[parent]->right == nullptr)
                nodes[parent]->right = nodes[son];
            else {
                isInvalidBinarySearchTree = true;
            }
            nodes[son]->parent = nodes[parent];
        }
        if (!isInvalidBinarySearchTree) {
            Node *rootNode = nodes[1];
            while (rootNode->parent != nullptr) rootNode = rootNode->parent;
            inOrderKeySet.clear();
            inOrder(rootNode);
            for (int i = 0; i < n - 1; i++) {
                if (inOrderKeySet[i] > inOrderKeySet[i + 1]) {
                    isInvalidBinarySearchTree = true;
                    break;
                }
            }
        }
        if (isInvalidBinarySearchTree) {
            printf("Case #%d: NO\n", t);
        } else {
            printf("Case #%d: YES\n", t);
        }
    }
}
