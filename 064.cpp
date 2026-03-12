#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    long long a[100009],diff[100009];
    cin >> n >> q;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n-1;i++) {
        diff[i] = a[i+1] - a[i];
    }
    long long initial_diff = 0;
    for (int i=1;i<=n-1;i++) {
        initial_diff += abs(diff[i]);
    }
    while(q--) {
        long long l,r,v;
        cin >> l >> r >> v;
        if (l > 1) {
            initial_diff -= abs(diff[l-1]);
            diff[l-1] += v;
            initial_diff += abs(diff[l-1]);
        }
        if (r < n) {
            initial_diff -= abs(diff[r]);
            diff[r] -= v;
            initial_diff += abs(diff[r]);
        }
        cout << initial_diff << endl;
    }
    return 0;
}