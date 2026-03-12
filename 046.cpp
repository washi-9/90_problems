#include <bits/stdc++.h>
using namespace std;

long long n,a[50],b[50],c[50];

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a_in;
        cin >> a_in;
        a[(a_in)%46]++;
    }
    for (int i=1;i<=n;i++) {
        int b_in;
        cin >> b_in;
        b[(b_in)%46]++;
    }
    for (int i=1;i<=n;i++) {
        int c_in;
        cin >> c_in;
        c[(c_in)%46]++;
    }
    long long ans = 0;
    for (int i=0;i<46;i++) {
        for (int j=0;j<46;j++) {
            for (int k=0;k<46;k++) {
                if ((i + j + k) % 46 == 0) {
                    ans += a[i] * b[j] * c[k];
                }
            }
        }
    }
    cout << ans << endl;
}