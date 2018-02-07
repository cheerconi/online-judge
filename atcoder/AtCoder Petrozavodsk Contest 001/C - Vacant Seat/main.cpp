#include <iostream>
#include <string>
using namespace std;

string ask(int i) {
    cout << i << endl;
    string s;
    cin >> s;
    if (s == "Vacant") {
        exit(0);
    }
    return s;

}
void solve (int i, int j, string s1, string s2) {
    int mid = (i+j) >> 1;
    string s0 = ask(mid);
    if ((s0 == s1 && (mid-i)%2 != 0) || (s0 != s1 && (mid-i)%2 == 0)) {
        solve (i, mid, s1, s0);
    }
    else solve(mid, j, s0, s2);

}
int main() {
    int n;
    cin >> n;
    string s1 = ask(0);
    string s2 = ask(n-1);
    solve(0, n-1, s1, s2);
    return 0;
}