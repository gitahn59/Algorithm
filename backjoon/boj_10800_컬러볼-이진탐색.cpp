/*
boj_10800_컬러볼(난이도 : 골드3)
lower bound, 누적합
1. 정렬 후 같은 색, 크기 별로 누적합 계산
2. 크기가 작은 모든 볼의 누적합을 lower bound로 탐색 
3. 색이 같고 크기가 작은 모든 볼의 누적합을 lower bound로 탐색
4. (2)-(3) 출력
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

typedef struct bal {
	int num, color, size, sum;
}Ball;

int N;
ii arr[200001];
Ball brr[200002];
vii crr[200001];

bool mySortCmp(Ball a, Ball b) {
	if (a.size != b.size) {
		return a.size < b.size;
	}
	else {
		return a.color < b.color;
	}
}

bool myBallLowerCmp(Ball ball, Ball value) {
	if (ball.size < value.size) return true;
	return false;
}

bool myCrrCmp(ii a, ii b) {
	return a.first < b.first;
}
bool myiiLowerCmp(ii a, ii value) {
	if (a.first < value.first) return true;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int c, s;
	for (int n = 1; n <= N; n++) {
		cin >> c >> s;
		arr[n] = { c, s };
		brr[n] = { n,c,s };
		crr[c].push_back({ s,s });
	}

	sort(brr + 1, brr + N + 1, mySortCmp);
	for (int n = 1; n <= N; n++) {
		brr[n].sum += brr[n].size + brr[n - 1].sum;
	}

	for (int n = 1; n <= N; n++) {
		vii& v = crr[n];
		if (v.size() == 0) continue;
		sort(v.begin(), v.end());
		for (int i = 1; i < v.size(); i++) {
			v[i].second += v[i - 1].second;
		}
	}

	for (int n = 1; n <= N; n++) {
		Ball b;
		b.size = arr[n].second;
		auto it = lower_bound(brr + 1, brr + 1 + N, b, myBallLowerCmp);
		int idx = it - (brr + 1);
		int sum = 0;
		if (idx > 0) sum += brr[idx].sum;

		ii value = { arr[n].second,0 };
		vii& v = crr[arr[n].first];
		auto right = lower_bound(v.begin(), v.end(), value, myiiLowerCmp);
		idx = right - v.begin();
		if (idx >= 1) {
			sum -= v[idx - 1].second;
		}

		cout << sum << "\n";
	}

	return 0;
}

