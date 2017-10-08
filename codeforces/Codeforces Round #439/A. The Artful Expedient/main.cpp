#include <iostream>
#include <unordered_set>
using namespace std;
const int MAXN = 2e3 + 10;
int a[MAXN], b[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        us.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        us.insert(b[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = a[i]^b[j];
            if (us.find(tmp) != us.end()) cnt++;
        }

    }
    if (cnt & 1) {
        cout << "Koyomi" << endl;
    }
    else {
        cout << "Karen" << endl;
    }
    return 0;
}