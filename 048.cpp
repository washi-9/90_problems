#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> ab(2*n);
    for (int i=0;i<2*n;i += 2) {
        int a,b;
        cin >> a >> b;
        ab.at(i) = b;
        ab.at(i+1) = a - b;
    }
    sort(ab.rbegin(), ab.rend());
    long long ans = 0;
    int index = 0;
    while(k--) {
        ans += ab.at(index);
        index++;
    }
    cout << ans << endl;
}