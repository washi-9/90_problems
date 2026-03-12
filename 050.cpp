#include <bits/stdc++.h>
using namespace std;

long long dp[100009];

int main(){
    int n,l;
    cin >> n >> l;
    long long ans = 0;
    dp[0] = 1;
    for (int i=1;i<=n;i++) {
        dp[i] += dp[i-1] % 1000000007;
        if (i-l >= 0) dp[i] += dp[i-l] % 1000000007;
    }
    ans = dp[n] % (1000000007);
    cout << ans << endl;
}