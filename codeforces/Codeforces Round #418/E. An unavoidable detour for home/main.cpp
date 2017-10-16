#include <iostream>
#include <vector>
#include <memory.h>

typedef long long ll;
using namespace std;

vector<int> du;

const int mod = 1000000007;
int N = 0;

ll dp[50][50][50];
ll ct[53][53];

ll get(int two, int three, int next_num) {
    if (two < 0 || three < 0 || next_num < 0) return 0;
    ll & ret = dp[two][three][next_num];
    if (ret != -1) return ret;
    if (next_num>two+2 * three){
        ret = 0;
        return ret;
    }
    if (next_num) {
        ret = two * get(two-1, three, next_num-1)  + three * get(two+1, three-1, next_num-1);
        if (ret >= mod) ret = ret % mod;
        return ret;
    }
    if (two) {
        ret = (two-1)*get(two-2, three, 0) + three * get(two, three-1, 0);
        if (ret >= mod) ret = ret % mod;
        return ret;
    }
    if (three) {
        ret = ((three-1)*(three-2))/2 * get(2, three-3, 0);
        if (ret >= mod) ret = ret % mod;
        return ret;
    }
    return 1;



}
ll count(int next, int next_num) {
    if (next < 0 || next > 50) return 0;
    if (next < 0 || next_num > 50) return 0;
    ll & cnt = ct[next][next_num];
    if (cnt != -1) return cnt;
    cnt = 0;
    if (next+next_num-1 >= N) return 0;
    if (next == N) {
        cnt = (next_num==0);
        return cnt;
    }
    if (next_num == 0) return 0;
    int two = 0;
    int three = 0;
    for (int i = next; i <= next+next_num-1; i++) {
        if (du[i] == 2) two++;
        else three++;
    }
    for (int i = next+next_num-1; i < N; i++) {
        int d = i - next-next_num+1;
        ll tmp = count(next+next_num, d);
        if (tmp >= mod) tmp = tmp % mod;
        if (tmp != 0) cnt += tmp * get(two, three, d);
        if (cnt >= mod) cnt = cnt % mod;
    }
    return cnt;


}


int main() {
    memset(dp,-1,sizeof(dp));
    memset(ct,-1,sizeof(ct));
    //freopen("test.txt", "r", stdin);
    cin >> N;
    du = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> du[i];
    }
    ll ret = count(1, du[0]);
    if (ret >= mod) ret = ret % mod;
    cout << ret << endl;


    return 0;
}