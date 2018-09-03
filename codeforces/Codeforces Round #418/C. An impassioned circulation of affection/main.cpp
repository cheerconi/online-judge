#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
//C. An impassioned circulation of affection
using namespace std;

vector<vector<int> > dp;

void compute(string &garland) {
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < garland.size(); i++) {
            if (i >= 1 && garland[i-1]==c+'a') continue;
            int d = 0;
            for (int j = i; j < garland.size(); j++) {
                if (garland[j] != c+'a') d++;
                dp[c][d] = max(dp[c][d], j-i+1);
            }
            d++;
            while (d <= garland.size()) {
                dp[c][d] = max(dp[c][d], dp[c][d-1]);
                d++;
            }
        }
    }

}


int main() {
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    dp = vector<vector<int> >(26, vector<int>(n+1, -1));
    string garland;
    cin >> garland;
    compute(garland);
    int q;
    cin >> q;
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        int ret = dp[c-'a'][m];
        cout << ret << endl;
    }

    return 0;
}