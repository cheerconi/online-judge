#include <iostream>
const int MAXN = 1000000 + 10;
int next[MAXN];
char s[MAXN];

void make_next(int n) {
    next[0] = -1;
    for (int i = 1; i <= n; i++) {
        int pre = next[i-1];
        while (pre != -1 && s[pre] != s[i-1]) {
            pre = next[pre];
        }
        next[i] = pre + 1;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    while (scanf("%s", s) && strcmp(s, ".") != 0) {
        int n = strlen(s);
        make_next(n);
        int substr = n - next[n];
        if (n % substr == 0) {
            printf("%d\n", n / substr);
        }
        else {
            printf("%d\n", 1);
        }
    }
    return 0;
}