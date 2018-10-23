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

int main() {
    int T;
    cin >> T;
    for (; T > 0; T--) {
        int n, m;
        cin >> n >> m;
        string nn, mm;
        cin >> nn >> mm;
        string p = nn + mm;
        int shit = getMaxLen(p);
        if (shit > n) {
            shit = n;
        }
        if (shit > m) {
            shit = m;
        }
        string fuck = p.substr(0, shit);
        printf("%d %s\n", shit, fuck.c_str());
    }
}
