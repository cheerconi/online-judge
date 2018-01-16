#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<char, char> pcc;
const int MAXN= 5000;
vector<int> edges[MAXN];
vector<pcc> ind;
map<pcc, int> table;
int in[MAXN], out[MAXN], st, ed, tot;
string ret;

void fleury(int i) {
    while (!edges[i].empty()) {
        int tmp = edges[i].back();
        edges[i].pop_back();
        fleury(tmp);
    }
    ret.push_back(ind[i].second);
};

bool check () {
    for (int i = 1;  i < tot; i++) {
        if (in[i] == out[i]) continue;
        if (in[i]+1 == out[i]) {
            if (st == 0) st = i;
            else return false;
        }
        else if (in[i] == out[i]+1) {
            if (ed == 0) ed = i;
            else return false;
        }
        else return false;
    }
    if (st != 0 && ed != 0) return true;
    if (st == 0 && ed == 0) {
        st = 1;
        return true;
    }
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s;
    tot = 1;
    ind.push_back({'-','-'});
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (table.find({s[0],s[1]}) == table.end()) {
            table[{s[0],s[1]}] = tot++;
            ind.push_back({s[0],s[1]});
        }
        if (table.find({s[1],s[2]}) == table.end()) {
            table[{s[1],s[2]}] = tot++;
            ind.push_back({s[1],s[2]});
        }
        edges[table[{s[0],s[1]}]].push_back(table[{s[1],s[2]}]);
        out[table[{s[0],s[1]}]]++;
        in[table[{s[1],s[2]}]]++;
    }
    if (!check()) {
        cout << "NO" << endl;
    }
    else {
        fleury(st);
        ret.push_back(ind[st].first);
        reverse(ret.begin(), ret.end());
        if (ret.size() != n+2) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << ret << endl;
        }

    }

}

