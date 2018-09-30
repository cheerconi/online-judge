#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long ll;

vector<int> x;
vector<int> y;
vector<int> r;
vector<int> dads;
const double pi = acos(-1.0);

int belong(int i, int j) {
    ll dis = ((ll)x[i]-x[j])*(x[i]-x[j]) + ((ll)y[i]-y[j])*(y[i]-y[j]);
    ll ri = (ll)r[i] * r[i];
    ll rj = (ll)r[j] * r[j];
    if (dis >= ri+rj) return 0;
    if (r[i] > r[j]) return -1;
    return 1;

}

int main() {
    //freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    x = vector<int>(n, 0);
    y = vector<int>(n, 0);
    r = vector<int>(n, 0);
    dads = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int tmp = belong(i, j);
            if (tmp == 0) continue;
            if (tmp == 1) dads[i]++;
            else dads[j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (dads[i]==0 || dads[i]%2==1) ans += (ll)r[i]*r[i];
        else ans -= (ll)r[i]*r[i];
    }
    double ret = ans * pi;
    printf("%.8f\n", ret);



    return 0;
}