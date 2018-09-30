#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long LL;
static const int MAXN = 2000 + 10;
int scores[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int k, n;
    scanf("%d%d", &k, &n);
    scores[0] = 0;
    unordered_set<int> relatve;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &scores[i]);
        scores[i] += scores[i-1];
        relatve.insert(scores[i]);
    }
    int tmp;
    unordered_set<int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        table.insert(tmp);
    }
    if (relatve.size() < table.size()) {
        cout << 0 << endl;
        return 0;
    }
    unordered_set<int> ret;
    int score = *table.begin();
    for (int i : relatve) {
        int dis = score - i;
        int cnt = 0;
        for (int j : relatve) {
            if (table.find(dis + j) != table.end()) cnt++;
            if (cnt == n) {
                ret.insert(dis);
                break;
            }

        }
    }
//    for (int i : ret) cout << i << ' ';
//    cout << endl;
    cout << ret.size() << endl;


    return 0;
}