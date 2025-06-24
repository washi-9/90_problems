#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int N, Q;

int main() {
    cin>>N;
    vector<long long> A(N);

    for (int i=0;i<N;i++) {
        cin>>A[i];
    }
    sort(A.begin(), A.begin() + N);
    
    cin>>Q;
    while (Q--) {
        long long B;
        cin>>B;

        // lower_boundを使ってB以上の最小の要素のインデックスを取得
        int j = lower_bound(A.begin(), A.end(), B) - A.begin();

        long long ans = INF; // 十分大きな値で初期化;
        if (j < N) ans = min(ans, abs(B - A[j]));
        if (j > 0) ans = min(ans, abs(B - A[j-1]));

        cout << ans << endl;
    }
}