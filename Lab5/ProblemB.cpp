#include <iostream>

using namespace std;

int kmpSearch(string p, string t, int positionAfterThis) {
    int plen = (int) p.size();
    int tlen = (int) t.size();
    int ppos = 1, tpos = 0;
    int pmt[plen + 1], shift = 0;
    pmt[0] = -1;
    while (ppos < plen) {
        if (p[ppos] == p[shift]) {
            pmt[ppos] = pmt[shift];
            shift++;
            ppos++;
        } else {
            pmt[ppos] = shift;
            shift = pmt[shift];
            while (shift >= 0 && p[ppos] != p[shift]) shift = pmt[shift];
            ppos++;
            shift++;
        }
    }
    pmt[ppos] = shift;
    ppos = 0;
    int res = 0;
    while (tpos < tlen) {
        if (p[ppos] == t[tpos]) {
            ppos++;
            tpos++;
            if (ppos == plen && tpos - plen >= positionAfterThis) {
                return tpos - plen;
            }
        } else {
            ppos = pmt[ppos];
            if (ppos < 0) {
                ppos++;
                tpos++;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        string p, t;
        cin >> p >> t;
        if (p == "*") {
            printf("YES\n");
            continue;
        }
        int i = 0;
        while (p[i] != '*') {
            i++;
            if (i > n) break;
        }
        if (i > 0 && i < n - 1) {
            string p1 = p.substr(0, i);
            string p2 = p.substr(i + 1, n - 1);
            int p1pos = kmpSearch(p1, t, 0);
            int p2pos = kmpSearch(p2, t, p1pos + i);
            if (p1pos >= 0 && p2pos >= 0)
                printf("YES\n");
            else
                printf("NO\n");
        } else if (i == 0) {
            string p1 = p.substr(1, n);
            int p1pos = kmpSearch(p1, t, 0);
            if (p1pos >= 0)
                printf("YES\n");
            else
                printf("NO\n");
        } else if (i == n - 1) {
            string p1 = p.substr(0, n - 1);
            int p1pos = kmpSearch(p1, t, 0);
            if (p1pos >= 0)
                printf("YES\n");
            else
                printf("NO\n");
        } else {
            int ppos = kmpSearch(p, t, 0);
            if (ppos >= 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
