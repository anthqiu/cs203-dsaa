//
// Created by antsy on 2018/10/15.
//
#include <iostream>

using namespace std;

int getMaxLen(string p) {
    int plen = (int) p.size();
    int ppos = 1;
    int pmt[plen + 1];
    int shift = 0;
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
    return shift;
}

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
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        string m;
        cin >> m;
        int max = getMaxLen(m);
        while (max > n / 3) {
            max = getMaxLen(m.substr(0, max));
        }
        if (max <= 0) {
            printf("0\n");
            continue;
        }
        int mid = kmpSearch(m.substr(0, max), m, max);
        while (mid + 2 * max > m.length()) {
            max = getMaxLen(m.substr(0, max));
            mid = kmpSearch(m.substr(0, max), m, max);
        }
        if (mid == -1 || max <= 0) {
            printf("0\n");
            continue;
        }
        printf("%d\n", max);
    }
}
