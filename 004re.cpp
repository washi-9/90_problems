#include <bits/stdc++.h>
using namespace std;

int H, W;
int A[2009][2009]; // 合計値のmaxは99 * 2000 * 2 = 396000でint型で十分
int row_sum[2009], col_sum[2009];

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; ++i) {
        int sum = 0;
        for (int j = 1; j <= W; ++j) {
            cin >> A[i][j];
            sum += A[i][j];
        }
        row_sum[i] = sum;
    }

    for (int j = 1; j <= W; ++j) {
        int sum = 0;
        for (int i = 1; i <= H; ++i) {
            sum += A[i][j];
        }
        col_sum[j] = sum;
    }

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            int total = row_sum[i] + col_sum[j] - A[i][j];
            cout << total;
            if (j < W) cout << " ";
            else cout << endl;
        }
    }
}
