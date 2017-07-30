#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> mid;
int m, n;

bool check(int a, int b) {
    if (a == 1) {
        if (mid.find(b) != mid.end()) return true;
        mid.insert(b);
    }
    if (b == n) {
        if (mid.find(a) != mid.end()) return true;
        mid.insert(a);
    }
    return false;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        if (check(a, b)) {
            printf("POSSIBLE\n");
            return 0;
        }

    }
    printf("IMPOSSIBLE\n");
    return 0;
}