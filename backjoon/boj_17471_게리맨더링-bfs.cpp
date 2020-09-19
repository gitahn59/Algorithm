/*
boj_17471_게리맨더링(난이도 : 골드5)
bfs
bfs를 통해 선정된 후보군이 서로 연결되어있는지 확인
모든 후보군의 조합이 2^N개 있고, 각 후보군의 bfs 수행에 O(N^2) 이 걸리므로
O(2^N * N^2)의 시간복잡도를 가지지만,
N이 아주 작아 수행 가능함
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
int cost[10];
vi adj[10];

int bfs(vi& a, vi& b) {
	int start = a[0];
	bool visited[10];
	bool deny[10];
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
		deny[i] = 0;
	}
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	for (int i : b) {
		deny[i] = 1;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i : adj[now]) {
			if (deny[i] == 1) continue;
			if (visited[i] == 0) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	for (int i : a) {
		if (visited[i] == 0) return 0;
	}
	return 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> cost[n];
	}

	int M, city;
	for (int n = 0; n < N; n++) {
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> city;
			adj[n].push_back(city - 1);
		}
	}

	int myMin = INT_MAX;
	int last = (1 << N) - 1;
	for (int i = 1; i < last; i++) {
		vi a, b;
		for (int j = 0; j < N; j++) {
			if ((1 << j) & i) a.push_back(j);
			else b.push_back(j);
		}
		bool left = bfs(a, b);
		bool right = bfs(b, a);
		if (left && right) {
			int l = 0;
			for (int i : a) {
				l += cost[i];
			}
			int r = 0;
			for (int i : b) {
				r += cost[i];
			}
			myMin = min(myMin, abs(l - r));
		}
	}

	if (myMin == INT_MAX) cout << "-1\n";
	else cout << myMin << "\n";

	return 0;
}


