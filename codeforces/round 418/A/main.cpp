#include <iostream>
#include <vector>
//A. An abandoned sentiment from past
using namespace std;

bool check(vector<int> &s1, vector<int> &s2, int hole) {
    if (s2.size() >= 2) return true;
    s1[hole] = s2[0];
    for (int i = 1; i < s1.size(); i++) {
        if (s1[i-1] > s1[i]) return true;
    }
    return false;
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> seq1(a, 0);
    vector<int> seq2(b, 0);
    int hole = -1;
    for (int i = 0; i < a; i++) {
        cin >> seq1[i];
        if (seq1[i] == 0) hole = i;
    }
    for (int i = 0; i < b; i++) {
        cin >> seq2[i];
    }
    if (check(seq1, seq2, hole)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }


    return 0;
}