#include <bits/stdc++.h>
using namespace std;

set<string> user;
long long n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (!user.contains(name)) {
            user.insert(name);
            cout << i + 1 << endl;
        }
    }
    return 0;
}