#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 8000 + 10;
char s[MAXN];
int compress[MAXN][MAXN];
int net[MAXN];
int dp[MAXN];

int getlength(int n) {
    int cnt = 0;
     while (n != 0) {
         cnt++;
         n /= 10;
     }
    return cnt;
}
void make_next(int i, int j) {
    net[i] = -1;
    for (int k = i+1; k <= j+1; k++) {
        int pre = net[k-1];
        while (pre != -1 && s[pre+i] != s[k-1]) {
            pre = net[pre+i];
        }
        net[k] = pre + 1;
        int length = k - i;
        if (length % (length - net[k]) == 0) {
            int num = length / (length - net[k]);
            length = getlength(length / (length-net[k])) + length - net[k];
        }
        else length++;
        compress[i][k-1] = length;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);
    for  (int i = 0; i < n; i++) {
        make_next(i, n-1);
    }
    for (int i = 0; i < n; i++) {
        dp[i] = compress[0][i];
        if (dp[i] == getlength(i+1) + 1) continue;
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + compress[j+1][i]);
        }
    }
    cout << dp[n-1] << endl;


    return 0;
}