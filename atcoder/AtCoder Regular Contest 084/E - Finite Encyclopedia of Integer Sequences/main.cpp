#include <iostream>
#include <vector>
using namespace std;
vector<int> ret;

void solve(int k, int n) {
    if (n % 2 == 0) {
        ret.push_back(n/2);
        for (int i = 0; i < k-1; i++) {
            ret.push_back(n);
        }
        return;
    }
    for (int i = 0; i < k; i++) ret.push_back(n/2+1);
    for (int i = 0; i < k/2; i++) {
        if (ret.back() == 1) {
            ret.pop_back();
            continue;
        }
        ret.back()--;
        while (ret.size() < k) {
            ret.push_back(n);
        }
    }

}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> k >> n;
    solve(n, k);
    for (int i = 0; i < ret.size(); i++) {
        printf("%d", ret[i]);
        if (i+1 == ret.size()) printf("\n");
        else printf(" ");
    }
}