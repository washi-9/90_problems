#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

const double PI = acos(-1);

long double t,l,x,y,e;
int q;

double solve(double d) {
    double cx,cy,cz,d1,d2,fukaku;
    cx = 0;
    cy = -(l / 2.0) * sin(d / t * 2.0 * PI);
	cz = (l / 2.0) * (1.0 - cos(d / t * 2.0 * PI));
	d1 = sqrt(pow((cx - x),2) + pow((cy - y),2)); // 水平
	d2 = cz; // 観覧車の高さ
	fukaku = atan2(d2, d1);
	return fukaku * 180.0L / PI;
}

int main() {
	cin >> t;
	cin >> l >> x >> y;
	cin >> q;
	cout << fixed << setprecision(12);
	for (int i = 0; i < q ;i++) {
		cin >> e;
		cout << solve(e) << endl;
	}
	return 0;
}