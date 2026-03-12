#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    deque<int> yama;
    cin >> q;
    for (int i=0;i<q;i++) {
        int t,x;
        cin >> t >> x;
        if (t == 1) {
            yama.push_front(x);
        }
        else if (t == 2) {
            yama.push_back(x);
        }
        else {
            cout << yama[x-1] << endl;
        }
    }
    
    return 0;
}