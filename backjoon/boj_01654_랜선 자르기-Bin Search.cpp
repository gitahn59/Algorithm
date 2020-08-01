/*
boj_1654_(난이도 : 실버 3)
이진탐색
큐를 사용한 안정적인 이진탐색 구현
자료형의 범위가 2^31이므로 ll을 사용해야함
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

int K, N;
int arr[10000];

ll getCnt(int len) {
	ll cnt = 0;
	for (int k = 0; k < K; k++) {
		cnt += arr[k] / len;
	}
	return cnt;
}

int binSearch() {
	queue<LL> q;

	ll rst = 1;
	q.push({ 1, arr[K - 1] });
	while (q.size()) {
		LL now = q.front();
		q.pop();
		if (now.first > now.second) continue;
		ll mid = (now.first + now.second) >> 1;
		ll cnt = getCnt(mid);
		if (cnt >= N) {
			q.push({ mid + 1, now.second });
			if (rst < mid) rst = mid;
		}
		else {
			q.push({ now.first, mid - 1 });
		}
	}
	return rst;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;
	for (int k = 0; k < K; k++) {
		cin >> arr[k];
	}
	sort(arr, arr + K);
	cout << binSearch() << "\n";
	return 0;
}
