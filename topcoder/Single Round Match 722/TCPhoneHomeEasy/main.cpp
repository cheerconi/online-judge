#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode{
    vector<TrieNode*> sons;
    bool end = false;
};
void add (TrieNode* root, string & s, int i) {
    if (i == s.size()) {
        root->end = true;
        return;
    }
    int n = s[i] - '0';
    if (root->sons.size() == 0) root->sons = vector<TrieNode*>(10, NULL);
    if (root->sons[n] == NULL) root->sons[n] = new TrieNode();
    add (root->sons[n], s, i+1);
}

int power(int base, int n) {
    int ret = 1;
    while(n--) {
        ret = ret * base;
    }
    return ret;
}
int count(TrieNode*root, int base, int n) {
    if (root->end) {
        return power(base, n);
    }
    int ret = 0;
    for (TrieNode* son : root->sons) {
        if (!son) continue;
        ret += count(son, base, n-1);
    }
    return ret;
}

struct TCPhoneHomeEasy{
    int validNumbers(int digits, vector <string> specialPrefixes) {
        TrieNode* root = new TrieNode();
        for (string & s : specialPrefixes) {
            add (root, s, 0);
        }
        int ret = power(10, digits);
        ret -= count(root, 10, digits);
        return ret;
    }

};

int main() {
    TCPhoneHomeEasy test = TCPhoneHomeEasy();
    vector<string> s{ "1", "2", "3" ,"34"};
    int digits = 6;
    cout << test.validNumbers(digits, s) << endl;

    return 0;
}