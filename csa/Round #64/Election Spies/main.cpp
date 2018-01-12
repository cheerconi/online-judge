#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int spy[2];

bool split(vector<int> & A, vector<int> & B) {
    if (A.empty() || B.empty()) return false;
    cout << "Q " << A.size();
    for (int num : A) {
        cout << " " << num;
    }
    cout << endl;
    int ret;
    cin >> ret;
    if (ret != 0 && ret != A.size()) return false;
    cout << "Q " << B.size();
    for (int num : B) {
        cout << " " << num;
    }
    cout << endl;
    cin >> ret;
    if (ret != 0 && ret != B.size()) return false;
    if (ret == B.size()) swap(A, B);
    return true;
}

void solve (vector<int> & target, vector<int> & base, int start, int end, int idx) {
    if (start == end) {
        spy[idx] = target[start];
        return;
    }
    int mid = (start + end) >> 1;
    int tot = base.size() + (mid-start+1);
    cout << "Q " << tot;
    for (int num : base) {
        cout << " " << num;
    }
    for (int i = start; i <= mid; i++) {
        cout << " " << target[i];
    }
    cout << endl;
    int ret; cin >> ret;
    if (ret == 0 || ret == tot) {
        solve (target, base, mid+1, end, idx);
        return;
    }
    solve (target, base, start, mid, idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A, B;
    for (int i = 0; i < 32; i++) {
        A.clear(); B.clear();
        for (int j = 1; j <= n; j++) {
            if (j & (1<<i)) A.push_back(j);
            else B.push_back(j);
        }
        if (split(A, B)) break;
    }
    solve (A, B, 0, A.size()-1, 0);
    A.clear(); A.push_back(spy[0]);
    solve (B, A, 0, B.size()-1, 1);
    cout << "A " << spy[0] << " " << spy[1] << endl;

}