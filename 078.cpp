#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<long long> ab(n+1,0);

    while(m--) {
        int a,b;
        cin >> a >> b;
        int max_num = max(a,b);
        ab[max_num]++;
    }
    long long ans = 0;
    for (int i=1;i<=n;i++) {
        if (ab[i] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}