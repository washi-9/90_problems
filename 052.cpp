#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    const long long MOD = 1000000007;
    cin >> n;
    vector<long long> sum(n);
    long long dice[n][6];
    for (int i=0;i<n;i++){
        long long dice_sum = 0;
        for (int j=0;j<6;j++){
            cin >> dice[i][j];
            dice_sum += dice[i][j] % MOD;
        }
        sum[i] = dice_sum;
    }
    long long ans = 1;
    for (int i=0;i<n;i++) {
        ans =  ((ans%MOD) * (sum[i] %MOD)) %MOD;
    }
    cout << ans << endl;
}