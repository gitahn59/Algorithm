/*
boj_15681_트리와 쿼리(난이도 : 골드5)
dfs
dfs를 통해 트리를 탐색 하며 각 서브트리의
노드 숫자 계산
O(N) 시간에 탐색 가능
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

int N, R, Q;
vi adj[100001];
int cnt[100001];
int prnt[100001];

int dfs(int now, int p) {
	prnt[now] = p;
	int c = 0;
	for (int i : adj[now]) {
		if (i == p) continue;
		c += dfs(i, now);
	}
	return cnt[now] = c + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> Q;
	int a, b;
	for (int n = 1; n < N; n++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(R, 0);
	for (int q = 0; q < Q; q++) {
		cin >> a;
		cout << cnt[a] << "\n";
	}

	return 0;
}


