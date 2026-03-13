#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod; // 最初から a が mod より大きい場合に備える
    while (b > 0) {
        if (b & 1) { // b の最下位ビットが 1 なら（奇数なら）
            res = (res * a) % mod;
        }
        a = (a * a) % mod; // a を 2乗, 4乗, 8乗... と育てていく
        b >>= 1;           // b を 1ビット右にシフト（2で割る）
    }
    return res;
}

int main() {
    long long n,k;
    cin >> n >> k;
    if (n==1) cout << k << endl;
    else if (n==2) cout << (k%MOD * (k-1)%MOD)%MOD;
    else {
        long long ans = (((k%MOD) * ((k-1)%MOD))%MOD * (modpow((k-2), n-2, MOD)))%MOD;
        cout << ans << endl;
    }
    return 0;
}