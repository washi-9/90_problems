#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    int n;
    vector<char> s;
    s.push_back(-1);
    cin >> n;
    for (int i=0;i<n;i++) {
        char c;
        cin >> c;
        if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r') {
            s.push_back(c);
        }
    }
    vector<long long> dp(8, 0);
    dp[0] = 1;

    string T = "atcoder";
    for (int i=1;i<s.size();i++) {
        int index = T.find(s[i])+1;
        dp[index] = (dp[index] + dp[index-1])%MOD;
    }
    cout << dp[7] << endl;
    return 0;
}