#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(vector<int> &gem, vector<int> &p, int t) {
    int gem_i = 0;
    int p_i = 0;
    while (gem_i < gem.size() && p_i < p.size()) {
        int cur = p[p_i];
        if (gem[gem_i] < p[p_i]) {
            if (p[p_i]-gem[gem_i] > t) return false;
            cur = max(cur, t-2*(p[p_i]-gem[gem_i]) + p[p_i]);
            cur = max(cur, p[p_i] + (t - p[p_i]+gem[gem_i])/2);
        }
        else cur = p[p_i] + t;
        while (gem_i < gem.size() && gem[gem_i] <= cur) gem_i++;
        p_i++;
    }
    if (gem_i == gem.size()) return true;
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    string s;
    cin >> n >> s;
    vector<int> gem, p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') gem.push_back(i);
        else if (s[i] == 'P') p.push_back(i);
    }
    int left = 1, right = 2*n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (solve(gem, p, mid)) {
            right = mid;
        }
        else left = mid + 1;
    }
    cout << left << endl;

    return 0;
}