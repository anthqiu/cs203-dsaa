//
// Created by antsy on 2018/9/30.
//
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (; T > 0; T--) {
        int n, m;
        cin >> n >> m;
        char maze[n][m];
        int map = 0;
        int S[2];
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++) {
                maze[i][j] = tmp[j];
                if (tmp[j] == 'S') {
                    S[0] = i;
                    S[1] = j;
                }
            }
        }
        string dir;
        cin >> dir;
        int len = dir.size();
        bool flag;
        char mm[]{'0', '1', '2', '3'};
        for (char up:mm) {
            for (char down:mm) {
                for (char left:mm) {
                    for (char right:mm) {
                        if (up == down || up == left || up == right || down == left || down == right ||
                            left == right)
                            continue;
                        int x = S[0], y = S[1];
                        flag = false;
                        for (int i = 0; i < len; i++) {
                            if (dir[i] == up) {
                                if (x > 0) x--; else break;
                                if (maze[x][y] == '#') break;
                                if (maze[x][y] == 'E') {
                                    flag = true;
                                    break;
                                }
                            } else if (dir[i] == down) {
                                if (x < n - 1) x++; else break;
                                if (maze[x][y] == '#') break;
                                if (maze[x][y] == 'E') {
                                    flag = true;
                                    break;
                                }
                            } else if (dir[i] == left) {
                                if (y > 0) y--; else break;
                                if (maze[x][y] == '#') break;
                                if (maze[x][y] == 'E') {
                                    flag = true;
                                    break;
                                }
                            } else if (dir[i] == right) {
                                if (y < m - 1) y++; else break;
                                if (maze[x][y] == '#') break;
                                if (maze[x][y] == 'E') {
                                    flag = true;
                                    break;
                                }
                            }
                        }
                        if (flag) map++;
                    }
                }
            }
        }
        printf("%d\n", map);
    }
}