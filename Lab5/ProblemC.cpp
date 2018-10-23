//
// Created by antsy on 2018/10/9.
//

#include <iostream>
#include <array>

using namespace std;

int kmpSearch(string p, string t) {
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
            if (ppos == plen) {
                res++;
                ppos = pmt[ppos];
            }
        } else {
            ppos = pmt[ppos];
            if (ppos < 0) {
                ppos++;
                tpos++;
            }
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        int n;
        scanf("%lld", &n);
        char S[n];
        scanf("%s", &S);
        int m;
        scanf("%lld", &m);
        char P[m];
        if (m <= 0) {
            printf("0\n");
            continue;
        }
        scanf("%s", &P);
        string p = P;
        string t = S;
        printf("%d\n", kmpSearch(p, t));
    }
}
