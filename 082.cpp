#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

// a^b mod m を計算する（繰り返し二乗法）
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD; // 最初から MOD を取っておく
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// L から R までの整数の和を MOD の世界で計算する関数
long long sum_l_to_r(long long l, long long r) {
    // 範囲内の項数: (r - l + 1)
    long long count = (r - l + 1) % MOD;
    // 初項 + 末項: (l + r)
    // l, r は最大 10^18 なので足しても 2 * 10^18 (long long に収まる)
    long long sum = (l + r) % MOD;
    
    // 分子の計算
    long long res = (count * sum) % MOD;
    
    // 2 で割る代わりに、2 の「モジュラ逆元 (1/2)」を掛け算する
    // フェルマーの小定理より、MOD が素数のとき a^(MOD-2) ≡ 1/a (mod MOD)
    long long inv2 = power(2, MOD - 2);
    res = (res * inv2) % MOD;
    
    return res;
}

int main() {
    // 高速入出力
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r;
    cin >> l >> r;

    long long ans = 0;
    long long current_l = l;
    
    // 10倍して数える危険を避け、文字列に変換して桁数を安全に取得
    int start_len = to_string(l).length();
    int end_len = to_string(r).length();

    // 桁数ごとに区間を切り出して計算
    for (int len = start_len; len <= end_len; len++) {
        // 現在の桁数における最大値を作る (例: 3桁なら 999)
        // 19桁の最大値は long long をオーバーフローするため unsigned long long を使う
        unsigned long long max_val = 0;
        for (int i = 0; i < len; i++) {
            max_val = max_val * 10 + 9;
        }
        
        // この区間の右端は、全体の右端 R と max_val のうち小さい方
        long long current_r = min((unsigned long long)r, max_val);
        
        // 区間 [current_l, current_r] の和を求め、それに桁数(len)を掛ける
        long long s = sum_l_to_r(current_l, current_r);
        long long term = (s * len) % MOD;
        
        // 全体の答えに足し込む
        ans = (ans + term) % MOD;
        
        // 次の区間の左端は、今の右端の次の数
        current_l = current_r + 1;
    }

    cout << ans << "\n";
    return 0;
}