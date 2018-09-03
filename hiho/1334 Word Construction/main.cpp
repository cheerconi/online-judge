#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 40 + 5;
vector<string> words;
LL neg[MAXN];

bool check(int i, int j) {
    vector<bool> v(26, false);
    for (char c : words[i]) v[c-'a'] = true;
    for (char c : words[j]) {
        if (v[c-'a']) return false;
    }
    return true;
}

int card = 0;

int count1(LL cand) {
    int ret = 0;
    while (cand != 0) {
        ret++;
        cand &= (cand - 1);
    }
    return ret;
}

void clique(int sz, LL cand) {
    if (cand == 0) {
        card = max(card, sz);
        return;
    }
    for (int i = 0; cand != 0; i++) {
        if (count1(cand)+sz <= card) return;
        if (cand & (1LL << i)) {
            cand ^= (1LL << i);
            clique(sz+1, cand&neg[i]);
        }
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        words.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (check(i, j)) {
                neg[i] |= (1LL << j);
                neg[j] |= (1LL << i);
            }
        }
    }
    clique(0, (1LL<<n)-1);
    cout << card << endl;
    return 0;
}