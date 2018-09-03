#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;
unordered_map<string, int> table;
const int MAXN = 600 + 10;
int cost[MAXN][MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b, k, f;
    scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
    string s1, s2, pre;
    int id = 0;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (table.find(s1) == table.end()) {
            table[s1] = id++;
        }
        if (table.find(s2) == table.end()) {
            table[s2] = id++;
        }
        if (s1 == pre) {
            cost[table[s1]][table[s2]] += b;
            cost[table[s2]][table[s1]] += b;
        }
        else {
            cost[table[s1]][table[s2]] += a;
            cost[table[s2]][table[s1]] += a;
        }
        pre = s2;
    }
    int ret = 0;
    vector<int> v;
    for (int i = 1; i < id; i++) {
        for (int j = 0; j < i; j++) {
            v.push_back(cost[i][j]);
            ret += cost[i][j];
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < k; i++) {
        if (v[i] > f) ret = ret - v[i] + f;
        else break;
    }
    cout << ret << endl;
    return 0;
}