#include <iostream>
#include <queue>

using namespace std;

struct node {
    int key;
    node *parent;
    node *left;
    node *right;

    node() {
        key = 0;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        node a[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i].key = i;
            a[i].parent = nullptr;
            a[i].left = nullptr;
            a[i].right = nullptr;
        }
        for (int i = 1; i <= n; i++) {
            int b, c;
            scanf("%d%d", &b, &c);
            a[i].left = &a[b];
            a[i].right = &a[c];
            a[b].parent = &a[i];
            a[c].parent = &a[i];
        }
        node *root = &a[1];
        while (root->parent != nullptr) root = root->parent;
        queue<node *> c;
        c.push(root);
        while (c.front()->key != 0) {
            node *a = c.front()->left;
            if (a == nullptr) c.push(new node());
            else c.push(a);
            a = c.front()->right;
            if (a == nullptr) c.push(new node());
            else c.push(a);
            c.pop();
        }
        if (c.empty()) {
            printf("Yes\n");
        } else {
            bool empty = true;
            while (!c.empty()) {
                if (c.front()->key != 0) {
                    empty = false;
                    break;
                }
                c.pop();
            }
            if (empty) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}
