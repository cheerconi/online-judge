#include <iostream>
#include <string>
using namespace std;
const int MAXN = 256;
string E[MAXN], T[MAXN], F[MAXN];

bool cmp(const string &  a, const string & b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}
int update(string & a, string b) {
    if (a.empty() || cmp(b, a)) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    F[15] = "x"; F[51] = "y"; F[85] = "z";
    int mask = MAXN-1;
    while (true) {
        int cnt = 0;
        for(int i = 0; i < MAXN; i++) {
            if (!T[i].empty()) {
                cnt += update(E[i], T[i]);
            }
            if (!F[i].empty()) {
                cnt += update(T[i], F[i]);
            }
            if (!F[i].empty()) {
                cnt += update(F[~i & mask], "!" + F[i]);
            }
            if (!E[i].empty()) {
                cnt += update(F[i], "("+E[i]+")");
            }
            if (F[i].empty() && E[i].empty() && T[i].empty()) continue;
            for (int j = 0; j < MAXN; j++) {
                if (!E[i].empty() && !T[j].empty()) {
                    cnt += update(E[i|j], E[i]+"|"+T[j]);
                }
                if (!T[i].empty() && !F[j].empty()) {
                    cnt += update(T[i&j], T[i]+"&"+F[j]);
                }
            }
        }
        if (cnt  == 0) break;
    }
    int n, val;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        val = 0;
        for (char c : s) {
            val = val*2 + c-'0';
        }
        cout << E[val] << '\n';
    }

    return 0;
}