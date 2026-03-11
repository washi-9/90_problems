#include <bits/stdc++.h>
using namespace std;
long long start=0;

int main() {
    long long n,q,a[200009];
    cin >> n >> q;
    vector<long long> index(n+1);
    // indexは0~n-1
        for (int i=0;i<n;i++) {
        cin >> a[i];
        index.at(i) = i;
    }
    for (int i=0;i<q;i++) {
        int t,x,y;
        cin >> t >> x >> y;
        if (t == 1) {
            int temp = index.at((start + x-1)%n);
            index.at((start + x-1)%n) = index.at((start + y-1)%n);
            index.at((start + y-1)%n) = temp;
        }
        else if (t == 2) {
            start = (start + n - 1) % n;
        }
        else {
            cout << a[index.at((start + x -1) % n)] << endl;
        }
    }
    return 0;
}