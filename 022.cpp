#include <bits/stdc++.h>
using namespace std;

long long a,b,c;
int main() {
    cin >> a >> b >> c;

    long long result = 0;
    long long gcd = __gcd(__gcd(a,b),c);

    result += (a / gcd) - 1;
    result += (b / gcd) - 1;
    result += (c / gcd) - 1;
    cout << result << endl;
    return 0;
}