/*
boj_14003_가장 긴 증가하는 부분 수열 5(난이도 : 골드1)
segment tree
1. 크기에대해 오름차순, 인덱스에 대해 내림차순 정렬
2. 자신보다 작은 값들 중 최대 길이를 구간 탐색
3. 자신을 포함해서 1을 더해 업데이트
4. 2~3 반복
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

int N;
int src[1000001];
ii arr[1000001];
int segment[4000001];
int dist[1000001];

void update(int node, int start, int end, int idx, int diff) {
	if (idx<start || idx>end) return;
	segment[node] = max(segment[node], diff);
	if (start != end) {
		int mid = (start + end) >> 1;
		update(node << 1, start, mid, idx, diff);
		update((node << 1) + 1, mid + 1, end, idx, diff);
	}
}

int getMax(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) >> 1;
	return max(getMax(node << 1, start, mid, left, right), getMax((node << 1) + 1, mid + 1, end, left, right));
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n].first;
		src[n] = arr[n].first;
		arr[n].second = n;
	}

	sort(arr + 1, arr + 1 + N, [](ii& a, ii& b) {
		if (a.first != b.first) {
			return a.first < b.first;
		}
		else {
			return a.second > b.second;
		}
		});

	ii rst;
	for (int n = 1; n <= N; n++) {
		int cnt = getMax(1, 1, N, 1, arr[n].second - 1) + 1;
		update(1, 1, N, arr[n].second, cnt);
		dist[arr[n].second] = cnt;
		if (rst.first < cnt) {
			rst.first = cnt;
			rst.second = arr[n].second;
		}
	}

	cout << rst.first << "\n";
	stack<int> si;
	ii num = { arr[rst.second].first + 1, rst.first };
	for (int n = rst.second; n >= 1; n--) {
		if (dist[n] == rst.first) {
			si.push(src[n]);
			rst.first--;
		}
	}

	while (!si.empty()) {
		cout << si.top() << " ";
		si.pop();
	}
	cout << "\n";
	return 0;
}

