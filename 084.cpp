#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        char c; cin >> c;
        if (c == 'o') {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }

    long long ans = 0, right = 0;
    for (long long left = 0; left < n; left++) {
        while (a[right] == a[left]) {
            right++;
        }
        if (right > n) break;
        ans += n - right;
    }
    cout << ans << endl;
    return 0;
}