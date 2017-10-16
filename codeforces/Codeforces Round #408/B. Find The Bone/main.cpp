#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, k, tmp;
    unordered_set<int> hole;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        hole.insert(tmp);
    }
    int now = 1;
    int a, b;
    for (int i = 0; i < k; i++) {
        if (hole.find(now) != hole.end()) break;
        scanf("%d%d",&a, &b);
        if (a == now) {
            now = b;
        }
        else if (b == now) {
            now = a;
        }
    }
    cout << now << endl;
    return 0;
}