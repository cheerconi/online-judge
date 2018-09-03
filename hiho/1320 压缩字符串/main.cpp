#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
int net[MAXN][MAXN];
int dp[MAXN][MAXN];

void make_next(string const & s) {
    for (int i = 0; i < s.size(); i++) {
        net[i][i] = -1;
        for (int j = i+1; j <= s.size(); j++) {
            int pre = net[i][j-1];
            while (pre != -1 && s[pre+i] != s[j-1]) {
                pre = net[i][pre+i];
            }
            net[i][j] = pre+1;
        }
    }
}
int ntol(int num) {
    int cnt = 0;
    while (num) {
        cnt++;
        num /= 10;
    }
    return cnt;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        string s;
        cin >> s;
        make_next(s);
        for (int length = 1; length <= s.size(); length++) {
            for (int i = 0; i + length <= s.size(); i++) {
                dp[i][i+length-1] = length;
                int sublength = length - net[i][i+length];
                int num = length / sublength;
                int debris_length = length - sublength*num;
                int other = 0;
                if (debris_length > 0) other = dp[i+length-debris_length][i+length-1];
                dp[i][i+length-1] = min(dp[i][i+length-1], ntol(num)+2+dp[i][i+sublength-1]+other);
                for (int j = 0; j < length; j++) {
                    dp[i][i+length-1] = min(dp[i][i+length-1], dp[i][i+j]+dp[i+j+1][i+length-1]);
                }
            }
        }
        cout << dp[0][s.size()-1] << endl;
    }

}