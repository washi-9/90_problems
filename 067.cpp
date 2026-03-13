#include <bits/stdc++.h>
using namespace std;

void ntom(const string str, const int n, const int m, string &res) {
    unsigned long sum = 0;
    for (char c : str) {
        sum = sum * n + (c - '0');
    }
    res = "";
    do {
        int num = sum % m;
        res = static_cast<char>(num + '0') + res;
        sum /= m;
    } while (sum);
    res = regex_replace(res, regex("8"),"5");
}

int main() {
    string N;
    long long k;
    cin >> N >> k;
    const int n = 8, m = 9;
    string res;
    while(k--) {
        ntom(N,n,m,res);
        N = res;
    }
    cout << N << endl;
    return 0;
}