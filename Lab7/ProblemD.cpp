/* this code is redundant. please refer to ProblemD_using_Heap.cpp in the same folder. this is a backup branch.
 * */

#include <iostream>
#include <vector>

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

vector<int> inOrderKeySet;

void swap(Node *node1, Node *node2) {
    int tmpKey = node1->key;
    node1->key = node2->key;
    node2->key = tmpKey;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n, k;
        scanf("%d%d", &n, &k);
        int rootNodeValue;
        scanf("%d", &rootNodeValue);
        Node *rootNode = new Node(rootNodeValue);
        if (k <= 5000 && k < 0.99 * n) {
            for (int i = 1; i < k; i++) {
                int thisNodeValue;
                scanf("%d", &thisNodeValue);
                Node *nowJudging = rootNode;
                while (nowJudging != nullptr) {
                    Node *adding = new Node(thisNodeValue);
                    int nowNodeValue = nowJudging->key;
                    if (thisNodeValue > nowNodeValue) {
                        if (nowJudging->left == nullptr) {
                            nowJudging->left = adding;
                            break;
                        }
                        nowJudging = nowJudging->left;
                    } else {
                        if (nowJudging->right == nullptr) {
                            nowJudging->right = adding;
                            break;
                        }
                        nowJudging = nowJudging->right;
                    }
                }
            }
            //TODO: 把最左的右儿子替换到这个节点上
            Node *leftMostNode = rootNode;
            while (leftMostNode->left != nullptr) leftMostNode = leftMostNode->left;
            int minKey = leftMostNode->key;
            for (int i = k; i < n; i++) {
                int thisNodeValue;
                scanf("%d", &thisNodeValue);
                if (thisNodeValue < minKey) continue;
                leftMostNode->parent->left = nullptr;
                Node *nowJudging = rootNode;
                while (nowJudging != nullptr) {
                    Node *adding = new Node(thisNodeValue);
                    int nowNodeValue = nowJudging->key;
                    if (thisNodeValue > nowNodeValue) {
                        if (nowJudging->left == nullptr) {
                            nowJudging->left = adding;
                            break;
                        }
                        nowJudging = nowJudging->left;
                    } else {
                        if (nowJudging->right == nullptr) {
                            nowJudging->right = adding;
                            break;
                        }
                        nowJudging = nowJudging->right;
                    }
                }
                leftMostNode = rootNode;
                while (leftMostNode->left != nullptr) leftMostNode = leftMostNode->left;
            }
            printf("%d\n", &leftMostNode->key);
        } else {
            for (int i = 1; i < n - k + 1; i++) {
                int thisNodeValue;
                scanf("%d", &thisNodeValue);
                Node *nowJudging = rootNode;
                while (nowJudging != nullptr) {
                    Node *adding = new Node(thisNodeValue);
                    int nowNodeValue = nowJudging->key;
                    if (thisNodeValue > nowNodeValue) {
                        if (nowJudging->left == nullptr) {
                            nowJudging->left = adding;
                            break;
                        }
                        nowJudging = nowJudging->left;
                    } else {
                        if (nowJudging->right == nullptr) {
                            nowJudging->right = adding;
                            break;
                        }
                        nowJudging = nowJudging->right;
                    }
                }
            }
            Node *rightMostNode = rootNode;
            while (rightMostNode->right != nullptr) rightMostNode = rightMostNode->right;
            int maxKey = rightMostNode->key;
            for (int i = n - k + 1; i < n; i++) {
                int thisNodeValue;
                scanf("%d", &thisNodeValue);
                if (thisNodeValue < maxKey) continue;
                rightMostNode->parent->left = nullptr;
                Node *nowJudging = rootNode;
                while (nowJudging != nullptr) {
                    Node *adding = new Node(thisNodeValue);
                    int nowNodeValue = nowJudging->key;
                    if (thisNodeValue > nowNodeValue) {
                        if (nowJudging->left == nullptr) {
                            nowJudging->left = adding;
                            break;
                        }
                        nowJudging = nowJudging->left;
                    } else {
                        if (nowJudging->right == nullptr) {
                            nowJudging->right = adding;
                            break;
                        }
                        nowJudging = nowJudging->right;
                    }
                }
                rightMostNode = rootNode;
                while (rightMostNode->left != nullptr) rightMostNode = rightMostNode->left;
            }
            printf("%d\n", &rightMostNode->key);
        }
    }
}