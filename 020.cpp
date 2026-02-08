#include <bits/stdc++.h>
using namespace std;

long long a,b,c;

int main() {
    cin >> a >> b >> c;
    long long uhen = c;
    for (int i = 1; i < b; i++) {
        if (a / c < uhen) {
            uhen = a + 1;
            break;
        }
        uhen *= c;
    }
    if (a < uhen) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}