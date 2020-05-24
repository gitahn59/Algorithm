/*
boj_1166_선물(난이도 : 실버3)
이진탐색
사각형의 부피의 성질을 이용한 이진탐색
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <set>
#include <bitset>
#include <climits>
#include <tuple>

#define PRIME 1000000007
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

ll N;
double L, W, H;

ll getCount(double num) {
	ll sum = 1;
	sum *= (int)(L / num);
	sum *= (int)(W / num);
	sum *= (int)(H / num);
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> W >> H;
	double r = min(L, W);
	r = min(r, H);

	double l = 0;
	int cnt = 0;
	while (true) {
		cnt++;
		double min = (l + r) / 2;
		ll n = getCount(min);
		if (n < N) {
			r = min;
		}
		else {
			l = min;
		}

		if (cnt == 50) break;
	}

	printf("%.10lf\n", l);

	return 0;
}
