/*
boj_2104_부분배열 고르기(난이도 : 골드1)
분할정복, Segtree
히스토그램에서 가장 큰 직사각형 찾기 문제와 동치
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

int N;
int NONE = 100001;
int arr[100002];
int seg[400001];
ll acc[100001];

int init(int node, int start, int end) {
	if (start == end) return seg[node] = start;
	else {
		int mid = (start + end) >> 1;
		int l = init(node << 1, start, mid);
		int r = init((node << 1) + 1, mid + 1, end);
		if (arr[l] <= arr[r]) return seg[node] = l;
		else return seg[node] = r;
	}
}

int getIdx(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return NONE;
	else {
		if (l <= start && end <= r) return seg[node];
		else {
			int mid = (start + end) >> 1;
			int a = getIdx(node << 1, start, mid, l, r);
			int b = getIdx((node << 1) + 1, mid + 1, end, l, r);
			if (arr[a] <= arr[b]) return a;
			else return b;
		}
	}
}

void preprocessing() {
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		acc[n] = acc[n - 1] + arr[n];
	}

	arr[NONE] = 100000000;
	init(1, 1, N);
}

ll dq(int l, int r) {
	if (l > r) return 0;
	int idx = getIdx(1, 1, N, l, r);
	ll val = (acc[r] - acc[l - 1]) * arr[idx];
	ll a = dq(l, idx - 1);
	ll b = dq(idx + 1, r);

	ll rst = max(a, b);
	return max(rst, val);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();
	cout << dq(1, N) << "\n";

	return 0;
}


