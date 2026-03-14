#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,l,k;
    cin >> n >> l >> k;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    a.emplace_back(l);

    int left = 0;
    int right = 1e9+1;
    while (right - left > 1) {
        int c = 0;
        int m = (left + right) / 2;
        int prev = 0;
        for (int i=0;i<=n;i++) {
            if (a[i] - prev >= m) {
                prev = a[i];
                c++;
            }
        }
        if (c >= k+1) left = m;
        else right = m;
    }
    cout << left << endl;
    return 0;
}