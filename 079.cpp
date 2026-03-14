#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<int>> matrix1(h, vector<int>(w));
    vector<vector<int>> matrix2(h, vector<int>(w));

    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin >> matrix1[i][j];
        }
    }

    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            int val;
            cin >> val;
            matrix2[i][j] = val - matrix1[i][j];
        }
    }

    int direction_x[4] = {0,0,1,1}; // h 方向
    int direction_y[4] = {0,1,0,1}; // w 方向
    long long count = 0;
    for (int i=0;i<h-1;i++) {
        for (int j=0;j<w-1;j++) {
            int diff = matrix2[i][j];
            count += abs(diff);
            for (int k=0;k<4;k++) {
                int x = i+direction_x[k];
                int y = j+direction_y[k];
                matrix2[x][y]-=diff;
            }
        }
    }

    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            if (matrix2[i][j] != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << count << endl;
    return 0;
}