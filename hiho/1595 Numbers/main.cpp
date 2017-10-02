#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int n, k;

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    set<int> s;
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        s.insert(tmp);
    }
    int ret = *s.rbegin() - *s.begin();
    auto it = s.begin();
    int pre = *it;
    it++;
    vector<int> gaps;
    while (it != s.end()) {
        gaps.push_back(*it - pre);
        pre = *it;
        it++;
    }
    sort(gaps.begin(), gaps.end(), greater<int>());
    for (int i = 0; i < gaps.size() && i < k-1; i++) {
        ret -= gaps[i];
    }
    cout << ret << endl;
    return 0;
}