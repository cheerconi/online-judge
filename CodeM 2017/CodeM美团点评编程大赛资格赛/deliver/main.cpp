#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>

using namespace std;

string cur;
vector<int> used;
bool inf = false;

bool backtrack(vector<int> &a, vector<int> &b, int now) {
    if (now+1 == b.size()) return true;
    if (now >= b.size() || now < 0) return false;

    if (used[now] == -1) {
        inf = true;
        return false;
    }
    else if (used[now] == 1){
        return false;
    }
    else if (used[now] == 0) {
        used[now] = -1;
        cur.push_back('a');
        bool tmp = backtrack(a,b,now+a[now]);
        if (tmp) return true;
        cur.back() = 'b';
        used[now] = 1;
        tmp = backtrack(a,b,now+b[now]);
        if (tmp) return true;
        cur.pop_back();
        used[now] = 0;
    }
    return false;
}


int main(){
	freopen("1.in","r",stdin);
	int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    used = vector<int>(n, 0);
    bool tmp = backtrack(a,b,0);
    if (!tmp) {
        cout << "No solution!" << endl;
    }
    else {
        if (inf) {
            cout <<  "Infinity!" << endl;
            cout << cur << endl;
        }
        else {
            cout << cur << endl;
        }
    }



	return 0;
}