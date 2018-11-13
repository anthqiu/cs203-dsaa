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

int findNodeHeight(Node *node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    int leftHeight = findNodeHeight(node->left);
    int rightHeight = findNodeHeight(node->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

bool isInvalidAVLTree(Node *node) {
    if (node == nullptr)
        return false;
    int leftHeight = findNodeHeight(node->left);
    int rightHeight = findNodeHeight(node->right);
    int diff = leftHeight - rightHeight;
    if (diff <= 1 && diff >= -1) {
        bool left = isInvalidAVLTree(node->left);
        bool right = isInvalidAVLTree(node->right);
        return left || right;
    } else
        return true;
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
        for (int i = 1; i <= n; i++) {
            int left, right;
            scanf("%d%d", &left, &right);
            if (left != 0) {
                nodes[i]->left = nodes[left];
                nodes[left]->parent = nodes[i];
            }
            if (right != 0) {
                nodes[i]->right = nodes[right];
                nodes[right]->parent = nodes[i];
            }
        }
        Node *rootNode = nodes[1];
        while (rootNode->parent != nullptr) rootNode = rootNode->parent;
        inOrderKeySet.clear();
        inOrder(rootNode);
        bool isInvalidBinarySearchTree = false;
        for (int i = 0; i < n - 1; i++) {
            if (inOrderKeySet[i] >= inOrderKeySet[i + 1]) {
                isInvalidBinarySearchTree = true;
                break;
            }
        }
        if (!isInvalidBinarySearchTree) {
            if (isInvalidAVLTree(rootNode))
                printf("No\n");
            else
                printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

/*
 1
 2
 */

/*
 2
 2
 1 2
 2 0
 0 0
 2
 1 2
 0 2
 0 0
 */

/*
 1
 10
 1 2 3 4 5 6 7 8 9 10
 0 0
 1 4
 0 0
 3 0
 2 7
 0 0
 6 10
 0 0
 8 0
 9 0
 */
