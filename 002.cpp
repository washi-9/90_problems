#include <bits/stdc++.h>
using namespace std;
/* 参考: https://drken1215.hatenablog.com/entry/2021/06/12/151200 */
/* すべてのbit列を作りそれを()に対応させて全通りを作り，条件を満たすものだけを出力 */

/* カッコ列 S が整合しているかどうか */
bool isvalid(const string &S) {
    int score = 0;
    for (auto c: S) {
        if (c=='(') ++score;
        else if (c==')') --score;

        /* 途中で0を下回るとダメ */
        if (score < 0) return false;
    }
    /* 最後に0ならtrue，そうでないならfalse */
    return (score == 0);

}

int main(void) {
    int N;
    cin >> N;

    /* カッコ列を順に列挙していく */
    for (int bit=0; bit <(1<<N); ++bit) { // 1<<NはNビット左シフト
        string S ="";

        for (int i=N-1; i>=0; --i) {
            if (!(bit & (1<<i))) S += "("; // & は and演算
            else S+= ")";
        }

        /* 整合していたら出力 */
        if (isvalid(S)) cout << S << endl;
    }

    return 0;
}