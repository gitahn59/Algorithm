/*
boj_1849_순열(난이도 : 플레5)
boj_1777_순열복원을 뒤집은 문제
세그먼트트리, lower bound
lower bound와 segment tree를 이용한 빈도 수 탐색
segment tree가 비어있는 공간의 빈도를 저장
lower bound를 통해 공간의 갯수가 arr[i]+1 이상인 점을 탐색
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

int N;
int arr[100001];
int idx[100001];
int segment[400001];
int result[100001];

int init(int node, int start, int end) {
	if (start == end) return segment[node] = 1;
	int mid = (start + end) >> 1;
	return segment[node] = init(node << 1, start, mid) + init((node << 1) + 1, mid + 1, end);
}

int getCnt(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) >> 1;
	return getCnt(node << 1, start, mid, left, right) + getCnt((node << 1) + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
	if (start > idx || idx > end) return;

	segment[node] += diff;

	if (start != end) {
		int mid = (start + end) >> 1;
		update(node << 1, start, mid, idx, diff);
		update((node << 1) + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	init(1, 1, N);

	for (int n = 1; n <= N; n++) {
		int l = 1;
		int r = N;
		int target = arr[n] + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			int cnt = getCnt(1, 1, N, 1, mid);
			if (cnt >= target) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		result[l] = n;
		update(1, 1, N, l, -1);
	}

	for (int n = 1; n <= N; n++) {
		cout << result[n] << " ";
	}

	cout << "\n";

	return 0;
}
