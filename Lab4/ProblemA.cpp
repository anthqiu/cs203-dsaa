#include <iostream>
#include <stack>

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        std::string fuck;
        std::cin >> fuck;
        int shit = fuck.size();
        std::stack<char> s;
        std::stack<char> d;
        d.push('l');
        d.push('a');
        d.push('n');
        d.push('r');
        d.push('a');
        d.push('n');
        if (shit < 6) {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < shit; i++) {
            s.push(fuck[i]);
        }
        while (!s.empty()) {
            if (d.empty()) {
                break;
            }
            if (s.top() == d.top()) {
                d.pop();
            }
            s.pop();
        }
        if (!d.empty()) printf("NO\n");
        else printf("YES\n");
    }
}