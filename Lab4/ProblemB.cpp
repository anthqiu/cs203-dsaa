//
// Created by antsy on 2018/9/29.
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (; T > 0; T--) {
        int n;
        string a;
        cin >> n >> a;
        if (n % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        stack<char> s;
        bool fuck = false;
        int q = 0;
        for (int i = 0; i < n; i++) {
            char p = a[i];
            if (p == '(' || p == '[' || p == '{') {
                s.push(a[i]);
                q++;
                continue;
            }
            if (!s.empty() &&
                !((s.top() == '(' && p == ')') || (s.top() == '[' && p == ']') || (s.top() == '{' && p == '}'))) {
                fuck = true;
                break;
            } else if (!s.empty() && ((s.top() == '(' && p == ')') || (s.top() == '[' && p == ']') ||
                                      (s.top() == '{' && p == '}'))) {
                s.pop();
            }
        }
        if (fuck || q == 0) cout << "NO" << endl;
        else if (!s.empty()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
