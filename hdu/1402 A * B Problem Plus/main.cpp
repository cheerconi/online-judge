#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1<<17;
complex<double> nums1[MAXN], nums2[MAXN];
const double PI2 = acos(-1.0) * 2;

class FFT{
 public:
  void init(int n) {
    tot_ = n;
    for (int i = 0; i < tot_; i++) {
      double theta = PI2 * i / tot_;
      omegas_[i] = complex<double>(cos(theta), sin(theta));
    }
  }
  void dft(complex<double> a[], int n, bool reverse = false) {
    for (int i = 0, j = 0; i < n; i++) {
      if (i < j) swap(a[i], a[j]);
      for (int k = n>>1; k > 0; k >>= 1) {
        j ^= k;
        if (j & k) break;
      }
    }
    complex<double> tmp, w;
    for (int m = 1; m < n; m <<= 1) {
      for (int i = 0; i < m; i++) {
        w = omega(m<<1, i);
        if (reverse) w = conj(w);
        for (int bias = 0; bias < n; bias += m<<1) {
          tmp = w * a[m+i+bias];
          a[i+m+bias] = a[i+bias] - tmp;
          a[i+bias] = a[i+bias] + tmp;
        }
      }
    }
  }
  void idft(complex<double> a[], int n) {
    dft(a, n, true);
    for (int i = 0; i < n; i++) a[i] /= n;
  }
 private:
  complex<double> omegas_[MAXN];
  int tot_;

  complex<double> omega(int n, int k) {
    k *= tot_/n;
    return omegas_[k];
  }

} fft;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  string a, b;
  while (cin >> a) {
    cin >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = a.size() + b.size() - 1;
    while (true) {
      int tmp = n & (-n);
      if (tmp == n) break;
      n += tmp;
    }
    for (int i = 0; i < n; i++) {
      if (i < a.size()) nums1[i] = a[i] - '0';
      else nums1[i] = 0;
      if (i < b.size()) nums2[i] = b[i] -'0';
      else nums2[i] = 0;
    }
    fft.init(n);
    fft.dft(nums1, n);
    fft.dft(nums2, n);
    for (int i = 0; i < n; i++) {
      nums1[i] *= nums2[i];
    }
    fft.idft(nums1, n);
    int res = 0;
    string ret;
    for (int i = 0; i < n; i++) {
      res += round(nums1[i].real());
      ret.push_back(res%10 + '0');
      res /= 10;
    }
    while (res) {
      ret.push_back(res % 10 + '0');
      res /= 10;
    }
    while (ret.size() > 1) {
      if (ret.back() == '0') ret.pop_back();
      else break;
    }
    reverse(ret.begin(), ret.end());
    cout << ret << '\n';

  }
}