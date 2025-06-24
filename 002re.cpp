#include<bits/stdc++.h>
using namespace std;

int N;

bool is_valid(const string &S) {
    int score = 0;
    for (auto c : S) {
        if (c == '(') ++score;
        else if (c == ')') --score;

        if (score < 0) return false;
    }

    return (score == 0);
}

int main() {
    cin >> N;

    for (int bit = 0; bit < (1 << N); ++bit) {
        string S = "";

        for (int i=N-1; i>=0; --i) {
            if (!(bit & (1 << i))) S += "("; // i bitが0ならば'('
            else S += ")"; // i bitが1ならば')'
        }

        if (is_valid(S)) cout << S << endl;
    }

    return 0;
}