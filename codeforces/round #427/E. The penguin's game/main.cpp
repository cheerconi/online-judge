#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n, x, y;
vector<int> ret;


bool find2(int start, int end) {
    if (start > end) return false;
    printf("? %d ", end-start+1);
    for (int i = start; i <= end; i++) {
        printf("%d", i);
        if (i == end) cout << endl;
        else printf(" ");
    }
    int ret;
    scanf("%d", &ret);
    if (ret == 0 || ret == x) return false;
    return true;
}
int find1(int start, int end) {
    if (start == end) return start;
    int mid = (start+end) >> 1;
    printf("? %d ", mid-start+1);
    for (int i = start; i <= mid; i++) {
        printf("%d", i);
        if (i == mid) cout << endl;
        else printf(" ");
    }
    int ret;
    scanf("%d", &ret);
    if (ret == y || ret == (x^y)) return find1(start, mid);
    return find1(mid+1, end);
}

bool solve(int start, int end) {
    int mid = (start+end) >> 1;
    if (find2(start, mid)) {
        ret.push_back(find1(start, mid));
        ret.push_back(find1(mid+1, end));
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &x, &y);

    queue<pii> q;
    q.push({1,n});

    while (true) {
        int start = q.front().first;
        int end = q.front().second;
        q.pop();
        if (solve(start, end)) break;
        int mid = (start+end) >> 1;
        q.push({start, mid});
        q.push({mid+1, end});
    }

    cout << "! " << ret[0] << " " << ret[1] << endl;
    return 0;
}