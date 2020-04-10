/*
boj_1138_한 줄로 서기(난이도 : 플레4- 세그먼트트리 구현시 / 실버1 - bf)
1) 세그먼트트리
segment트리를 1로 초기화하여 남아있는 좌석을 계산하도록 하여
lower bound로 가장 왼쪽에 있으면서 남은 좌석이 arr[n] + 1인 위치를 탐색
+1을 통해 자신이 들어갈 자리를 확보하고, 가장 왼쪽을 선택함으로써
빈공간이 처음 출연한 위치를 찾음
ex)
좌석 1 1 0 1 0 
누적 1 2 2 3 3
target = 2 이면 2번 좌석을 선택

2) bf
크기가 작아 N^2 으로 전부 탐색 가능
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
int arr[11];
int segment[44];
int result[11];

int init(int node, int start, int end) {
	if (start == end) {
		return segment[node] = 1;
	}

	int mid = (start + end) >> 1;
	return segment[node] = init(node << 1, start, mid) + init((node << 1) + 1, mid + 1, end);
}

int getCnt(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right) return segment[node];
	if (start > right || end < left) return 0;

	int mid = (start + end) >> 1;
	return getCnt(node << 1, start, mid, left, right) + getCnt((node << 1) + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx<start || idx>end) return;
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
		int l = 1; int r = N;
		int target = arr[n] + 1;//빈공간 + 내가 들어갈 자리
		while (l < r) {
			int mid = (l + r) >> 1;
			if (getCnt(1, 1, N, 1, mid) >= target) {
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

