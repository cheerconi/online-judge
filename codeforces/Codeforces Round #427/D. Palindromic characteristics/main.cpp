#include <iostream>
#include <string>
using namespace std;
const int MAXN = 5000 + 10;
int dp[MAXN][MAXN];
int ret[MAXN];


int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) dp[i-1][i] = 2;
    }
    for (int length = 2; length <= s.size(); length++) {
        for (int i = 0; i+length <= s.size(); i++) {
            if (s[i] == s[i+length-1] && dp[i+1][i+length-2] != 0) {
                int mid = i+length/2-1;
                dp[i][i+length-1] = dp[i][mid]+1;
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            ret[dp[i][j]]++;
        }
    }
    for (int i = s.size(); i >= 0; i--) {
        ret[i] += ret[i+1];
    }

    for (int i = 1; i <= s.size(); i++) {
        printf("%d", ret[i]);
        if (i == s.size()) printf("\n");
        else printf(" ");
    }



}