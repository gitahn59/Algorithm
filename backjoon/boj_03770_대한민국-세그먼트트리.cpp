/*
boj_03770_대한민국(난이도 : 골드1)
기본적인 세그먼트 트리를 이용하여 빈도수를 계산
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

int T, N, M, K;

ii arr[400001];
ll segment[4004];

ll getCnt(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) >> 1;
	return getCnt(node << 1, start, mid, left, right) + getCnt((node << 1) + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
	if (start > idx || idx > end) return;
	segment[node] += diff;
	int mid = (start + end) >> 1;
	if (start != end) {
		update(node << 1, start, mid, idx, diff);
		update((node << 1) + 1, mid + 1, end, idx, diff);
	}
}

bool myCmp(const ii& a, const ii& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

ll solve() {
	cin >> N >> M >> K;
	int a, b;
	for (int k = 1; k <= K; k++) {
		cin >> arr[k].first >> arr[k].second;
	}

	sort(arr + 1, arr + 1 + K, myCmp);
	ll sum = 0;

	memset(segment, 0, sizeof(segment));

	for (int k = 1; k <= K; k++) {
		sum += getCnt(1, 1, M, arr[k].second + 1, M);
		update(1, 1, M, arr[k].second, 1);
	}

	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cout << "Test case " << t << ": " << solve() << "\n";
	}

	return 0;
}
