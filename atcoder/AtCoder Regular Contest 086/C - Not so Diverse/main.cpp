#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<int, int> table;
vector<int> v;
int main() {
    int n, k, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        table[val]++;
    }
    for (auto it = table.begin(); it != table.end(); it++) {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ret = 0;
    while (v.size() > k) {
        ret += v.back();
        v.pop_back();
    }
    cout << ret << endl;


    return 0;
}