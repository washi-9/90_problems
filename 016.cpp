#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N,A,B,C;
    cin >> N;
    vector<int> X(3);
    for (int i=0;i<3;i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    A = X[2]; // max value
    B = X[1];
    C = X[0];
    int ans = 9999;
    for (int i=0; i<=ans; i++) {
        for (int j=0; i + j<=ans; j++) {
            long long rest = N - (A * i + B * j);
            if (rest < 0) continue;
            if (rest % C != 0) continue;
            long long k = rest / C;
            if (i + j + k <= 9999) {
                ans = min(ans,(int)(i + j + k));
            }
        }
    }
    cout << ans << endl;
    return 0;
}