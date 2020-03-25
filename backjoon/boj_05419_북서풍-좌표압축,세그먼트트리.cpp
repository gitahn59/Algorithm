/*
boj_05419_북서풍(난이도 : 플레4)
구간 단축을 통해 세그먼트 트리를 구성할 수 있도록 좌표 조정
세그먼트 트리를 이용하여 가능한 쌍의 갯수를 구함
주의) x좌표는 오름차순, y좌표는 내림차순으로 정렬해야 함
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

int T;
int N;

ii island[75001];
int segment[300001];
void init() {
	memset(segment, 0, sizeof(segment));
}

int getCnt(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) >> 1;
	return getCnt(node << 1, start, mid, left, right) + getCnt((node << 1) + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx < start || end < idx) return;
	segment[node] += diff;
	if (start != end) {
		int mid = (start + end) >> 1;
		update(node << 1, start, mid, idx, diff);
		update((node << 1) + 1, mid + 1, end, idx, diff);
	}
}

bool myCmpY(ii a, ii b) {
	if (a.second < b.second) return true;
	return false;
}

bool myCmpXY(ii a, ii b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second > b.second)
			return true;
	}
	return false;
}

void solve() {
	sort(island + 1, island + N + 1, myCmpY);
	int cnt = 1;
	int pre = island[1].second;
	island[1].second = 1;
	for (int n = 2; n <= N; n++) {
		if (pre == island[n].second)
			island[n].second = cnt;
		else {
			pre = island[n].second;
			island[n].second = ++cnt;
		}
	}

	// x좌표 오름차순, y좌표 내림차순
	sort(island + 1, island + N + 1, myCmpXY);
	init();
	ll result = 0;
	for (int n = 1; n <= N; n++) {
		int now = getCnt(1, 1, 75000, island[n].second, 75000);
		result += now;
		update(1, 1, 75000, island[n].second, 1);
	}
	cout << result << "\n";
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int n = 1; n <= N; n++) {
			cin >> island[n].first >> island[n].second;
		}
		if (N == 1)
			cout << "0\n";
		else
			solve();
	}

	return 0;
}