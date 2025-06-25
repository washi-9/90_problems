#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;

    int DPc1[N+1],DPc2[N+1];
    for (int i=0;i<N;i++) {
        DPc1[i] = 0; // 初期化
        DPc2[i] = 0; // 初期化
    }

    int c1n=1,c2n=1;
    DPc1[0] = 0;
    DPc2[0] = 0;
    while(N--) {
        int c,p;
        cin>>c>>p;
        if (c==1) {
            DPc1[c1n] = DPc1[c1n-1] + p; // 前の値にpを加える
            DPc2[c2n] = DPc2[c2n-1]; // 2組目は変化なし
        } else {
            DPc2[c2n] = DPc2[c2n-1] + p; // 2組目にpを加える
            DPc1[c1n] = DPc1[c1n-1]; // 1組目は変化なし
        }
        c1n++;
        c2n++;
    }
    c1n--;
    c2n--;

    // Nまで値を埋める
    for (int i=c1n+1;i<N;i++) {
        DPc1[i] = DPc1[c1n]; // 1組目の値を最後まで埋める
    }
    for (int i=c2n+1;i<N;i++) {
        DPc2[i] = DPc2[c2n]; // 2組目の値を最後まで埋める
    }
    int Q;
    cin>>Q;
    while(Q--) {
        int L,R;
        cin>>L>>R;
        int ans1 = 0, ans2 = 0;

        // 1組
        ans1 = DPc1[R] - DPc1[L-1]; 
        // 2組
        ans2 = DPc2[R] - DPc2[L-1]; 
        

        cout << ans1 << " " << ans2 << endl;
    }
}