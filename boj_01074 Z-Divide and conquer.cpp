/*
boj_1074_Z(난이도 : 실버1)
분할정복
배열을 재귀적으로 4등분하여
정답을 찾는 분할정복 문제

정답 후보 구역만 분할하여 시간복잡도를
낮추어야 함
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
#include <climits>
#include <cstdio>

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

int N, H, W;

int solve(int h, int w, int size, int now) {
	if (size == 1) {
		return now;
	}
	int s = size >> 1;
	ii m11 = mp(h, w);
	if (m11.first <= H && H <= m11.first + s - 1) {
		if (m11.second <= W && W <= m11.second + s - 1) {
			return solve(h, w, s, now);
		}
	}

	ii m12 = mp(h, w + s);
	if (m12.first <= H && H <= m12.first + s - 1) {
		if (m12.second <= W && W <= m12.second + s - 1) {
			return solve(h, w + s, s, now + s * s);
		}
	}

	ii m21 = mp(h + s, w);
	if (m21.first <= H && H <= m21.first + s - 1) {
		if (m21.second <= W && W <= m21.second + s - 1) {
			return solve(h + s, w, s, now + 2 * s * s);
		}
	}
	ii m22 = mp(h + s, w + s);
	if (m22.first <= H && H <= m22.first + s - 1) {
		if (m22.second <= W && W <= m22.second + s - 1) {
			return solve(h + s, w + s, s, now + 3 * s * s);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> H >> W;
	H++; W++;

	cout << solve(1, 1, pow(2, N), 1) - 1 << "\n";
	return 0;
}

