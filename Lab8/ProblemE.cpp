#include <iostream>
#include <vector>

using namespace std;

short int matrix[1010][1010];
bool color[1010][1010];
int n, m;

struct pos {
    int x_pos;
    int y_pos;

    pos(int x, int y) {
        x_pos = x;
        y_pos = y;
    }

    pos() {
        x_pos = y_pos = 0;
    }
};

vector<pos> graph[1010][1010];

void reset() {
    for (int i = 1; i < 1010; i++) {
        for (int j = 1; j < 1010; j++) {
            matrix[i][j] = 0;
            color[i][j] = false;
            graph[i][j].clear();
        }
    }
    n = 0, m = 0;
}

void SearchAndTagAsRed(int x, int y) {
    color[x][y] = true;
    //printf("(%d,%d) ", x, y);
    for (pos a:graph[x][y]) {
        int a_x = a.x_pos;
        int a_y = a.y_pos;
        if (!color[a_x][a_y]) SearchAndTagAsRed(a_x, a_y);
    }
}

void work() {
    reset();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%4d", &matrix[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != 1 && matrix[i][j] == matrix[i - 1][j]) {
                pos a;
                a.x_pos = i - 1;
                a.y_pos = j;
                graph[i][j].push_back(a);
            }
            if (i != n && matrix[i][j] == matrix[i + 1][j]) {
                pos a;
                a.x_pos = i + 1;
                a.y_pos = j;
                graph[i][j].push_back(a);
            }
            if (j != 1 && matrix[i][j] == matrix[i][j - 1]) {
                pos a;
                a.x_pos = i;
                a.y_pos = j - 1;
                graph[i][j].push_back(a);
            }
            if (j != m && matrix[i][j] == matrix[i][j + 1]) {
                pos a;
                a.x_pos = i;
                a.y_pos = j + 1;
                graph[i][j].push_back(a);
            }
        }
        if (matrix[i][1] == matrix[i][m]) {
            pos a;
            a.x_pos = i;
            a.y_pos = m;
            graph[i][1].push_back(a);
            a.y_pos = 1;
            graph[i][m].push_back(a);
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (color[i][j] == 0) {
                SearchAndTagAsRed(i, j);
                count++;
                //printf("\n");
            }
        }
    }
    printf("%d\n", count);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) work();
}
