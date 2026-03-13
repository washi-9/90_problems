#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long soinsuu = 0;
    for (long long i = 2; i*i<=n;i++) {
        while (n % i == 0) {
            n /= i;
            soinsuu++;
        }
    }
    if (n > 1) soinsuu++;
    if (soinsuu == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1;
    long long mahou = 2;
    while(mahou < soinsuu) {
        mahou *= 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}