/*
boj_2243_사탕상자(난이도 : 플레4)
Segment Tree
세그먼트 트리와 이진탐색을 이용한
구간의 빈도 수 탐색
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
#include <functional>

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

int seg[4000001];

int getCnt(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) >> 1;
	return getCnt(node << 1, start, mid, left, right) + getCnt((node << 1) + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int value) {
	if (idx > end || idx < start) return;
	seg[node] += value;
	if (start != end) {
		int mid = (start + end) >> 1;
		update(node << 1, start, mid, idx, value);
		update((node << 1) + 1, mid + 1, end, idx, value);
	}
}

int myMin;
void binSearch(int l, int r, int target) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	int cnt = getCnt(1, 1, 1000000, 1, mid);
	if (cnt >= target) {
		myMin = min(myMin, mid);
		binSearch(l, mid - 1, target);
	}
	else {
		binSearch(mid + 1, r, target);
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int a, b, c;
	for (int n = 0; n < N; n++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			myMin = 1000000;
			binSearch(1, 1000000, b);
			cout << myMin << "\n";
			update(1, 1, 1000000, myMin, -1);
		}
		else {
			cin >> b >> c;
			update(1, 1, 1000000, b, c);
		}
	}

	return 0;
}


