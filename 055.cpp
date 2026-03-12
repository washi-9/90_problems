#include <bits/stdc++.h>
using namespace std;

long long n,p,q;
int main() {
    cin >> n >> p >> q;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    long long ans=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                for (int l=k+1;l<n;l++) {
                    for (int m=l+1;m<n;m++){
                        long long val = a[i] % p;
                        val = (val * a[j]) % p;
                        val = (val * a[k]) % p;
                        val = (val * a[l]) % p;
                        val = (val * a[m]) % p;
                        if (val == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}