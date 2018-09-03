#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
pii x, y;
vector<pii> f;
bool check(int a, int b) {
    if (a < min(x.first, y.first)) return false;
    if (a > max(x.first, y.first)) return false;
    if (b < min(x.second, y.second)) return false;
    if (b > max(x.second, y.second)) return false;
    return true;
}
bool cmp(pii a, pii b) {


}
int main() {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    x.first = x1, x.second = x2;
    y.first = y1, y.second = y2;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x1, &x2);
        if (check(x1, x2)) f.push_back({x1-x.first,x2-x.second});
    }
    y.first -= x.first;
    y.second -= x.second;



    return 0;
}