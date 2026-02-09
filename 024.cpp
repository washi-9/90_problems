#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long a[1009],b[1009];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long diff = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        diff += abs(a[i] - b[i]);
    }

    if (diff > k || diff % 2 != k % 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}