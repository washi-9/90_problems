#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long a, b;

int main() {
    cin >> a >> b;
    const long long GCD = __gcd(a, b);
    if (a / GCD > INF / b) {
        cout << "Large" << endl;
    } else {
        cout << (a / GCD) * b << endl;
    }
    return 0;
}