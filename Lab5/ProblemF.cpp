//
// Created by antsy on 2018/10/15.
//
#include <iostream>

using namespace std;

int kmpSearch(string p, string t, int pmt[], int plen) {
    int tlen = (int) t.size();
    int ppos = 0, tpos = 0;
    int res = 0;
    while (tpos < tlen) {
        if (p[ppos] == t[tpos]) {
            ppos++;
            tpos++;
            if (ppos == plen) {
                return 1;
                //ppos = pmt[ppos];
            }
        } else {
            ppos = pmt[ppos];
            if (ppos < 0) {
                ppos++;
                tpos++;
            }
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        // init
        int n;
        scanf("%d", &n);
        string fuck[n];
        int min = 201, m = -1;
        for (int i = 0; i < n; i++) {
            cin >> fuck[i];
            if (fuck[i].length() < min) {
                min = (int) fuck[i].length();
                m = i;
            }
        }
        int max = -1;
        string maxx;
        // start
        for (int i = 0; i < min - 1; i++) {
            for (int j = min - i; j >= max; j--) {
                string p = fuck[m].substr(i, j);
                // cal next array
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
                pmt[ppos] = shift;
                // judge
                bool is = true;
                for (int k = 0; k < n; k++) {
                    if (k == m)continue;
                    if (kmpSearch(p, fuck[k], pmt, plen) == 0) {
                        is = false;
                        break;
                    }
                }
                // save
                if (is && j > max) {
                    max = j;
                    maxx = p;
                    continue;
                } else if (is && j == max) {
                    maxx = maxx > p ? p : maxx;
                }
            }
        }
        printf("%s\n", max != -1 ? maxx.c_str() : "Hong");
    }
}
