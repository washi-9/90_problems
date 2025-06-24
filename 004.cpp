#include <bits/stdc++.h>
#include <vector>
using namespace std;

/* 各行・列の合計を末尾ではなく別の配列に足してもよかったかも */

int main() {
    int H/*行*/,W/*列*/,tmp=0;
    cin >> H >> W;

    vector<vector<int>> A(H+1, vector<int>(W+1));

    /* 入力 */
    for (int y=0;y<H;y++) {
        for (int x=0;x<W;x++) {
            cin >> A.at(y).at(x);
        }
    }
    /* 各行の合計を末尾に追加 */
    for (int y=0;y<H;y++) {
        for (int x=0;x<W;x++) {
            tmp+=A.at(y).at(x);
        }
        A.at(y).at(W)=tmp;
        tmp=0;
    }
    /* 各列の合計を末尾に追加 */
    for (int x=0;x<W;x++) {
        for (int y=0;y<H;y++) {
            tmp+=A.at(y).at(x);
        }
        A.at(H).at(x)=tmp;
        tmp=0;
    }

    for (int y=0;y<H;y++) {
        for (int x=0;x<W;x++) {
            int ans=A.at(y).at(W) + A.at(H).at(x) - A.at(y).at(x);
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}