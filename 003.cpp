#include <bits/stdc++.h>
using namespace std;

int MAX_DEPTH = -1;
int DEPTH_V = -1;

void dfs(int v,int p, int d, const vector<vector<int>>& g) {
    if (d > MAX_DEPTH) {
        MAX_DEPTH = d;
        DEPTH_V = v;
    }
    for(int next_v : g[v]) {
        if (next_v == p) continue;
        dfs(next_v, v, d + 1, g);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    for (int i=0;i<n-1;i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int max_score = -1;
    dfs(1, -1, 0, g);
    MAX_DEPTH = 0;
    dfs(DEPTH_V,-1, 0,g);
    cout << MAX_DEPTH+1 << endl;
    return 0;
}