#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> m;

bool check (int t) {
    int tmp;
    for (int i = 0; i < t; i++) {
        scanf("%d", &tmp);
        m[tmp]--;
        if (m[tmp] < 0) return false;
    }
    return true;

}

int main() {
    int n, t, tmp;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        m[tmp]++;
    }
    scanf("%d", &t);
    if (check(t)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}