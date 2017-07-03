#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Voucher{
    int start;
    int end;
    int cost;
    int pre;
    int rear = -1;
    Voucher(int s, int e,int c){
        start = s;
        end = e;
        cost = c;
    }
};
static bool cmp(Voucher const & v1, Voucher const & v2) {
    return v1.start < v2.start;
}

int findnext(vector<Voucher> const & v, int start) {
//    cout << "find next " << start << endl;
    int left =0;
    int right = v.size()-1;
    while (left < right) {
        int mid = (left+right) >> 1;
        if (v[mid].start == start) return mid;
        if (v[mid].start > start) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    if (v[left].start >= start) return left;
    return -1;
}

int findpre(vector<Voucher> const & v, int start) {
//    cout << "find pre " << start << endl;
    int left =0;
    int right = v.size()-1;
    while (left < right) {
        int mid = (left+right) >> 1;
        if (v[mid].start == start) return mid;
        if (v[mid].start > start) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    if (v[left].start <= start) return left;
    return left-1;
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, x, start, end, cost, time;
    scanf("%d%d", &n, &x);
    unordered_map<int, vector<Voucher> > table;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &start, &end, &cost);
        time = end - start + 1;
        auto it = table.find(time);
        if (it == table.end()){
            table[time] = vector<Voucher>(1, Voucher(start, end, cost));
        }
        else { // it != table.find(time)
            table[time].push_back(Voucher(start, end, cost));
        }
    }
    int cnt = INT_MAX;
    for (auto it = table.begin(); it != table.end(); it++) {
        time = it->first;
        auto v1 = it->second;
        auto tmp_it = table.find(x - time);
        if (tmp_it == table.end()) continue;
        auto v2 = tmp_it->second;
        if (v2[0].rear == -1) {
            sort(v2.begin(), v2.end(), cmp);
            cost = INT_MAX;
            for (int i = 0; i < v2.size(); i++) {
                cost = min(cost, v2[i].cost);
                v2[i].pre = cost;
            }
            cost = INT_MAX;
            for (int i = v2.size()-1; i >= 0; i--) {
                cost = min(cost, v2[i].cost);
                v2[i].rear = cost;
            }
        }

        for (int i = 0; i < v1.size(); i++) {
            if (cnt <= v1[i].cost) continue;
            int pos = findnext(v2, v1[i].end+1);
            if (pos != -1) cnt = min(cnt, v1[i].cost + v2[pos].rear);
            pos = findpre(v2, v1[i].start-x+time);
            if (pos != -1) cnt = min(cnt, v1[i].cost + v2[pos].pre);
        }
    }
    if (cnt != INT_MAX) cout << cnt << endl;
    else cout << -1 << endl;

    return 0;
}