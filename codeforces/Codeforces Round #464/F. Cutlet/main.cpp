#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int a[123], b[123];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    int pre = 0;
    for (int i = 0; i < k; i++) {
        vector<int> nxt(n+1, -1);
        int dist = a[i] - pre;
        
    }

}