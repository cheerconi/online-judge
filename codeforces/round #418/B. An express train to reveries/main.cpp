#include <iostream>
#include <vector>
//B. An express train to reveries
using namespace std;

void get(int n, int &dup1, int &dup2, int &need, vector<int> &seq) {
    int tmp;
    vector<int> used(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (used[tmp-1] != -1) {
            dup1 = used[tmp-1];
            dup2 = i;
        }
        used[tmp-1] = i;
        seq[i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == -1) {
            need = i+1;
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int dup11, dup12, dup21, dup22;
    int need1 = 0;
    int need2 = 0;
    vector<int> seq1(n, 0);
    vector<int> seq2(n, 0);
    get(n, dup11, dup12, need1, seq1);
    get(n, dup21, dup22, need2, seq2);
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (seq1[i] != seq2[i]) {
            diff.push_back(i);
        }
    }
    if (diff.size() == 1) seq1[diff[0]] = need1;
    else {
        if (need1 == seq2[diff[0]] && seq1[diff[1]]== need2) {
            seq1[diff[0]] = need1;
        }
        else if (seq1[diff[0]]==need2 && need1==seq2[diff[1]]) {
            seq1[diff[1]] = need1;
        }
    }
    for (int i = 0; i+1 < n; i++) cout << seq1[i] << ' ';
    cout << seq1[n-1] << endl;



    return 0;
}