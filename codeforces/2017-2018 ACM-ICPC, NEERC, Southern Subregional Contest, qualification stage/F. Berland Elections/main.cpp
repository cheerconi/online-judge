#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, m, a;
const int MAXN = 100 + 10;
struct Person{
    int first, second, id;
};
Person person[MAXN];
bool cmp(Person x, Person y) {
    if (x.first != y.first) return x.first > y.first;
    return x.second < y.second;
}

int solve(int i) {
    if (m == a) {
        if (i > k || person[i].first == 0) return 3;
        return 1;
    }
    int vote = person[i].first;
    vote += (m-a);
    for (int j = 1; j <= n; j++) {
        if (person[j].first < vote) {
            if (j > k) return 3;
            else break;
        }
    }
    vote = m - a;
    int cnt = 0;
    for (int j = i+1; j <= n; j++) {
        if (vote >= person[i].first+1-person[j].first) {
            vote = vote - (person[i].first+1-person[j].first);
            cnt++;
        }
        else break;
    }
    if (cnt+i <= k && person[i].first != 0) return 1;
    return 2;

}



int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> k >> m >> a;
    for (int i = 1; i <= n; i++) {
        person[i].first = 0;
        person[i].id = i;
    }
    int tmp;
    for (int i = 1; i <= a; i++) {
        cin >> tmp;
        person[tmp].first++;
        person[tmp].second = i;

    }
    sort(person+1, person+1+n, cmp);
    vector<int> ret(n+1, 0);
    for (int i = 1; i <= n; i++) {
        ret[person[i].id] = solve(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
        else cout << " ";
    }
    return 0;
}