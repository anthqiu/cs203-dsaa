#include <iostream>

int charSize(char str[], int length) {
    int min = 0;
    int max = length - 1;
    while (max - min > 0) {
        int mid = (min + max) / 2;
        if (str[mid] == 0) max = mid;
        else min = mid + 1;
    }
    return min;
}

int main() {
    int T;
    scanf("%d", &T);
    for (; T > 0; T--) {
        int n;
        scanf("%d", &n);
        int count = 0, res = 0;
        char rhym = 0;
        for (; n > 0; n--) {
            char str[105] = {0};
            scanf("%105s", str);
            int min = charSize(str, 105);
            if (min >= 1 && (str[min - 1] == rhym)) {
                count++;
            } else {
                if (count > res) res = count;
                if (min >= 1) {
                    count = 1;
                    rhym = str[min - 1];
                } else {
                    rhym = 0;
                }
            }
        }
        printf("%d\n", res > count ? res : count);
    }
}