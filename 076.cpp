#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n+1);
    long long total_size = 0;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        total_size += a[i];
    }
    if (total_size % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    long long target = total_size / 10;

    vector<long long> s(2*n + 1,0);
    for (int i=1;i<=2*n;i++) {
        long long val = (i <= n ? a[i] : a[i - n]);
        s[i] = s[i-1] + val;
    }

    int right = 1;
    for (int left = 0; left <= n; left++) {
        while (right <= 2 * n && s[right] - s[left] < target) {
            right++;
        }
        if (right <= 2 * n && s[right] - s[left] == target) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}