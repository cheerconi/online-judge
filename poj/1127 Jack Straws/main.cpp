#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 15;
const double eps = 1e-9;
int par[MAXN];
pii s[MAXN], t[MAXN];

int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

bool ismid(double a, double b, double m) {
    double tmp = (a-m)*(b-m);
    if (tmp - eps <= 0) return true;
    return false;
}

bool check(int i, int j) {
    double k, b;
    if (s[i].first == t[i].first) {
        if (s[j].first == t[j].first) {
            if (s[i].first != s[j].first) return false;
            if (ismid(s[i].second, t[i].second, s[j].second)) return true;
            if (ismid(s[i].second, t[i].second, t[j].second)) return true;
            return false;
        }
        if (!ismid(s[j].first, t[j].first, s[i].first)) return false;
        k  = (double)(t[j].second - s[j].second) / (t[j].first - s[j].first);
        b = t[j].second - k * t[j].first;
        double tmp = k * s[i].first + b;
        if (ismid(s[i].second, t[i].second, tmp)) return true;
        return false;
    }
    if (s[j].first == t[j].first) return check(j, i);
    double k1  = (double)(t[i].second - s[i].second) / (t[i].first - s[i].first);
    double b1 = t[i].second - k1 * t[i].first;
    double k2 = (double)(t[j].second - s[j].second) / (t[j].first - s[j].first);
    double b2 = t[j].second - k2 * t[j].first;
    if (fabs(k1-k2) < eps) {
        if (fabs(b1-b2) < eps) {
            if (ismid(s[i].first, t[i].first, s[j].first)) return true;
            if (ismid(s[i].first, t[i].first, t[j].first)) return true;
            return false;
        }
        return false;
    }
    double x = (b2 - b1) / (k1 - k2);
    double y = k1 * x + b1;
    if (!ismid(s[i].first, t[i].first, x)) return false;
    if (!ismid(s[j].first, t[j].first, x)) return false;
    if (!ismid(s[i].second, t[i].second, y)) return false;
    if (!ismid(s[j].second, t[j].second, y)) return false;
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n != 0) {
        for (int i = 1; i <= n; i++) par[i] = i;
        for (int i = 1; i <= n; i++) {
            cin >> s[i].first >> s[i].second >> t[i].first >> t[i].second;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (check(i, j)) add(i, j);

            }
        }
        int a, b;
        cin >> a >> b;
        while (a != 0 && b != 0) {
            if (find(a) != find(b)) cout << "NOT CONNECTED\n";
            else cout << "CONNECTED\n";
            cin >> a >> b;
        }
        cin >> n;
    }

    return 0;
}

