#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef long long ll;
const double eps = 1e-9;

using namespace std;

ll my_sum(vector<ll> & cup, vector<ll> & cup_c,ll &kg);
double check(ll sum, ll kg, vector<ll> & cup, vector<ll> & cup_c, ll sea, ll sea_c);


ll my_sum(vector<ll> & cup, vector<ll> & cup_c, ll &kg) {
    ll  total = 0;
    kg = 0;
    for (ll i = 0; i < cup.size(); i++) {
        total += cup[i]*cup_c[i];
        kg += cup[i];
    }
    return total;

}

double check(ll sum, ll kg, vector<ll> & cup, vector<ll> & cup_c, ll sea, ll sea_c) {
    double mean = (double)sum / kg;
    if (fabs(mean-sea_c) < eps) {
        for (ll c : cup_c) {
            if (c > sea_c || c < sea_c) return -1;
        }
        return mean;
    }
    if (mean > sea_c) {
        ll m_tmp = cup_c[0];
        for (ll c : cup_c) if(c < m_tmp) m_tmp = c;
        mean = m_tmp;
        double ml = sea;
        for (ll i = 0; i < cup.size(); i++) {
            if (cup_c[i] <= sea_c) return -1;
            double delta_ml = (cup[i]*cup_c[i] - mean*cup[i] + 0.0) / (mean - sea_c);
            if (delta_ml < 0 && fabs(delta_ml) > eps) return -1;
            ml = ml - delta_ml;
            if (ml < 0 && fabs(ml) > eps) return -1;

        }
        return mean;
    }
    else {
        mean = (sum+sea_c*sea+0.0) / (kg + sea + 0.0);
        double ml = sea;
        for (ll i = 0; i < cup.size(); i++) {
            if (cup_c[i] >= sea_c) return -1;
            double delta_ml = (cup[i]*cup_c[i] - mean*cup[i] + 0.0) / (mean - sea_c);
            if (delta_ml < 0 && fabs(delta_ml) > eps) return -1;
            ml = ml - delta_ml;
            if (ml < 0 && fabs(ml) > eps) return -1;

        }
        return mean;
    }

}




int main() {
    freopen("test.txt", "r", stdin);
    ll n;
    cin >> n;
    ll sea, sea_c;
    cin >> sea_c >> sea;
    vector<ll> cup(n, 0);
    vector<ll> cup_c(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> cup_c[i] >> cup[i];
    }
    ll kg = 0;
    ll sum = my_sum(cup, cup_c,kg);

    double tmp = check(sum, kg, cup, cup_c, sea, sea_c);

    if (fabs(tmp+1) < eps) {
        cout << "Impossible" << endl;
    }
    else {
        cout << "Possible" << endl;
        printf("%.4f\n", tmp);
    }




    return 0;
}