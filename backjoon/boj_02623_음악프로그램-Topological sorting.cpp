/*
boj_2623_음악프로그램(난이도 : 골드2)
Topological sorting
가수들 각각이 서로간에 순서가 있으므로
위상정렬을 통해 해결할 수 있음
주의 ) 
1. 가수들의 순서관계가 중복으로 들어올 수 있으므로 unique로 중복을 제거해야 함
2. 위상 정렬을 할 수 없는 경우 0을 출력해야 함
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

int N, M;

vi adj[1001];
int arr[101];
int cnt[1001];

vi topologySort() {
	vi rst;
	vi EMPTY;

	queue<int> q;
	for (int n = 1; n <= N; n++) {
		if (cnt[n] == 0) q.push(n);
	}

	while (!q.empty()) {
		int now = q.front();
		rst.push_back(now);
		q.pop();
		for (int child : adj[now]) {
			cnt[child]--;
			if (cnt[child] == 0) {
				q.push(child);
			}
			else if (cnt[child] < 0) {
				return EMPTY;
			}
		}
	}
	if (rst.size() != N) {
		return EMPTY;
	}
	else {
		return rst;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int K;
	for (int m = 1; m <= M; m++) {
		cin >> K;
		for (int k = 1; k <= K; k++) {
			cin >> arr[k];
		}
		for (int k = 2; k <= K; k++) {
			adj[arr[k - 1]].push_back(arr[k]);
		}
	}

	for (int n = 1; n <= N; n++) {
		sort(adj[n].begin(), adj[n].end());
		unique(adj[n].begin(), adj[n].end());
		for (int child : adj[n]) {
			cnt[child] ++;
		}
	}

	vi rst = topologySort();
	if (rst.size() == 0) {
		cout << "0\n";
	}
	else {
		for (int i : rst) {
			cout << i << "\n";
		}
	}

	return 0;
}



