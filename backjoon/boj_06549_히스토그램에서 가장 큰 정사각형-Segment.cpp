/*
boj_6549_히스토그램에서 가장 큰 정사각형(난이도 : 플레5)
segment

가장 큰 직사각형은 분할정복을 통해 탐색
분할정복(){
	1. 현재 구간에서 최소값의 idx 탐색(segment로 lgN에 탐색)
	2. 구간 * 최소값의 높이 --- a
	3-1 왼쪽 구간 분할정복 --- b
	3-2 오른쪽 구간 분할정복 --- c
	4. return max(a,b,c)
}

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
int arr[100000];
int seg[400000];

int init(int node, int start, int end) {
	if (start == end) return seg[node] = start;
	int mid = (start + end) >> 1;
	int a = init(node << 1, start, mid);
	int b = init((node << 1) + 1, mid + 1, end);
	if (arr[a] < arr[b]) return seg[node] = a;
	else return seg[node] = b;
}

int getMin(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return -1;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) >> 1;
	int a = getMin(node << 1, start, mid, left, right);
	int b = getMin((node << 1) + 1, mid + 1, end, left, right);
	if (a == -1) return b;
	else if (b == -1) return a;
	else {
		if (arr[a] < arr[b]) return a;
		else return b;
	}
}

ll dq(int l, int r) {
	if (l > r) return 0;
	int min_idx = getMin(1, 0, N - 1, l, r);
	ll temp = (ll)(r - l + 1) * arr[min_idx];
	temp = max(temp, dq(l, min_idx - 1));
	temp = max(temp, dq(min_idx + 1, r));

	return temp;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int n = 0; n < N; n++) {
			cin >> arr[n];
		}
		init(1, 0, N - 1);
		cout << dq(0, N - 1) << "\n";
	}

	return 0;
}


